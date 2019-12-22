package assignment4;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Random;

/**
 * @author Nathan Donaldson & Michael Fleming.
 * 
 */
public class SortUtil 
{	
	private static int threshold = 20;
	
	/**
	 * Helper insertion sort method.  
	 * @param arr - input ArrayList of objects
	 * @param left - start of the subarray 
	 * @param right - end of the subarray
	 */
	private static <T extends Comparable<? super T>> void insertionsort(ArrayList<T> arr, int left, int right)
	{
	  
	  /*Object*/T holder = null;
	  			T holder2 = null;
	  			T holder3 = null;
	
	  		//Walk through "data" again.
	  for(int leftsies = left; leftsies < right; leftsies++)  		
	  {		//If the item at the current position is greater than the item one position over...
		  		//System.out.println(cmp.compare(toBeSorted.get(pos),toBeSorted.get(pos+1)))
		  
		  if(arr.get(leftsies).compareTo(arr.get(leftsies + 1)) > 0)  
		  {		//Store the item to be moved.
			  holder = arr.get(leftsies);
			  	//Move the lesser value over to the left by one position.
			  arr.set(leftsies, arr.get(leftsies +1));		
			  	//Insert the stored item to the right by one position.	
			  arr.set(leftsies+1, holder);																																																
		  }
		  		//Now walk backwards through the Arraylist..
		  for(int pos2 = leftsies; pos2 >= 1; pos2--)  
		  {
			  //if the switched item is less than the item before it...
			  if(arr.get(pos2).compareTo(arr.get(pos2-1)) < 0)
			  {
				  
				  holder2 = arr.get(pos2);
			  holder3 = arr.get(pos2-1);
				  
				  
			  //switch again...
				  arr.set(pos2-1,holder2);
				  
				  arr.set(pos2,holder3);
			  }
		  }
	  }
	}
	
	/**
	 * MergSort algorithm driver.
	 * @param arr - input ArrayList of objects
	 */
	public static <T extends Comparable<? super T>> void mergesort(ArrayList<T> arr)
	{
			//Create copy of argument ArrayList
		ArrayList<T> tmpArray =  new ArrayList<T>();
		
			//mergesort the temporary ArrayList
		mergesort( arr, tmpArray, 0, arr.size() -1 );
		
		
	}
		
	/**
	 * Main mergeSort method. Makes recursive calls. 
	 * @param arr - input ArrayList of objects
	 * @param temp - temporary ArrayList to hold the merged result 
	 * @param left - start of the subarray 
	 * @param right - end of the subarray
	 */
	private static <T extends Comparable<? super T>> void mergesort(ArrayList<T> arr, ArrayList<T> temp, int left, int right)
	{
	
		int splitIndex = 0; 
		

		
			
					//split in half, but splt is determined by left and right.
									//The first split, left 0, and right will be .size() --> split at /2
	
			//if the size of the subarray being sent in is less than the threshold,
				//just call insertionsort method.
			if(left + right < threshold) 
				 insertionsort(arr,left,right); 
			else
			{
				//if array has 2 items...
			  if (left < right)
			 {
				 //	Determine where to split the array.
			 splitIndex = ( left + right ) / 2;
			 		//Pass the left half back into "mergesort".
			 mergesort( arr, temp, left, splitIndex );			
			 		//Pass the right half back into "mergesort".
			 mergesort( arr, temp, splitIndex+1, right );
			 		//Call "merge" on the two subbarrays.
			 merge( arr, temp, left, right ); 
			 
			
			 }
			}
			

			 
			 
	}

