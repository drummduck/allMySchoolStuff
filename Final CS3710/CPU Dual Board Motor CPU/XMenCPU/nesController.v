`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:45:29 11/17/2015 
// Design Name: 
// Module Name:    nesController 
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
module nesController(input clk,
							input reset,
							input data,
							output reg [7:0] nesControlOut,
							output reg latch,
							output reg clkOut
    );
	 parameter Loop = 12;
	 //parameter LatchCounter = ;
	 reg [10:0] counter;
	 reg [9:0] count;
	 reg [7:0] nesControl;
	 reg nesEnable;
	 
	 
	 wire [7:0] nesControlWire;
    assign nesControlWire = nesControl;	 
	
	 always @(posedge clk)
	 begin
	   if(reset == 1'b1) nesControlOut <= 8'hff;		
	   else if(nesEnable == 1'b1) nesControlOut <= nesControlWire;
	 end

	 
	 
	 always @(posedge clk)
	 begin
	   if (reset ==1'b1) 
		begin
		  clkOut <= 1'b0;
		  count  <= 10'b0;
		end
		else if (count == 10'd1000)  // Generates nes Controller shift register   (count = 1000) => clock 50kHz
		begin
		  clkOut <= ~clkOut;
		  count  <= 19'b0;
	   end
		else
		begin
		  clkOut <= clkOut;
		  count  <= count + 10'b1;
		end
	 end
	 
	 
	 always@(posedge clkOut)
	   begin
		  if(reset == 1'b1)
		    begin
			   nesControl <= 8'hff;
				latch      <= 1'b0;
				counter    <= 11'b0;
				nesEnable  <= 1'b0;
			 end
		  else if (counter <= Loop)
		    begin
			   case(counter)
					0: 
					  begin
					    latch <= 1'b1;
						 counter <= counter + 1'b1;
						 nesEnable <= 1'b0;
					  end
					  
					1:
					  begin
					    latch <= 1'b0;
						 counter <= counter + 1'b1;
						 nesControl <= {nesControl[6:0], data};
						 nesEnable <= 1'b0;
					  end
					  
					2:
					  begin
					    latch <= 1'b0;
						 counter <= counter + 1'b1;
						 nesControl <= {nesControl[6:0], data};
						 nesEnable <= 1'b0;
					  end
					  
					3:
					  begin
					    latch <= 1'b0;
						 counter <= counter + 1'b1;
						 nesControl <= {nesControl[6:0], data};
						 nesEnable <= 1'b0;
					  end
					4:
					  begin
					    latch <= 1'b0;
						 counter <= counter + 1'b1;
						 nesControl <= {nesControl[6:0], data};
						 nesEnable <= 1'b0;
					  end
					
					5:
					  begin
					    latch <= 1'b0;
						 counter <= counter + 1'b1;
						 nesControl <= {nesControl[6:0], data};
						 nesEnable <= 1'b0;
					  end
					6:
					  begin
					    latch <= 1'b0;
						 counter <= counter + 1'b1;
						 nesControl <= {nesControl[6:0], data};
						 nesEnable <= 1'b0;
					  end
					  
					7:
					  begin
					    latch <= 1'b0;
						 counter <= counter + 1'b1;
						 nesControl <= {nesControl[6:0], data};
						 nesEnable <= 1'b0;
					  end
					8:
					  begin
					    latch <= 1'b0;
						 counter <= counter + 1'b1;
						 nesControl <= {nesControl[6:0], data};
						 nesEnable <= 1'b0;
					  end
					  
					9:
					  begin
					    latch <= 1'b0;
						 counter <= counter + 1'b1;
						 nesControl <= {nesControl[6:0], data};
						 nesEnable <= 1'b0;
					  end
					
					10:
					  begin
					    latch <= 1'b0;
						 counter <= counter + 1'b1;
						 nesEnable <= 1'b1;
					  end
					
					11:
					  begin
					    latch <= 1'b0;
						 counter <= counter + 1'b1;
						 nesEnable <= 1'b1;
					  end
					12:
					  begin
					    latch <= 1'b0;
						 counter <= 1'b0;
						 nesEnable <=1'b0;
					  end
					default:
					  begin
					    latch <= 1'b0;
						 counter <= 1'b0;
						 nesEnable <=1'b0;
					  end
			endcase
		end	
	end
endmodule
