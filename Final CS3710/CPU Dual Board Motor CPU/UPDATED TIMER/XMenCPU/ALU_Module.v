`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Keith Madsen, Nathan Donaldson, Clint Wilkonson, John McKay
// 
// Create Date:    20:09:38 08/31/2015 
// Design Name: 
// Module Name:    ALU_Module 
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
  module ALU_Module(A, B, Opcode, Cin, C, Flags, start, timer
    );
	 input [15:0] A, B;
	 input [7:0] Opcode;  //15-12(opcode), 7-4(opcode extension).  My encoding is bits 7-4(opcode) and 3-0(opcode extension or immediate value).
	 input Cin; //Used for the ADDC operations.
	 output reg [15:0] C;
	 output reg [4:0] Flags;  //0 = Carry, 1 = Low flag (rdest B <  A Rsource) not used.  Using 4 for both signed and unsigned., 2 = Overflow, 3 = Zbit (operands are =), 4 = Negative bit. (rdest B <  A Rsource) signed  See lab1 for full details.
	 output reg start;
	 input [15:0] timer;
	 
	 parameter ADD = 8'b00000101;
	 parameter ADDI = 8'b0101????; //The other 4 are the immediate.  All immediates follow this logic.
	 parameter ADDU = 8'b00000110;
	 parameter ADDUI = 8'b0110????; //other 4 immediate value.  Immediate high only.  Need immediate low from other other bits.  Will pass using mux.
	 parameter ADDC = 8'b00000111;
	 parameter ADDCU = 8'b00000100; //first unused on cr16 document. 
	 parameter ADDCUI = 8'b0001????; //my assignment
	 parameter ADDCI = 8'b0111????;
	 parameter SUB = 8'b00001001;
	 parameter SUBI = 8'b1001????;
	 parameter CMP = 8'b00001011;
	 parameter CMPI = 8'b1011????;
	 parameter CMPU = 8'b00001000; //Second unused op from cr16
	 parameter CMPUI = 8'b0010????; //My assignment */
	 parameter AND = 8'b00000001;
	 parameter ANDI = 8'b1010????;
	 parameter OR = 8'b00000010;
	 parameter XOR = 8'b00000011;
	 parameter NOT = 8'b00001100; //Third unused cr16
	 parameter LSH = 8'b10000100;
	 parameter LSHI = 8'b1000000?;  //Adding ? to indicate sign bit of shift.
	 //parameter RSH = 8'b00001111; //Fourth unused cr16
	 parameter ASH = 8'b01001111; //Fifth unused cr16
	 parameter ASHI = 8'b1000001?;//  Making new opcode.  old: 8'b10000101; //Sixth unused cr16
	 parameter WAIT = 8'b00000000;
	 parameter MOV = 8'b00001101; //Pass through ALU
	 parameter MOVI = 8'b0011????; //My assignment
	 parameter GET = 8'b10000101;
	 parameter START = 8'b00001111;
	 
always @(A, B, Opcode, Cin, timer) //On any input...decode
begin
	//Set all default values to prevent latches.  If nothing changes these are the default values.  Shouldn't matter if cased correctly.
	C = 16'b0000000000000000;
	Flags = 5'b00000;
	start = 1'b0;
	
	//Decode everything and do the work.
	casez (Opcode) //Casez allows for don't cares listed as ? in bits.
	ADD:
			begin
				C = A + B;
				//Set flags
				if ((A[15] & B[15]) | (~A[15] & B[15] & ~C[15]) | (A[15] & ~B[15] & ~C[15])) //Carry out occured
					begin
						Flags[0] = 1'b1;
					end
				if ((~A[15] & ~B[15] & C[15]) | (A[15] & B[15] & ~C[15]))//Check overflow
					begin
						Flags[2] = 1'b1;
					end
					
				if (A == B)
					begin
						Flags[3] = 1;
					end
			end
			
	ADDI: 
			begin
				C = A + B;
				//Set flags
				if ((A[15] & B[15]) | (~A[15] & B[15] & ~C[15]) | (A[15] & ~B[15] & ~C[15])) //Carry out occured
					begin
						Flags[0] = 1'b1;
					end
				if ((~A[15] & ~B[15] & C[15]) | (A[15] & B[15] & ~C[15]))//Check overflow
					begin
						Flags[2] = 1'b1;
					end
					
				if (A == B)
					begin
						Flags[3] = 1;
					end
			end

	ADDU:
		begin
				C = A + B;
				//Set flags
				if ((A[15] & B[15]) | (~A[15] & B[15] & ~C[15]) | (A[15] & ~B[15] & ~C[15])) //Carry out occured
					begin
						Flags[0] = 1'b1;
					end

				if (A == B)
					begin
						Flags[3] = 1;
					end
			end
	ADDUI:
		begin
				C = A + B;
				//Set flags
				if ((A[15] & B[15]) | (~A[15] & B[15] & ~C[15]) | (A[15] & ~B[15] & ~C[15])) //Carry out occured
					begin
						Flags[0] = 1'b1;
					end
					
				if (A == B)
					begin
						Flags[3] = 1;
					end
			end	
	ADDC: 
		begin
			C = A + B + Cin;
				//Set flags
				if ((A[15] & B[15]) | (~A[15] & B[15] & ~C[15]) | (A[15] & ~B[15] & ~C[15])) //Carry out occured
					begin
						Flags[0] = 1'b1;
					end
				if ((~A[15] & ~B[15] & C[15]) | (A[15] & B[15] & ~C[15]))//Check overflow
					begin
						Flags[2] = 1'b1;
					end
					
				if (A == B)
					begin
						Flags[3] = 1;
					end
		end
	
	ADDCU: 
		begin
		 		C = A + B + Cin;
				//Set flags
				if ((A[15] & B[15]) | (~A[15] & B[15] & ~C[15]) | (A[15] & ~B[15] & ~C[15])) //Carry out occured
					begin
						Flags[0] = 1'b1;
					end
					
				if (A == B)
					begin
						Flags[3] = 1;
					end
		end
	ADDCUI: 
		begin
		 		C = A + B + Cin;
				//Set flags
				if ((A[15] & B[15]) | (~A[15] & B[15] & ~C[15]) | (A[15] & ~B[15] & ~C[15])) //Carry out occured
					begin
						Flags[0] = 1'b1;
					end
					
				if (A == B) // z flag check
					begin
						Flags[3] = 1;
					end
		end
	
	ADDCI:
		begin
		 		C = A + B + Cin;
				//Set flags
				if ((A[15] & B[15]) | (~A[15] & B[15] & ~C[15]) | (A[15] & ~B[15] & ~C[15])) //Carry out occured
					begin
						Flags[0] = 1'b1;
					end
					
				if ((~A[15] & ~B[15] & C[15]) | (A[15] & B[15] & ~C[15]))//Check overflow
					begin
						Flags[2] = 1'b1;
					end
					
				if (A == B) // z flag check
					begin
						Flags[3] = 1;
					end
		end
	
	
	SUB: 
		begin
			C = B - A;
			if (((A[15] == B[15] == C[15]) && (A > B)) || (B[15] & ~A[15] & ~C[15]) || (~B[15] & A[15] & C[15])) // overflow
				begin
					Flags[2] = 1;
				end
			if (A == B)
				begin
					Flags[3] = 1;
				end
		end

	////Keith.....here ya go. 
	
SUBI:
		begin
			C = B - A;
			if (((A[15] == B[15] == C[15]) && (A > B)) || (B[15] & ~A[15] & ~C[15]) || (~B[15] & A[15] & C[15])) // overflow
				begin
					Flags[2] = 1;
				end
			if (A == B)
				begin
					Flags[3] = 1;
				end
		end
		
	CMP: //Flags 2 no longer used.  Only flag 4 for 2 in unsigned.
		begin
			if($signed(A) > $signed(B))
				begin
					Flags[4] = 1;
				end
			if(A == B)
				begin
					Flags[3] = 1;
				end
			
		end
	
	CMPI: 
		begin
			if($signed(A) > $signed(B))
				begin
					Flags[4] = 1;
				end
			if(A == B)
				begin
					Flags[3] = 1;
				end
			
		end
	CMPU: 
		begin
			if($unsigned(A) > $unsigned(B))
				begin
					Flags[4] = 1;
				end
			if(A == B)
				begin
					Flags[3] = 1;
				end
			
		end
	
	CMPUI:   ////Clint
		begin
			if($unsigned(A) > $unsigned(B))
				begin
					Flags[4] = 1;
				end
			if(A == B)
				begin
					Flags[3] = 1;
				end
			
		end
		
	// Nathan's cosde starts here
	AND:
		begin
			C = A&B;
			if(A == B)
				begin
					Flags[3] = 1;
				end
			if(B < A)
				begin
					Flags[1] = 1;
				end
		end
		
	ANDI:
		begin
			C = A&B;
			if(A == B)
				begin
					Flags[3] = 1;
				end
			if(B < A)
				begin
					Flags[1] = 1;
				end
		end
	OR: 
		begin
			C = A|B;
			if(A == B)
				begin
					Flags[3] = 1;
				end
			if(B < A)
				begin
					Flags[1] = 1;
				end
		end
	XOR: 
		begin
			C = A^B;
				if(A == B)
					begin
						Flags[3] = 1;
					end
				if(B < A)
					begin
						Flags[1] = 1;
					end
		end
	NOT: 
		begin
			C = ~A;
		end
	LSH: //Logical shift.
		begin
			if($signed(A) >= 0)
				begin
					C = B << $signed(A);
				end
			else
				begin
					C = B >> $signed(-A);
				end
		end
	LSHI:	 
		begin
			if($signed(A) >= 0)
				begin
					C = B << $signed(A);
				end
			else
				begin
					C = B >> $signed(-A);
				end
		end
//	
//	
//	// John 
//	RSH:
//	begin 
//		C = B >> 1;
//	end
//	
//	RSHI:
//	begin
//		C = B >> A;
//	end
	
	ASH:
	begin
			if($signed(A) >= 0)
				begin
					C = B <<< A;
				end
			else
				begin
					C = $signed(B) >>> $signed(-A);
				end
		end
	
	ASHI:
	begin
			if($signed(A) >= 0)
				begin
					C = B <<< A;
				end
			else
				begin
					C = $signed(B) >>> $signed(-A);
				end
		end
	WAIT:
	begin
		C = 16'b0000000000000000;  //Defaults to nothing.
		Flags = 5'b00000;
	end
	
	MOV:	////John
	begin
		C = A;
	end
	MOVI:
		begin
			C = A;
		end
	GET:
		begin
			C = timer;
		end
	START:
		begin
			start = 1'b1;
		end
	default:
			begin
				C = 16'b0000000000000000;  //Defaults to nothing.
				Flags = 5'b00000;
			end
	endcase
end

endmodule
