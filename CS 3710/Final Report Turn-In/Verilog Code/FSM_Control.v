`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:34:49 10/26/2015 
// Design Name: 
// Module Name:    FSM_Control 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module FSM_Control(instruction, pc, flags, clk, reset, Reg_write,
					Flags_enable, PCen, Read_Reg_BusA, Read_Reg_BusB, ALU_Buff_ctrl,
					READ_Imm, jump_ctrl, branch_ctrl, mem_doutA_ctrl, mem_addA_ctrl,
					mem_enA, mem_weA, mem_doutB_ctrl, mem_addB_ctrl, mem_enB, mem_weB,
					link, ret
    );

input [15:0] instruction, pc;
input [4:0] flags;
input clk;
input reset;

// We need to decide what all jumps we want to do

// Register File Control Signals
output reg[15:0] Reg_write;
output reg Flags_enable;  
// PC Control Signals
output reg PCen; 
output reg link;  //Saves the current PC value to a register internal to PC Module.
output reg ret;  //Restores the PC to the saved value + 1.                      
// Buffer Control Signals 
output reg [15:0] Read_Reg_BusA, Read_Reg_BusB;
output reg ALU_Buff_ctrl;
// Mux Control Signals
output reg READ_Imm, jump_ctrl, branch_ctrl;
// Memory A Control Signals      
output reg mem_doutA_ctrl;  	// controls buffer that goes to regfile
output reg mem_addA_ctrl; 	   // controls mux that allows pc or alu_busB from registers             
output reg mem_enA, mem_weA;  // controls enable and write of memory A
// Memory B Control Signals
output reg mem_doutB_ctrl;  	// controls buffer that goes to regfile
output reg mem_addB_ctrl; 	   // controls mux that allows pc or alu_busB from registers             
output reg mem_enB, mem_weB;  // controls enable and write of memory B


reg [3:0] state;     // Current state
reg [3:0] nextstate; // Next state

reg [7:0] op;
reg [7:0] inst;  //Source and destination concatenated.

//Define states as constants.  May not use all states in the end, but 16 are defined.
parameter Reset      = 4'd0;  // Reset state.  Everything goes to 0.
parameter Fetch      = 4'd1;  // Fetch the next instruction
parameter Decode     = 4'd2;  // decode state
parameter Rtype      = 4'd3;  // R type commands dealt with
parameter Itype      = 4'd4;  // I types dealt with
parameter Load_step1 = 4'd5;  // load instructions.
parameter Load_step2 = 4'd6;
parameter Store      = 4'd7;  // Store instructions. 
parameter JAL_step1  = 4'd8;  // JAL JAL_step1 and JAL_step2 //Jump commands land here.  Use what states are needed.  Delete unused parameters later.
parameter JAL_step2  = 4'd9;
parameter RET        = 4'd10; // Return Address
parameter Branch     = 4'd11; // Branch
parameter s11        = 4'd12;
parameter s12        = 4'd13;
parameter s13        = 4'd14;
parameter s14        = 4'd15;

//Present State
always @(posedge clk)
begin
	if(reset)
		begin
			state <= Reset;
		end
	else
		begin
			state <= nextstate;
			if(state == Decode)
				begin
					//Make op and inst at every decode state.  Safety so that when data bus changes the instruction is preserved as inst.
					op <= {instruction[15:12], instruction[7:4]};
					inst <= {instruction[11:8], instruction[3:0]};
				end
		end
end

//Next State Block
always @(state)
begin
	case (state)
	Reset: 
		begin
			nextstate = Fetch;
		end
	Fetch:
		begin
			nextstate = Decode;
		end
	Decode:
		begin
			
			//Check for R type instructions based on the opcode.
			if((instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b0101) || (instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b0110) ||
			(instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b0111) || (instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b0100) ||
			(instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b1001) || (instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b1011) ||
			(instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b1000) || (instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b0001) ||
			(instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b0010) || (instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b0011) ||
			(instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b1100) || (instruction[15:12] == 4'b1000 && instruction[7:4] == 4'b0100) ||
			(instruction[15:12] == 4'b0100 && instruction[7:4] == 4'b1111) || (instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b0000) ||
			(instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b1101) || (instruction[15:12] == 4'b1000 && instruction[7:4] == 4'b0101) ||
			(instruction[15:12] == 4'b0000 && instruction[7:4] == 4'b1111) || (instruction[15:12] == 4'b1000 && instruction[7:4] == 4'b0111))
			/*if (op == 8'b0000 0101 || op == 8'b0000 0110 || op == 8'b0000 0111 || op == 8'b0000 0100
			|| op == 8'b0000 1001 || op == 8'b0000 1011 || op == 8'b0000 1000 || op == 8'b0000 0001
			|| op == 8'b0000 0010 || op == 8'b0000 0011 || op == 8'b0000 1100 || op == 8'b1000 0100
			|| op == 8'b0100 1111 || op == 8'b0000 0000 || op == 8'b0000 1101)*/  //Old version using undefined op.
				begin
					nextstate = Rtype;
				end
			//Check for I type instructions
			else if (instruction [15:12] == 4'b0101 || instruction [15:12] == 4'b0110 || instruction [15:12] == 4'b0001
			|| instruction [15:12] == 4'b0111 || instruction [15:12] == 4'b1001 || instruction [15:12] == 4'b1011
			|| instruction [15:12] == 4'b0010 || instruction [15:12] == 4'b1010 || (instruction[15:12] == 4'b1000 && instruction[7:5] == 3'b000)
			|| (instruction[15:12] == 4'b1000 && instruction[7:5] == 3'b001)|| instruction [15:12] == 4'b0011)
				begin
					nextstate = Itype;
				end
			//Check for Load instruction (uses Load_step1 and Load_step2).
			else if ((instruction[15:12] == 4'b0100 && instruction[7:4] == 4'b0000))  //(op == 8'b01000000)
				begin
					nextstate = Load_step1;
				end
			//Check for Store instruction
			else if ((instruction[15:12] == 4'b0100 && instruction[7:4] == 4'b0100))  //(op == 8'b01000100)
				begin
					nextstate = Store;
				end
			//Check for jumps.  NEED TO DEFINE JUMP COMMANDS.  Jump is JAL_step1.
			else if ((instruction[15:12] == 4'b0100 && instruction[7:4] == 4'b1000))  //(op == 8'b01001000)
				begin
					nextstate = JAL_step1;
				end
			else if ((instruction[15:12] == 4'b0100 && instruction[7:4] == 4'b1001))  //(op == 8'b01001001)
				begin
					nextstate = RET;
				end
			else
				begin
					nextstate = Branch;
				end
		end
	Rtype:
		begin
			nextstate = Fetch;
		end
	Itype:
		begin
			nextstate = Fetch;
		end
	Load_step1:
		begin
			nextstate = Load_step2;
		end
	Load_step2:
		begin
			nextstate = Fetch;
		end
	Store:
		begin
			nextstate = Fetch;
		end
	JAL_step1:
		begin
			nextstate = JAL_step2; 
		end
	JAL_step2: // This 2nd JAL state sets the PC to Rtarget, which is a register containing the target jump address 
		begin
			nextstate = Fetch;
		end	
	RET:
		begin
			nextstate = Fetch;
		end
	Branch:
		begin
			nextstate = Fetch;
		end
	default:
		begin
			nextstate = Fetch;
		end
	endcase
end

always @(state)
begin
	// Define all signals here for each state. case statements ...  Need to fully understand all signals.
   // Set all default values to prevent latches.  If nothing changes these are the default values. 
	
	
	//Register File Control Signals
	Reg_write    = 16'b0000000000000000;
	Flags_enable = 0;  
	//PC Control Signals
	PCen = 0;                       
	//Buffer Control Signals 
	Read_Reg_BusA = 0;
	Read_Reg_BusB = 0;
	ALU_Buff_ctrl = 0;
	//Mux Control Signals
	READ_Imm    = 0;
	jump_ctrl   = 0;
	branch_ctrl = 0;
	//Memory A Control Signals      
	mem_doutA_ctrl = 0;  	// controls buffer that goes to regfile
	mem_addA_ctrl  = 0;     // controls mux that allows pc or alu_busB from registers             
	mem_enA        = 0;     // controls enable for memory A
	mem_weA        = 0;     // controls write for memory A
	//Memory B Control Signals
	mem_doutB_ctrl = 0;  	// controls buffer that goes to regfile
	mem_addB_ctrl  = 0; 	   // controls mux that allows pc or alu_busB from registers             
	mem_enB        = 1;     // controls enable for memory B
	mem_weB        = 0;     // controls write for memory B
	link = 0;
	ret = 0;
	//op = {instruction[15:12], instruction[7:4]};  Defined now in decode during next state.

	
	case (state)
	Reset: 
		begin
		end
	Fetch:
		begin
			mem_enA = 1;
		end
	Decode:
		begin
		end
	Rtype:
	begin
		case(op)
						//All the operations below set all the same control signals. For now i am not using the Cin
						//output because Cin is fed into ALU regardless. So when ADDC runs it will already have Cin.
			
				//ADD				ADDU				ADDC				ADDCU				SUB				AND				 OR				 XOR				 LSH				 ASH
			8'b00000101,  8'b00000110,   8'b00000111,   8'b00000100,  8'b00001001,   8'b00000001,   8'b00000010,    8'b00000011,   8'b10000100,    8'b01001111:	
				begin
											
						Flags_enable = 1;
						
						PCen = 1;
						
						ALU_Buff_ctrl = 1;
							
					case(inst[7:4])		//Register destination we are writing to.
					
						4'b0000: //1
							begin
								Reg_write = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Reg_write = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Reg_write = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Reg_write = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Reg_write = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Reg_write = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Reg_write = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Reg_write = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Reg_write = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Reg_write = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Reg_write = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Reg_write = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Reg_write = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Reg_write = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Reg_write = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Reg_write = 16'b1000000000000000;
							end
						
					endcase
					
					Read_Reg_BusB[15:0] = Reg_write[15:0];	//Read_Reg_BusB is same as one we are writing to.
					
					case(inst[3:0])		//Read_Reg_BusA determination.
					
						4'b0000: //Register 1
							begin
								Read_Reg_BusA = 16'b0000000000000001;
							end
						4'b0001: //Register 2
							begin
								Read_Reg_BusA = 16'b0000000000000010;
							end
						4'b0010: //Register 3
							begin
								Read_Reg_BusA = 16'b0000000000000100;
							end
						4'b0011: //Register 4
							begin
								Read_Reg_BusA = 16'b0000000000001000;
							end
						4'b0100: //Register 5
							begin
								Read_Reg_BusA = 16'b0000000000010000;
							end
						4'b0101: //Register 6
							begin
								Read_Reg_BusA = 16'b0000000000100000;
							end
						4'b0110: //Register 7
							begin
								Read_Reg_BusA = 16'b0000000001000000;
							end
						4'b0111: //Register 8
							begin
								Read_Reg_BusA = 16'b0000000010000000;
							end
						4'b1000: //Register 9
							begin
								Read_Reg_BusA = 16'b0000000100000000;
							end
						4'b1001: //Register 10
							begin
								Read_Reg_BusA = 16'b0000001000000000;
							end
						4'b1010: //Register 11
							begin
								Read_Reg_BusA = 16'b0000010000000000;
							end
						4'b1011: //Register 12
							begin
								Read_Reg_BusA = 16'b0000100000000000;
							end
						4'b1100: //Register 13
							begin
								Read_Reg_BusA = 16'b0001000000000000;
							end
						4'b1101: //Register 14
							begin
								Read_Reg_BusA = 16'b0010000000000000;
							end
						4'b1110: //Register 15
							begin
								Read_Reg_BusA = 16'b0100000000000000;
							end
						4'b1111: //Register 16
							begin
								Read_Reg_BusA = 16'b1000000000000000;
							end
					endcase		
					end
					

					//CMP				//CMPU	
				8'b00001011,    8'b00001000:
					begin
					
					
					PCen = 1;
					
					Flags_enable = 1;
					
					
					case(inst[7:4])		//Register B we are reading from.
					
						4'b0000: //1
							begin
								Read_Reg_BusB = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Read_Reg_BusB = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Read_Reg_BusB = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Read_Reg_BusB = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Read_Reg_BusB = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Read_Reg_BusB = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Read_Reg_BusB = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Read_Reg_BusB = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Read_Reg_BusB = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Read_Reg_BusB = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Read_Reg_BusB = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Read_Reg_BusB = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Read_Reg_BusB = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Read_Reg_BusB = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Read_Reg_BusB = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Read_Reg_BusB = 16'b1000000000000000;
							end
						
					endcase	

				case(inst[3:0])			//Register A are reading from.
				
					4'b0000: //1
							begin
								Read_Reg_BusA = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Read_Reg_BusA = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Read_Reg_BusA = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Read_Reg_BusA = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Read_Reg_BusA = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Read_Reg_BusA = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Read_Reg_BusA = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Read_Reg_BusA = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Read_Reg_BusA = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Read_Reg_BusA = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Read_Reg_BusA = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Read_Reg_BusA = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Read_Reg_BusA = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Read_Reg_BusA = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Read_Reg_BusA = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Read_Reg_BusA = 16'b1000000000000000;
							end
						
						endcase
					end
					
					//NOT				MOV               GET                ENCHECK
				8'b00001100,   8'b00001101,     8'b10000101,         8'b10000111:			
					begin
					
					
					PCen = 1;
					
					ALU_Buff_ctrl = 1;
					
					case(inst[7:4])		//Register B we are reading from to.
					
						4'b0000: //1
							begin
								Reg_write = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Reg_write = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Reg_write = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Reg_write = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Reg_write = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Reg_write = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Reg_write = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Reg_write = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Reg_write = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Reg_write = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Reg_write = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Reg_write = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Reg_write = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Reg_write = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Reg_write = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Reg_write = 16'b1000000000000000;
							end
						
					endcase	
					
				case(inst[3:0])			//Register A are reading from.
				
					4'b0000: //1
							begin
								Read_Reg_BusA = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Read_Reg_BusA = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Read_Reg_BusA = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Read_Reg_BusA = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Read_Reg_BusA = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Read_Reg_BusA = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Read_Reg_BusA = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Read_Reg_BusA = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Read_Reg_BusA = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Read_Reg_BusA = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Read_Reg_BusA = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Read_Reg_BusA = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Read_Reg_BusA = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Read_Reg_BusA = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Read_Reg_BusA = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Read_Reg_BusA = 16'b1000000000000000;
							end
						
						endcase
					end
					
					//Wait           START
				8'b00000000,    8'b00001111:
					begin
								
						PCen = 1;
						
					end
				endcase
			
				
		end
	Itype:
		begin
			
			casez(op)
			
				 //ADDI		 		ADDUI			 ADDCUI		 	 ADDCI		 		SUBI		  		ANDI				LSHI			  ASHI
				8'b0101????,   8'b0110????,  8'b0001????,  8'b0111????,    8'b1001????,   8'b1010????,   8'b1000000?,   8'b1000001?:
				begin
				
				
				PCen = 1;
				
				Flags_enable = 1;
				
				ALU_Buff_ctrl = 1;
				
				READ_Imm = 1;
				
				
					case(inst[7:4])		//Register B we are reading from.
					
						4'b0000: //1
							begin
								Read_Reg_BusB = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Read_Reg_BusB = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Read_Reg_BusB = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Read_Reg_BusB = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Read_Reg_BusB = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Read_Reg_BusB = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Read_Reg_BusB = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Read_Reg_BusB = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Read_Reg_BusB = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Read_Reg_BusB = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Read_Reg_BusB = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Read_Reg_BusB = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Read_Reg_BusB = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Read_Reg_BusB = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Read_Reg_BusB = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Read_Reg_BusB = 16'b1000000000000000;
							end
						
					endcase	
					
					Reg_write[15:0] = Read_Reg_BusB[15:0];
					
					
					end
						
					  //CMPI         //CMPUI
					8'b1011????,   8'b0010????:
						begin
					
							READ_Imm = 1;
					
							PCen = 1;
										
							Flags_enable = 1;
							
							case(inst[7:4])		//Register B we are reading from.
					
						4'b0000: //1
							begin
								Read_Reg_BusB = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Read_Reg_BusB = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Read_Reg_BusB = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Read_Reg_BusB = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Read_Reg_BusB = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Read_Reg_BusB = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Read_Reg_BusB = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Read_Reg_BusB = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Read_Reg_BusB = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Read_Reg_BusB = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Read_Reg_BusB = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Read_Reg_BusB = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Read_Reg_BusB = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Read_Reg_BusB = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Read_Reg_BusB = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Read_Reg_BusB = 16'b1000000000000000;
							end
						
					endcase	

				
						
						
						
				end
				
			     //MOVI
				8'b0011????:
				
				begin
					
					
					PCen = 1;
					
					ALU_Buff_ctrl = 1;
					
					READ_Imm = 1;
					
					case(inst[7:4])		//Register B we are writing to.
					
						4'b0000: //1
							begin
								Reg_write = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Reg_write = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Reg_write = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Reg_write = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Reg_write = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Reg_write = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Reg_write = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Reg_write = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Reg_write = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Reg_write = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Reg_write = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Reg_write = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Reg_write = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Reg_write = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Reg_write = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Reg_write = 16'b1000000000000000;
							end
						
					endcase	
					
					Read_Reg_BusB[15:0] = Reg_write[15:0];   //Register we are reading from is same as register we are writing to.

				
					end
				
					
				endcase
					
				
		
		end
	Load_step1:
		begin
			
	//PCen = 1;                          
	mem_addA_ctrl  = 1;                
	mem_enA        = 1;  
	
					case(inst[3:0])	//Register that holds address that is sent to mem.
	
						4'b0000: //1
							begin
								Read_Reg_BusB = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Read_Reg_BusB = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Read_Reg_BusB = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Read_Reg_BusB = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Read_Reg_BusB = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Read_Reg_BusB = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Read_Reg_BusB = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Read_Reg_BusB = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Read_Reg_BusB = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Read_Reg_BusB = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Read_Reg_BusB = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Read_Reg_BusB = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Read_Reg_BusB = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Read_Reg_BusB = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Read_Reg_BusB = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Read_Reg_BusB = 16'b1000000000000000;
							end
						endcase		
			
			
		end
	Load_step2:
		begin
	
	PCen = 1;                       
	mem_doutA_ctrl = 1;  	
	mem_enA        = 1;  

			
			case(inst[7:4])		//Register we are writing memory data into.
					
						4'b0000: //1
							begin
								Reg_write = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Reg_write = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Reg_write = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Reg_write = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Reg_write = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Reg_write = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Reg_write = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Reg_write = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Reg_write = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Reg_write = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Reg_write = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Reg_write = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Reg_write = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Reg_write = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Reg_write = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Reg_write = 16'b1000000000000000;
							end
						
					endcase	
			
			

			
		end
	Store:
		begin
	
			PCen = 1;                       	        
			mem_enA        = 1;     
			mem_weA        = 1; 
			mem_addA_ctrl  = 1;
			
	
			case(inst[3:0])		//Address that we are writing data into.
				
				4'b0000: //1
							begin
								Read_Reg_BusB = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Read_Reg_BusB = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Read_Reg_BusB = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Read_Reg_BusB = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Read_Reg_BusB = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Read_Reg_BusB = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Read_Reg_BusB = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Read_Reg_BusB = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Read_Reg_BusB = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Read_Reg_BusB = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Read_Reg_BusB = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Read_Reg_BusB = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Read_Reg_BusB = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Read_Reg_BusB = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Read_Reg_BusB = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Read_Reg_BusB = 16'b1000000000000000;
							end
					endcase	

					
					case(inst[7:4])			//Data in register that is being written into memory.
					
						4'b0000: //1
							begin
								Read_Reg_BusA = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Read_Reg_BusA = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Read_Reg_BusA = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Read_Reg_BusA = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Read_Reg_BusA = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Read_Reg_BusA = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Read_Reg_BusA = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Read_Reg_BusA = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Read_Reg_BusA = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Read_Reg_BusA = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Read_Reg_BusA = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Read_Reg_BusA = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Read_Reg_BusA = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Read_Reg_BusA = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Read_Reg_BusA = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Read_Reg_BusA = 16'b1000000000000000;
							end
						
					endcase
						
				
				
			
			
		end
	JAL_step1: // This first JAL state takes PC and stores it inside of the PC module.  link = 1.
		begin
			link = 1'b1;
		end
	JAL_step2: // This 2nd JAL state sets the PC to Rtarget, which is a register containing the target jump address 
		begin
			//Route the correct register to the PC then enable the changes.
					case(inst[3:0])			//Register with the correct address.
					
						4'b0000: //1
							begin
								Read_Reg_BusA = 16'b0000000000000001;
							end
						4'b0001: //2
							begin
								Read_Reg_BusA = 16'b0000000000000010;
							end
						4'b0010: //3
							begin
								Read_Reg_BusA = 16'b0000000000000100;
							end
						4'b0011: //4
							begin
								Read_Reg_BusA = 16'b0000000000001000;
							end
						4'b0100: //5
							begin
								Read_Reg_BusA = 16'b0000000000010000;
							end
						4'b0101: //6
							begin
								Read_Reg_BusA = 16'b0000000000100000;
							end
						4'b0110: //7
							begin
								Read_Reg_BusA = 16'b0000000001000000;
							end
						4'b0111: //8
							begin
								Read_Reg_BusA = 16'b0000000010000000;
							end
						4'b1000: //9
							begin
								Read_Reg_BusA = 16'b0000000100000000;
							end
						4'b1001: //10
							begin
								Read_Reg_BusA = 16'b0000001000000000;
							end
						4'b1010: //11
							begin
								Read_Reg_BusA = 16'b0000010000000000;
							end
						4'b1011: //12
							begin
								Read_Reg_BusA = 16'b0000100000000000;
							end
						4'b1100: //13
							begin
								Read_Reg_BusA = 16'b0001000000000000;
							end
						4'b1101: //14
							begin
								Read_Reg_BusA = 16'b0010000000000000;
							end
						4'b1110: //15
							begin
								Read_Reg_BusA = 16'b0100000000000000;
							end
						4'b1111: //16
							begin
								Read_Reg_BusA = 16'b1000000000000000;
							end
						
					endcase
					
					//Enable the PC to change to the address stored in the register.
					jump_ctrl = 1'b1;
					PCen = 1'b1;
		end	
	RET:       // This state sets the PC to next insruction after the most recent jump instruction
		begin
			ret = 1'b1;
		end
	Branch:
		begin
		
	PCen = 1;                       
	//If B < A then flag[4] = 1    B < IMM 
	
		case(inst[7:4])

			4'b0000: //Jump
				begin
					branch_ctrl = 1;
				end
			4'b0001:  //JG
				begin
					if(flags[4] == 0)  //Signed or unsigned
						begin
							branch_ctrl = 1;
						end
				end
			4'b0010:  //JL
				begin
					if(flags[4] == 1)  //Signed or Unsigned
						begin
							branch_ctrl = 1;
						end
				end
			4'b0011:  //JE
				begin
					if(flags[3] == 1)
						begin
							branch_ctrl = 1;
						end
				end
			4'b0100: //JLE
				begin
					if (flags[3] == 1 || flags[4] == 1)
						begin
							branch_ctrl = 1;
						end
				end
			4'b0101: //JGE
				begin
					if(flags[4] == 0 || flags[3] == 1)
						begin
							branch_ctrl = 1;
						end
				end
			4'b0110: //JNE
				begin
					if(flags[3] == 0)
						begin
							branch_ctrl = 1;
						end
				end
			default:  //Just in case.  It defaults to no jump.  Should not happen with correct coding.
				begin
					branch_ctrl = 0;
				end
				endcase
			
		end
		
	

	endcase



end
endmodule

