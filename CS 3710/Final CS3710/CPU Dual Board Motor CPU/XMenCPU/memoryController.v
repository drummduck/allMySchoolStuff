`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:41:19 12/01/2015 
// Design Name: 
// Module Name:    memoryController 
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
module memoryController(input clk,
								input reset,
								input startButton,
								input[14:0] addrA,
								input[15:0] dinA,
								input[15:0] doutA,
								input[15:0] xPointer,
								input[15:0] yPointer,
								input[15:0] zPointer,
								output reg[15:0] mem_doutA,
								output reg[6:0] movementEnable,
								output reg startSignal,
								input timesUp3
    );


reg timesUp;

always @(posedge clk)
  begin
    if (reset == 1'b1)
	   begin
		  timesUp <= 1'b0;
		end
	 else timesUp <= timesUp3;
  end	   

//always@ (posedge clk)
//  begin
//    if (reset == 1'b1)
//	   begin
//	     addressA <= 15'b0;
//	   end
//	 else if (addrA == 15'd20006)
//	   begin
//	     addressA <= addrA;
//      end
//	 else addressA <= addressA;
//  end
always@*
  begin
    case(addrA)
	   20003: mem_doutA = xPointer;
	   20004: mem_doutA = yPointer;
	   20005: mem_doutA = zPointer;
		20007: mem_doutA = movementEnable;
	   default: mem_doutA = doutA;
	 endcase
  end 

always@(posedge clk)
  begin
	 if(reset == 1'b1) 
	   begin 
		  movementEnable <= 7'd0; //7'd25; //	
		  startSignal <= 1'b0;
		  
		end
	 else if(startButton == 1'b0) 
	   begin 
		  //movementEnable <= movementEnable; //Start <= 1'b1;
		  movementEnable[6] <= 1'b1;
		  startSignal <= 1'b1;
	   end
	else if (timesUp == 1'b1)
	   begin
		  movementEnable[6] <= 1'b0;
		  startSignal <= 1'b0;
		end
		
//	 else if (addrA == 15'd20006)
//	   begin
//		  //movementEnable <= movementEnable;
//		  case(dinA)
//		    // Enable Cases
//			 15'd1  : movementEnable[0] <= 1'b1; //Z down
//			 15'd2  : movementEnable[1] <= 1'b1; //Z up
//			 15'd4  : movementEnable[2] <= 1'b1; //Y down
//			 15'd8  : movementEnable[3] <= 1'b1; //Y up
//			 15'd16 : movementEnable[4] <= 1'b1; //X right
//			 15'd32 : movementEnable[5] <= 1'b1; //X left
//				
//			 // Disable Cases
//			 15'd126: movementEnable[0] <= 1'b0; //Z down
//			 15'd125: movementEnable[1] <= 1'b0; //Z up
//			 15'd123: movementEnable[2] <= 1'b0; //Y down
//			 15'd119: movementEnable[3] <= 1'b0; //Y up
//			 15'd111: movementEnable[4] <= 1'b0; //X right
//			 15'd95 : movementEnable[5] <= 1'b0; //X left
//		    default: movementEnable <= movementEnable;
//		  endcase
//		end
    else   
      begin
		  movementEnable <= movementEnable;
      end
  end
endmodule
