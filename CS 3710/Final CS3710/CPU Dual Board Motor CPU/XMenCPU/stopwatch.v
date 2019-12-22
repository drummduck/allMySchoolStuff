`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Keith Madsen u0687930
// 
// Create Date:    12:34:58 03/30/2015 
// Design Name: 
// Module Name:    stopwatch 
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
module stopwatch(
    input fclk,
    input start,
	 output reg [15:0] timer,
    input reset
    );
	 
reg strt; //Keeps track of my start enable signal.
//Initialize the strt wire.
initial
begin
strt = 0;
end

reg [27:0] counter;  //Divider
reg [15:0] tracker; //Count

always @(posedge fclk)
begin
	if (reset == 1'b1)
	begin
		counter <= 0;
		timer <= 16'd90;  //CHANGE LATER FOR TIMER ALSO BELOW
		strt <= 0;
		tracker <= 16'b0000000000000000;
	end
	if (strt == 1'b0)
	begin
		counter <= 28'b0000000000000000000000000000;
		timer <= 16'd90;  //CHANGE HERE AS WELL
		strt <= 1'b0;
		tracker <= 16'b0000000000000000;
	end
	if (start == 1'b1)
	begin
		strt <= 1'b1;
	end
	else
	begin
		if (strt == 1'b1)
		begin	
			if(counter == 28'd50000000)
			begin
				counter <= 28'b0000000000000000000000000000;
				timer <= timer - 1'b1;
				if (tracker == 16'd90)
				begin
					strt <= 1'b0;
				end
				else
					tracker <= tracker + 1'b1;
			end
			else
				counter <= counter + 1'b1;
		end
	end
end

endmodule
