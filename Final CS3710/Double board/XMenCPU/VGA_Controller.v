`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:10:01 11/16/2015 
// Design Name: 
// Module Name:    VGA_Controller 
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
module VGA_Controller(input 				clock, clear,
							 input				[15:0] screen_offset_ctrl,
							 output reg 		hSync, vSync, bright,
							 output 		[14:0] mem_address,
							 output		[15:0] offset_ctrl_send,
							 output reg [9:0] hCount, 
							 output reg [8:0] vCount);
							 reg [15:0]offset_save = 0;

							 
	assign mem_address = 15'h4E84;
	assign offset_ctrl_send = offset_save;
		
	 
	 // ***********************************************************
	 initial   hSync  = 1; // Active low signal for the VGA port
	 initial   vSync  = 1; // Active low signal for the VGA port
	 initial   bright = 0; // Active high signal for the Bitgen circuit
	 initial   hCount = 0; // Horizontal pixel counter for the Bitgen circuit 
	 initial   vCount = 0; // Vertical pixel cunter for the Bitgen circuit
	 
 	 reg 	     clkDivPulse  = 0; // Used to notify every 25MHz clock tick
	 reg 		  H_Enable     = 0; // Used to enbale the horizontal pixel counter
	 reg 		  V_Enable     = 0; // Used to enbale the vertical pixel counter	
	 reg       hCountEnable = 0;
	 reg       vCountEnable = 0;
	 reg 	     clkDivCount  = 0; // Used to count to 4 to determine the 25MHz ticks
	 reg [9:0] hTickCounter = 0; // Used to store the horizontal clock tick count
	 reg [9:0] vLineCounter = 0; // Used to store the vertical clock tick count

	 // Horizontal parameters
	 parameter H_pulse_width  = 96;    // clocks required for horizontal pulse width
	 parameter H_back_porch   = 48;	  // clocks required for horizontal back porch
	 parameter H_display_time = 640;	  // clocks required for horizontal display time
	 parameter H_front_porch  = 16;    // clocks required for horizontal front porch
	 
	 parameter Hpw   = H_pulse_width;          //  96 clocks
	 parameter Hbp   = H_back_porch   + Hpw;   // 144 clocks = 48  + 96
	 parameter Hdisp = H_display_time + Hbp;   // 784 clocks = 640 + 144
	 parameter Hfp   = H_front_porch  + Hdisp; // 800 clocks = 16  + 784
	 
	 // Vertical parameters
	 parameter V_pulse_width  =  2;    // lines required for vertical pulse width
	 parameter V_back_porch   = 29;	  // lines required for vertical back porch
	 parameter V_display_time = 480;	  // lines required for vertical display time
	 parameter V_front_porch  = 10;    // lines required for vertical front porch
	 
	 parameter Vpw   = V_pulse_width;          //   2 lines
	 parameter Vbp   = V_back_porch   + Vpw;   //  31 lines = 29  + 2
	 parameter Vdisp = V_display_time + Vbp;   // 511 lines = 480 + 31
 	 parameter Vfp   = V_front_porch  + Vdisp; // 521 lines = 10  + 511
	 
 	 // ***********************************************************
	 // Clock division pulse generator block, Divide clock by 4 and send out pulse.


		
		always@(posedge clock)
			begin
				if(clear)
					begin
						clkDivCount <= 0;
						H_Enable <= 0;
					end
				else
					begin
					
						if(clkDivCount == 1)
							begin
								clkDivCount <= 0;
								H_Enable <= 1;
							end
						else
							begin
								clkDivCount <= clkDivCount + 1;
								H_Enable <= 0;
							end
					end
			end
	
	 // ***********************************************************
	 // Horizontal clock tick counter
	 // This counts from 0 to 800.
	 
		always@(posedge clock)
			begin
				if(clear)															//If reset is high reset the counters.
					begin							
						hTickCounter <= 0;
						hCountEnable = 0;
						V_Enable <= 0;
					end
				else																	
					begin
						if(H_Enable == 1)
							begin
								
					if(bright != 1)
						begin
							offset_save <= screen_offset_ctrl;
						end
								
								if(hTickCounter == Hfp - 1)					// 799 = 800-1 horizontal clock ticks reached
									begin
										hTickCounter <= 0;						// reset hTickCounter
										hCountEnable = 0;
										V_Enable <= 1;								// Enable the vLineCounter
									end
								else if (hTickCounter >= Hbp && hTickCounter < Hdisp && vLineCounter >= Vbp)
									begin
										hTickCounter <= hTickCounter + 1; // increment vertical count
										hCountEnable = 1;
										V_Enable <= 0;
									end
								else 
									begin
										hTickCounter <= hTickCounter + 1;  //Count vertical lines
										hCountEnable = 0;
										V_Enable <= 0;
									end
							end
					end
			end
	
	 
	 // ***********************************************************
	 // Vertical line counter
	 // This counts from 0 to 521.
	 
		always@(posedge clock)
			begin
				if(clear)														  //If reset is high reset the counters.
					begin				
						vLineCounter <= 0;
						vCountEnable = 0;
					end
				else
					begin
						if(V_Enable == 1 && H_Enable == 1)
							begin
								if(vLineCounter == Vfp - 1)				  // 520 = 521-1 vertical lines reached, so reset vLineCounter
									begin
										vLineCounter <= 0;
										vCountEnable = 0;
									end
								else if (vLineCounter >= Vbp && vLineCounter < Vdisp)
									begin
										vLineCounter <= vLineCounter + 1; // increment vertical count
										vCountEnable = 1;
									end
								else
									begin
										vLineCounter <= vLineCounter + 1;  //Count vertical lines
										vCountEnable = 0;
									end
							end
					end		
			end
	
	 // ***********************************************************
	 // Horizontal and vertical pixel counters
	 //These count the actual screen pixels. Once hTickCounter is within 640x480 the bright is on and
	 //so are the hCountEnable and vCountEnable
	 
		always@(posedge clock)
			begin
				if(clear != 1)
					begin
						if(H_Enable == 1)	//Base it off of clkDivPulse
							begin
								if(hCountEnable == 1)	
									begin
										if(hCount == 10'b1010000000 - 1)		//If hCount equals 639 = 640-1 then set to 0.
											begin
												hCount <= 0;
											end
										else
											begin
												hCount <= hCount + 1;		//else keep counting horizontally.
											end
									end
									
								if(vCountEnable == 1 && V_Enable == 1)					//vCount enabled when horizontal tick is 800
									begin
										if(vCount == 10'b0111100000 - 1)	//ifvCount is 479 = 480-1 set it back to 0
											begin
												vCount <= 0;
											end
										else
											begin
												vCount <= vCount + 1;
											end
									end
							end
						end
				else
					begin				//if reset
						vCount <= 0;
						hCount <= 0;
					end
				
			end
	 // ***************************************************************
	 // Generate the outputs, hSync, vSync, and bright signals
		always@(hTickCounter, vLineCounter, clear)
			begin			
				if(clear != 1)
					begin					 
						if(vLineCounter < Vpw && hTickCounter < Hpw) // check if the h-tick or v-line is in the pulse width region
							begin
								hSync  = 0;
								vSync  = 0;
								bright = 0;
							end
						else if (vLineCounter < Vpw && hTickCounter >= Hpw) // Vbp = 2, check if current v-line is in vertical pulse width
							begin
								hSync  = 1;
								vSync  = 0;
								bright = 0;
							end
						else if(vLineCounter >= Vpw && hTickCounter < Hpw)  // Hbp = 96, check if current h_tick is in the horizontal pulse width
							begin
								hSync  = 0;
								vSync  = 1;
								bright = 0;
							end         // Vbp = 31            Vdisp = 511                Hbp = 144           Hdisp = 784
						else if(vLineCounter >= Vbp && vLineCounter < Vdisp && hTickCounter >= Hbp && hTickCounter < Hdisp) // check to see if both the v-line and h-tick are in the display region
							begin
								hSync  = 1;
								vSync  = 1;
								bright = 1;
							end
						else      // default
							begin
								hSync  = 1;
								vSync  = 1;
								bright = 0;
							end
					end
				else
					begin								//If clear, set everything to 0
						hSync = 0;
						vSync = 0;
						bright = 0;
					end
			end
		
endmodule

module VGA_Bitgen(input             bright,
						input 	  [15:0] offset_ctrl,
						input 	  [9:0]  hCount,
						input 	  [8:0]  vCount,
						input      [15:0] mem_doutB,
						output     [14:0] frame_address,
						output     [7:0]  rgb);	
						
	reg [15:0] offset_ctrl_save = 0;			
	reg [14:0]frame_offset = 0;
	reg frame_glyph = 0;
	assign frame_address = frame_offset + (vCount[8:3] * 5) + hCount[9:7];
	assign rgb = (bright) ? {8{frame_glyph}}: 8'b00000000;

	always@(*)
		begin
		
			
			offset_ctrl_save <= offset_ctrl;
			
			case(offset_ctrl_save)
			
				16'h0000: frame_offset = 15'h7ED4;
				
				16'h0001: frame_offset = 15'h7DA8;
				
				16'h0002: frame_offset = 15'h7C7C;
				
				16'h0003: frame_offset = 15'h7B50;
				
				16'h0004: frame_offset = 15'h7A24;
				
				16'h0005: frame_offset = 15'h78F8;
				
				16'h0006: frame_offset = 15'h77CC;
				
				16'h0007: frame_offset = 15'h76A0;
				
				16'h0008: frame_offset = 15'h7574;
				
				16'h0009: frame_offset = 15'h7448;
				
				16'h000A: frame_offset = 15'h731C;
				
				16'h000B: frame_offset = 15'h71F0;
				
				16'h000C: frame_offset = 15'h70C4;
		
				default: frame_offset = 15'h7ED4;
				
			endcase
				
				
			case (hCount[6:3])	//Find out which glyph we are on in the screen. 
			
				4'b0000: frame_glyph = mem_doutB[15];
			
				4'b0001: frame_glyph = mem_doutB[14];
			
				4'b0010: frame_glyph = mem_doutB[13];
					
				4'b0011: frame_glyph = mem_doutB[12];
			
				4'b0100: frame_glyph = mem_doutB[11];
			
				4'b0101: frame_glyph = mem_doutB[10];
			
				4'b0110: frame_glyph = mem_doutB[9];
			
				4'b0111: frame_glyph = mem_doutB[8];
			
				4'b1000: frame_glyph = mem_doutB[7];
			
				4'b1001: frame_glyph = mem_doutB[6];
			
				4'b1010: frame_glyph = mem_doutB[5];
			
				4'b1011: frame_glyph = mem_doutB[4];
			
				4'b1100: frame_glyph = mem_doutB[3];
			
				4'b1101: frame_glyph = mem_doutB[2];
			
				4'b1110: frame_glyph = mem_doutB[1];
			
				4'b1111: frame_glyph = mem_doutB[0];
			
				default: frame_glyph = 0;
			
			endcase
			
			
		end		
		
endmodule