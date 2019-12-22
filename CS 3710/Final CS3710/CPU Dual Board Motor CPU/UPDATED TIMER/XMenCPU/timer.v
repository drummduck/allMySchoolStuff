`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:11:40 12/07/2015 
// Design Name: 
// Module Name:    timer 
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
module timer(clk, start, activetime
    );

//Inputs and outputs
input clk;
input start;
output reg [15:0] activetime;

//Signals to make it work
reg [25:0] totaltime;

always@(posedge clk)
begin
if (start == 1'b1)
	begin
		activetime <= 16'd90;  //How many seconds we are going to use.
		totaltime <= 26'b0;
	end
else
	begin
		totaltime <= totaltime + 1'b1;
		if (totaltime == 26'd50000000)
			begin
				totaltime <= 26'b0;
				if(activetime == 16'b0)
					activetime <= activetime + 1'b0;
				else
					activetime <= activetime - 1'b1;
			end
	end	
end
endmodule
