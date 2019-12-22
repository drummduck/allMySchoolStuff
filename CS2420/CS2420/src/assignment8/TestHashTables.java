package assignment8;

import java.util.ArrayList;

import junit.framework.TestCase;

public class TestHashTables extends TestCase {

		//This is a quick fix!!!!
	private static final HashFunctor MediocreHashFunctor = new MediocreHashFunctor();
	
	private static final GoodHashFunctor GoodieHashFunctor = new GoodHashFunctor();

	public void testfunctors()
	{
		String hashstring = "azz";
		
		MediocreHashFunctor hashymcsashy = new MediocreHashFunctor();
		assertEquals(hashymcsashy.hash(hashstring), 341);
		
		BadHashFunctor hashybadsashy = new BadHashFunctor();
		assertEquals(hashybadsashy.hash(hashstring), 3);
		
	}
	
	public void testChain1()
	{
		ChainingHashTable testChain1 = new ChainingHashTable(10, MediocreHashFunctor);
		
		MediocreHashFunctor hashymcsashy = new MediocreHashFunctor();
		assertEquals(hashymcsashy.hash("A"), 65);
		
		testChain1.add("A");
		
		assertEquals(true, testChain1.storage[5].contains("A"));
		
		testChain1.add("0");
		
		assertEquals(true, testChain1.storage[8].contains("0"));
		
		testChain1.add("K");
		
		assertEquals(true, testChain1.storage[5].contains("K"));
		
		
	}
	
	public void testreHashchain()
	{
		
		
		ChainingHashTable testChain2 = new ChainingHashTable(1, MediocreHashFunctor);
		
		testChain2.add("A");
		testChain2.add("b");
		testChain2.add("C");
		testChain2.add("d");
		testChain2.add("E");
		//Testing for duplicates, should return false.
		assertEquals(testChain2.add("A"),false); 
		testChain2.add("f");
		testChain2.add("G");
		testChain2.add("h"); 
		testChain2.add("I");
		testChain2.add("j");
		//Testing a normal add, should return true.
		assertEquals(testChain2.add("K"), true);
		
		//Testing another duplicate.
		assertEquals(testChain2.add("I"), false);
		
		//Checking to see if size is what we want.
		assertEquals(testChain2.size(), 11);
		
		//Testing the clear method.
		testChain2.clear();
		assertEquals(testChain2.size(), 0);
		
		//Testing for size.
		assertEquals(testChain2.add("meow"),true);
		assertEquals(testChain2.size(), 1);
		
		testChain2.add("woof");
		testChain2.add("bowy-wowy-woof-woof");
		testChain2.add("moo-cow");
		testChain2.add("horses are terrible people");
		
		//Testing for large strings.
		assertEquals(testChain2.size(),5);
		assertEquals(testChain2.contains("moo-cow"),true);
		
		//Testing nextPrime method.
		assertEquals(testChain2.nextPrime(5), 11);
		
		assertEquals(testChain2.size(),5);
		//Testing isPrime method. 
		assertEquals(testChain2.isPrime(5), true);
		
		
	}
	
