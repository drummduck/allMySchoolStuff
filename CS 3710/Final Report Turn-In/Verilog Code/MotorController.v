`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:58:07 11/17/2015 
// Design Name: 
// Module Name:    MotorController 
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
module MotorController( input clk,
								input reset,
								input directionA,
								input directionB,
								input directionAEnable,
								input directionBEnable,
								input globalEnable,
								input [15:0]axisUpperSetpoint, 
								output reg dir,
								output reg stepOut,
								output reg [15:0] axisPointer
    );
	
	reg [15:0]axisUpperLimit; //3000; // // Change when we know true value.
	//parameter axisLowerLimit = 8;    // Change when we know true value.
	
	
	reg [13:0] counter;  // Used to make step clock & Sample controller inputs
   reg [18:0]	axisCounter;	//Counts total number of steps
	reg step;
	reg enable;
	
	
	always @(posedge clk)
	  begin
	    if(reset == 1'b1) 
		   begin
			  axisPointer      <= 16'd0;
			  axisUpperLimit   <= 16'd0;
			end
		 else 
		   begin
			  axisPointer   <= axisCounter[18:3];
			  axisUpperLimit <= axisUpperSetpoint;
			end
	  end
	  
always @(posedge clk)
  begin
    if(reset == 1'b1)
	   begin
		  counter        <= 14'd0;
		  axisCounter    <= 19'd0;
		  step           <= 1'b0;
		  dir            <= 1'b0;
		  enable         <= 1'b0;
		end
    else if (counter == 14'd10000) /// Generates motor step clock.
	   begin
		  step    <= ~step;
		  counter <= 14'd0;
		  if(globalEnable == 1'b1) //Enables motors once game starts
		    begin								
			   if(directionA == 1'b0 && axisPointer <= axisUpperLimit)// directionAEnable == 1'b1) //axisPointer <= axisUpperLimit)  // Limiting Statement
				  begin
				    axisCounter <= axisCounter + 16'd1;
					 dir         <= 1'b0;
					 enable      <= ~enable;//1'b1;
					 
				  end
				 else if(directionB == 1'b0 && axisPointer >= 10)//directionBEnable == 1'b1) //axisPointer >= axisLowerLimit) // Limiting Statement
				  begin
				    axisCounter <= axisCounter - 16'd1;
					 dir         <= 1'b1;
					 enable      <= ~enable;//1'b1;
					 
				  end
		    end
		end
    else
	   begin
		  step        <= step;
		  counter     <= counter + 14'd1;
		  enable      <= 1'b0;
	   end
    end
	
	always @(posedge enable) // Passes step signal out only when controller inputs are pressed.
	  begin
	    if (reset) stepOut <= 1'b0;
	    else if (directionA == 1'b0 || directionB == 1'b0) stepOut <= step;
	    else stepOut <= 0;
	  end
		
		
endmodule
