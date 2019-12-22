`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:07:09 11/04/2015 
// Design Name: 
// Module Name:    Combo 
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
module Combo(input clk,
				 input reset,
				 input [15:0] Write,
				 input Flags_enable,
				 input PCen,
				 input [15:0] Read_Reg_BusA,
				 input [15:0] Read_Reg_BusB,
				 input ALU_Buff_ctrl,
				 input READ_Imm,
				 input jump_ctrl,
				 input branch_ctrl,
				 input mem_doutA_ctrl,
				 input mem_addA_ctrl,
				 input mem_enA,
				 input mem_weA,
				 
				 
				 input mem_addB_ctrl,
				 input mem_enB,
				 input mem_weB,
				 
				 output [15:0] mem_doutA,
				 output [15:0] mem_doutB,
				 output [4:0] Flags_out,
				 output [15:0] pc,
				 
				 input link_signal,
				 input ret_signal
    );

		
	wire [15:0] ALUBus, ALU_BUS_A, ALU_BUS_B, ALU_BUS_subA, Data_Bus, IMM_BUS, mem_dinB;	
	wire [15:0] r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
	wire [14:0] mem_addrA, mem_addrB;
	wire [4:0] Flags_in;
		
	memory mem(clk, mem_enA, mem_enB, mem_weA, mem_weB, ALU_BUS_subA, mem_dinB, mem_addrA,
					mem_addrB, mem_doutA, mem_doutB);
					
	assign mem_addrA = (mem_addA_ctrl) ? ALU_BUS_B[14:0] : pc[14:0];
		
	TriBuff ALU_Buffer(Data_Bus, ALUBus, ALU_Buff_ctrl);
	TriBuff doutA_Buffer(Data_Bus, mem_doutA, mem_doutA_ctrl);
	
	RegFile Reg(Data_Bus, Flags_in, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10,
						r11, r12, r13, r14, r15, Flags_out, Write, clk, reset, Flags_enable);
				
	Buffer BusA(r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, 
						r13, r14, r15, Read_Reg_BusA, ALU_BUS_subA);
	Buffer BusB(r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, 
						r13, r14, r15, Read_Reg_BusB, ALU_BUS_B);	
		
	ALU_Module ALU(ALU_BUS_A, ALU_BUS_B, {mem_doutA[15:12], mem_doutA[7:4]}, Flags_out[0], ALUBus, Flags_in);

	assign ALU_BUS_A = (READ_Imm) ? IMM_BUS : ALU_BUS_subA;
	
	signextend Immediate({mem_doutA[15:12], mem_doutA[7:4]}, mem_doutA[3:0], IMM_BUS);
	
	ProgramCounter PC(pc, pc, PCen, clk, reset, branch_ctrl, jump_ctrl, IMM_BUS, ALU_BUS_subA, link_signal, ret_signal);

endmodule
