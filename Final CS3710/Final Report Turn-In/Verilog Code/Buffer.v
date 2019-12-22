`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:24:27 09/14/2015 
// Design Name: 
// Module Name:    Buffer 
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
module Buffer(in0, in1, in2, in3, in4, in5, in6, in7, in8, in9, in10,
				  in11, in12, in13, in14, in15, read, out);
	
	input [15:0] in0, in1, in2, in3, in4, in5, in6, in7, in8, in9,
					in10, in11, in12, in13, in14, in15, read;
	output [15:0] out;  
				  
	TriBuff B0(out, in0, read[0]);
	TriBuff B1(out, in1, read[1]);
	TriBuff B2(out, in2, read[2]);
	TriBuff B3(out, in3, read[3]);
	TriBuff B4(out, in4, read[4]);
	TriBuff B5(out, in5, read[5]);
	TriBuff B6(out, in6, read[6]);
	TriBuff B7(out, in7, read[7]);
	TriBuff B8(out, in8, read[8]);
	TriBuff B9(out, in9, read[9]);
	TriBuff B10(out, in10, read[10]);
	TriBuff B11(out, in11, read[11]);
	TriBuff B12(out, in12, read[12]);
	TriBuff B13(out, in13, read[13]);
	TriBuff B14(out, in14, read[14]);
	TriBuff B15(out, in15, read[15]);

endmodule

module TriBuff(out, in , control
    );
	input control;
	input [15:0] in;
	output[15:0] out;
	
	assign out = (control) ? in : 16'bz;
	
//	bufif1 a0(out[0], in[0], control);
//	bufif1 a1(out[1], in[1], control);
//	bufif1 a2(out[2], in[2], control);
//	bufif1 a3(out[3], in[3], control);
//	bufif1 a4(out[4], in[4], control);
//	bufif1 a5(out[5], in[5], control);
//	bufif1 a6(out[6], in[6], control);
//	bufif1 a7(out[7], in[7], control);
//	bufif1 a8(out[8], in[8], control);
//	bufif1 a9(out[9], in[9], control);
//	bufif1 a10(out[10], in[10], control);
//	bufif1 a11(out[11], in[11], control);
//	bufif1 a12(out[12], in[12], control);
//	bufif1 a13(out[13], in[13], control);
//	bufif1 a14(out[14], in[14], control);
//	bufif1 a15(out[15], in[15], control);
	
endmodule
