package assignment4;

import java.util.ArrayList;
import java.util.Random;

import junit.framework.Test;

public class TestSortUtil {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
	
//------------Tests for MergSort__All tests tested for insertionSort via changing of threshold----------------
		
	//#1
		//A simple test for mergeSort.
			//Test List.
		ArrayList<Integer> test1Array = new ArrayList<Integer>();
			//Comparison List.
		ArrayList<Integer> expected1Array = new ArrayList<Integer>();
		 //Make a few ints.
		int one = 1;
		int five = 5;
		int seven = 7;
		int two = 2;
		int twenty = 20;
		int six = 6;
		int neg10 = -10;
		int thousand = 1000;
		int two2 = 2;
			//Add ints.
		test1Array.add(five);
		test1Array.add(seven);
		test1Array.add(one);
		test1Array.add(thousand);
		test1Array.add(two2);
		test1Array.add(six);
		test1Array.add(neg10);	
		test1Array.add(two);
		test1Array.add(twenty);
		expected1Array.add(one);
		expected1Array.add(two);
		expected1Array.add(five);
		expected1Array.add(seven);
		expected1Array.add(twenty);
		
			//Call the method to be tested.
		SortUtil.mergesort(test1Array);
		
			//For debugging.
		System.out.println(test1Array.toString());
		
			//Assertions.
		if(test1Array.get(0) != -10) 
			System.err.println("Test 1 failed: test1Array not sorted correctly(-10)."); 
		if(test1Array.get(1) != 1) 
			System.err.println("Test 1 failed: test1Array not sorted correctly(1)."); 
		if(test1Array.get(2) != 2)
			System.err.println("Test 1 failed: test1Array not sorted correctly(2).");
		if(test1Array.get(3) != 2)
			System.err.println("Test 1 failed: test1Array not sorted correctly(2).");    
		if(test1Array.get(4) != 5)
			System.err.println("Test 1 failed: test1Array not sorted correctly(5).");
		if(test1Array.get(5) != 6)
			System.err.println("Test 1 failed: test1Array not sorted correctly(6).");   
		if(test1Array.get(6) != 7)
			System.err.println("Test 1 failed: test1Array not sorted correctly(7).");  
		if(test1Array.get(7) != 20)
			System.err.println("Test 1 failed: test1Array not sorted correctly(20).");
		if(test1Array.get(8) != 1000)
			System.err.println("Test 1 failed: test1Array not sorted Correctly(1000)");
		
		
		//#2
			//Sort an list of size 0;
		ArrayList<Integer> test2Array = new ArrayList<Integer>();
		
		try
		{
			SortUtil.mergesort(test2Array);
		}
		catch(Exception e)
		{
			System.err.println("Test 2 failed: mergeSort is throwing an exception when sorting an empty list");
		}
		
		
		//#3
			//Sort a list of size 1.
		ArrayList<Integer> test3Array = new ArrayList<Integer>();
		
		test3Array.add(one);
		
		try
		{
			SortUtil.mergesort(test3Array);
			if(test3Array.get(0) != 1) 
				System.err.println("Test 3 failed: test3Array does not contain the only item that was sorted."); 
			
		}
		catch(Exception e)
		{
			System.err.println("Test 3 failed: mergeSort is throwing an exception when " +
										"sorting a list with one item");
		}
		
	//#4
		//Sort a list of size 2.
	ArrayList<Integer> test4Array = new ArrayList<Integer>();
	
	test4Array.add(twenty);
	test4Array.add(one);
	
	try
	{
		SortUtil.mergesort(test4Array);
		if(test4Array.get(0) != 1) 
			System.err.println("Test 4 failed: mergeSort is not sorting an array with two items properly(1).");
		if(test4Array.get(1) != 20) 
			System.err.println("Test 4 failed: mergeSort is not sorting an array with two items properly(20).");
		
	}
	catch(Exception e)
	{
		System.err.println("Test 4 failed: mergeSort is throwing an exception when " +
									"sorting a list with two items.");
	}
	
	
	//#5
			//Sort a list of size 3.
		ArrayList<Integer> test5Array = new ArrayList<Integer>();
		
