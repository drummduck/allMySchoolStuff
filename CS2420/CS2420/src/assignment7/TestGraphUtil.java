package assignment7;

import java.util.ArrayList;

import junit.framework.TestCase;


public class TestGraphUtil extends TestCase {

	
	
public void testtop()
{
	ArrayList<String> compare = new ArrayList<String>();
	
	
	compare = (ArrayList<String>) GraphUtil.topologicalSort("dot.dot");
	
	for(int pos = 0; pos < compare.size(); pos++)
	{
		System.out.println(compare.get(pos).toString());
	}
		
	
	
	
} 

public void testBST()
{
	ArrayList<String> compare = new ArrayList<String>();
	
	compare
}

}