	/**
	 * Internal method for merging two storted subarrays
	 * @param arr - input ArrayList of objects
	 * @param temp - temporary ArrayList in  which the result with be placed
	 * @param left - start of the subarray 
	 * @param right - end of the subarray
	 */
	private static <T extends Comparable<? super T>> void merge(ArrayList<T> arr, ArrayList<T> temp, int left, int right)
	{	//keeps track of where left iteration is currently at.
		int leftIndex = left;
		//keeps track of where right iteration is currently at.
		int rightIndex = ((left + right)/2)+1;  
		//keeps track of the split between the two arrays.
		int mid = rightIndex-1;
		
		
		
		
		
		
		
			//while the left index is less than or equal to the middle and while the right index
			// is less than or equal to the end of the subarray....
		while(leftIndex <= mid && rightIndex <= right)   
		{		
			// if the subarray only contains 2 items...
			if((right - left) == 1)
			{
				//break out of the while loop.
				break;
			}
			
			
			
			//if the leftIndex object is less than the rightIndex object.
			if(arr.get(leftIndex).compareTo(arr.get(rightIndex)) < 0)
			{		
				//..then add the item at the leftIndex to the temp ArrayList.
					temp.add(arr.get(leftIndex));
					//increment leftIndex;
					leftIndex++;
				
				
				
			
					
			}	//If we have duplicates at both of the current indices...
			else if(arr.get(leftIndex).compareTo(arr.get(rightIndex)) == 0) 
			{		//... then add both of the current items at both of the current indices to the 
						//temporary array.
				temp.add(arr.get(leftIndex));
				temp.add(arr.get(rightIndex));
				//increment leftIndex
					leftIndex ++;
				//increment rightIndex
					rightIndex ++;
				
				
			}
				//Else if the item at the leftIndex is less than the item at 
					//the rightIndex....
			else 
			{		
				//add the object at rightIndex to temp.
				temp.add(arr.get(rightIndex));
				//increment rightIndex.
					rightIndex ++;
				
			}
			 
			 
			
			
		}
		//if the rightIndex goes past the end of the subarray...
		 if(rightIndex > right)
		 {
			 //add the rest of the left subarray to temp until it is past the middle.
			 while(leftIndex <= mid)
			 {
				 temp.add(arr.get(leftIndex));
				 leftIndex++;
			 } 
		 }
		 //if the leftIndex goes passed the end of the middle...
		 if(leftIndex > mid)
		 {
			 //add the rest of right subarray to temp until it is past the end of the subbaray.
			 while(rightIndex <= right)
			 {
				 temp.add(arr.get(rightIndex));
				 rightIndex++;
			 }
		 }
		
		//This is for the case of ArrayLists of size 2.
		 	//While the ArrayList stays at length 1....
		while((right - left) == 1)
		{
			
			//if the left object is less than the right object...
		if(arr.get(left).compareTo(arr.get(right)) < 0)
		{
			//add left first to temp and then right.
			temp.add(arr.get(left));
			temp.add(arr.get(right));
			right++;
		}
		//else if the two object equal....
		else if(arr.get(left).compareTo(arr.get(right)) == 0)
		{
			//add both of them to temp.
			temp.add(arr.get(left));
			temp.add(arr.get(right));
			right++;
		}
		//else....
		else
		{
			//add right first to temp and then add left.
			temp.add(arr.get(right));
			temp.add(arr.get(left));
			right++;
		}
		
		}
	
		
		
	
		
			
			//Now add each item from "temp" into "arr". 
		for(int pos = 0; pos <= temp.size()-1; pos++) 
		{
			arr.set(pos+left, temp.get(pos));
		}
			//Clear the temporary array.
		temp.clear();
	}
		
	
	/**
	 * Quicksort algorithm driver
	 * @param arr - input ArrayList of objects
	 */
	public static <T extends Comparable<? super T>> void quicksort(ArrayList<T> arr)
	{
		//sends the ArrayList into quicksort to be sorted.
		quicksort(arr,0,arr.size()-1);	
	}

	/**
	 * Main quicksort method. Makes recursive calls. 
	 * @param arr - input ArrayList of objects. 
	 * @param left - start of the subarray 
	 * @param right - end of the subarray
	 */
	public static <T extends Comparable<? super T>> void quicksort(ArrayList<T> arr, int left, int right)
	{
		//if the size of the ArrayList is less than the threshold...
		if(left + right < threshold) 
			//call insertion sort on arr.
			 insertionsort(arr,left,right);
		
		//else...
				  // If the list has at least 2 items....
		else
			if(left < right)
			      {
			 
			        //pick a pivot by calling a pivot strategy method.
			      int pivotint = pivotStrategy2(arr,left,right);
					
			 
			          // Get lists of bigger and smaller items and final position of pivot.
			          int pivotNewIndex = partition(arr, left, right, pivotint);
			 
			          // Recursively sort elements smaller than the pivot
			          quicksort(arr, left, pivotNewIndex - 1);
			 
			          // Recursively sort elements at least as big as the pivot
			          quicksort(arr, pivotNewIndex + 1, right);
			      }
	}
	
	
	/**
	 * partition method.partition's the array and finds new pivot. 
	 * @param arr - input ArrayList of objects. 
	 * @param left - start of the subarray 
	 * @param right - end of the subarray
	 * @param pivotIndex - the index of the current pivot.
	 */
	public static <T extends Comparable<? super T>> int partition(ArrayList<T> arr, int left, int right, int pivotIndex)
	{
		//set a variable to a value at the current pivot.
    T pivotValue = arr.get(pivotIndex);
 
    //switch the pivot and the object at the end of the array.
    arr.set(pivotIndex, arr.get(right));
    arr.set(right, pivotValue);
   
    //keep track of the number of inversions and where they are.
   int storeIndex = left;
   //create object storeval to be used as a holder.
   T storeval;
   //compare each item in the array (excluding the pivot) to the pivot.
    for (int i = left;  i < right; i++) 
    {
    	//get value of item that may have to be switched.
    	storeval = arr.get(storeIndex);
    	//if the value at i is less than the pivotValue.....
        if (arr.get(i).compareTo(pivotValue) <= 0)
        {
        	//swap the items at i and storeIndex.
    		arr.set(storeIndex, arr.get(i));
   			arr.set(i, storeval);
        	
   			//increment the inversion tracker.
            storeIndex++;
        }   

          
    }
    
    //switch the pivot with the new pivot.
    T holder2 = arr.get(storeIndex);
    arr.set(storeIndex, arr.get(right));
    arr.set(right,holder2);
              
    //return new pivot.
            return storeIndex;
	}

