package assignment9;

import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.Comparator;
import java.util.NoSuchElementException;

/**
 * Represents a priority queue of generically-typed items. 
 * The queue is implemented as a min heap. 
 * The min heap is implemented implicitly as an array.
 * 
 * @author Paymon Saebi & Nathan Donaldson & Mike Fleming
 */
public class PriorityQueueHEAP<AnyType> 
{
	public int currentSize;						//DID THIS COME PRIVATE??
	public AnyType[] array;  				//DID THIS COME PRIVATE??
	private Comparator<? super AnyType> cmp;
		//Keeps track of where an item to be added is while it is percolating up the heap.
	private int addPosition = -1;
	
	/**
	 * Constructs an empty priority queue. Orders elements according
	 * to their natural ordering (i.e., AnyType is expected to be Comparable)
	 * AnyType is not forced to be Comparable.
	 */
	@SuppressWarnings("unchecked")
	public PriorityQueueHEAP() 
	{
		currentSize = 0;		
		array = (AnyType[]) new Object[10]; // safe to ignore warning
		cmp = null;
	}

	/**
	 * Construct an empty priority queue with a specified comparator.
	 * Orders elements according to the input Comparator 
	 * (i.e., AnyType need not be Comparable).
	 */
	@SuppressWarnings("unchecked")
	public PriorityQueueHEAP(Comparator<? super AnyType> c) 
	{
		currentSize = 0;		
		array = (AnyType[]) new Object[10]; // safe to ignore warning
		cmp = c;
	}

	/**
	 * @return the number of items in this priority queue.
	 */
	public int size() 
	{
		return currentSize;
	}

	/**
	 * Makes this priority queue empty.
	 */
	public void clear() 
	{
			//Make a new array.
		array = (AnyType[]) new Object[10];
			//Set size to 0.
		currentSize = 0;
		
	}

	/**
	 * @return the minimum item in this priority queue.
	 * @throws NoSuchElementException if this priority queue is empty.
	 * 
	 * (Runs in constant time.)
	 */
	public AnyType findMin() throws NoSuchElementException 
	{
		if(this.size() == 0)
		{
			throw new NoSuchElementException("Queue is empty");
			
		}
		return this.array[0];
	}

	/**
	 * Removes and returns the minimum item in this priority queue.
	 * 
	 * @throws NoSuchElementException if this priority queue is empty.
	 * 
	 * (Runs in logarithmic time.)
	 */
	public AnyType deleteMin() throws NoSuchElementException 
	{
		
		//If the size is zero, throw an exception.
		if(this.size() == 0)
		{
			throw new NoSuchElementException("Queue is empty.");
		}
		//minimum value to be deleted.
		AnyType minimum = this.array[0];
		//last item to be taken to the root.
		AnyType lastItem = this.array[this.currentSize-1];
		//Set the root to the last item.
		this.array[0] = lastItem;
		//set the lastitem to null.
		this.array[this.currentSize-1] = null;
		//Call percolateDown
		percolateDown(lastItem);
		
		
	
		//Decrement size.
		this.currentSize --;
		
		

		//Return the minimum value.
		return minimum;
	}
	
	public void percolateDown(AnyType lastItem) 
	{
		//Variables
		int LChildIndex;
		int RChildIndex;
		int IndexSmaller=0;
		AnyType Smaller;
		boolean Lboolean = true;
		boolean Rboolean = true;
		
		// Iterate through the array.
		for(int i = 0; i < this.array.length; i++)
		{
			i = IndexSmaller;
			//If the leftChildIndex is out of bounds or is null, set the Lboolean to false.
			if(leftChildIndex(i) > this.array.length-1)
			{
				Lboolean = false;
			}
			
			else if(this.array[leftChildIndex(i)] == null)
			{
				Lboolean = false;
			}
			//If the rightChildIndex is out of bounds or is null, set the Rboolean to false.
			if(rightChildIndex(i) > this.array.length-1)
			{
				Rboolean = false;
			}
			else if(this.array[rightChildIndex(i)] == null)
			{
				Rboolean = false;
			}
			
			//Create the index's at where the left and right children are.
			LChildIndex = leftChildIndex(i);
			RChildIndex = rightChildIndex(i);
			//If they are both out of bounds or null return, you are at the bottom and cannot go any further.
			if(Lboolean == false && Rboolean == false)
				return;
			
			//If the left child is out of bounds or null and the right child is not....
			else if(Lboolean == false && Rboolean != false)
			{
				//Set the Smaller AnyType to the right child.
				Smaller = this.array[RChildIndex];
				//Keep track of the right child index.
				IndexSmaller = RChildIndex;
				// If the item sent in is greater than the child....
				if(compare(lastItem, Smaller) > 0)
				{
					//Swap them.
					this.array[IndexSmaller] = lastItem;
					this.array[parentIndex(i)] = Smaller;
					
				}
			}
			//If the left child is not out bounds or null but the right child is...
			else if(Lboolean != false && Rboolean == false)
			{
				//Set the AnyType Smaller to the left child.
				Smaller = this.array[LChildIndex];
				//Keep track of that index.
				IndexSmaller = LChildIndex;
			
			}
				//If neither of them are null or out of bounds and the left child is less than the right child...
			else if(compare(this.array[LChildIndex], this.array[RChildIndex])<0)
			{
				//Set the Smaller AnyType to the left child.
				Smaller = this.array[LChildIndex];
				//Keep track of that index.
				IndexSmaller = LChildIndex;
			}
			//If the left child isnt less than the right...
			else
			{
				//Set the smaller AnyType to the right child.
				Smaller = this.array[RChildIndex];
				//Keep track of the index.
				IndexSmaller = RChildIndex;
				}
			//If the item sent in is greater than the child...
			if(compare(lastItem, Smaller) > 0)
			{
				//Swap them.
				
				this.array[IndexSmaller] = lastItem;
				this.array[parentIndex(IndexSmaller)] = Smaller;
				
				
			}
			//You have reached an end point. Return.
			else
				return;
		}
		
		
		}	
	
