`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:17:22 11/08/2015
// Design Name:   CPU
// Module Name:   C:/Users/Beef Jerky/Documents/Beef Jerky Documents/ECE 3710/XMenCPU/Test_CPU.v
// Project Name:  XMenCPU
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CPU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Test_CPU; //

	// Inputs
	reg clk;
	reg reset;
	//reg [14:0] addrA;
	
	// Outputs
	wire [15:0] mem_doutA;
	
	// Instantiate the Unit Under Test (UUT)
	CPU uut (
		.clk(clk), 
		.reset(reset), 
		.mem_doutA(mem_doutA)
	);
	
		
always #4 clk = ~clk;  //Make a continuous clock.
	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		
		
		#100;
		
		reset = 0;
		//Make a clock
		
//		
//		
//		#8;
//	//addrA = 15'd20006;
//	dinA = 1;
//	#8;
//	dinA = 2;
//	#8;
//	dinA = 4;
//	#8;
//	dinA = 8;
//	#8;
//	dinA = 16;
//	#8;
//	dinA = 32;
//	#8;
//	dinA = 126;
//	#8;
//	dinA = 125;
//	#8;
//	dinA = 123;
//	#8;
//	dinA = 119;
//	#8;
//	dinA = 111;
//	#8;
//	dinA = 95;
//	
//	#30;
//		#30;
//	
//	//addrA = 20003;
//	xAxisPointer = 1;
//	#8;
//	xAxisPointer = 2;
//	#8;
//	xAxisPointer = 3;
//	#8;
//	xAxisPointer = 4;
//	#8;
//	xAxisPointer = 5;
//	#8;
//	xAxisPointer = 6;
//	#8;
//	xAxisPointer = 7;
//	#8;
//	xAxisPointer = 8;
//	#8;
//	xAxisPointer = 9;
//	#8;
//	xAxisPointer = 10;
//	
//	#30;
//	
//	
//	//addrA = 20004;
//	yAxisPointer = 1;
//	#8;
//	yAxisPointer = 2;
//	#8;
//	yAxisPointer = 3;
//	#8;
//	yAxisPointer = 4;
//	#8;
//	yAxisPointer = 5;
//	#8;
//	yAxisPointer = 6;
//	#8;
//	yAxisPointer = 7;
//	#8;
//	yAxisPointer = 8;
//	#8;
//	yAxisPointer = 9;
//	#8;
//	yAxisPointer = 10;
//	
//	#30;
//	
//	//addrA = 20003;
//	zAxisPointer = 1;
//	#8;
//	zAxisPointer = 2;
//	#8;
//	zAxisPointer = 3;
//	#8;
//	zAxisPointer = 4;
//	#8;
//	zAxisPointer = 5;
//	#8;
//	zAxisPointer = 6;
//	#8;
//	zAxisPointer = 7;
//	#8;
//	zAxisPointer = 8;
//	#8;
//	zAxisPointer = 9;
//	#8;
//	zAxisPointer = 10;
//	
//	#30;
//	
	end
      
endmodule

