Documents: Processor Specs and Notes

	   Compiler Instructions

	   Text files that contained program and VGA information that was preloaded into memory. These text files are as follows:
	   hexprogram - program used on demo day

           hexprogramwithvga - program used on demo day with vga info preloads included.

	   InitialMem - Initial memory filled with 0's(used to keep track of 32767 spaces in memory).

	   *End of Text Files
	   *Note that the text files above were also used for testing.

	   Demo Poster - Poster used on demo day.

	   CS 3710 presentation - Presentation slides for mid semester.


Software Code_&_Assembler: AssemblyCompiler - Program that converts assembly into hex.

			   Instruction - Helper functions for AssemblyCompiler.
			  

Test Benches: sextendtest - Test for the sign extender.

	      Test_CPU - Test for the overall CPU.

	      testone - Text file used for Test_CPU

	      testtwo - Text file used for Test_CPU


Verilog Code: ALU_Module - The ALU module

	      Buffer - Module made of smaller tristate buffer modules.

	      clkmanager.ucf - User constraint file for the clock manager.

	      Combo - Module containing entire CPU minus the FSM.

	      CPU.ucf - User contraint file for the entire CPU.

	      CPU - Module that contains instantiated Combo and FSM modules.

	      display - Module for seven segment display.

	      FSM_Control - Module that sends out control signals to Combo module.

	      memory - Module that contains all 32767 16-bit memory spaces.

	      memoryController - Module that kept track of crane coordinates and movement enable signals to motor. Also sent signal to second board on when to start program.

	      Motion - Module connecting nesController and memoryController.

	      MotorController - Module that controls motor movement based on nesController.

	      nesController - Module for NES input and output to MotorController.

	      programCounter - Module that keeps track of where we are in memory.

	      RegFile - Module that has smaller register modules inside, making 16 registers.

	      signextend - Module that extends values needed for ALU or address jumping.

	      stopwatch - A timer module based off of the clock. Sends time to timer module for state determination.

	      timer - A module that uses time from stopwatch module to determine state of program and change state of VGA and disable motors.

	      VGA_Controller - Contains VGA_Controller module and BitGen module. Scans and controls pixels on VGA screen based on a division of clock.
	      
	      