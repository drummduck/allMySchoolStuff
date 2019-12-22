`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:18:47 09/14/2015 
// Design Name: 
// Module Name:    RegFile 
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
module RegFile(in, Flags_in, reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, 
					reg8, reg9,	reg10, reg11, reg12, reg13, reg14, reg15, Flags_out,
					regEnable, clk, reset, Flags_enable);
					
	input clk, reset, Flags_enable;
	input [4:0]  Flags_in;
	input [15:0] in, regEnable;
	output[4:0]  Flags_out;
	output[15:0] reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, reg8, reg9,
					 reg10, reg11, reg12, reg13, reg14, reg15;
	
Register Reg0(in, regEnable[0], reset, clk, reg0);
Register Reg1(in, regEnable[1], reset, clk, reg1);
Register Reg2(in, regEnable[2], reset, clk, reg2);
Register Reg3(in, regEnable[3], reset, clk, reg3);
Register Reg4(in, regEnable[4], reset, clk, reg4);
Register Reg5(in, regEnable[5], reset, clk, reg5);
Register Reg6(in, regEnable[6], reset, clk, reg6);
Register Reg7(in, regEnable[7], reset, clk, reg7);
Register Reg8(in, regEnable[8], reset, clk, reg8);
Register Reg9(in, regEnable[9], reset, clk, reg9);
Register Reg10(in, regEnable[10], reset, clk, reg10);
Register Reg11(in, regEnable[11], reset, clk, reg11);
Register Reg12(in, regEnable[12], reset, clk, reg12);
Register Reg13(in, regEnable[13], reset, clk, reg13);
Register Reg14(in, regEnable[14], reset, clk, reg14);
Register Reg15(in, regEnable[15], reset, clk, reg15);
Flag_Register Flags(Flags_in, Flags_enable, reset, clk, Flags_out);

endmodule


module Register(in, wEnable, reset, clk, out
    );
	 
	 input[15:0] in;
	 input clk, wEnable, reset;
	 output [15:0] out;
	 reg[15:0] out;
 
 always @( posedge clk )
	begin
		if (reset) out <= 16'b0;
		else if (wEnable == 1'b1)out <= in;
	end
endmodule

module Flag_Register(in, wEnable, reset, clk, out
    );
	 
	 input[4:0] in;
	 input wEnable, reset, clk;
	 output [4:0] out;
	 reg[4:0] out;
	 
	 
 always @( posedge clk )
	begin
		if (reset) out <= 5'b0;
		else if (wEnable == 1'b1) out <= in;			
	end
endmodule
