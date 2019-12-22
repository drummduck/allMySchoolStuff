`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:20:09 11/03/2015 
// Design Name: 
// Module Name:    CPU 
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
module CPU(
    input clk,
    input reset,
	 output[15:0] mem_doutA
	 );

	 mainClock instance_name
   (// Clock in ports
    .CLK_IN1(clk),      // IN
    // Clock out ports
    .CLK_OUT1(CLK_OUT1)); 
//	// ALU Wiring Declarations
//	wire Cin;
//	wire [4:0] Flags_in;
//	wire[7:0] Opcode;
//	wire [15:0] ALU_BUS_A , ALU_BUS_B, ALUBus;//
//	
//	// Immediate/Register MUX Wiring Declarations
//	wire READ_Imm;
//	wire [15:0]  ALU_BUS_subA,IMM_BUS;//
//	
//	// Bus A & B Buffer Wiring Declarations
	wire [15:0] Read_Reg_BusA, Read_Reg_BusB;
//	wire [15:0] r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
//	
//	// Register File Wiring Declarations
//	wire Flags_enable;
	wire [4:0]  Flags_out;
	wire [15:0] Data_Bus, Write;
//	
//	// ALU Output Buffer Wiring Declarations
//	wire ALU_Buff_ctrl;
//	
//	// mem_doutA Buffer Wiring Declarations
//	wire mem_doutA_ctrl;
//	//wire [15:0] mem_doutA;
//	
//	// memory module Wiring Declarations
//	wire mem_enA, mem_enB, mem_weA, mem_weB;
//	wire [14:0] mem_addrA, mem_addrB;
	wire [15:0] mem_dinB, mem_doutB; // mem_doutA,
//	
//	// memory address A Wiring Declarations
//	wire mem_addA_ctrl;
	wire [15:0] pc;
//	
//	// FSM_Control Wiring Declarations
//	wire reset_all, PCen, jump_ctrl, branch_ctrl; 

//Wires added to make the new PC functionality work
wire link;
wire ret;

Combo Guts(.clk(CLK_OUT1), .reset(reset), .Write(Write), .Flags_enable(Flags_enable), .PCen(PCen),
			  .Read_Reg_BusA(Read_Reg_BusA), .Read_Reg_BusB(Read_Reg_BusB), .ALU_Buff_ctrl(ALU_Buff_ctrl),
			  .READ_Imm(READ_Imm), .jump_ctrl(jump_ctrl), .branch_ctrl(branch_ctrl), .mem_doutA_ctrl(mem_doutA_ctrl),
			  .mem_addA_ctrl(mem_addA_ctrl), .mem_enA(mem_enA), .mem_weA(mem_weA),
				 
			  .mem_addB_ctrl(mem_addB_ctrl), .mem_enB(mem_enB), .mem_weB(mem_weB),
				 
			  .mem_doutA(mem_doutA), .mem_doutB(mem_doutB), .Flags_out(Flags_out), .pc(pc), .link_signal(link), .ret_signal(ret)
    );
	 
	 
FSM_Control Brains(mem_doutA, pc, Flags_out, CLK_OUT1, reset, Write, Flags_enable, PCen, Read_Reg_BusA,
						 Read_Reg_BusB, ALU_Buff_ctrl, READ_Imm, jump_ctrl, branch_ctrl, mem_doutA_ctrl, 
						 mem_addA_ctrl, mem_enA, mem_weA, mem_doutB_ctrl, mem_addB_ctrl, mem_enB, mem_weB, link, ret);
					
endmodule