		test5Array.add(twenty);
		test5Array.add(one);
		test5Array.add(seven);
		
		try
		{
			SortUtil.mergesort(test5Array);
			if(test5Array.get(0) != 1) 
				System.err.println("Test 5 failed: mergeSort is not sorting an array with 3 items properly(1).");
			if(test5Array.get(1) != 7) 
				System.err.println("Test 5 failed: mergeSort is not sorting an array with 3 items properly(7).");
			if(test5Array.get(2) != 20) 
				System.err.println("Test 5 failed: mergeSort is not sorting an array with 3 items properly(20).");
		}
		catch(Exception e)
		{
			System.err.println("Test 5 failed: mergeSort is throwing an exception when " +
										"sorting a list with three items.");
		}
		
	//#6
		//Sort a list of size 4.
	ArrayList<Integer> test6Array = new ArrayList<Integer>();
	
	test6Array.add(twenty);
	test6Array.add(one);
	test6Array.add(neg10);
	test6Array.add(seven);
	
	try
	{
		SortUtil.mergesort(test6Array);
		
		if(test6Array.get(0) != -10) 
			System.err.println("Test 6 failed: mergeSort is not sorting an array with 4 items properly(-10).");
		if(test6Array.get(1) != 1) 
			System.err.println("Test 6 failed: mergeSort is not sorting an array with 4 items properly(1).");
		if(test6Array.get(2) != 7) 
			System.err.println("Test 6 failed: mergeSort is not sorting an array with 4 items properly(7).");
		if(test6Array.get(3) != 20) 
			System.err.println("Test 6 failed: mergeSort is not sorting an array with 4 items properly(20).");
	}
	catch(Exception e)
	{
		System.err.println("Test 6 failed: mergeSort is throwing an exception when " +
									"sorting a list with 4 items.");
	}
	
	//#7
			//Sort a list of size 5.
		ArrayList<Integer> test7Array = new ArrayList<Integer>();
		
		test7Array.add(twenty);
		test7Array.add(thousand);
		test7Array.add(one);
		test7Array.add(neg10);
		test7Array.add(seven);
		
		try
		{
			SortUtil.mergesort(test7Array);
			
			if(test7Array.get(0) != -10) 
				System.err.println("Test 7 failed: mergeSort is not sorting an array with 5 items properly(-10).");
			if(test7Array.get(1) != 1) 
				System.err.println("Test 7 failed: mergeSort is not sorting an array with 5 items properly(1).");
			if(test7Array.get(2) != 7) 
				System.err.println("Test 7 failed: mergeSort is not sorting an array with 5 items properly(7).");
			if(test7Array.get(3) != 20) 
				System.err.println("Test 7 failed: mergeSort is not sorting an array with 5 items properly(20).");
			if(test7Array.get(4) != 1000) 
				System.err.println("Test 7 failed: mergeSort is not sorting an array with 5 items properly(1000).");
		}
		catch(Exception e)
		{
			System.err.println("Test 7 failed: mergeSort is throwing an exception when " +
										"sorting a list with 5 items.");
		}
		
