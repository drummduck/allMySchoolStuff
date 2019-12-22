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
	 output[15:0] mem_doutA,
	 output ca,
	 output cb,
	 output cc,
	 output cd,
    output ce,
	 output cf,
	 output cg,
	 output an0,
	 output an1,
	 output an2,
	 output an3,
	 output expired,
	 output[7:0] rgb,
	 output hSync, vSync,
	 input enable
	 );

	 mainClock instance_name
   (// Clock in ports
    .CLK_IN1(clk),      // IN
    // Clock out ports
    .CLK_OUT1(CLK_OUT1)); 

	wire [15:0] Read_Reg_BusA, Read_Reg_BusB;
	wire [4:0]  Flags_out;
	wire [15:0] Data_Bus, Write;
	wire [15:0] mem_dinB, mem_doutB; // mem_doutA,
	wire [15:0] pc;
	wire link;
	wire ret;

Combo Guts(.clk(CLK_OUT1), .reset(reset), .Write(Write), .Flags_enable(Flags_enable), .PCen(PCen),
			  .Read_Reg_BusA(Read_Reg_BusA), .Read_Reg_BusB(Read_Reg_BusB), .ALU_Buff_ctrl(ALU_Buff_ctrl),
			  .READ_Imm(READ_Imm), .jump_ctrl(jump_ctrl), .branch_ctrl(branch_ctrl), .mem_doutA_ctrl(mem_doutA_ctrl),
			  .mem_addA_ctrl(mem_addA_ctrl), .mem_enA(mem_enA), .mem_weA(mem_weA),
				 
			  .mem_addB_ctrl(mem_addB_ctrl), .mem_enB(mem_enB), .mem_weB(mem_weB), .rgb(rgb), .hSync(hSync), .vSync(vSync),
				 
			  .mem_doutA(mem_doutA), .mem_doutB(mem_doutB), .Flags_out(Flags_out), .pc(pc), .link_signal(link), .ret_signal(ret),
				.ca(ca), .cb(cb), .cc(cc), .cd(cd), .ce(ce), .cf(cf), .cg(cg), .an0(an0), .an1(an1), .an2(an2), .an3(an3), .expired(expired),
				.enable(enable));
	 
	 
FSM_Control Brains(mem_doutA, pc, Flags_out, CLK_OUT1, reset, Write, Flags_enable, PCen, Read_Reg_BusA,
						 Read_Reg_BusB, ALU_Buff_ctrl, READ_Imm, jump_ctrl, branch_ctrl, mem_doutA_ctrl, 
						 mem_addA_ctrl, mem_enA, mem_weA, mem_doutB_ctrl, mem_addB_ctrl, mem_enB, mem_weB, link, ret);
					
endmodule
