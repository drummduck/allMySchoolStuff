`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:49:49 09/07/2015 
// Design Name: 
// Module Name:    display 
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
module display(
    input clk,
    input [15:0] number,
    output reg ca,
    output reg cb,
    output reg cc,
    output reg cd,
    output reg ce,
    output reg cf,
    output reg cg,
    output reg an0,
    output reg an1,
    output reg an2,
    output reg an3
    );
reg [1:0] state;  //Keeps track of which segment is active.
reg [19:0] divide;  //Slows the update on the display.

initial
begin
state = 2'b00;
divide = 0;
end


always @(posedge clk)
begin
	an0 = 1;  //States of output defaults.  Display off.
	an1 = 1;
	an2 = 1;
	an3 = 1;
	ca = 1;
	cb = 1;
	cc = 1;
	cd = 1;
	ce = 1;
	cf = 1;
	if (divide == 20'd312500)  //Clock divider for display refresh.
		begin
			state <= state + 1'b1;
			divide <= 0;
		end
	else
		divide <= divide + 1'b1;
	
	
		
			if (state == 2'b00) //Activate the first display for [0].
				begin
					an0 = 0;
					an1 = 1;
					an2 = 1;
					an3 = 1;
					case (number[3:0])
					
						4'b0000:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 1;
						end
						4'b0001:
						begin
							ca = 1;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 1;
							cf = 1;
							cg = 1;
						end
						4'b0010:
						begin
							ca = 0;
							cb = 0;
							cc = 1;
							cf = 1;
							cg = 0;
							ce = 0;
							cd = 0;
						end
						4'b0011:
						begin
							ca = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							ce = 1;
							cf = 1;
						end
						4'b0100:
						begin
							cf = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							ca = 1;
							cd = 1;
							ce = 1;
						end
						4'b0101:
						begin
							ca = 0;
							cf = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							cb = 1;
							ce = 1;
						end
						4'b0110:
						begin
							ca = 0;
							cf = 0;
							cg = 0;
							ce = 0;
							cc = 0;
							cd = 0;
							cb = 1;
						end
						4'b0111:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 1;
							cf = 1;
							cg = 1;
						end
						4'b1000:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1001:
						begin
							ca = 0;
							cf = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							ce = 1;
						end
						4'b1010:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1011:
						begin
							ca = 1;
							cb = 1;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1100:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 1;
						end
						4'b1101:
						begin
							ca = 1;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 1;
							cg = 0;
						end
						4'b1110:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1111:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 1;
							ce = 0;
							cf = 0;
							cg = 0;
						end
					endcase
				end
			if (state == 2'b01)  //Activating the display for [1].
				begin
					an0 = 1;
					an1 = 0;
					an2 = 1;
					an3 = 1;
					case (number[7:4])
						4'b0000:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 1;
						end
						4'b0001:
						begin
							ca = 1;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 1;
							cf = 1;
							cg = 1;
						end
						4'b0010:
						begin
							ca = 0;
							cb = 0;
							cc = 1;
							cf = 1;
							cg = 0;
							ce = 0;
							cd = 0;
						end
						4'b0011:
						begin
							ca = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							ce = 1;
							cf = 1;
						end
						4'b0100:
						begin
							cf = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							ca = 1;
							cd = 1;
							ce = 1;
						end
						4'b0101:
						begin
							ca = 0;
							cf = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							cb = 1;
							ce = 1;
						end
						4'b0110:
						begin
							ca = 0;
							cf = 0;
							cg = 0;
							ce = 0;
							cc = 0;
							cd = 0;
							cb = 1;
						end
						4'b0111:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 1;
							cf = 1;
							cg = 1;
						end
						4'b1000:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1001:
						begin
							ca = 0;
							cf = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							ce = 1;
						end
						4'b1010:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1011:
						begin
							ca = 1;
							cb = 1;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1100:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 1;
						end
						4'b1101:
						begin
							ca = 1;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 1;
							cg = 0;
						end
						4'b1110:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1111:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 1;
							ce = 0;
							cf = 0;
							cg = 0;
						end
					endcase
				end
			if (state == 2'b10)  //Activate the display for [2].
				begin
					an0 = 1;
					an1 = 1;
					an2 = 0;
					an3 = 1;
					case (number[11:8])
						4'b0000:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 1;
						end
						4'b0001:
						begin
							ca = 1;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 1;
							cf = 1;
							cg = 1;
						end
						4'b0010:
						begin
							ca = 0;
							cb = 0;
							cc = 1;
							cf = 1;
							cg = 0;
							ce = 0;
							cd = 0;
						end
						4'b0011:
						begin
							ca = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							ce = 1;
							cf = 1;
						end
						4'b0100:
						begin
							cf = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							ca = 1;
							cd = 1;
							ce = 1;
						end
						4'b0101:
						begin
							ca = 0;
							cf = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							cb = 1;
							ce = 1;
						end
						4'b0110:
						begin
							ca = 0;
							cf = 0;
							cg = 0;
							ce = 0;
							cc = 0;
							cd = 0;
							cb = 1;
						end
						4'b0111:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 1;
							cf = 1;
							cg = 1;
						end
						4'b1000:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1001:
						begin
							ca = 0;
							cf = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							ce = 1;
						end
						4'b1010:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1011:
						begin
							ca = 1;
							cb = 1;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1100:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 1;
						end
						4'b1101:
						begin
							ca = 1;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 1;
							cg = 0;
						end
						4'b1110:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1111:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 1;
							ce = 0;
							cf = 0;
							cg = 0;
						end
					endcase
				end
			if (state == 2'b11)  //Activate the display for [3].
				begin
					an0 = 1;
					an1 = 1;
					an2 = 1;
					an3 = 0;
					case (number[15:12])
						4'b0000:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 1;
						end
						4'b0001:
						begin
							ca = 1;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 1;
							cf = 1;
							cg = 1;
						end
						4'b0010:
						begin
							ca = 0;
							cb = 0;
							cc = 1;
							cf = 1;
							cg = 0;
							ce = 0;
							cd = 0;
						end
						4'b0011:
						begin
							ca = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							ce = 1;
							cf = 1;
						end
						4'b0100:
						begin
							cf = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							ca = 1;
							cd = 1;
							ce = 1;
						end
						4'b0101:
						begin
							ca = 0;
							cf = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							cb = 1;
							ce = 1;
						end
						4'b0110:
						begin
							ca = 0;
							cf = 0;
							cg = 0;
							ce = 0;
							cc = 0;
							cd = 0;
							cb = 1;
						end
						4'b0111:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 1;
							cf = 1;
							cg = 1;
						end
						4'b1000:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1001:
						begin
							ca = 0;
							cf = 0;
							cb = 0;
							cg = 0;
							cc = 0;
							cd = 0;
							ce = 1;
						end
						4'b1010:
						begin
							ca = 0;
							cb = 0;
							cc = 0;
							cd = 1;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1011:
						begin
							ca = 1;
							cb = 1;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1100:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 1;
						end
						4'b1101:
						begin
							ca = 1;
							cb = 0;
							cc = 0;
							cd = 0;
							ce = 0;
							cf = 1;
							cg = 0;
						end
						4'b1110:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 0;
							ce = 0;
							cf = 0;
							cg = 0;
						end
						4'b1111:
						begin
							ca = 0;
							cb = 1;
							cc = 1;
							cd = 1;
							ce = 0;
							cf = 0;
							cg = 0;
						end
					endcase
		end
end
endmodule

