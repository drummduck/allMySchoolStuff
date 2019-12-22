package assignment6;

import java.io.File;
import java.util.ArrayList;
import java.util.Collection;
import java.util.NoSuchElementException;

import junit.framework.TestCase;

public class TestBST extends TestCase {

	protected void setUp() throws Exception {
		super.setUp();
	}

	protected void tearDown() throws Exception {
		super.tearDown();
	}

	
	public void testAddSize()
	{
		BinarySearchTree testAddSize = new BinarySearchTree();
		
		testAddSize.add(1);
		
		assertEquals(1, testAddSize.size());
			
				//SO FAR THIS TEST IS ONLY FILLING IN THE FIRST LEVEL UNDER THE ROOT,
					//IT IS DOING SO CORRECTLY ACCORDING TO THE DEBUGGER,
						//BUT MORE TESTING IS NEEDED TO MAKE SURE OUR SHIT IS BEING BUILT CORRECTLY.
		
		assertEquals(false, testAddSize.add(1));
			//Test for duplicate handling.
		assertEquals(1, testAddSize.size());
		
		assertEquals(true, testAddSize.add(2));
		assertEquals(2, testAddSize.size());
		
		assertEquals(false, testAddSize.add(2));
		assertEquals(2, testAddSize.size());
		
		assertEquals(true, testAddSize.add(0));
		assertEquals(3, testAddSize.size());
		
		assertEquals(false, testAddSize.add(0));
		assertEquals(3, testAddSize.size());
		
		testAddSize.add(4);
		assertEquals(4,testAddSize.size());
		
			//this sort of thing is illegal do to private shit, but I think the node class has a getter
				//method that might be usable for this kind of test.
		//assertEquals(2, testAddSize.root.right);
		
		assertEquals(false, testAddSize.add(2));
		assertEquals(4, testAddSize.size());
	}
	
	@SuppressWarnings("unchecked")
	public void testContains()
	{
		BinarySearchTree containstest = new BinarySearchTree();
		
		containstest.add(5);
		containstest.add(4);
		containstest.add(6);
		containstest.add(3);
		containstest.add(7);
		containstest.add(2);
		containstest.add(8);
		containstest.add(1);
		containstest.add(9);
		containstest.add(0);
		containstest.add(10);
		
		assertEquals(containstest.contains(1),true);
		assertEquals(containstest.contains(12), false);
		
		assertEquals(containstest.first(), 0);
		assertEquals(containstest.last(), 10);
		
		containstest.clear();
		assertEquals(containstest.isEmpty(), true);
		
		
		try
		{
			containstest.first();
			fail();
		}
		catch (Exception e)
		{
			
		}
		
		try
		{
			containstest.last();
			fail();
		}
		catch (Exception e)
		{
			
		}
		
		containstest.add(1);
		
		assertEquals(containstest.isEmpty(), false);
		
		assertEquals(containstest.remove(1), true);
		
		containstest.add(5);
		containstest.add(4);
		containstest.add(6);
		containstest.add(3);
		containstest.add(7);
		containstest.add(2);
		containstest.add(8);
		containstest.add(1);
		containstest.add(9);
		containstest.add(0);
		containstest.add(10);
		
		
		
		assertEquals(containstest.remove(8),true);
		assertEquals(containstest.remove(4), true);
		assertEquals(containstest.remove(2), true);
		
	}
	
//		//Test a larger tree.   THIS TEST ONLY WORKS OF NODE CLASS IS NOT PRIVATE.
//	public static void testAdd()
//	{
//		BinarySearchTree testAddBST = new BinarySearchTree();
//		
//		testAddBST.add(5);
//		testAddBST.add(3);
//		testAddBST.add(8);
//		testAddBST.add(2);
//		testAddBST.add(4);
//		testAddBST.add(7);
//		testAddBST.add(9);
//		testAddBST.add(1);
//		testAddBST.add(6);
//		testAddBST.add(10);
//		
//		assertEquals(10, testAddBST.size());
//		
//			//First level.
//		assertEquals(3, testAddBST.root.getLeft().data);
//		assertEquals(8, testAddBST.root.getRight().data);
//		
//			//Second Level.
//		assertEquals(2, testAddBST.root.getLeft().getLeft().data);
//		assertEquals(4, testAddBST.root.getLeft().getRight().data);
//		assertEquals(7, testAddBST.root.getRight().getLeft().data);
//		assertEquals(9, testAddBST.root.getRight().getRight().data);
//		
//			//Third level
//		assertEquals(1, testAddBST.root.getLeft().getLeft().getLeft().data);
//		assertEquals(6, testAddBST.root.getRight().getLeft().getLeft().data);
//		assertEquals(10, testAddBST.root.getRight().getRight().getRight().data);
//		
//	}
	