	//A basic test of the add method, written before any rehashing implementation.
	//THIS TEST WILL FAIL ONCE REHASHING IS IMPLEMENTED!!!
//public static void testQuadAdd1()
//{
//QuadProbeHashTable testQuadAdd1 = new QuadProbeHashTable(11, MediocreHashFunctor);
//
//	//first addition
//testQuadAdd1.add("A");
//	//assert that added item is in the correct position.
//assertEquals("A", testQuadAdd1.quadTable[10]);
//	//assert that size is being incremented correctly.
//assertEquals(1, testQuadAdd1.size);
//assertEquals((double)1/11, testQuadAdd1.lambda);
//	//second addition
//testQuadAdd1.add("k");
//assertEquals("k", testQuadAdd1.quadTable[8]);
//assertEquals(2, testQuadAdd1.size);
//assertEquals((double)2/11, testQuadAdd1.lambda);
//	//Third addition.
//testQuadAdd1.add("Q");
//assertEquals("Q", testQuadAdd1.quadTable[4]);
//assertEquals(3, testQuadAdd1.size);
//assertEquals((double)3/11, testQuadAdd1.lambda);
//	//Fourth addition.
//testQuadAdd1.add("1");
//assertEquals("1", testQuadAdd1.quadTable[5]);
//assertEquals(4, testQuadAdd1.size);
//assertEquals((double)4/11, testQuadAdd1.lambda);
//	//Fifth addition.
//testQuadAdd1.add("L");
//assertEquals("L", testQuadAdd1.quadTable[0]);
//assertEquals(5, testQuadAdd1.size);
//assertEquals((double)5/11, testQuadAdd1.lambda);
//	//Sixth addition.
//testQuadAdd1.add("m");		//this one must quad probe twice.
//assertEquals("m", testQuadAdd1.quadTable[3]);
//assertEquals(6, testQuadAdd1.size);
//assertEquals((double)6/11, testQuadAdd1.lambda);
//	//Seventh addition.
//testQuadAdd1.add("u");		
//assertEquals("u", testQuadAdd1.quadTable[7]);
//assertEquals(7, testQuadAdd1.size);
//assertEquals((double)7/11, testQuadAdd1.lambda);
//	//Eighth addition.
//testQuadAdd1.add("Y");		
//assertEquals("Y", testQuadAdd1.quadTable[1]);
//assertEquals(8, testQuadAdd1.size);
//assertEquals((double)8/11, testQuadAdd1.lambda);
//	//Ninth addition.
//testQuadAdd1.add("G");	//This one must probe 5 times	
//assertEquals("G", testQuadAdd1.quadTable[6]);
//assertEquals(9, testQuadAdd1.size);
//assertEquals((double)9/11, testQuadAdd1.lambda);
//	//Tenth addition.
//testQuadAdd1.add("x");	
//assertEquals("x", testQuadAdd1.quadTable[2]);
//assertEquals(10, testQuadAdd1.size);
//assertEquals((double)10/11, testQuadAdd1.lambda);
//////Eleventh addition.
////testQuadAdd1.add("8");																	//an addition of this manner will never			
////assertEquals("8", testQuadAdd1.quadTable[9]);				//actually happen, so we will not worry 
////assertEquals(11, testQuadAdd1.size);											//about it.
////assertEquals((double)11/11, testQuadAdd1.lambda);
//}