	//#8
		//Test a List of all duplicates.
	ArrayList<Integer> test8Array = new ArrayList<Integer>();
	
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);
	test8Array.add(twenty);		//That is 20 twenties.
	
	try
	{
		SortUtil.mergesort(test8Array);
		
		int indexCount = 0;
		
		for(int twensies = 0; twensies < 19; twensies++)
		{
			if(test8Array.get(twensies) != 20)
				System.err.println("Test 8 Failed: List of 20 20's is not sorted corectly at index " + indexCount + "." );
				//Increment index count.
			indexCount ++;
		}


	}
	catch(Exception e)
	{
		System.err.println("Test 8 failed: mergeSort is throwing an exception when " +
									"sorting a list of 20 20's items.");
	}
	
	
	//#9
			//Test a List two repeated values and crossing the threshold.
		ArrayList<Integer> test9Array = new ArrayList<Integer>();
			
			//Add 20 20's and 20 5's in "permuted" order.
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(five); 
		test9Array.add(twenty);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(five);
		test9Array.add(five);
		test9Array.add(twenty);
		test9Array.add(twenty);	
		test9Array.add(five);
		
		try
		{
			SortUtil.mergesort(test9Array);
			
			int indexCount = 0;
			
			for(int twensies : test9Array)
			{
				if(indexCount < 20 && test9Array.get(twensies) != 5)
					System.err.println("Test 9 Failed: List of 20 20's % 20 5's is not sorted " +
											"correctly at index " + indexCount + "." );
				if(indexCount > 19 && test9Array.get(twensies) != 20)
					System.err.println("Test 9 Failed: List of 20 20's % 20 5's is not sorted " +
							"correctly at index " + indexCount + "." );
					//Increment index count.
				indexCount ++;
			}

		}
		catch(Exception e)
		{
			System.err.println("Test 9 failed: mergeSort is throwing an exception when " +
										"sorting a list of 20 20's & 20 5's items.");
		}

		
		//#10
			//Test a sorted array.
		
		ArrayList<Integer> test10Array = new ArrayList<Integer>();
		
		try
		{
		test10Array.add(0);
		test10Array.add(1);
		test10Array.add(2);
		test10Array.add(3);
		test10Array.add(4);
		test10Array.add(5);
		test10Array.add(6);
		test10Array.add(7);
		test10Array.add(8);
		test10Array.add(9);
		
			//Comparison string.
		String expectedToString = test10Array.toString();
		
		SortUtil.mergesort(test10Array);
			//For debugging.
		//System.out.println(test10Array.toString());
		

		if(!test10Array.toString().equals(expectedToString)) 
		{
			System.err.println("Test 10 Failed: Sorted List has become unsorted" );
		}
		
		}
		catch(Exception e)
		{
			System.err.println("Test 10 failed: mergeSort is throwing an exception when " +
					"ascending sorted List.");
		}
		
		
	//#11
		//Test a sorted array.
	
	ArrayList<Integer> test11Array = new ArrayList<Integer>();
	
	try
	{
		test11Array.add(9);
		test11Array.add(8);
		test11Array.add(7);
		test11Array.add(6);
		test11Array.add(5);
		test11Array.add(4);
		test11Array.add(3);
		test11Array.add(2);
		test11Array.add(1);
		test11Array.add(0);
			//Comparison string.
		String expectedString = "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]";
	
		SortUtil.mergesort(test11Array);
		
			//For debugging.
		//System.out.println(test11Array.toString());

		if(!test11Array.toString().equals(expectedString))
		{
			System.err.println("Test 11 Failed: Sorted List has become unsorted" );
		}
	
	}
	catch(Exception e)
	{
		System.err.println("Test 11 failed: List in descending order is not sorted corectly.");
	}
	
	
	//#12
		//Test a large permuted set.
	ArrayList<Integer> test12Array = new ArrayList<Integer>();
	
	Random randomTestGenerator = new Random();
		//Fill an array with many  random integers.
	for(int pos = 0; pos < 10000; pos++)
	{
		int randy = randomTestGenerator.nextInt();
		test12Array.add(randy);
	}
	
	SortUtil.mergesort(test12Array);
		
		//**VISUALLY VERIFY RESULTS**//
	//String expectedString = test12Array.toString();
		
		//For debugging.
	//System.out.println(test12Array.toString());
	
	for(int pos = 1; pos < 9999; pos++)
	{		//if the item at the current position is less than the item at the previous position and the
				//item at the current position is greater than the item in the next position...
		if(test12Array.get(pos).compareTo(test12Array.get(pos -1)) <= 0 || test12Array.get(pos).compareTo(test12Array.get(pos +1)) >= 0)
				//...test fails.
			System.err.println("Test 12 Failed: large set is not being sorted."); 
	}
	
