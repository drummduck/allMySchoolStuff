package assignment9;

import junit.framework.TestCase;

public class TestPriorityQueue extends TestCase {
	
	public void testremoveMin()
	{
		PriorityQueueHEAP removeArray = new PriorityQueueHEAP();
		
		removeArray.add(22);
		removeArray.add(21);
		removeArray.add(30);
		removeArray.add(1);
		removeArray.add(10);
		removeArray.add(55);
		removeArray.add(63);
		removeArray.add(5);
		removeArray.add(21);
		removeArray.add(0);
		removeArray.add(357);
		removeArray.add(11);
		removeArray.add(6);
		
		removeArray.generateDotFile("heap1");
		
		
		assertEquals(removeArray.deleteMin(),0);
		
		assertEquals(removeArray.size(), 12);
		
		assertEquals(removeArray.deleteMin(),1);
		
		assertEquals(removeArray.size(), 11);
		
		assertEquals(removeArray.deleteMin(),5);
		
		assertEquals(removeArray.size(), 10);
		
		assertEquals(removeArray.deleteMin(),6);
		
		assertEquals(removeArray.size(), 9);
		
		assertEquals(removeArray.deleteMin(),10);
		
		assertEquals(removeArray.size(), 8);
		
		removeArray.generateDotFile("heap2");
		
		assertEquals(removeArray.deleteMin(),11);
		
		assertEquals(removeArray.size(), 7);
		
		assertEquals(removeArray.deleteMin(),21);
		
		assertEquals(removeArray.size(), 6);
		
		assertEquals(removeArray.deleteMin(),21);
		
		assertEquals(removeArray.size(), 5);
		
		assertEquals(removeArray.deleteMin(),22);
		
		assertEquals(removeArray.size(), 4);
		
		assertEquals(removeArray.deleteMin(),30);
		
		assertEquals(removeArray.size(), 3);
		
		assertEquals(removeArray.deleteMin(),55);
		
		assertEquals(removeArray.size(), 2);
		
		assertEquals(removeArray.deleteMin(),63);
		
		assertEquals(removeArray.size(), 1);
		
		assertEquals(removeArray.deleteMin(),357);
		
		assertEquals(removeArray.size(), 0);
		
		
		try{
			removeArray.deleteMin();
			fail();
		}
		catch (Exception e)
		{
			
		}
		
		PriorityQueueHEAP removeArray2 = new PriorityQueueHEAP();
		
		removeArray2.add(1);
		removeArray2.add(2);
		removeArray2.add(3);
		removeArray2.add(4);
		removeArray2.add(5);
		removeArray2.add(6);
		removeArray2.add(7);
		removeArray2.add(8);
		removeArray2.add(9);
		
		assertEquals(removeArray2.deleteMin(),1); 
		
		
		PriorityQueueHEAP removeArray3 = new PriorityQueueHEAP();
		
		removeArray3.add(1);
		removeArray3.add(4);
		removeArray3.add(3);
		
		assertEquals(removeArray3.deleteMin(),1);
		
		removeArray3.add(1);
		removeArray3.add(10);
		removeArray3.add(6);
		
		removeArray3.clear();
		
		assertEquals(removeArray3.size(),0);
		
	}
	
