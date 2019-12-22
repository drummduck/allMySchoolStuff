package lab3;

import junit.framework.TestCase;

public class TestFindSmallesDiff extends TestCase {
	private int[] arr1, arr2, arr3, arr4, arr5;
	
	
	public void testFindSmallestDiff1() 
	{
	  assertEquals(-1, DiffUtil.findSmallestDiff(arr1));
	}

	public void testFindSmallestDiff2() 
	{
	  assertEquals(0, DiffUtil.findSmallestDiff(arr2));
	}

	public void testFindSmallestDiff3() 
	{
	  assertEquals(4, DiffUtil.findSmallestDiff(arr3));
	}
	
	public void testFindSmallestDiff4() 
	{
	  assertEquals(1, DiffUtil.findSmallestDiff(arr4));
	  
	}
	
	public void testFindSmallestDiff5() 
	{
	  assertEquals(0, DiffUtil.findSmallestDiff(arr5));
	  
	}
	
	

	protected void setUp() throws Exception {
		 super.setUp();
		    
		  arr1 = new int[0];
		  arr2 = new int[] { 3, 3, 3 };
		  arr3 = new int[] { 52, 4, -8, 0, -17 };
		  arr4 = new int[]
				  {-3, 9, 100, 45, 99, 105};
		  arr5 = new int[] {-5,-5,-5,-5,-5,10};
	}

	protected void tearDown() throws Exception {
		super.tearDown();
	}
	
	

}