//----------------------------------------End of tests for mergeSort-----------------------------------
	
//----------------------------------------Tests for quicksort-----------------------------	
	
	//#13
			//A simple test for mergeSort.
				//Test List.
			ArrayList<Integer> test13Array = new ArrayList<Integer>();
				
			
			 //Make a few ints.
			int one13 = 1;
			int five13 = 5;
			int seven13 = 7;
			int two13 = 2;
			int twenty13 = 20;
			int six13 = 6;
			int neg1013 = -10;
			int thousand13 = 1000;
			int two213 = 2;
				//Add ints.
			test13Array.add(five13);
			test13Array.add(seven13);
			test13Array.add(one13);
			test13Array.add(thousand13);
			test13Array.add(two213);
			test13Array.add(six13);
			test13Array.add(neg1013);	
			test13Array.add(two13);
			test13Array.add(twenty13);
			
			
				//Call the method to be tested.
			SortUtil.quicksort(test13Array);
			
				//For debugging.
			System.out.println(test13Array.toString());
			
				//Assertions.
			if(test13Array.get(0) != -10) 
				System.err.println("Test 13 failed: test13Array not sorted correctly(-10)."); 
			if(test13Array.get(1) != 1) 
				System.err.println("Test 13 failed: test13Array not sorted correctly(1)."); 
			if(test13Array.get(2) != 2)
				System.err.println("Test 13 failed: test13Array not sorted correctly(2).");
			if(test13Array.get(3) != 2)
				System.err.println("Test 13 failed: test13Array not sorted correctly(2).");    
			if(test13Array.get(4) != 5)
				System.err.println("Test 13 failed: test13Array not sorted correctly(5).");
			if(test13Array.get(5) != 6)
				System.err.println("Test 13 failed: test13Array not sorted correctly(6).");   
			if(test13Array.get(6) != 7)
				System.err.println("Test 13 failed: test13Array not sorted correctly(7).");  
			if(test13Array.get(7) != 20)
				System.err.println("Test 13 failed: test13Array not sorted correctly(20).");
			if(test13Array.get(8) != 1000)
				System.err.println("Test 13 failed: test13Array not sorted Correctly(1000)");
			
			
			//#14
				//Sort an list of size 0;
			ArrayList<Integer> test14Array = new ArrayList<Integer>();
			
			try
			{
				SortUtil.quicksort(test14Array);
			}
			catch(Exception e)
			{
				System.err.println("Test 14 failed: quicksort is throwing an exception when sorting an empty list");
			}
			
			
			//#15
				//Sort a list of size 1.
			ArrayList<Integer> test15Array = new ArrayList<Integer>();
			
			test15Array.add(one);
			
			try
			{
				SortUtil.quicksort(test15Array);
				if(test15Array.get(0) != 1) 
					System.err.println("Test 15 failed: test15Array does not contain the only item that was sorted."); 
				
			}
			catch(Exception e)
			{
				System.err.println("Test 15 failed: quicksort is throwing an exception when " +
											"sorting a list with one item");
			}
			
		//#16
			//Sort a list of size 2.
		ArrayList<Integer> test16Array = new ArrayList<Integer>();
		
		test16Array.add(twenty);
		test16Array.add(one);
		
		try
		{
			SortUtil.quicksort(test16Array);
			if(test16Array.get(0) != 1) 
				System.err.println("Test 16 failed: quicksort is not sorting an array with two items properly(1).");
			if(test16Array.get(1) != 20) 
				System.err.println("Test 16 failed: quicksort is not sorting an array with two items properly(20).");
			
		}
		catch(Exception e)
		{
			System.err.println("Test 16 failed: quicksort is throwing an exception when " +
										"sorting a list with two items.");
		}
		
		
		//#17
				//Sort a list of size 3.
			ArrayList<Integer> test17Array = new ArrayList<Integer>();
			
			test17Array.add(twenty);
			test17Array.add(one);
			test17Array.add(seven);
			
			try
			{
				SortUtil.quicksort(test17Array);
				if(test17Array.get(0) != 1) 
					System.err.println("Test 5 failed: quicksort is not sorting an array with 3 items properly(1).");
				if(test17Array.get(1) != 7) 
					System.err.println("Test 5 failed: quicksort is not sorting an array with 3 items properly(7).");
				if(test17Array.get(2) != 20) 
					System.err.println("Test 5 failed: quicksort is not sorting an array with 3 items properly(20).");
			}
			catch(Exception e)
			{
				System.err.println("Test 17 failed: quicksort is throwing an exception when " +
											"sorting a list with three items.");
			}
			
		//#18
			//Sort a list of size 4.
		ArrayList<Integer> test18Array = new ArrayList<Integer>();
		
		test18Array.add(twenty);
		test18Array.add(one);
		test18Array.add(neg10);
		test18Array.add(seven);
		
		try
		{
			SortUtil.quicksort(test18Array);
			
			if(test18Array.get(0) != -10) 
				System.err.println("Test 18 failed: quicksort is not sorting an array with 4 items properly(-10).");
			if(test18Array.get(1) != 1) 
				System.err.println("Test 18 failed: quicksort is not sorting an array with 4 items properly(1).");
			if(test18Array.get(2) != 7) 
				System.err.println("Test 18 failed: quicksort is not sorting an array with 4 items properly(7).");
			if(test18Array.get(3) != 20) 
				System.err.println("Test 18 failed: quicksort is not sorting an array with 4 items properly(20).");
		}
		catch(Exception e)
		{
			System.err.println("Test 18 failed: quicksort is throwing an exception when " +
										"sorting a list with 4 items.");
		}
		
		//#19
				//Sort a list of size 5.
			ArrayList<Integer> test19Array = new ArrayList<Integer>();
			
			test19Array.add(twenty);
			test19Array.add(thousand);
			test19Array.add(one);
			test19Array.add(neg10);
			test19Array.add(seven);
			
			try
			{
				SortUtil.quicksort(test19Array);
				
				if(test19Array.get(0) != -10) 
					System.err.println("Test 19 failed: quicksort is not sorting an array with 5 items properly(-10).");
				if(test19Array.get(1) != 1) 
					System.err.println("Test 19 failed: quicksort is not sorting an array with 5 items properly(1).");
				if(test19Array.get(2) != 7) 
					System.err.println("Test 19 failed: quicksort is not sorting an array with 5 items properly(7).");
				if(test19Array.get(3) != 20) 
					System.err.println("Test 19 failed: quicksort is not sorting an array with 5 items properly(20).");
				if(test19Array.get(4) != 1000) 
					System.err.println("Test 19 failed: quicksort is not sorting an array with 5 items properly(1000).");
			}
			catch(Exception e)
			{
				System.err.println("Test 19 failed: mergeSort is throwing an exception when " +
											"sorting a list with 5 items.");
			}
			
		//#20
			//Test a List of all duplicates.
		ArrayList<Integer> test20Array = new ArrayList<Integer>();
		
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);
		test20Array.add(twenty);		//That is 20 twenties.
		
		try
		{
			SortUtil.quicksort(test20Array);
			
			int indexCount = 0;
			
			for(int twensies = 0; twensies < 19; twensies++)
			{
				if(test20Array.get(twensies) != 20)
					System.err.println("Test 20 Failed: List of 20 20's is not sorted corectly at index " + indexCount + "." );
					//Increment index count.
				indexCount ++;
			}


		}
		catch(Exception e)
		{
			System.err.println("Test 20 failed: quicksort is throwing an exception when " +
										"sorting a list of 20 20's items.");
		}
		
		
		//#21
				//Test a List two repeated values and crossing the threshold.
			ArrayList<Integer> test21Array = new ArrayList<Integer>();
				
				//Add 20 20's and 20 5's in "permuted" order.
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(five); 
			test21Array.add(twenty);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(five);
			test21Array.add(five);
			test21Array.add(twenty);
			test21Array.add(twenty);	
			test21Array.add(five);
			
			try
			{
				SortUtil.quicksort(test21Array);
				
				int indexCount = 0;
				
				for(int twensies : test9Array)
				{
					if(indexCount < 20 && test21Array.get(twensies) != 5)
						System.err.println("Test 21 Failed: List of 20 20's % 20 5's is not sorted " +
												"correctly at index " + indexCount + "." );
					if(indexCount > 19 && test21Array.get(twensies) != 20)
						System.err.println("Test 21 Failed: List of 20 20's % 20 5's is not sorted " +
								"correctly at index " + indexCount + "." );
						//Increment index count.
					indexCount ++;
				}

			}
			catch(Exception e)
			{
				System.err.println("Test 21 failed: quicksort is throwing an exception when " +
											"sorting a list of 20 20's & 20 5's items.");
			}

			
			//#22
				//Test a sorted array.
			
			ArrayList<Integer> test22Array = new ArrayList<Integer>();
			
			try
			{
			test22Array.add(0);
			test22Array.add(1);
			test22Array.add(2);
			test22Array.add(3);
			test22Array.add(4);
			test22Array.add(5);
			test22Array.add(6);
			test22Array.add(7);
			test22Array.add(8);
			test22Array.add(9);
			
				//Comparison string.
			String expectedToString = test22Array.toString();
			
			SortUtil.quicksort(test22Array);
				//For debugging.
			//System.out.println(test22Array.toString());
			

			if(!test22Array.toString().equals(expectedToString)) 
			{
				System.err.println("Test 22 Failed: Sorted List has become unsorted" );
			}
			
			}
			catch(Exception e)
			{
				System.err.println("Test 22 failed: quicksort is throwing an exception when " +
						"ascending sorted List.");
			}
			
			
		//#23
			//Test a sorted array.
		
		ArrayList<Integer> test23Array = new ArrayList<Integer>();
		
		try
		{
			test23Array.add(9);
			test23Array.add(8);
			test23Array.add(7);
			test23Array.add(6);
			test23Array.add(5);
			test23Array.add(4);
			test23Array.add(3);
			test23Array.add(2);
			test23Array.add(1);
			test23Array.add(0);
				//Comparison string.
			String expectedString = "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]";
		
			SortUtil.quicksort(test23Array);
			
				//For debugging.
			//System.out.println(test23Array.toString());

			if(!test23Array.toString().equals(expectedString))
			{
				System.err.println("Test 23 Failed: Sorted List has become unsorted" );
			}
		
		}
		catch(Exception e)
		{
			System.err.println("Test 23 failed: List in descending order is not sorted corectly.");
		}
		
		
		//#24
			//Test a large permuted set.
		ArrayList<Integer> test24Array = new ArrayList<Integer>();
		
		Random randomTestGenerator2 = new Random();
			//Fill an array with many  random integers.
		for(int pos = 0; pos < 10000; pos++)
		{
			int randy2 = randomTestGenerator2.nextInt();
			test24Array.add(randy2);
		}
		
		SortUtil.quicksort(test24Array);
			
			//**VISUALLY VERIFY RESULTS**//
		//String expectedString = test23Array.toString();
			
			//For debugging.
		//System.out.println(test24Array.toString());
		
		for(int pos = 1; pos < 9999; pos++)
		{
				//if the item at the current position is less than the item at the previous position and the
					//item at the current position is greater than the item in the next position...
			if(test24Array.get(pos).compareTo(test24Array.get(pos -1)) <= 0 || test24Array.get(pos).compareTo(test24Array.get(pos +1)) >= 0)
			//...test fails.
				System.err.println("Test 24 Failed: large set is not being sorted."); 
	
		
		}
	}
}

	


