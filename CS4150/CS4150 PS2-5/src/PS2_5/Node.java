package PS2_5;

public class Node {

	public Node left;
	public Node right;
	public int data;
	
	public Node(int inData) 
	{
		 data = inData;
		 left = null;
		 right = null;
	}
	
	public int get()
	{
		return this.data;
	}
	
	public void set(int indata)
	{
		this.data = indata;
	}

}