	//A basic test of the contains method, written before any rehashing implementation.
		//THIS TEST WILL FAIL ONCE REHASHING IS IMPLEMENTED!!!
//public static void testQuadContains1()
//{
//	QuadProbeHashTable testQuadContains1 = new QuadProbeHashTable(11, MediocreHashFunctor);
//
//	testQuadContains1.add("A");
//	assertEquals(true, testQuadContains1.contains("A"));
//	
//	testQuadContains1.add("Y");
//	assertEquals(true, testQuadContains1.contains("Y"));
//	
//	testQuadContains1.add("o");
//	assertEquals(true, testQuadContains1.contains("o"));
//	
//	testQuadContains1.add("7");
//	assertEquals(true, testQuadContains1.contains("7"));
//	
//		//Test for false return.
//	assertEquals(false, testQuadContains1.contains("n"));
//	
//	testQuadContains1.add("n");
//	assertEquals(true, testQuadContains1.contains("n"));
//	
//	testQuadContains1.add("M");		//This one will have to probe 3 times.
//	assertEquals(true, testQuadContains1.contains("M"));
//	
//	//Test for false return.
//	assertEquals(false, testQuadContains1.contains("v"));
//	
//	testQuadContains1.add("v");
//	assertEquals(true, testQuadContains1.contains("v"));
//	
//	//Test for false return.
//	assertEquals(false, testQuadContains1.contains("5"));
//	
//	testQuadContains1.add("5");		//This one will have to probe 3 times.
//	assertEquals(true, testQuadContains1.contains("5"));
//	
//	//Test for false return.
//	assertEquals(false, testQuadContains1.contains("c"));
//	
//	testQuadContains1.add("c");		//This one will have to probe 4 times.
//	assertEquals(true, testQuadContains1.contains("c"));
//	
//	//Test for false return.
//	assertEquals(false, testQuadContains1.contains("d"));
//	
//	testQuadContains1.add("d");		//This one will have to probe 4 times.
//	assertEquals(true, testQuadContains1.contains("d"));
//}
		//Tests multiple methods in the QuadhashTable.
	public static void testQuadRehash1()
	{
		QuadProbeHashTable testQuadRehash1a = new QuadProbeHashTable(4, MediocreHashFunctor);
			//HashTable should be resized to 11.
		assertEquals(11, testQuadRehash1a.trueCapacity);
	
		QuadProbeHashTable testQuadRehash1b = new QuadProbeHashTable(3, MediocreHashFunctor);
			//HashTable should not  be resized.
		assertEquals(3, testQuadRehash1b.trueCapacity);
	
			//Mostly testing this one.
		QuadProbeHashTable testQuadRehash1c = new QuadProbeHashTable(2, MediocreHashFunctor);
			//HashTable should be resized to 5.
		assertEquals(2, testQuadRehash1c.trueCapacity);
		
		testQuadRehash1c.add("9");
			assertEquals(2, testQuadRehash1c.trueCapacity);		//this should be here after rehashing
			assertEquals("9", testQuadRehash1c.quadTable[1]);  //9 = 57
			assertEquals(1, testQuadRehash1c.size);
			assertEquals((double)1/2, testQuadRehash1c.lambda);
		testQuadRehash1c.add("r");									//r = 114
			assertEquals("9", testQuadRehash1c.quadTable[2]);  //9 = 57
			assertEquals("r", testQuadRehash1c.quadTable[4]);  //r = 114
			assertEquals(5, testQuadRehash1c.trueCapacity);
			assertEquals(2, testQuadRehash1c.size);
			assertEquals((double)2/5, testQuadRehash1c.lambda);
		testQuadRehash1c.add("U");			//U = 85		
			assertEquals("9", testQuadRehash1c.quadTable[2]);  //9 = 57
			assertEquals("r", testQuadRehash1c.quadTable[4]);  //r = 114
			assertEquals("U", testQuadRehash1c.quadTable[0]); 	//U = 85
			assertEquals(5, testQuadRehash1c.trueCapacity);
			assertEquals(3, testQuadRehash1c.size);
			assertEquals((double)3/5, testQuadRehash1c.lambda);
		testQuadRehash1c.add("m");		//m = 109
			assertEquals(11, testQuadRehash1c.trueCapacity);
			assertEquals("U", testQuadRehash1c.quadTable[8]); 	//U = 85
			assertEquals("9", testQuadRehash1c.quadTable[2]);  //9 = 57
			assertEquals("r", testQuadRehash1c.quadTable[4]);  //r = 114
			assertEquals("m", testQuadRehash1c.quadTable[10]);  //m = 109
			assertEquals(11, testQuadRehash1c.trueCapacity);
				//Make sure contains works after rehashing.
			assertEquals(true, testQuadRehash1c.contains("U"));
			assertEquals(true, testQuadRehash1c.contains("9"));
			assertEquals(true, testQuadRehash1c.contains("r"));
			assertEquals(true, testQuadRehash1c.contains("m"));
			assertEquals(4, testQuadRehash1c.size);
			assertEquals((double)4/11, testQuadRehash1c.lambda);
		testQuadRehash1c.add("F");		//F = 70			//one collision.
			assertEquals("F", testQuadRehash1c.quadTable[5]);	//F = 70
			assertEquals(5, testQuadRehash1c.size);
			assertEquals((double)5/11, testQuadRehash1c.lambda);
		testQuadRehash1c.add("d");		//d = 100
			assertEquals("d", testQuadRehash1c.quadTable[1]);	//d = 100
			assertEquals(6, testQuadRehash1c.size);
			assertEquals((double)6/11, testQuadRehash1c.lambda); 
		testQuadRehash1c.add("t");			//t = 116		//rehash
			assertEquals(23, testQuadRehash1c.trueCapacity);
			assertEquals("d", testQuadRehash1c.quadTable[8]);	//d = 100
			assertEquals("9", testQuadRehash1c.quadTable[11]);  //9 = 57
			assertEquals("r", testQuadRehash1c.quadTable[22]);  //r = 114
					//THERE IS A PROBLEM HERE!!!!!
						//REVERSAL OF ORDER.
			assertEquals("F", testQuadRehash1c.quadTable[1]);	//F = 70		//one collision
			assertEquals("U", testQuadRehash1c.quadTable[16]); 	//U = 85
			assertEquals("m", testQuadRehash1c.quadTable[17]);  //m = 109
			assertEquals(7, testQuadRehash1c.size);
			assertEquals((double)7/23, testQuadRehash1c.lambda);
			assertEquals(true, testQuadRehash1c.contains("r"));
			assertEquals(true, testQuadRehash1c.contains("F"));
	}
	
