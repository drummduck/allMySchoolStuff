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
module timer(clk, start, activetime, reset, expired, enable, enable_transit
    );

//Inputs and outputs
input clk;
input start;
input reset;
output reg [15:0] activetime;
output reg expired;
input enable;
output reg enable_transit;

//Signals to make it work
reg [25:0] totaltime;

always@(posedge clk)
begin
if (reset == 1'b1)
begin
	activetime <= 16'd0;
	totaltime <= 26'b0;
	expired <= 1'b0;
end
else if (start == 1'b1)
	begin
		activetime <= 16'd60;  //How many seconds we are going to use.
		totaltime <= 26'b0;
		expired <= 1'b0;
	end
else
	begin
		if (totaltime == 26'd50000000)
			begin
				totaltime <= 26'b0;
				if(activetime == 16'b0000000000000001)
					expired <= 1'b1;
				if(activetime == 16'b0)
				begin
						activetime <= 16'b0;
						expired <= 1'b1;
				end
				else
					activetime <= activetime - 1'b1;
			end
		else
		totaltime <= totaltime + 1'b1;
	end	
end
always@(posedge clk)
begin
	enable_transit <= enable;
end
endmodule
