package compiler;
/*
 * This is an instruction object.  It will hold values needed for conversion from the main in AssemblyCompiler.
 */
public class Instruction 
{
	private String command = null;
	private String rdest = null;  
	private String rsrc = null;  //Also used as IMMLOW
	private String label = null;
	private String toLabel = null;
	private int count;
	private String opcode;
	private String immediateValue;
	
	/**
	 * This is the constructor for the instruction object.
	 * @param command  Command name
	 * @param rdest    destination register
	 * @param rsrc	   source register
	 * @param label    label of this command if any.  NULL otherwise
	 * @param count	   The program count of this instruction
	 * @param toLabel  The label getting jumped to by this command if any.  NULL otherwise
	 */
	public Instruction (String command, String rdest, String rsrc, String label, int count, String toLabel)
	{
		if (command != null)
			this.command = command.toLowerCase();
		if (rdest != null)
			this.rdest = rdest.toLowerCase();
		if (rsrc != null)
			this.rsrc = rsrc.toLowerCase();
		if (label != null)
			this.label = label.toLowerCase();
		this.count = count;
		if (toLabel != null)
			this.toLabel = toLabel.toLowerCase();  //Update in future to become address for the jump.
	}
	/**
	 * Checks if there is a label.  Returns true if there is.
	 * @return
	 */
	public boolean hasLabel()
	{
		if (label == null)
		{
			return false;
		}
		return true;
	}
	/**
	 * Returns the label of this instruction.
	 * @return
	 */
	public String getLabel()
	{
		return this.label;
	}
	/**
	 * Checks to see if this command jumps to a label.
	 * If so it returns true.
	 * @return
	 */
	public boolean hasJumpLabel()
	{
		if (toLabel == null)
			return false;
		
		return true;
	}
	/**
	 * Returns the label that needs to be jumped to by this command.
	 * @return
	 */
	public String getJumpLabel()
	{
		return toLabel;
	}
	/**
	 * Returns the count or PC of this command.
	 * @return
	 */
	public int getCount()
	{
		return count;
	}
	/**
	 * Returns the source register as a string.
	 * @return
	 */
	public String getSource()
	{
		return rsrc;
	}
	/**
	 * Returns the destination register as a String.
	 * @return
	 */
	public String getDest()
	{
		return rdest;
	}
	/**
	 * Returns the command as a String.
	 * @return
	 */
	public String getCommand()
	{
		return command;
	}
	/**
	 * This method places an opcode in this instruction.
	 * @param op
	 */
	public void putOpcode(String op)
	{
		opcode = op;
	}
	/**
	 * This method returns the opcode.
	 * @return
	 */
	public String getOpcode()
	{
		return opcode;
	}
	/**
	 * Returns the current immediate value
	 * @return
	 */
	public String getImmediate()
	{
		return immediateValue;
	}
	/**
	 * Stores the immediate value to this instruction.
	 * @param immediate
	 */
	public void putImmediate(String immediate)
	{
		immediateValue = immediate;
	}
	/**
	 * Replaces the source with the passed in value
	 * @param source
	 */
	public void putSource(String source)
	{
		rsrc = source;
	}
	/**
	 * Replaces the destination with the passed in value.
	 * @param dest
	 */
	public void putDest(String dest)
	{
		rdest = dest;
	}
	/**
	 * Changes the label to the passed in label.
	 * @param label String to become the new label.
	 */
	public void putLabel(String label)
	{
		this.label = label;
	}
}