	/**
	 * First pivot strategy, which chooses the first item in the subarray.
	 * @param arr - input ArrayList of objects.
	 * @param left - start of the subarray 
	 * @param right - end of the subarray
	 * @return index of chosen pivot
	 */
	public static <T extends Comparable<? super T>> int pivotStrategy1(ArrayList<T> arr, int left, int right)
	{
		//return the very first index in the ArrayList.
		return left;  
	}
	
	/**
	 * Second pivot strategy, which chooses the median of the subarray
	 * @param arr - input ArrayList of objects.
	 * @param left - start of the subarray 
	 * @param right - end of the subarray
	 * @return index of chosen pivot
	 */
	public static <T extends Comparable<? super T>> int pivotStrategy2(ArrayList<T> arr, int left, int right)
	{
		//Return the middle index of the ArrayList.
		return (left+right)/2;  
	}
	
	/**
	 * Third pivot strategy, which chooses the median of three.
	 * @param arr - input ArrayList of objects.
	 * @param left - start of the subarray 
	 * @param right - end of the subarray
	 * @return index of chosen pivot 
	 */
	public static <T extends Comparable<? super T>> int pivotStrategy3(ArrayList<T> arr, int left, int right)
	{
		//Get values at the beginning,end, and middle of the ArrayList.
		T leftsies = arr.get(left);
		T rightsies = arr.get(right);
		T middlesies = arr.get((left+right)/2);
		
		//Find the median of those three values.
		if(leftsies.compareTo(rightsies) > 0 && leftsies.compareTo(middlesies) < 0)
		return left;
		
		else if(leftsies.compareTo(rightsies) < 0 && leftsies.compareTo(middlesies) > 0)
		return left;
		
		else if(rightsies.compareTo(leftsies) > 0 && rightsies.compareTo(middlesies) < 0)
		return right;
		
		
		
		else if(rightsies.compareTo(leftsies) < 0 && rightsies.compareTo(middlesies) > 0)
		return right;
		
		else if(middlesies.compareTo(rightsies) > 0 && middlesies.compareTo(leftsies) < 0)
		return ((left+right)/2);	
	    
		else
		return ((left+right)/2);	
		
		
	}


	/**
	 * Generates the BestCase (ascending sorted ArrayList) for input into sorting algorithms.
	 * @param size size of the returned ArrayList
	 * @return an ArrayList of integers in sorted, ascending order. 
	 */
	public static ArrayList<Integer> generateBestCase(int size)
	{
		ArrayList<Integer> temp = new ArrayList<Integer>();
		
		
		
		
			for(int pos = 0; pos < size-1;pos++)
			{
				temp.add(pos);
			}
		
		
		return temp;
	}

	/**
	 * Generates the AverageCase (permuted ArrayList) for input into sorting algorithms. 
	 * @param size the size of the returned ArrayList
	 * @return An ArrayList of random integers from 0-size(-1) in permuted order
	 */
	public static ArrayList<Integer> generateAverageCase(int size)
	{
			//Keep track of the random index of insertion.
		int randomIndex = 0;
			//keep track of the item to be swapped.
		int holder = 0;
		
			//Make a random number generator.
		Random averageRandy = new Random();
		
		ArrayList<Integer> temp = new ArrayList<Integer>();
		
			//Fill temp array with sequentially ascending values.
		for(int pos = 0; pos < size-1; pos++)
		{
			temp.add(pos);
		}
			//Now permute temp.
		for(int randyPos =0; randyPos < size-1; randyPos ++)
		{
				//Generate a random index between 0 and "size" -1.
			randomIndex = averageRandy.nextInt((size-1)-0) +0;
			
			//Now swap the value at the current "randyPos" with the value at "randomIndex".
				//Set "holder" to item at randomIndex.
			holder = temp.get(randomIndex);
				//Put the value at "randyPos" in "randomIndex".
			temp.set(randomIndex, temp.get(randyPos));
				//Now put the stored value in "holder" in the current randyPos.
			temp.set(randyPos, holder);
		}
			//Return permuted List.
		return temp;	
	}

	/**
	 * Generates a WorstCase (descending sorted ArrayList) for input into sorting algorithms. 
	 * @param size the size of the returned ArrayList
	 * @return An ArrayList of integers in descending order
	 */
	public static ArrayList<Integer> generateWorstCase(int size)
	{
		ArrayList<Integer> temp = new ArrayList<Integer>();
		
		for(int pos = size-1; pos >= 0; pos--)
		{
			temp.add(pos);
		}
		
		return temp;
	}	
}

