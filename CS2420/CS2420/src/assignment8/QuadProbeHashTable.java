package assignment8;

import java.lang.reflect.Array;

public class QuadProbeHashTable  extends HashTable{
	
	private HashFunctor quadFunctor;
	int trueCapacity;
	String[] quadTable;
	double lambda;		
	int size;
	int initialCapacity = 0;    
	int colisionCounter = 0;
	
	
	/**
	 * 
	 * @param capacity
	 * @param functor
	 */
	public QuadProbeHashTable(int capacity, HashFunctor functor)          		
	{		//Assign the capacity
		trueCapacity = capacity;
		initialCapacity = capacity;	
		
		if(!isPrime(trueCapacity))		
		{
			trueCapacity = nextPrime(trueCapacity);
		}
		
			quadTable = new String[trueCapacity];
		
		
		size = super.size;
		
		lambda = super.lambda;		
		
		quadFunctor = functor;
		
	}
	
	/**
	 * Ensures that this set contains the specified item.
	 * 
	 * @param item
	 *            - the item whose presence is ensured in this set
	 * @return true if this set changed as a result of this method call (that
	 *         is, if the input item was actually inserted); otherwise, returns
	 *         false
	 */
	@Override
	public boolean add(String item) 
	{
		int desiredPosition = 0;
		
			//used to increment quad probing.
		int positionCoefficient = 1;
			//Used with quad probing.
		int incrementPosition = 0;
		
			//If we need to rehash...
		if(super.lambda >= 0.5 )
		{
			quadTable = reHash(quadTable);		
		}
		
			//Check for duplicate.
		if(size > 0)
		{
				if(this.contains(item) == true)	
					return false;				
		}
			//get a position from the hash functor.
		desiredPosition = this.quadFunctor.hash(item) % quadTable.length;
			//set incrementedPostion to desiredPostion initially.
		incrementPosition = desiredPosition;
		
			//If the slot is empty..
		if(quadTable[desiredPosition] == null)
		{		//...add the item to the desired position.
			quadTable[desiredPosition] = item;
				//Increment size.
			super.size ++;		
			size = super.size;
				//adjust load factor.
			super.lambda = (double)super.size/quadTable.length;	
			lambda = super.lambda;
			
			return true;
		}
			//Else if the desired slot is not empty...
		else
		{		//while the desired position is not empty...
			while(quadTable[incrementPosition] != null)		
			{		//probe quadratically
				incrementPosition = (int) (desiredPosition + Math.pow(positionCoefficient, 2));
					//increment probing coefficient.
				positionCoefficient ++;
					//while the probing position is out of  bounds 
				while(incrementPosition >= quadTable.length)
				{		//subtract array length from incremented position.
					incrementPosition = incrementPosition - quadTable.length;		
				}		//for timing.
				colisionCounter ++;		//SUSPECT!!!
			}
				//Once we've found an empty slot...
					//...add the item
			quadTable[incrementPosition] = item;
				//increment size.
			super.size ++;
			size = super.size;
				//Adjust load factor.
			super.lambda =(double) super.size/quadTable.length;	 
			lambda = super.lambda;
			
			return true;
		}
	}
	
	/**
	 * Removes all items from this set. The set will be empty after this method
	 * call.
	 */
	@Override
	public void clear() {

	    QuadProbeHashTable theNewThis = new QuadProbeHashTable(initialCapacity, this.quadFunctor);
		quadTable = theNewThis.quadTable;
		
		super.size = 0;							
		size = super.size;
		super.lambda = 0;
	}

	/**
	 * Determines if there is an item in this set that is equal to the specified
	 * item.
	 * 
	 * @param item
	 *            - the item sought in this set
	 * @return true if there is an item in this set that is equal to the input
	 *         item; otherwise, returns false
	 */
	@Override
	public boolean contains(String item) {
		
		int desiredPosition = 0;
			//used to increment quad probing.
		int positionCoefficient = 1;
			//Used with quad probing.
		int incrementPosition = 0;
		
			//get a position from the hash functor.
		desiredPosition = this.quadFunctor.hash(item) % quadTable.length;
			//set incrementedPostion to desiredPostion initially.
		incrementPosition = desiredPosition;
		
		
			//while the desired position is not empty...
		while(quadTable[incrementPosition] != null)		
		{		//If the item sought after is found, return true.
			if(quadTable[incrementPosition].equals(item))
				return true;																						//UNTESTED
				//probe quadratically
			incrementPosition = (int) (desiredPosition + Math.pow(positionCoefficient, 2));
				//increment probing coefficient.
			positionCoefficient ++;
				//while the probing position is out of  bounds
			while(incrementPosition >= quadTable.length)
			{		//subtract array length from incremented position.
				incrementPosition = incrementPosition - quadTable.length;		
			}
		}
			//Else, if a null is encountered, return false.
		return false;
	}
	
	/**
	 * 
	 * @param capacity
	 * @return
	 */
	public boolean isPrime(int capacity)
	{
		
		boolean isPrimebool = true;
		//If the number is not divisible by only itself and one....
		for(int pos = capacity-1; pos >= 2; pos --)
		{
			if(capacity%pos == 0)
				isPrimebool = false;
		}
		//Otherwise it is prime.
		return isPrimebool;
	}
	
	public int nextPrime(int capacity)
	{
		//Double the capacity.
		capacity *= 2;
		//Find the next prime number and return it.
		while(!isPrime(capacity))   
		{
			capacity++;
		}
		return capacity;    
	}
	
	/**
	 * 
	 * @param reHashArray
	 * @return
	 */
	public String[] reHash(String[] reHashArray)
	{
		//create an integer that is the same length as the reHashArray.
		int reHashLength = reHashArray.length;
		//create a new QuadProbeHashTable to rehash to.
		QuadProbeHashTable reHashed;
		
		//find the next prime number to set the new QuadProbeHashTable's capacity to.
		reHashLength = nextPrime(reHashLength);
		//Instantiate the new QuadProbeHashTable.
		reHashed = new QuadProbeHashTable(reHashLength,this.quadFunctor);
		
		//Add each item in the reHashArray to the new QuadProbeHashTable.
		for(String e: reHashArray)
		{
			//If the slot in the array is null, go to next slot.
			if(e == null)
				continue;
			//add item to new QuadProbeHashTable.
			reHashed.add(e);
		}
		//Update variables.
		trueCapacity = reHashLength;
		super.lambda = super.size/trueCapacity;
		lambda = super.lambda;
		
		//return the array from the new QuadProbeHashTable.
		return reHashed.quadTable;
	}
	
	/**
	 * This method returns the number of collisions.
	 * @return
	 */
	public int collision()
	{
		return colisionCounter;
	}
}