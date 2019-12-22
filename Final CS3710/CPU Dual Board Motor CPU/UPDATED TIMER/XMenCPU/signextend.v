`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:14:48 10/20/2015 
// Design Name: 
// Module Name:    signextend 
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
module signextend(Opcode, Immlow, Extended
   );
  
	input [7:0] Opcode;
	input [3:0] Immlow;
	output reg [15:0] Extended;

	parameter LSHI = 8'b1000000?;
	parameter ASHI = 8'b1000001?;
	
	
	
	always @(*)  //Change on any input
	begin
	casez (Opcode)
			LSHI:
				begin
					Extended [3:0] = Immlow [3:0];
					Extended [15:4] = {12{Opcode [0]}};  //12 bit extend
				end
			ASHI:
				begin
					Extended [3:0] = Immlow [3:0];
					Extended [15:4] = {12{Opcode [0]}};
				end
			default:
				begin
					Extended [3:0] = Immlow [3:0];
					Extended [7:4] = Opcode [3:0];
					Extended [15:8] = {8{Opcode [3]}};  //8 bit extend
				end
		endcase
end

endmodule
