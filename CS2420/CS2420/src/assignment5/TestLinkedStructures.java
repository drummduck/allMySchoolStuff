package assignment5;

import java.util.NoSuchElementException;

import junit.framework.TestCase;

public class TestLinkedStructures extends TestCase {

	protected void setUp() throws Exception {
		super.setUp();
	}

	protected void tearDown() throws Exception {
		super.tearDown();
	}

	
	public static void testSize()
	{
		MyLinkedList<Integer> list = new MyLinkedList<Integer>();
		assertEquals(list.size(), 0);
	}
	
	public static void testGetFirstException()
	{
		MyLinkedList<Integer> listTestException = new MyLinkedList<Integer>();
		
		try{
			listTestException.getFirst();
			fail();
		}
		catch(NoSuchElementException e)
		{}
	}
	
	public static void testGetLastException()
	{
		MyLinkedList<Integer> listTestException = new MyLinkedList<Integer>();
		
		try{
			listTestException.getLast();
			fail();
		}
		catch(NoSuchElementException e)
		{}
	}
	
		//This test tests the addFirst, size, clear, and isEmpty methods.
	public static void testSize2()
	{
		MyLinkedList<Integer> listTestAddFirst = new MyLinkedList<Integer>();
		
		listTestAddFirst.addFirst(1);
		listTestAddFirst.addFirst(1);
		listTestAddFirst.addFirst(1);
		listTestAddFirst.addFirst(1);
		
		assertEquals(listTestAddFirst.size(), listTestAddFirst.size);
		
		listTestAddFirst.clear();
		
		assertEquals(listTestAddFirst.size(), listTestAddFirst.size);
		
		assertEquals(listTestAddFirst.isEmpty(), listTestAddFirst.size == 0);
		
		listTestAddFirst.addFirst(0);
		
		assertEquals(false, listTestAddFirst.isEmpty());
	}
			
		//These test the exception thrown by add() only.
	public static void testAdd()
	{
		MyLinkedList addTestList = new MyLinkedList();
		try
		{
			addTestList.add(56, 0);
			fail();
		}
		catch(IndexOutOfBoundsException e)
		{}
		
		try
		{
			addTestList.add(-1, 0);
			fail();
		}
		catch(IndexOutOfBoundsException e)
		{}
	}
	
	
	public static void testAddLast()
	{
		MyLinkedList addLastTest = new MyLinkedList();
		
		addLastTest.addLast(0);
		
		assertEquals(addLastTest.get(0), 0);
		addLastTest.addLast(1);
		assertEquals(addLastTest.get(1), 1);
		addLastTest.addLast(2);
		assertEquals(addLastTest.get(2), 2);
		addLastTest.addLast(3);
		assertEquals(addLastTest.get(3), 3);
		addLastTest.addLast(4);
		assertEquals(addLastTest.get(4), 4);
	}
		//Tests the "add(index, element)" method, so that it will work.
	public static void testAdd2()
	{
		MyLinkedList addTest = new MyLinkedList();
		
		assertEquals(addTest.size(), 0);
			//Add zero to the position 0;		//[0]
		addTest.add(0, 0);		//First addition, size = 1
				
			//Add 2 to position 0.	//[2,0]
		addTest.add(0,2);		//Second addition, size = 2
				
			//Add 1 to position 1.		//[2,1,0] 
		addTest.add(1, 1);						//Third addition, size = 3
		
			 //size = 3
		assertEquals(2, addTest.get(0));
		
		assertEquals(1, addTest.get(1));		//[2,1,0] 
		
		assertEquals(0, addTest.get(2));
			//Add 3 to last position.
		addTest.addLast(3);			//[2,0,1,3]			//Fourth addition, size = 4.
			
		assertEquals(addTest.get(3), 3);
		
			//Add 4 to the current last position in the list, 
							//once this item has been added, 
								//this position (position 3) will no longer be the last position in the list.
		addTest.add(3, 4);  		//[2,0,1,4,3]	//fifth addition, size = 5
		
		assertEquals(4, addTest.get(3));
		assertEquals(3, addTest.getLast());
		
		addTest.add(3, 33);	//[2,0,1,33,4,3]		//sixth addition size = 6
		
		assertEquals(33, addTest.get(3));
		assertEquals(4, addTest.get(4));
				//assert that get(last position in the list) & getLast() are doing the same thing.
		assertEquals(3, addTest.get(5));
		assertEquals(3, addTest.getLast());
		
		//[2,0,1,33,3,4,5]	
			//Add to position at size.
		addTest.add(6, 5);						//seventh addition, size = 7
		
		assertEquals(7, addTest.size());
		
		assertEquals(5, addTest.getLast());
		
		assertEquals(2, addTest.getFirst());
	}
	
