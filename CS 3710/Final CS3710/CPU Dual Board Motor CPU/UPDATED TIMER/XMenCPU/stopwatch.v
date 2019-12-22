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
    input stop,
    input reset,
	 output ca,
	 output cb,
	 output cc,
	 output cd,
	 output ce,
	 output cf,
	 output cg,
	 output an0,
	 output an1,
	 output an2,
	 output an3
    );
	 
reg strt; //Keeps track of my start enable signal.
//Initialize the strt wire.
initial
begin
strt = 0;
end

reg [27:0]counter;  //Divider
reg [3:0] bcd; //Count

always @(posedge fclk)
begin
	if (reset == 1'b1)
	begin
		counter <= 0;
		bcd <= 0;
		strt <= 0;
	end
	if (strt == 1'b0 || stop == 1'b1)
	begin
		counter <= counter + 0;
		strt <= 0;
	end
	if (start == 1'b1)
	begin
		strt <= 1'b1;
	end
	else
	begin
		if (strt == 1'b1)
		begin	
			if(counter == 27'd100000000)
			begin
				counter <= 0;
				if (bcd == 4'b1001)
					bcd <= 0;
				else
					bcd <= bcd + 1'b1;				
			end
			else
				counter <= counter + 1'b1;
		end
	end
end
//Instantiate the display decoder.
display driver (bcd, ca, cb, cc, cd, ce, cf, cg, an0, an1, an2, an3);
endmodule