		//This is a basic involved test for the add method.
	public void testAdd1()
	{
		PriorityQueueHEAP/*<AnyType>*/ testAdd1 = new PriorityQueueHEAP/*<AnyType>*/();
			//Set a large item as a min to start with.
		testAdd1.add(99);
		
		assertTrue(testAdd1.array[0] == (Object) 99);
		
		testAdd1.add(80);
		
		assertTrue(testAdd1.array[0] == (Object) 80);
		assertTrue(testAdd1.array[1] == (Object) 99);
		
		assertTrue(testAdd1.currentSize == 2);
		
		testAdd1.add(70);
		
		assertTrue(testAdd1.array[0] == (Object) 70);
		assertTrue(testAdd1.array[2] == (Object) 80);
		assertTrue(testAdd1.array[1] == (Object) 99);
		
		testAdd1.add(149);
		
		assertTrue(testAdd1.array[0] == (Object) 70);
		assertTrue(testAdd1.array[2] == (Object) 80);
		assertTrue(testAdd1.array[1] == (Object) 99);
		//assertTrue(testAdd1.array[3] == (Object) 149);
		assertEquals(149, testAdd1.array[3]);
		
		testAdd1.add(90);
		
		assertEquals(70, testAdd1.array[0]);
		assertEquals(90, testAdd1.array[1]);
		assertEquals(80, testAdd1.array[2]);
		assertEquals(149, testAdd1.array[3]);
		assertEquals(99, testAdd1.array[4]);
		
			//add a new min.
		testAdd1.add(60);
		
		assertEquals(60, testAdd1.array[0]);
		assertEquals(90, testAdd1.array[1]);
		assertEquals(70, testAdd1.array[2]);
		assertEquals(149, testAdd1.array[3]);
		assertEquals(99, testAdd1.array[4]);
		assertEquals(80, testAdd1.array[5]);
		
		//add a duplicate min.	
		testAdd1.add(60);
		
		assertEquals(60, testAdd1.array[0]);
		assertEquals(90, testAdd1.array[1]);
		assertEquals(60, testAdd1.array[2]);
		assertEquals(149, testAdd1.array[3]);
		assertEquals(99, testAdd1.array[4]);
		assertEquals(80, testAdd1.array[5]);
		assertEquals(70, testAdd1.array[6]);
		
		testAdd1.add(130);
		
		assertEquals(60, testAdd1.array[0]);
		assertEquals(90, testAdd1.array[1]);
		assertEquals(60, testAdd1.array[2]);
		assertEquals(130, testAdd1.array[3]);
		assertEquals(99, testAdd1.array[4]);
		assertEquals(80, testAdd1.array[5]);
		assertEquals(70, testAdd1.array[6]);
		assertEquals(149, testAdd1.array[7]);
		
			//Add a new min
		testAdd1.add(50);
		
		assertEquals(50, testAdd1.array[0]);
		assertEquals(60, testAdd1.array[1]);
		assertEquals(60, testAdd1.array[2]);
		assertEquals(90, testAdd1.array[3]);
		assertEquals(99, testAdd1.array[4]);
		assertEquals(80, testAdd1.array[5]);
		assertEquals(70, testAdd1.array[6]);
		assertEquals(149, testAdd1.array[7]);
		assertEquals(130, testAdd1.array[8]);
		
		testAdd1.add(55);
		
		assertEquals(50, testAdd1.array[0]);
		assertEquals(55, testAdd1.array[1]);
		assertEquals(60, testAdd1.array[2]);
		assertEquals(90, testAdd1.array[3]);
		assertEquals(60, testAdd1.array[4]);
		assertEquals(80, testAdd1.array[5]);
		assertEquals(70, testAdd1.array[6]);
		assertEquals(149, testAdd1.array[7]);
		assertEquals(130, testAdd1.array[8]);
		assertEquals(99, testAdd1.array[9]);
		
			//Add a new min that requires doubling the size of the array.
		testAdd1.add(40);
		
		assertEquals(40, testAdd1.array[0]);
		assertEquals(50, testAdd1.array[1]);
		assertEquals(60, testAdd1.array[2]);
		assertEquals(90, testAdd1.array[3]);
		assertEquals(55, testAdd1.array[4]);
		assertEquals(80, testAdd1.array[5]);
		assertEquals(70, testAdd1.array[6]);
		assertEquals(149, testAdd1.array[7]);
		assertEquals(130, testAdd1.array[8]);
		assertEquals(99, testAdd1.array[9]);
		assertEquals(60, testAdd1.array[10]);
		
			//Add a negative value.
		testAdd1.add(-10);
		
		assertEquals(-10, testAdd1.array[0]);
		assertEquals(50, testAdd1.array[1]);
		assertEquals(40, testAdd1.array[2]);
		assertEquals(90, testAdd1.array[3]);
		assertEquals(55, testAdd1.array[4]);
		assertEquals(60, testAdd1.array[5]);
		assertEquals(70, testAdd1.array[6]);
		assertEquals(149, testAdd1.array[7]);
		assertEquals(130, testAdd1.array[8]);
		assertEquals(99, testAdd1.array[9]);
		assertEquals(60, testAdd1.array[10]);
		assertEquals(80, testAdd1.array[11]);
		
			//One more duplicate min
		testAdd1.add(-10);
		
		assertEquals(-10, testAdd1.array[0]);
		assertEquals(50, testAdd1.array[1]);
		assertEquals(-10, testAdd1.array[2]);
		assertEquals(90, testAdd1.array[3]);
		assertEquals(55, testAdd1.array[4]);
		assertEquals(40, testAdd1.array[5]);
		assertEquals(70, testAdd1.array[6]);
		assertEquals(149, testAdd1.array[7]);
		assertEquals(130, testAdd1.array[8]);
		assertEquals(99, testAdd1.array[9]);
		assertEquals(60, testAdd1.array[10]);
		assertEquals(80, testAdd1.array[11]);
		assertEquals(60, testAdd1.array[12]);
		
			//done.
	}
}