	public static void testRemoveFirst()
	{
		MyLinkedList removeFirstTest = new MyLinkedList();
		
		removeFirstTest.addFirst(3);
		removeFirstTest.addFirst(2);
		removeFirstTest.addFirst(1);
		removeFirstTest.addFirst(0);
		
		removeFirstTest.removeFirst();
		assertEquals(1, removeFirstTest.get(0));
		
		removeFirstTest.removeFirst();
		assertEquals(2, removeFirstTest.get(0));
		
		removeFirstTest.removeFirst();
		assertEquals(3, removeFirstTest.get(0));
			//remove the last item in the list.
		
			//Assert last removal returns 3
		assertEquals(removeFirstTest.removeFirst(),3);
		
		assertEquals(removeFirstTest.size(), 0);
		
				//Now test exception.
		try
		{
			removeFirstTest.removeFirst();
			fail();
		}
			//If exception is not thrown, test fails.
		catch(NoSuchElementException e)
		{}
	}
	
	
	public static void testRemove()
	{
			//create a MyLinkedList
		MyLinkedList removeTest = new MyLinkedList();
		
			//add various items to removetest.
		removeTest.addFirst(2);
		removeTest.addFirst(13);
		removeTest.addFirst(91);
		removeTest.addFirst(1);
		
			//remove second item in linked list.
		removeTest.remove(1);
		
		assertEquals(removeTest.get(1),13);
		
			//remove first item in linked list.
		removeTest.remove(0);
		
		assertEquals(removeTest.get(0), 13);
		
		try
		{
			removeTest.remove(5000);
			fail();
		}
			//If exception is not thrown, test fails.
		catch(IndexOutOfBoundsException e)
		{}
		
		removeTest.remove(0);
		
		assertEquals(removeTest.get(0), 2);
		
		assertEquals(removeTest.remove(0), 2);
		
		
		assertEquals(removeTest.size(), 0);
		assertEquals(removeTest.size, 0);
		
		try
		{
			removeTest.remove(0);
			fail();
		}
			//If exception is not thrown, test fails.
		catch(IndexOutOfBoundsException e)
		{}
		
		
		
	}
	
	
		//This test also tests "getLast()" method.
	public static void testRemoveLast()
	{
		MyLinkedList removeLastTest = new MyLinkedList();
		
		removeLastTest.addLast(0);
		removeLastTest.addLast(1);
		removeLastTest.addLast(2);
		removeLastTest.addLast(3);
		
		removeLastTest.removeLast();
		assertEquals(2, removeLastTest.getLast());
		
		removeLastTest.removeLast();
		assertEquals(1, removeLastTest.getLast());
		
		removeLastTest.removeLast();
		assertEquals(0, removeLastTest.getLast());
		
		 
		assertEquals(removeLastTest.removeLast(), 0);
			//Now test exception.
		try
		{
			removeLastTest.removeLast();
				//If exception is not thrown, test fails.
			fail();
		}
		catch(NoSuchElementException e)
		{}
	}
	
	
		//This test will test everything except the indexOf methods.
	public static void testManyMethods()
	{
		MyLinkedList manyTests = new MyLinkedList();
		
		assertEquals(0, manyTests.size());
		
		manyTests.add(0, "first");
		
		assertEquals(1, manyTests.size());
		
		assertEquals("first", manyTests.getFirst());
		assertEquals("first", manyTests.getLast());
			//Test for a list that has different types of objects in it.
		manyTests.addLast(0);
		
		assertEquals(2, manyTests.size());
		
		assertEquals(0, manyTests.getLast());
			//[true, "first", 0]
		manyTests.addFirst(true);
		
		assertEquals(3, manyTests.size());
		
		assertEquals(true, manyTests.getFirst());
			//[true, 3.14, "first", 0]
		manyTests.add(1, 3.14);
		
		assertEquals(3.14, manyTests.get(1));
			//[3.14, "first", 0]
		manyTests.remove(0);
		
		assertEquals(3.14, manyTests.getFirst());
			//[3.14, "first", 0, 'c']
		//manyTests.add(manyTests.size()-1 , 'c');	//NOT ADDING TO THE LAST POSITION, needs resolution.
		manyTests.addLast('c');
		
		assertEquals(4, manyTests.size());
		
		assertEquals(3.14, manyTests.get(0));
		assertEquals("first", manyTests.get(1));
		assertEquals(0, manyTests.get(2));
		assertEquals('c', manyTests.get(3));
	}
	
	
	public static void testIndexOf()
	{
		MyLinkedList indexOfTest = new MyLinkedList();
		
		indexOfTest.addFirst(0);
		indexOfTest.addFirst(1);
		indexOfTest.addFirst(2);
		indexOfTest.addFirst(3);
		indexOfTest.addFirst(4);
		indexOfTest.addFirst(5);
		indexOfTest.addFirst(6);
		
		assertEquals(indexOfTest.get(4), 2);
		
		assertEquals(indexOfTest.indexOf(10),-1);
		
		indexOfTest.addFirst(2);
		
		assertEquals(indexOfTest.lastIndexOf(2),5);
	}
	
