`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:08:01 09/28/2015 
// Design Name: 
// Module Name:    memory 
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
// This is a template for a single-port memory. 
// You should modify this to design a dual-port memory
//////////////////////////////////////////////////////////////////////////////////
	
	module memory( clk, enA, enB, weA, weB, dinA, dinB, addrA, addrB,  doutA, doutB
    );
		parameter RAM_WIDTH = 16; //<ram_width>;
		parameter RAM_ADDR_BITS = 15; //<ram_addr_bits>;
		
 
	// Notice that the address bits = 10 implies 1024 words, which can be included in
	// one block. If this is increased to 11, the tool will map it to 2 BRAMs. 
	// View Tech Schematic.
	// RAM_ADDR_BITS = 15 will address 32 blocks of RAM. If this is extended to 16, then
	// the tool will also start synthesizing distributed RAM, and that will just be infeasible.
		 
	 // Port A
	 input clk, enA, weA;
	 input [RAM_WIDTH-1:0] dinA;
	 input [RAM_ADDR_BITS-1:0] addrA;
	 output reg [RAM_WIDTH-1:0] doutA;
	 
	 // Port B 
	 input enB, weB;
	 input [RAM_WIDTH-1:0] dinB;
	 input [RAM_ADDR_BITS-1:0] addrB; 
	 output reg [RAM_WIDTH-1:0] doutB;
	 
	 
	 reg [RAM_WIDTH-1:0] the_memory_core [(2**RAM_ADDR_BITS)-1:0];
//   reg [RAM_WIDTH-1:0] <output_data>;
//
//   <reg_or_wire> [RAM_ADDR_BITS-1:0] <address>;
//   <reg_or_wire> [RAM_WIDTH-1:0] <input_data>;

   //  The following code is only necessary if you wish to initialize the RAM 
   //  contents via an external file (use $readmemb for binary data)
  initial
		//$readmemh("InitialMem.txt", the_memory_core, 0, 32767);//16383);
		  $readmemh("testone.txt", the_memory_core, 0, 32767);  //Test program.
		  
	always @(posedge clk )
	begin
	  if (enA == 1'b1 ) 
	  	 begin
		   if (weA == 1'b1) 
			  begin
				 the_memory_core[addrA] <= dinA;
				 doutA <= dinA;		// In write-first mode, the din is also passed on to dout
			  end
			else doutA <= the_memory_core[addrA];  
	  	 end
	end		
			
			// Until we know for sure Port B will be configured the same as A.
	always @(posedge clk)
	begin
	  if (enB == 1'b1) 
		 begin
			if (weB == 1'b1) 
			  begin
				 the_memory_core[addrB] <= dinB;
				 doutB <= dinB;		// In write-first mode, the din is also passed on to dout
			  end
			else doutB <= the_memory_core[addrB];  
		 end
	end
endmodule