	public void testquad()
	{
		//Short test for QuadProbeHashTable
		QuadProbeHashTable testQuad = new QuadProbeHashTable(1,MediocreHashFunctor);
		testQuad.add("A");
		testQuad.add("b");
		testQuad.add("C");
		assertEquals(testQuad.trueCapacity, 5);
		
	}
	
	public void testHashTable()
	{
		GoodHashFunctor goodFunctor = new GoodHashFunctor();
		HashTable testHashTable = new QuadProbeHashTable(10,goodFunctor);
		
		ArrayList hashTableArray = new ArrayList();
		
		hashTableArray.add("A");
		hashTableArray.add("B");
		hashTableArray.add("C");
		hashTableArray.add("D");
		hashTableArray.add("!");
		hashTableArray.add("6");
		hashTableArray.add("y");
		hashTableArray.add("s");
		hashTableArray.add("l");
		hashTableArray.add("U");
		hashTableArray.add("R");
		hashTableArray.add("B");
		hashTableArray.add("A");
		
		ArrayList hashTableArray2 = new ArrayList();
		
		hashTableArray2.add("A");
		hashTableArray2.add("B");
		hashTableArray2.add("C");
		hashTableArray2.add("D");
		hashTableArray2.add("!");
		hashTableArray2.add("6");
		hashTableArray2.add("y");
		hashTableArray2.add("s");
		hashTableArray2.add("l");
		hashTableArray2.add("U");
		hashTableArray2.add("R");
		
		ArrayList hashTableArray3 = new ArrayList();
		
		hashTableArray3.add("Pewpty-pewpty-pants");
		
		//Testing hashtable addall method.
			testHashTable.addAll(hashTableArray);
		assertEquals(testHashTable.size(), 11);
		//Testing contains on items that should be in this hashtable.
		assertEquals(testHashTable.containsAll(hashTableArray2),true);
		//Testing contains on items that shouldnt be in this hashtable.
		assertEquals(testHashTable.containsAll(hashTableArray3),false);
		
		assertEquals(testHashTable.isEmpty(),false);
		
		testHashTable.clear();
		//Testing hashtable isEmpty method.
		assertEquals(testHashTable.isEmpty(),true); 
	}
			//A test for the add method returning false when attempting to add a duplicate.
	public static void testQuadDuptlicate()
	{
		QuadProbeHashTable testQuadDuplicate = new QuadProbeHashTable(11, GoodieHashFunctor); 
	
		testQuadDuplicate.add("a");
		
		assertEquals(false, testQuadDuplicate.add("a"));
	}
		
	
		//Test reaching around a probe, and then the clear method.
	public static void testQuadReachAround()
	{
		QuadProbeHashTable testReachingAroundMyProbe = new QuadProbeHashTable(11, MediocreHashFunctor);
				//add to position 0.
		testReachingAroundMyProbe.add("!"); 		
			assertEquals("!", testReachingAroundMyProbe.quadTable[0]);
			
		testReachingAroundMyProbe.add(","); 		
			assertEquals(",", testReachingAroundMyProbe.quadTable[1]);
			
		testReachingAroundMyProbe.add("7"); 		
			assertEquals("7", testReachingAroundMyProbe.quadTable[4]);
			
		testReachingAroundMyProbe.add("B"); 		
			assertEquals("B", testReachingAroundMyProbe.quadTable[9]);
				//Now please perform a reach-around.
		testReachingAroundMyProbe.add("M"); 		
			assertEquals("M", testReachingAroundMyProbe.quadTable[5]);
			//Now please perform multiple reach-arounds.
		testReachingAroundMyProbe.add("X"); 		
			assertEquals("X", testReachingAroundMyProbe.quadTable[3]);
			
			//Now double the length the array.
		testReachingAroundMyProbe.add("l");
			assertEquals(23, testReachingAroundMyProbe.trueCapacity);
		
				//Now clear the table.
		testReachingAroundMyProbe.clear();
			assertEquals(0, testReachingAroundMyProbe.size);
			
			//Now make sure everything has been removed.
		assertEquals(false, testReachingAroundMyProbe.contains("!"));
		assertEquals(false, testReachingAroundMyProbe.contains(","));
		assertEquals(false, testReachingAroundMyProbe.contains("7"));
		assertEquals(false, testReachingAroundMyProbe.contains("B"));
		assertEquals(false, testReachingAroundMyProbe.contains("M"));
		assertEquals(false, testReachingAroundMyProbe.contains("X"));
		assertEquals(false, testReachingAroundMyProbe.contains("l"));
	}
}
