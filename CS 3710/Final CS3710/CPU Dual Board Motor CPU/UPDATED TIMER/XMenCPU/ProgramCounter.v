`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:38:05 11/04/2015 
// Design Name: 
// Module Name:    ProgramCounter 
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
module ProgramCounter(PC_Out, PC_In, en, clk, reset, branch_ctl, jump_ctl, IMM_BUS, jump_addr, link, ret)
    ;
	 
	 input reset, clk, en, branch_ctl, jump_ctl, link, ret;
	 input[15:0] PC_In, IMM_BUS, jump_addr;
	 output reg[15:0] PC_Out;
	 reg [15:0] saved_address;  //The address to be saved during JAL commands.
	 wire [15:0] displacementValue, PC;

assign 	displacementValue = (branch_ctl) ? IMM_BUS : 16'b1;
assign PC = PC_In + $signed(displacementValue);  //signed value for negative jumping.

always@(posedge clk)
	begin
		if (reset == 1'b1) PC_Out <= 16'b0;
		else if(en == 1'b1)
			begin
				if(jump_ctl == 1'b1) PC_Out <= jump_addr;
				else PC_Out <= PC;
			end
		else
		begin
			if (link == 1'b1) saved_address <= PC_In;  //Save the current address.
			else if (ret == 1'b1) PC_Out <= saved_address + 16'b1; //The return address.
		end
	end

endmodule