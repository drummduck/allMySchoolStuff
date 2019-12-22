`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:07:28 11/17/2015 
// Design Name: 
// Module Name:    Motion 
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
module Motion(input clk,
				  input reset,
				  input data,
				  input [6:0]movementEnable,
				  				  
				  output xStep,
				  output xDir,
				  output [15:0] xAxisPointer,
				  output yStep,
				  output yDir,
				  output [15:0] yAxisPointer,
				  output zStep,
				  output zDir,
				  output [15:0] zAxisPointer,
				  
				  output latch,
				  output clkOut,
				  output startButton
				  
				  //Added for simulation only
				  //input [7:0]nesControl2	 

				  				  
    );


reg [15:0] xAxisUpperSetpoint, yAxisUpperSetpoint, zAxisUpperSetpoint;
wire[7:0] nesControl;
wire nesEnable;


always @(posedge clk)
  begin
    if (reset == 1'b1)
	   begin
		  xAxisUpperSetpoint <= 2559;
		  yAxisUpperSetpoint <= 2560;
		  zAxisUpperSetpoint <= 2560;
	   end
	 else
	   begin
		  xAxisUpperSetpoint <= 2600;
		  yAxisUpperSetpoint <= 2300;
		  zAxisUpperSetpoint <= 2600;
	   end
  end
nesController Mario(.clk(clk), .reset(reset), .data(data), .nesControlOut(nesControl), .latch(latch),
						  .clkOut(clkOut));


assign startButton = nesControl[4];
//assign startButton = nesControl2[4];

//always @(posedge clk)
//  begin
//    if(reset == 1'b0) startButton <=  1;
//	 else startButton <= nesControl[4];
//  end
	 

MotorController xAxis(.clk(clk),
							 .reset(reset),
							 .directionA(nesControl[0]),
							 .directionB(nesControl[1]),
							 //.directionA(nesControl2[0]),
							 //.directionB(nesControl2[1]),
							 .directionAEnable(movementEnable[4]),
							 .directionBEnable(movementEnable[5]),
							 .globalEnable(movementEnable[6]),
							 .axisUpperSetpoint(xAxisUpperSetpoint),
							 .dir(xDir),
							 .stepOut(xStep),
							 .axisPointer(xAxisPointer)
							);

MotorController yAxis(.clk(clk),
							 .reset(reset),
							 .directionA(nesControl[3]),
							 .directionB(nesControl[2]),
							 //.directionA(nesControl2[3]),
							 //.directionB(nesControl2[2]),
							 .directionAEnable(movementEnable[3]),
							 .directionBEnable(movementEnable[2]),
							 .globalEnable(movementEnable[6]),
							 .axisUpperSetpoint(yAxisUpperSetpoint),
							 .dir(yDir),
							 .stepOut(yStep),
							 .axisPointer(yAxisPointer)
							);
							
MotorController zAxis(.clk(clk),
							 .reset(reset),
							 .directionA(nesControl[7]),
							 .directionB(nesControl[6]),
							 //.directionA(nesControl2[7]),
							 //.directionB(nesControl2[6]),
							 .directionAEnable(movementEnable[1]),
							 .directionBEnable(movementEnable[0]),
							 .globalEnable(movementEnable[6]),
							 .axisUpperSetpoint(zAxisUpperSetpoint),
							 .dir(zDir),
							 .stepOut(zStep),
							 .axisPointer(zAxisPointer)
							);


//display limits(clk, zAxisPointer, ca, cb, cc, cd, ce, cf, cg, an0, an1, an2, an3);


endmodule
