`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:20:51 11/10/2015
// Design Name:   signextend
// Module Name:   U:/My Documents/ECE 3710/Processor with control/XMenCPU/sextendtest.v
// Project Name:  XMenCPU
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: signextend
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module sextendtest;

	// Inputs
	reg [7:0] Opcode;
	reg [3:0] Immlow;

	// Outputs
	wire [15:0] Extended;

	// Instantiate the Unit Under Test (UUT)
	signextend uut (
		.Opcode(Opcode), 
		.Immlow(Immlow), 
		.Extended(Extended)
	);

	initial begin
		// Initialize Inputs
		Opcode = 0;
		Immlow = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		Opcode = 8'h30;
		Immlow = 4'b0001;
		#10;

	end
      
endmodule