		//Test the clear method.
	public void testClear()
	{
		BinarySearchTree testClear = new BinarySearchTree();
		
		testClear.add(5);
		testClear.add(3);
		testClear.add(8);
		testClear.add(2);
		testClear.add(4);
		testClear.add(7);
		testClear.add(9);
		testClear.add(1);
		testClear.add(6);
		testClear.add(10);
		
		assertEquals(10, testClear.size());
		
		testClear.clear();
		
		assertEquals(0, testClear.size());
	}
	
	//Test the clear method.
	public void testClearAdd()
	{
		BinarySearchTree testClearAdd = new BinarySearchTree();
		
		testClearAdd.add(5);
		testClearAdd.add(3);
		testClearAdd.add(8);
		testClearAdd.add(2);
		testClearAdd.add(4);
		testClearAdd.add(7);
		testClearAdd.add(9);
		testClearAdd.add(1);
		testClearAdd.add(6);
		testClearAdd.add(10);
		
		assertEquals(10, testClearAdd.size());
		
		testClearAdd.clear();
		
		assertEquals(0, testClearAdd.size());
		
			//Now that we've cleared, rebuild the tree again.
		
		testClearAdd.add(5);
		testClearAdd.add(3);
		testClearAdd.add(8);
		testClearAdd.add(2);
		testClearAdd.add(4);
		testClearAdd.add(7);
		testClearAdd.add(9);
		testClearAdd.add(1);
		testClearAdd.add(6);
		testClearAdd.add(10);
		
		assertEquals(10, testClearAdd.size());
	}
	
	public static void testContains2()
	{
		BinarySearchTree testContains2= new BinarySearchTree();
		
		testContains2.add(5);
		testContains2.add(3);
		testContains2.add(8);
		testContains2.add(2);
		testContains2.add(4);
		testContains2.add(7);
		testContains2.add(9);
		testContains2.add(1);
		testContains2.add(6);
		testContains2.add(10);
		
		assertEquals(true, testContains2.contains(5));
		assertEquals(true, testContains2.contains(3));
		assertEquals(true, testContains2.contains(8));
		assertEquals(true, testContains2.contains(2));
		assertEquals(true, testContains2.contains(4));
		assertEquals(true, testContains2.contains(7));
		assertEquals(true, testContains2.contains(1));
		assertEquals(true, testContains2.contains(6));
		assertEquals(true, testContains2.contains(10));
		
	}
	
	
	
	@SuppressWarnings("unchecked")
	public void testRemove()
	{
		BinarySearchTree removeTestTree = new BinarySearchTree();
		ArrayList removeTestTreearray = new ArrayList();
		
		
		removeTestTree.add(20);
		removeTestTree.add(27);
		removeTestTree.add(9);
		removeTestTree.add(5);
		removeTestTree.add(2);
		removeTestTree.add(6);
		removeTestTree.add(16);
		removeTestTree.add(11);
		removeTestTree.add(10);
		removeTestTree.add(19);
		removeTestTree.add(17);
		
		
		removeTestTreearray.add(1);
		
		
		
		assertEquals(removeTestTree.size(), 11);
		
		removeTestTree.writeDot("testRemove");
		
		assertEquals(removeTestTree.remove(6), true);
		
		removeTestTree.writeDot("testRemove2");
		
		removeTestTree.add(6);
		
		assertEquals(removeTestTree.remove(19), true);
		
		removeTestTree.writeDot("testRemove3");
		
		removeTestTree.remove(17); 
		
		removeTestTree.writeDot("testRemove4");
		
		removeTestTree.add(19);
		removeTestTree.add(17);
		
		removeTestTree.writeDot("testRemove4");
		
		assertEquals(removeTestTree.remove(9), true);
		
		removeTestTree.writeDot("testRemove5");
		
		assertEquals(removeTestTree.remove(39), false);
	}
		//Test the first() method.
	public static void testFirst()
	{
		BinarySearchTree testFirst = new BinarySearchTree();
		
		testFirst.add(10);
		assertEquals(10, testFirst.first());
		
		testFirst.add(9);
		assertEquals(9, testFirst.first());
		
		testFirst.add(8);
		assertEquals(8, testFirst.first());
		
		testFirst.add(7);
		assertEquals(7, testFirst.first());
		
		testFirst.add(6);
		assertEquals(6, testFirst.first());
		
		testFirst.add(5);
		assertEquals(5, testFirst.first());
		
		testFirst.add(4);
		assertEquals(4, testFirst.first());
		
		testFirst.add(3);
		assertEquals(3, testFirst.first());
		
		testFirst.add(2);
		assertEquals(2, testFirst.first());
		
			//Clear the array.
		testFirst.clear();
		
		assertEquals(0, testFirst.size());
		
			//Test for the exception.
		try 
		{
			testFirst.first();
			fail();
		} 
		catch (NoSuchElementException e) 
		{}
	}
	
