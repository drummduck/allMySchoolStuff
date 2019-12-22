package compiler;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

/*
 * This program will convert assembly language for the 3710 processor into hex code
 * that can be directly downloaded into the memory of the processor.  It will dump the hex code
 * into a file in the same directory as the original assembly file.  The completed conversion file
 * will be called "hexprogram.txt"
 */
public class AssemblyCompiler 
{

	public static void main(String[] args) 
	{
		//Get the file.
		JFileChooser chooser = new JFileChooser();  
		chooser.setDialogTitle("Select the text file for conversion");  //Making a title

        int result;
        result = chooser.showOpenDialog(null);  // Gets back a value to determine if the user cancelled.

        if (result == JFileChooser.CANCEL_OPTION)
        {
       	 	System.exit(0);  //Exit on cancel option
        }
  
        File inputFile;
        inputFile = chooser.getSelectedFile();  //Tells which file was chosen to inputFile
        
        String path = inputFile.getPath();  //Save the path of the selected file.
        path = path.replace(inputFile.getName(), "");
        path = path + "hexprogram.txt";  //Path now updated for file creation.
        
        int count = 0;  //Represents the program counter.
        String command;
        String rdest = null;  //null the inputs that might not be used.
        String rsrc = null;
        String label = null;
        String temp;
        ArrayList<Instruction> instructions = new ArrayList<Instruction>();
        
        //Read in the commands from the chosen file
        try 
        {
        	Scanner in = new Scanner(inputFile);
        	boolean singular = false;
			while(in.hasNext())
			{
				temp = in.next();
				temp = temp.toLowerCase();
				
				//Check temp to see if it is a label
				if(temp.endsWith(":"))
				{
					label = temp;
					temp = in.next();
					temp = temp.toLowerCase();
				}
				
				//Check for singular argument or no argument commands.
				if(temp.equals("wait") || temp.equals("return") || temp.equals("jal") || temp.equals("jump") ||
						temp.equals("jg") || temp.equals("jl") || temp.equals("je") || temp.equals("jle") ||
						temp.equals("jge") || temp.equals("jne") || temp.equals("start") || temp.equals("get"))
				{
					//If JAL then first make 6 blank commands that later get updated with location of the label.
					if(temp.equals("jal"))
					{
						//Make the blank commands and update that jal happened.
						singular = true;
						for(int i = 0; i < 6; i++)
						{
							instructions.add(new Instruction(("move " + (i + 1)), null, null, null, count, null));
							count++;
						}
						instructions.add(new Instruction(temp, "r15,", "r15", label, count, in.next()));  //Add the actual JAL command
						count ++;
					}
					//Build the return command.
					if (temp.equals("return"))
					{
						singular = true;
						instructions.add(new Instruction(temp, "r0,", "r0", label, count, null));
						count++;
					}
					//Build the start command
					if (temp.equals("start"))
					{
						singular = true;
						instructions.add(new Instruction(temp, "r0,", "r0", label, count, null));
						count++;
					}
					//Build the get command
					if (temp.equals("get"))
					{
						singular = true;
						instructions.add(new Instruction(temp, "r0,", "r0", label, count, null));
						count++;
					}
					//Build the wait.
					if (temp.equals("wait"))
					{
						singular = true;
						instructions.add(new Instruction(temp, "r0,", "r0", label, count, null));
						count++;
					}
					//Build all jump possibilities
					if (temp.equals("jump"))
					{
						singular = true;
						instructions.add(new Instruction(temp, "0", null, label, count, in.next()));
						count++;
					}
					if (temp.equals("jg"))
					{
						singular = true;
						instructions.add(new Instruction(temp, "1", null, label, count, in.next()));
						count++;
					}
					if (temp.equals("jl"))
					{
						singular = true;
						instructions.add(new Instruction(temp, "2", null, label, count, in.next()));
						count++;
					}
					if (temp.equals("je"))
					{
						singular = true;
						instructions.add(new Instruction(temp, "3", null, label, count, in.next()));
						count++;
					}
					if (temp.equals("jle"))
					{
						singular = true;
						instructions.add(new Instruction(temp, "4", null, label, count, in.next()));
						count++;
					}
					if (temp.equals("jge"))
					{
						singular = true;
						instructions.add(new Instruction(temp, "5", null, label, count, in.next()));
						count++;
					}
					if (temp.equals("jne"))
					{
						singular = true;
						instructions.add(new Instruction(temp, "6", null, label, count, in.next()));
						count++;
					}
				}
				else if(!singular) //All other commands
				{
					//Deal with block comments.
					if(temp.startsWith("//") && in.hasNextLine())
					{
						in.nextLine();
					}
					else
					{
						if(temp.startsWith("//")  && !in.hasNextLine())
							break;
						
						//Set up for the next go around.
						command = temp;
						rdest = in.next();
						rsrc = in.next();
						instructions.add(new Instruction(temp, rdest, rsrc, label, count, null));
						count++;
					}
					
				}
				//Check for comments and ignore them if they exist.
				if (in.hasNextLine())
					in.nextLine();
				
				//Reset variables for the next loop.
				singular = false;
				command = null;
				rdest = null;
				rsrc = null;
				label = null;
			}
			in.close();
		} 
        catch (Exception e) 
        {
        	String error = ("There was a problem reading the selected file: " + e.getMessage());
			JOptionPane.showMessageDialog(null, error);
			System.exit(0);  //Close if error.
		}
        //Debug test output.  Parsing worked!!
        /*for (int i = 0; i < instructions.size(); i++)
        	System.out.println(instructions.get(i).getLabel() + " " + instructions.get(i).getCommand() + " " + instructions.get(i).getDest()
        			+ " " + instructions.get(i).getSource() + " " + instructions.get(i).getJumpLabel() + " " + instructions.get(i).getCount());*/
        
        //Begin preparation for conversion to hex code starting with registers.  Integer.toHexString()
        for (int i = 0; i < instructions.size(); i++)
        {
        	temp = instructions.get(i).getDest();
        	if (temp != null)
        	{
        		//Remove the r and the comma.
        		if (temp.startsWith("r"))
        		{
        			temp = temp.substring(1);
        			if (temp.endsWith(","))
        				temp = temp.replace(",", "");
        			instructions.get(i).putDest(temp);  //Store the new destination parsed correctly.
        			temp = null;
        		}
        	
        	}
        	temp = instructions.get(i).getSource();
        	if (temp != null)
        	{
        		//Remove the r
        		if (temp.startsWith("r"))
        		{
        			temp = temp.substring(1);
        			instructions.get(i).putSource(temp);  //Store the new destination parsed correctly.
        			temp = null;
        		}
        	
        	}
        	//Convert registers to hex excluding jump commands.
        	if (!instructions.get(i).hasJumpLabel() || instructions.get(i).getCommand().equals("jal"))
        	{
        		//End up here for all commands that are not jumps.
        		temp = instructions.get(i).getSource();
        		if (temp != null)
        		{
        			int sreg;
        			sreg = Integer.parseInt(temp);
        			temp = Integer.toHexString(sreg);
        			instructions.get(i).putSource(temp);
        			temp = null;
        		}
        		temp = instructions.get(i).getDest();
        		if (temp != null)
        		{
        			int dreg;
            		dreg = Integer.parseInt(temp);
            		temp = Integer.toHexString(dreg);
            		instructions.get(i).putDest(temp);
            		temp = null;
        		}
        		
        	}
        	//Form all opcodes based off of the commands.  All values are in hex now except jump labels and counts.
        	switch(instructions.get(i).getCommand())
        	{
        	case "add":
        		instructions.get(i).putOpcode("05");
        		break;
        	case "addi":
        		instructions.get(i).putOpcode("5");
        		break;
        	case "addu":
        		instructions.get(i).putOpcode("06");
        		break;
        	case "addui":
        		instructions.get(i).putOpcode("6");
        		break;
        	case "addc":
        		instructions.get(i).putOpcode("07");
        		break;
        	case "addcu":
        		instructions.get(i).putOpcode("04");
        		break;
        	case "addcui":
        		instructions.get(i).putOpcode("1");
        		break;
        	case "addci":
        		instructions.get(i).putOpcode("7");
        		break;
        	case "sub":
        		instructions.get(i).putOpcode("09");
        		break;
        	case "subi":
        		instructions.get(i).putOpcode("9");
        		break;
        	case "cmp":
        		instructions.get(i).putOpcode("0b");
        		break;
        	case "cmpi":
        		instructions.get(i).putOpcode("b");
        		break;
        	case "cmpu":
        		instructions.get(i).putOpcode("08");
        		break;
        	case "cmpui":
        		instructions.get(i).putOpcode("2");
        		break;
        	case "and":
        		instructions.get(i).putOpcode("01");
        		break;
        	case "andi":
        		instructions.get(i).putOpcode("a");
        		break;
        	case "or":
        		instructions.get(i).putOpcode("02");
        		break;
        	case "xor":
        		instructions.get(i).putOpcode("03");
        		break;
        	case "not":
        		instructions.get(i).putOpcode("0c");
        		break;
        	case "logsh":
        		instructions.get(i).putOpcode("84");
        		break;
        	case "lshi":
        		instructions.get(i).putOpcode("80");
        		break;
        	case "rshi":
        		instructions.get(i).putOpcode("81");
        		break;
        	case "alogsh":
        		instructions.get(i).putOpcode("4f");
        		break;
        	case "arshi":
        		instructions.get(i).putOpcode("83");
        		break;
        	case "alshi":
        		instructions.get(i).putOpcode("82");
        		break;
        	case "wait":
        		instructions.get(i).putOpcode("00");
        		break;
        	case "mov":
        		instructions.get(i).putOpcode("0d");
        		break;
        	case "movi":
        		instructions.get(i).putOpcode("3");
        		break;
        	case "load":
        		instructions.get(i).putOpcode("40");
        		break;
        	case "store":
        		instructions.get(i).putOpcode("44");
        		break;
        	case "jal":
        		instructions.get(i).putOpcode("48");
        		break;
        	case "return":
        		instructions.get(i).putOpcode("49");
        		break;
        	case "jump":
        		instructions.get(i).putOpcode("c");
        		break;
        	case "jg":
        		instructions.get(i).putOpcode("c");
        		break;
        	case "jl":
        		instructions.get(i).putOpcode("c");
        		break;
        	case "je":
        		instructions.get(i).putOpcode("c");
        		break;
        	case "jle":
        		instructions.get(i).putOpcode("c");
        		break;
        	case "jge":
        		instructions.get(i).putOpcode("c");
        		break;
        	case "jne":
        		instructions.get(i).putOpcode("c");
        		break;
        	case "get":
        		instructions.get(i).putOpcode("85");
        		break;
        	case "start":
        		instructions.get(i).putOpcode("0f");
        		break;
        	default:
        		if (instructions.get(i).getCommand().startsWith("move"))
        				break;
        		String problem = "Command \"" + instructions.get(i).getCommand() + "\" is not a known instruction.  Line " + (instructions.get(i).getCount() + 1);
        		JOptionPane.showMessageDialog(null, problem);
        		System.exit(0);
        		break;
        	}
        	//Remove : from end of labels.
        	if(instructions.get(i).hasLabel())
        	{
        		String full = instructions.get(i).getLabel();
        		full = full.substring(0, full.length() - 1);
        		instructions.get(i).putLabel(full);
        	}
        }
        //Collect labeled commands as well as jump to commands.
        ArrayList<Integer> labelIndexes = new ArrayList<Integer>();
        ArrayList<Integer> toLabelIndexes = new ArrayList<Integer>();
        for (int i = 0; i < instructions.size(); i++)
        {
        	//Collect indexes of labeled instructions.
        	if (instructions.get(i).hasLabel())
        	{
        		labelIndexes.add(i);
        	}
        	if (instructions.get(i).hasJumpLabel())
        	{
        		toLabelIndexes.add(i);
        	}
        }
        //Do the math for normal jump commands.  Convert it to hex and error if out of range.
        //Store the immediate value into the immediate variable.  I types have source already as I value.
        for (int i = 0; i < toLabelIndexes.size(); i++)
        {
        	for (int j= 0; j < labelIndexes.size(); j++)
        	{
        		//If the labels are equal find the distance and do the conversion.
        		if(instructions.get(toLabelIndexes.get(i)).getJumpLabel().equals(instructions.get(labelIndexes.get(j)).getLabel()))
        		{
        			//Act differently for JAL
        			if (instructions.get(toLabelIndexes.get(i)).getCommand().equals("jal"))
        			{
        				int address = instructions.get(labelIndexes.get(j)).getCount();
        				String hexAddress = Integer.toHexString(address);
        				//Add leading zeroes to make 16 bit.
        				switch (hexAddress.length())
        				{
        				case 1:
        					hexAddress = "000" + hexAddress;
        					break;
        				case 2:
        					hexAddress = "00" + hexAddress;
        					break;
        				case 3:
        					hexAddress = "0" + hexAddress;
        					break;
        				case 4:
        					break;
        				default:
        					String error = "JAL address not valid. " + "Line " + instructions.get(toLabelIndexes.get(i)).getCount();
            				JOptionPane.showMessageDialog(null, error);
            				System.exit(0);
        					break;
        				}
        				//Store the new address in JAL immediate.
        				instructions.get(toLabelIndexes.get(i)).putImmediate(hexAddress);
        			}
        			else
        			{
        				//to - from
            			int to = instructions.get(labelIndexes.get(j)).getCount();
            			int from = instructions.get(toLabelIndexes.get(i)).getCount();
            			int jAmount = to - from;
            			//Convert to hex and make the Immediate for this jump
            			String jump = Integer.toHexString(jAmount);
            			//Add leading 0 for single values.
            			if (jump.length() == 1)
            				jump = "0" + jump;
            			//Check for f's present in negative jumping and remove extra ones
            			if(jump.length() > 2)
            			{
            				if(jump.startsWith("f"))
            				{
            					jump = jump.substring(jump.length() -  2);  //Removes the sign extension inherent to java conversion.
            				}
            			}
            			//Check for out of range.
            			if (jump.length() > 2)
            			{
            				String error = "Jump out of range.";
            				JOptionPane.showMessageDialog(null, error);
            				System.exit(0);
            			}
            			//Store the jump value in immediate.
            			instructions.get(toLabelIndexes.get(i)).putImmediate(jump);	
        			}
        		}
        			
        	}
        }
        //Fix register values in all immediate commands that may be too long.  Missed this the first time around.
        for (int i = 0; i < instructions.size(); i++)
        {
        	//This narrows it down to immediates that may have long source rcodes 
        	if (instructions.get(i).getCommand().endsWith("i") && !(instructions.get(i).getOpcode().startsWith("8")))
        			{
        				if(instructions.get(i).getSource().length() > 2)
        				{
        					if (instructions.get(i).getSource().startsWith("f"))
        					{
        						//If it starts with f we need to trim it down.
        						String hex = instructions.get(i).getSource();
        						hex = hex.substring(hex.length() -  2);
        						instructions.get(i).putSource(hex);
        					}
        					else
        					{
        						String error = "The immediate value given is too large. Line " + instructions.get(i).getCount();
            					JOptionPane.showMessageDialog(null, error);
            					System.exit(0);
        					}
        					
        				}
        				//Fix things that need to have more values added.  Immediate registers at this stage may only have 1 character.
        				if (instructions.get(i).getSource().length() < 2)
        				{
        					String correction = "0" + instructions.get(i).getSource();
        					instructions.get(i).putSource(correction);
        				}
        			}
        }
        //Make the commands necessary to get jal to have an address in it in r15.  Use r14 as needed
        for (int i = 0; i < instructions.size(); i++)
        {
        	if (instructions.get(i).getCommand().equals("jal"))
        	{
        		if (instructions.get(i).getImmediate() == null)
        		{
        			String problem = "The jal destination does not exist.  Line " + instructions.get(i).getCount();
        			JOptionPane.showMessageDialog(null, problem);
        			System.exit(0);
        		}
        		//Start with move 1 and work forward.
        		String firstTwo = instructions.get(i).getImmediate().substring(0, 2);
        		int changeIndex = (i - 6);  //Takes us back to move 1.
        		instructions.set(changeIndex, new Instruction("movi", "f", firstTwo, null, 0, null));
        		instructions.get(changeIndex).putOpcode("3");  //instructions.get(i).putOpcode("3");
        		//Now move it left by eight.
        		instructions.set((changeIndex + 1), new Instruction("lshi", "f", "8", null, 0, null));
        		instructions.get(changeIndex + 1).putOpcode("80");  //instructions.get(i).putOpcode("80");
        		//Move the next one down into r14
        		String mid = "0" + instructions.get(i).getImmediate().charAt(2);
        		String last = "0" + instructions.get(i).getImmediate().charAt(3);
        		instructions.set((changeIndex + 2), new Instruction("movi", "e", mid, null, 0, null));
        		instructions.get(changeIndex + 2).putOpcode("3");  //instructions.get(i).putOpcode("3");
        		instructions.set((changeIndex + 3), new Instruction("lshi", "e", "4", null, 0, null)); //Shift it 4
        		instructions.get(changeIndex + 3).putOpcode("80");  //instructions.get(i).putOpcode("80");
        		instructions.set((changeIndex + 4), new Instruction("addi", "e", last, null, 0, null));// add the next one in
        		instructions.get(changeIndex + 4).putOpcode("5");  //instructions.get(i).putOpcode("5");
        		instructions.set((changeIndex + 5), new Instruction("add", "f", "e", null, 0, null)); //Add the two together.  Final in f or r15
        		instructions.get(changeIndex + 5).putOpcode("05");  //instructions.get(i).putOpcode("05");
        	}
        }
        //Print out the final information to the file path.
        try 
        {
			PrintWriter out = new PrintWriter(path);
			
			//Loop through instructions in order and put them out.
			for (int i = 0; i < instructions.size(); i++)
			{
				String opcode, immediate;  //Immediate for jumping only.
				opcode = instructions.get(i).getOpcode();
				rsrc = instructions.get(i).getSource();
				rdest = instructions.get(i).getDest();
				command = instructions.get(i).getCommand();
				immediate = instructions.get(i).getImmediate();
				
				//ophigh, rdest, oplow/immhigh, rsrc/immlow
				switch(command)
				{
				case "add":
	        		//instructions.get(i).putOpcode("05");
					out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //add");
	        		break;
	        	case "addi":
	        		//instructions.get(i).putOpcode("5");
	        		out.println(opcode + rdest + rsrc + "  //addi");
	        		break;
	        	case "addu":
	        		//instructions.get(i).putOpcode("06");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //addu");
	        		break;
	        	case "addui":
	        		//instructions.get(i).putOpcode("6");
	        		out.println(opcode + rdest + rsrc + "  //addui");
	        		break;
	        	case "addc":
	        		//instructions.get(i).putOpcode("07");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //addc");
	        		break;
	        	case "addcu":
	        		//instructions.get(i).putOpcode("04");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //addcu");
	        		break;
	        	case "addcui":
	        		//instructions.get(i).putOpcode("1");
	        		out.println(opcode + rdest + rsrc + "  //addcui");
	        		break;
	        	case "addci":
	        		//instructions.get(i).putOpcode("7");
	        		out.println(opcode + rdest + rsrc + "  //addci");
	        		break;
	        	case "sub":
	        		//instructions.get(i).putOpcode("09");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //sub");
	        		break;
	        	case "subi":
	        		//instructions.get(i).putOpcode("9");
	        		out.println(opcode + rdest + rsrc + "  //subi");
	        		break;
	        	case "cmp":
	        		//instructions.get(i).putOpcode("0b");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //cmp");
	        		break;
	        	case "cmpi":
	        		//instructions.get(i).putOpcode("b");
	        		out.println(opcode + rdest + rsrc + "  //cmpi");
	        		break;
	        	case "cmpu":
	        		//instructions.get(i).putOpcode("08");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //cmpu");
	        		break;
	        	case "cmpui":
	        		//instructions.get(i).putOpcode("2");
	        		out.println(opcode + rdest + rsrc + "  //cmpui");
	        		break;
	        	case "and":
	        		//instructions.get(i).putOpcode("01");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //and");
	        		break;
	        	case "andi":
	        		//instructions.get(i).putOpcode("a");
	        		out.println(opcode + rdest + rsrc + "  //andi");
	        		break;
	        	case "or":
	        		//instructions.get(i).putOpcode("02");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //or");
	        		break;
	        	case "xor":
	        		//instructions.get(i).putOpcode("03");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //xor");
	        		break;
	        	case "not":
	        		//instructions.get(i).putOpcode("0c");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //not");
	        		break;
	        	case "logsh":
	        		//instructions.get(i).putOpcode("84");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //logsh");
	        		break;
	        	case "lshi":
	        		//instructions.get(i).putOpcode("80");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //lshi");
	        		break;
	        	case "rshi":
	        		//instructions.get(i).putOpcode("81");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //rshi");
	        		break;
	        	case "alogsh":
	        		//instructions.get(i).putOpcode("4f");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //alogsh");
	        		break;
	        	case "arshi":
	        		//instructions.get(i).putOpcode("83");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //arshi");
	        		break;
	        	case "alshi":
	        		//instructions.get(i).putOpcode("82");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //alshi");
	        		break;
	        	case "wait":
	        		//instructions.get(i).putOpcode("00");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //wait");
	        		break;
	        	case "start":
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //start");
	        		break;
	        	case "mov":
	        		//instructions.get(i).putOpcode("0d");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //mov");
	        		break;
	        	case "get":
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //get");
	        		break;
	        	case "movi":
	        		//instructions.get(i).putOpcode("3");
	        		out.println(opcode + rdest + rsrc + "  //movi");
	        		break;
	        	case "load":
	        		//instructions.get(i).putOpcode("40");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //load");
	        		break;
	        	case "store":
	        		//instructions.get(i).putOpcode("44");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //store");
	        		break;
	        	case "jal":
	        		//instructions.get(i).putOpcode("48");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //jal");
	        		break;
	        	case "return":
	        		//instructions.get(i).putOpcode("49");
	        		out.println(getCode(opcode, 0) + rdest + getCode(opcode, 1) + rsrc + "  //return");
	        		break;
	        	case "jump":
	        		//instructions.get(i).putOpcode("c");
	        		out.println(opcode + rdest + immediate + "  //jump");
	        		break;
	        	case "jg":
	        		//instructions.get(i).putOpcode("c");
	        		out.println(opcode + rdest + immediate + "  //jg");
	        		break;
	        	case "jl":
	        		//instructions.get(i).putOpcode("c");
	        		out.println(opcode + rdest + immediate + "  //jl");
	        		break;
	        	case "je":
	        		//instructions.get(i).putOpcode("c");
	        		out.println(opcode + rdest + immediate + "  //je");
	        		break;
	        	case "jle":
	        		//instructions.get(i).putOpcode("c");
	        		out.println(opcode + rdest + immediate + "  //jle");
	        		break;
	        	case "jge":
	        		//instructions.get(i).putOpcode("c");
	        		out.println(opcode + rdest + immediate + "  //jge");
	        		break;
	        	case "jne":
	        		//instructions.get(i).putOpcode("c");
	        		out.println(opcode + rdest + immediate + "  //jne");
	        		break;
	        	default:
	        		String problem = "Command \"" + instructions.get(i).getCommand() + "\" is not a known instruction.  Line " + (instructions.get(i).getCount() + 1);
	        		JOptionPane.showMessageDialog(null, problem);
	        		System.exit(0);
	        		break;
				}
			}
			//All new code here.  Finishes filling the file with zeros and preloads the motor limits.
			while (count < 32768)
			{
				switch (count)
				{
				case 20000:
					out.println("0a28" + " //Xlim");
					break;
				case 20001:
					out.println("08fc" + " //Ylim");
					break;
				case 20002:
					out.println("0a28" + " //Zlim");
					break;
				default:
					out.println("0000");
					break;
				}
				count++;
			}
			out.close();
		} 
        catch (FileNotFoundException e) 
        {
			String error = "Error making output file.  Error: " + e;
			JOptionPane.showMessageDialog(null, error);
		} 
        String success = "Conversion is complete.";
        JOptionPane.showMessageDialog(null, success);
        //Debugging statements
        /*for (int i = 0; i < instructions.size(); i++)
        	System.out.println(instructions.get(i).getLabel() + " " + instructions.get(i).getCommand() + " " + instructions.get(i).getDest()
        			+ " " + instructions.get(i).getSource() + " " + instructions.get(i).getJumpLabel() + " " + instructions.get(i).getCount());*/
	}
	/**
	 * Takes in an opcode and returns the value of the int index.  0 = first entry.  1 = second entry.
	 * @param opcode The two length code.
	 * @param index The index 0 or 1.
	 * @return
	 */
public static String getCode(String opcode, int index)
{
	String high = "" + opcode.charAt(0);
	String low = "" + opcode.charAt(1);
	if (index == 0)
		return high;
	return low;
}
}