		//Test the "toArray()" along with a few other methods.
	public static void testToArray()
	{
		MyLinkedList toArrayTest = new MyLinkedList();
		Object[] Array = {6,5,4,3,2,1,0};
		
		toArrayTest.addFirst(0);
		toArrayTest.addFirst(1);
		toArrayTest.addFirst(2);
		toArrayTest.addFirst(3);
		toArrayTest.addFirst(4);
		toArrayTest.addFirst(5);
		toArrayTest.addFirst(6);	//Size == 7, last position == 6;
		
		assertEquals(7, toArrayTest.size());
		
		Object[] toArrayTestArray = toArrayTest.toArray();

		for(int pos = 0; pos < toArrayTestArray.length; pos++)
		{
			assertEquals(Array[pos],toArrayTestArray[pos]);
		}
//			//Setup of comparison for string representation of expected and actual strings.
//		String returnedArrayString = toArrayTest.toArray().toString();
//		String expectedArrayString = Array.toString();
//		
//		assertEquals(expectedArrayString, returnedArrayString);
		
		//Now clear the linked list to test for a case 
			//when the "toArray()" method returns an empty array.
		toArrayTest.clear();
			//Check for "clear()" method working.
		assertEquals(0, toArrayTest.size());
		
		Object[] clearedToArray = toArrayTest.toArray();
		
		assertEquals(0, clearedToArray.length);
	}
	
	public static void testAdd3()
	{
		MyLinkedList addTest3 = new MyLinkedList();
		
		addTest3.addFirst(0);
		
		addTest3.add(1, 1);
		
		assertEquals(2, addTest3.size());
		
		addTest3.add(2, 2);		//[0,1,2]
		
		assertEquals(3, addTest3.size());
		
		addTest3.add(2, "This should be at index 2");
		
		assertEquals("This should be at index 2", addTest3.get(2));
	} 
	
