package assignment4;

import java.util.ArrayList;
import java.util.Random;

public class TimeSortUtil { 

	/**
	 * @param args
	 */
	  public static void main(String[] args) 
	  {		//"theEnd" is subject to immediate change without notice.
		  for(int theEnd = 10000; theEnd < 250000; theEnd += 10000)
		  {
	    long startTime, midpointTime, stopTime;

	    	// First, spin computing stuff until one second has gone by.
	    		// This allows this thread to stabilize.
	    startTime = System.nanoTime();
	    
	    while (System.nanoTime() - startTime < 1000000000) 
	    {} // empty block   

	    	// Now, run the test.
	    long timesToLoop = 100;

	    startTime = System.nanoTime();

	    for (long i = 0; i < timesToLoop; i++)
	    {
	      
	    	SortUtil.quicksort(SortUtil.generateBestCase(theEnd));  //<---- TO BE TIMED.
	    }

	    midpointTime = System.nanoTime();

	    // Run an empty loop to capture the cost of running the loop.
	    for (long i = 0; i < timesToLoop; i++) 
	    {
	    	SortUtil.generateBestCase(theEnd);		//<----Subtracted from timing.
	    } 

	    stopTime = System.nanoTime();

	    // Compute the time, subtract the cost of running the loop
	    // from the cost of running the loop and computing square roots.
	    // Average it over the number of runs.
	    double averageTime = ((midpointTime - startTime) - (stopTime - midpointTime)) / timesToLoop;

	    System.out.println(averageTime);
	  
	  }
	}		//<-------- main
}