	public static void testContainsAll()
	{
		BinarySearchTree testContainsAll = new BinarySearchTree();
		
		ArrayList collection1 = new ArrayList();
		
		ArrayList collection2 = new ArrayList();
		
		ArrayList collection3 = new ArrayList();
		
		ArrayList collection4 = new ArrayList();
		
		
		testContainsAll.add(5);
		testContainsAll.add(3);
		testContainsAll.add(7);
		testContainsAll.add(2);
		testContainsAll.add(6);
		testContainsAll.add(9);
		testContainsAll.add(1);
		testContainsAll.add(4);
		testContainsAll.add(8);
		testContainsAll.add(10);
		
			//A collection entirely contained within the tree.
		collection1.add(4);
		collection1.add(1);
		collection1.add(7);
		collection1.add(2);
		
		assertEquals(true, testContainsAll.containsAll(collection1));
		
			//A collection with every item in tree.
		collection2.add(1);
		collection2.add(2);
		collection2.add(3);
		collection2.add(4);
		collection2.add(5);
		collection2.add(6);
		collection2.add(7);
		collection2.add(8);
		collection2.add(9);
		collection2.add(10);
		
		assertEquals(true, testContainsAll.containsAll(collection2));
		
			//A collection with both items contained and not contained by the tree.
		collection3.add(1);
		collection3.add(5);
		collection3.add(8);
		collection3.add(0);
		collection3.add(9);
		collection3.add(15);
		collection3.add(13);
		
		assertEquals(false, testContainsAll.containsAll(collection3));
		
			//A collection with no items contained by the tree.
		collection4.add(0);
		collection4.add(-2);
		collection4.add(12);
		collection4.add(21);
		collection4.add(99);
		collection4.add(34);
		collection4.add(344);
		collection4.add(334);
		collection4.add(354);
		collection4.add(3874);
		
		assertEquals(false, testContainsAll.containsAll(collection4));
		
			//Now test for the method throwing the appropriate NullPointerException.
		try 
		{
			testContainsAll.add(null);
			fail();
		} 
		catch (NullPointerException e)  
		{}
	}
	
		//Test for "add()" method throwing NullPointerException.
	public static void testAddException()
	{
		BinarySearchTree testAddException = new BinarySearchTree();
		
		try
		{
			testAddException.add(null);
			fail();
		}
		catch (NullPointerException e)
		{}
		
		Object nullzies = null;
		
		try
		{
			testAddException.add((Comparable) nullzies);
			fail();
		}
		catch (NullPointerException e)
		{}
	}
		
		//Test for "contains()" method throwing NullPointerException.
	public static void testContainsException()
	{
		BinarySearchTree testContainsException = new BinarySearchTree();
		
		try
		{
			testContainsException.contains(null);
			fail();
		}
		catch(NullPointerException e)
		{}
	}
	
