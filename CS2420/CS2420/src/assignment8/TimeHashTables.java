package assignment8;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;
import java.util.TreeSet;

import assignment6.BinarySearchTree;

public class TimeHashTables {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {

		Random randy = new Random();
		
		  
		ArrayList words = new ArrayList();
		File dictionary = new File("RealDictionary.txt");
		Scanner s = new Scanner(dictionary);
		
		BadHashFunctor baddy = new BadHashFunctor();
		MediocreHashFunctor okee = new MediocreHashFunctor();
		GoodHashFunctor goody = new GoodHashFunctor();
		
		QuadProbeHashTable quadtester = new QuadProbeHashTable(1,okee);
		QuadProbeHashTable quadtester2 = new QuadProbeHashTable(1,baddy);
		QuadProbeHashTable quadtester3 = new QuadProbeHashTable(1,goody);
		
		ChainingHashTable chaintester = new ChainingHashTable(1,okee);
		ChainingHashTable chaintester2 = new ChainingHashTable(1,baddy);
		ChainingHashTable chaintester3 = new ChainingHashTable(1,goody);
		
		System.out.println("N\t\t" + "Time" + "\t" + "\t" + "Collisions");
		
		while(s.hasNext())
		{
			words.add(s.next());
		}
		
			//This loop is for timing sorted lists, 
				//since we get a stack overflow, with sorted lists
		long timesToLoop = 50;

		for (int N = 10000; N < 150000; N += 5000)
			//This loop is for timing permuted lists
		//for (int N = 1000; N < 20000; N += 500) 
			{
			long startTime, midpointTime, stopTime;	
			
			// First, spin computing stuff until one second has gone by.
			// This allows this thread to stabilize.
			startTime = System.nanoTime();

			while (System.nanoTime() - startTime < 1000000000) {
			} // empty block

			
//-----------------------------	THE DIVIDING LINE BETWEEN SPACE AND TIME!!!!-------------		
			
			startTime = System.nanoTime();
			
				//THIS LOOP TIMES(verb) WHAT IS BEING TIMED!!!
			for (long i = 0; i < timesToLoop; i++) 
			{	
				//Test fo good chain
				chaintester3.add((String)words.get(randy.nextInt(2000000)));
				//Test for bad chain
				//chaintester2.add((String)words.get(randy.nextInt(2000000)));
				//Test for mediocre chain
			//chaintester.add((String)words.get(randy.nextInt(2000000)));
				//Test for bad quad
				//quadtester2.add((String)words.get(randy.nextInt(2000000)));
					//Test for medicore quad
				//quadtester.add((String)words.get(randy.nextInt(2000000)));
				
			}
			midpointTime = System.nanoTime();

			// Run an empty loop to capture the cost of running the loop.
			for (long i = 0; i < timesToLoop; i++) 
			{
				//inOrderTree.addAll(inOrderList);
																// <----Subtracted from timing
					//Subtract for timing of contains() and remove() 		
			
			}

			stopTime = System.nanoTime();

			// Compute the time, subtract the cost of running the loop
			// from the cost of running the loop and computing square roots.
			// Average it over the number of runs.
			double averageTime = ((stopTime - startTime) - (stopTime - midpointTime));
					/// timesToLoop; 
			timesToLoop *= 1.5;
				//Clear our table so we will get accurate collision counting.
			
			System.out.println("N = " + N + "\t" + averageTime + "\t" + "\t" + chaintester3.collision() + "\t" + chaintester3.thiscapacity);
			//For chain good test.
			chaintester3 = new ChainingHashTable(1,goody);
			//For chain bad test.
			//chaintester2 = new ChainingHashTable(1,baddy);
			//For chain mediocre test
			//chaintester = new ChainingHashTable(1,okee);
				//For quad bad test.
			//quadtester2 = new QuadProbeHashTable(1, baddy);
				//For quad medicore test
			//quadtester = new QuadProbeHashTable(1, okee);
			
		}
	} // <-------- main
	
//	/**
//	 * Generates the AverageCase (permuted ArrayList) for input into sorting algorithms. 
//	 * @param size the size of the returned ArrayList
//	 * @return An ArrayList of random integers from 0-size(-1) in permuted order
//	 */
//	public static ArrayList<Integer> generateAverageCase(int size)
//	{
//			//Keep track of the random index of insertion.
//		int randomIndex = 0;
//			//keep track of the item to be swapped.
//		int holder = 0;
//		
//			//Make a random number generator.
//		Random averageRandy = new Random();
//		
//		ArrayList<Integer> temp = new ArrayList<Integer>();
//		
//			//Fill temp array with sequentially ascending values.
//		for(int pos = 0; pos < size-1; pos++)
//		{
//			temp.add(pos);
//		}
//			//Now permute temp.
//		for(int randyPos =0; randyPos < size-1; randyPos ++)
//		{
//				//Generate a random index between 0 and "size" -1.
//			randomIndex = averageRandy.nextInt((size-1)-0) +0;
//			
//			//Now swap the value at the current "randyPos" with the value at "randomIndex".
//				//Set "holder" to item at randomIndex.
//			holder = temp.get(randomIndex);
//				//Put the value at "randyPos" in "randomIndex".
//			temp.set(randomIndex, temp.get(randyPos));
//				//Now put the stored value in "holder" in the current randyPos.
//			temp.set(randyPos, holder);
//		}
//			//Return permuted List.
//		return temp;	
//	}
}
