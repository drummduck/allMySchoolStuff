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

module Test_CPU;

	// Inputs
	reg clk;
	reg reset;

	// Outputs
	wire [15:0] mem_doutA;

	// Instantiate the Unit Under Test (UUT)
	CPU uut (
		.clk(clk), 
		.reset(reset), 
		.mem_doutA(mem_doutA)
	);
integer i;
	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		
		repeat(4) #1 clk = ~clk; //Pulse the clock with reset active.
		$display("Reset pulse sent");
		reset = 0;
		
		//Make a clock
		forever #1 clk = ~clk;  //Make a continuous clock.
		$display("Clock started.");
	end
	initial begin
		@ (negedge reset);  //Wait for the reset to complete before proceeding.
		
		for (i = 0; i < 1600000000; i = i + 1)
		begin
			@ (posedge clk);  //Wait for enough clock edges to see outputs change.
			if (i == 1300000000)
			begin
			reset = 1;
				$display("Triggering second reset.");
			end
			if (i == 1300000002)
			begin
				reset = 0;
			end
			if (i == 1500000000)
			begin
				reset = 1;
				$display("Third reset.");
			end
			if (i == 1500000002)
			begin
				reset = 0;
			end
		end
		$display("The simulation has completed.");
		$finish;  //Ends the simulation.
	end
      
endmodule