	/**
	 * This method returns the index of a a left child.
	 * @param i
	 * @return
	 */
	public int leftChildIndex (int i) {
		return ( i * 2 ) + 1 ;
		}
		
	/**
	 * This method returns the index of a a right child.
	 * @param i
	 * @return
	 */
	public int rightChildIndex (int i) {
		return ( i * 2 ) + 2 ;
		}
		
	/**
	 * This method returns the index of a parent node.
	 * @param i
	 * @return
	 */
	public int parentIndex(int i)		
	{
		return (i-1)/2;
	}
	
	/**
	 * Adds an item to this priority queue.
	 * 
	 * (Runs in constant time, worst case logarithmic)
	 * 
	 * @param x -- the item to be inserted
	 */
	public void add(AnyType x) 
	{
		//If adding for the first time...
		if(currentSize == 0)
		{		//...first addition goes in the first position in "array".
			array[0] = x;
				//Increment size variable.
			currentSize ++;
				//We are done.
			return;				
		}
			//Else, if we are not adding for the first time...
		else 
		{
				// if the array is full, double its capacity.
			if(currentSize == array.length)							
			{
					//Make a temp array.
				AnyType[] temp = (AnyType[]) new Object[array.length*2];		
				for(int addPos = 0; addPos < currentSize; addPos++)					
				{		//Transfer data to temp array.								
					temp[addPos] = array[addPos]; 
				}
				array = temp;		
			}

			// add the new item to the next available node in the tree regardless of absence 
					//or presence of comparator, so that complete tree structure is maintained.
			array[currentSize] = x;									
				//Set global index member.
			addPosition = currentSize;

		// percolate the new item up the levels of the tree until heap order is restored

		//IF Constructor has a comparator....
		
						//While the added item is smaller than or equal to its parent...	
					while((compare((AnyType) x,array[parentIndex((Integer) addPosition)]) < 0))
					{	//...Call percolateUp on the added item.
						percolateUp(x,addPosition);		
					}
						//Once added item is in its correct position, increment size.
					currentSize ++;
						//Reset global "addPosition" member.
					addPosition = -1;
						//be done.
					return;
			
		}
	}
	
	/**
	 * This  method percolates an added item up to its proper position.
	 * @param item
	 */
	public void percolateUp(AnyType item, int position)
	{		
			//A storage holder for the parent value.
		Object parentStorage = null;
		
			//Store parent in temp holder "parentStorage".
		parentStorage = array[parentIndex(position)];
			//Now put "item" in place of its parent.
		array[parentIndex(position)] = item;
			//Now update global "addPosition" member.
		addPosition = parentIndex(position);  
			//Now put parent holder "parentStorage" in the swapped place.
		array[position] = (AnyType) parentStorage;
			//We are done.
		return;       			
	}

	/**
	 * Generates a DOT file for visualizing the binary heap.
	 */
	public void generateDotFile(String filename) 
	{
		try 
		{
			PrintWriter out = new PrintWriter(filename);
			out.println("digraph Heap {\n\tnode [shape=record]\n");

			for(int i = 0; i < currentSize; i++) {
				out.println("\tnode" + i + " [label = \"<f0> |<f1> " + array[i] + "|<f2> \"]");
				if(((i*2) + 1) < currentSize)
					out.println("\tnode" + i + ":f0 -> node" + ((i*2) + 1) + ":f1");
				if(((i*2) + 2) < currentSize)
					out.println("\tnode" + i + ":f2 -> node" + ((i*2) + 2) + ":f1");
			}

			out.println("}");
			out.close();
		} 
		catch (IOException e) 
		{
			System.out.println(e);
		}
	}

	/**
	 * Internal method for comparing lhs and rhs using Comparator if provided by the
	 * user at construction time, or Comparable, if no Comparator was provided.
	 */
	@SuppressWarnings("unchecked")
	private int compare(AnyType lhs, AnyType rhs) 
	{
		if (cmp == null)
			return ((Comparable<? super AnyType>) lhs).compareTo(rhs); // safe to ignore warning
		// We won't test your code on non-Comparable types if we didn't supply a Comparator

		return cmp.compare(lhs, rhs);
	}
	
	//LEAVE IN for grading purposes
	public Object[] toArray() {    
		Object[] ret = new Object[currentSize];
		for(int i = 0; i < currentSize; i++)
			ret[i] = array[i];
		return ret;
	}
}