		//Test "first()" and "last()" methods several times.
	public static void testFirstLast()
	{
		BinarySearchTree testFirstLast = new BinarySearchTree();
		
		testFirstLast.add(5);
			//Change
		assertEquals(5, testFirstLast.first());
		assertEquals(5, testFirstLast.last());
		
		testFirstLast.add(3);
			//Change
		assertEquals(3, testFirstLast.first());
		assertEquals(5, testFirstLast.last());
		
		testFirstLast.add(8);
			//Change
		assertEquals(3, testFirstLast.first());
		assertEquals(8, testFirstLast.last());
		
		testFirstLast.add(1);
			//Change
		assertEquals(1, testFirstLast.first());
		assertEquals(8, testFirstLast.last());
		
		testFirstLast.add(4);
			//No Change
		assertEquals(1, testFirstLast.first());
		assertEquals(8, testFirstLast.last());
		
		testFirstLast.add(7);
			//No Change
		assertEquals(1, testFirstLast.first());
		assertEquals(8, testFirstLast.last());
		
		testFirstLast.add(9);
			//Change
		assertEquals(1, testFirstLast.first());
		assertEquals(9, testFirstLast.last());
		
		testFirstLast.add(0);
			//Change
		assertEquals(0, testFirstLast.first());
		assertEquals(9, testFirstLast.last());
		
		testFirstLast.add(2);
			//No Change
		assertEquals(0, testFirstLast.first());
		assertEquals(9, testFirstLast.last());
		
		testFirstLast.add(6);
			//No Change
		assertEquals(0, testFirstLast.first());
		assertEquals(9, testFirstLast.last());
		
		testFirstLast.add(10);
			//Change
		assertEquals(0, testFirstLast.first());
		assertEquals(10, testFirstLast.last());
	}
	
	public void testAddAll()
	{
		BinarySearchTree testAddAll = new BinarySearchTree();
		
		ArrayList addAllList = new ArrayList();
		
		addAllList.add(5);
		addAllList.add(6);
		addAllList.add(7);
		addAllList.add(8);
		addAllList.add(9);
		addAllList.add(0);
		addAllList.add(1);
		addAllList.add(2);
		addAllList.add(3);
		addAllList.add(4);
		
		testAddAll.addAll(addAllList);
		
		testAddAll.writeDot("addAll");
		
		assertEquals(10, testAddAll.size());
	
		
	}
	
	public void testtoArray()
	{
		BinarySearchTree bleh = new BinarySearchTree();
		ArrayList toArrayTest = new ArrayList();
		
		 
		bleh.add(20);
		bleh.add(27);
		bleh.add(9);
		bleh.add(5);
		bleh.add(2);
		bleh.add(6);
		bleh.add(16);
		bleh.add(11);
		bleh.add(10);
		bleh.add(19);
		bleh.add(17);
		
		toArrayTest.add(2);
		toArrayTest.add(5);
		toArrayTest.add(6);
		toArrayTest.add(9);
		toArrayTest.add(10);
		toArrayTest.add(11);
		toArrayTest.add(16);
		toArrayTest.add(17);
		toArrayTest.add(19);
		toArrayTest.add(20);
		toArrayTest.add(27);
		
		ArrayList listsies = bleh.toArrayList();
		
		for(int pos = 0; pos <= toArrayTest.size()-1; pos++)
		{
			assertEquals(toArrayTest.get(pos).equals(listsies.get(pos)), true);
		} 
		
		 
		
	}
	
	public void testRemoveAll()
	{
		BinarySearchTree RemoveAlltest = new BinarySearchTree();
		ArrayList RemoveAllArray = new ArrayList();
		
		RemoveAllArray.add(11);
		RemoveAllArray.add(11);
		RemoveAllArray.add(2);
		RemoveAllArray.add(16);
		RemoveAllArray.add(19);
		
		
		RemoveAlltest.add(20);
		RemoveAlltest.add(27);
		RemoveAlltest.add(9);
		RemoveAlltest.add(5);
		RemoveAlltest.add(2);
		RemoveAlltest.add(6);
		RemoveAlltest.add(16);
		RemoveAlltest.add(11);
		RemoveAlltest.add(10);
		RemoveAlltest.add(19);
		RemoveAlltest.add(17); 
		
		
		assertEquals(RemoveAlltest.removeAll(RemoveAllArray), true);
		
		RemoveAlltest.writeDot("testRmoveAll");
		
		
	}
	
	public void testSpellcheckIn()
	{
		File dic = new File("dictionary.txt");
			//Make a new dictionary
		SpellCheckUtil checkInSpell = new SpellCheckUtil(dic);
		
		
		
		
		
		
	}
	
	
	
}