		//Tests for a variety of situation in which the "get()" method will
			//throw an index out of bounds exception.
	public static void testGetOutOfBounds()
	{
		MyLinkedList getOutOfBoundsTest = new MyLinkedList();
		
		getOutOfBoundsTest.addFirst(0);
		
		getOutOfBoundsTest.add(1, 1);
		
		getOutOfBoundsTest.add(2, 2);		//[0,1,2]
		
		getOutOfBoundsTest.add(2, "This should be at index 2");		//size == 4
		
		assertEquals("This should be at index 2", getOutOfBoundsTest.get(2));
		
			//Now test for exception in multiple ways.
		try
		{		//Out of  bounds to the left by 1.
			getOutOfBoundsTest.get(-1);
			fail();
		}
		catch(IndexOutOfBoundsException e)
		{}
		
		try
		{		//Out of  bounds to the left by more than 1.
			getOutOfBoundsTest.get(-2);
			fail();
		}
		catch(IndexOutOfBoundsException e)
		{}
		
		try
		{		//Out of  bounds to the left by an unholy amount.
			getOutOfBoundsTest.get(-666);
			fail();
		}
		catch(IndexOutOfBoundsException e)
		{}
		
		try
		{		//Out of  bounds to the right by 1.
			getOutOfBoundsTest.get(4);
			fail();
		}
		catch(IndexOutOfBoundsException e)
		{}
		
		try
		{		//Out of  bounds to the right by more than 1.
			getOutOfBoundsTest.get(5);
			fail();
		}
		catch(IndexOutOfBoundsException e)
		{}
		
		try
		{		//Out of  bounds to the right by an unholy amount.
			getOutOfBoundsTest.get(666);
			fail();
		}
		catch(IndexOutOfBoundsException e)
		{}
	}
	
		//Test for an instance of "get()" method calling "getLast()" method.
	public static void testGetCallsGetLast()
	{
		MyLinkedList getCallsGetLastTestList = new MyLinkedList();

		getCallsGetLastTestList.addFirst(0);
		
		getCallsGetLastTestList.add(1, 1);
		
		getCallsGetLastTestList.add(2, 2);		//[0,1,2] size == 3
		
		assertEquals(2, getCallsGetLastTestList.get(getCallsGetLastTestList.size() -1)); 
	}
	
		//Test for "removeFirst()" method throwing NoSuchElementException. 
	public static void testRemoveFirstNoSuchElement()
	{
		MyLinkedList removeFirstNoSuchElementList = new MyLinkedList();
		
		assertEquals(0, removeFirstNoSuchElementList.size());	//size == 0
		
			//Test for exception by attempting to remove the 
					//first item from an empty list.
		try 
		{
			removeFirstNoSuchElementList.removeFirst();
			fail(); 
		} 
		catch (NoSuchElementException e)
		{}
	}

	
		//Test for "removeLast()" method throwing NoSuchElementException. 
	public static void testRemoveLastNoSuchElement()
	{	
		MyLinkedList removeLastNoSuchElementList = new MyLinkedList();
	
		assertEquals(0, removeLastNoSuchElementList.size());	//size == 0
	
			//Test for exception by attempting to remove the 
				//first item from an empty list.
		try 
		{
			removeLastNoSuchElementList.removeLast();
			fail(); 
		} 
		catch (NoSuchElementException e)
		{}
	}

		//Test "indexOf()" method for positive case.
	public static void testIndexOf2()
	{
		MyLinkedList indexOfTestList = new MyLinkedList();

		indexOfTestList.addFirst(0);
		
		indexOfTestList.add(1, 1);
		
		indexOfTestList.add(2, 2);		//[0,1,2] size == 3
		
			//Position 1and 3 both have a value of 1.
		indexOfTestList.add(3, 1);		//[0,1,2, 1] size == 4
		
		assertEquals(1, indexOfTestList.indexOf(1));
	}
	
	//Need more testing for toArray();
	
}		//<---- last brace.


