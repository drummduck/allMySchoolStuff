package assignment8;

import java.util.LinkedList;

public class ChainingHashTable extends HashTable {
	
	//Member variables.
	private HashFunctor chainFunctor;
	public LinkedList<String>[] storage;
	int thiscapacity;
	private int firstKnownCapacity;
	private int collisionCounter;
	
	@SuppressWarnings("unchecked") 
	/**
	 * 
	 * @param capacity - capacity of the hashtable.
	 * @param functor - hash functor to be used in this table.
	 */
	public ChainingHashTable(int capacity, HashFunctor functor) 
	{
		//Keeps track of collisions.
		collisionCounter = 0;
		//Keeps track of the first capacity sent in.
		firstKnownCapacity = capacity;
		//The capacity that is used around this class.
		thiscapacity = capacity;
		//The hash function used that is used around this class.
		chainFunctor = functor;
		//The array of this hashtable.
		storage = (LinkedList<String>[]) new LinkedList[thiscapacity];  
		
		super.lambda = (double)super.size()/thiscapacity;  
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
	public boolean add(String item) {
		
	
		//If 75% full....
		if(super.lambda >= 0.75)
		{
			//...set the array of this hashtable to the array of the rehashed array.
			this.storage = reHash(this.storage);
		}
		
		//Get the hash number of the string, and find where it is to be placed.
		int ascii = chainFunctor.hash(item)%(this.storage.length);
		//If the slot in the array is null....
		if (this.storage[ascii] == null)
		{
			//...make a new LinkedList.
			LinkedList firstAddlist = new LinkedList();
			//add the item to the linked list.
			firstAddlist.add(item);
			//add the linked list to the slot in the array of this hashtable.
			this.storage[ascii] = firstAddlist;	
		}
		else
		{
			//If the item already exists in the hashtable....
			if(this.contains(item))
			{
				//Add returns false;
				return false;
			}
			//Otherwise add the item to the linkedlist in the array slot.
		this.storage[ascii].add(item);
		collisionCounter++;
		}
		//Update variables.
		super.size ++;
		super.lambda = (double)super.size()/thiscapacity;
		return true;
	}
	/**
	 * Removes all items from this set. The set will be empty after this method
	 * call.
	 */
	@Override
	public void clear() {
		//Create a new ChainingHashTable with the first capacity and this hash function.
		ChainingHashTable theNewThis = new ChainingHashTable(firstKnownCapacity, this.chainFunctor);
		
		//set this array equal to that empty array.
		this.storage = theNewThis.storage;
		
		//Update variables.
		super.size = 0;
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
		
		//Find where the item should be placed.
		int ascii = chainFunctor.hash(item)%(storage.length);
		
		
		//If the item is in the linkedlist in the specified array slot....
		 if(this.storage[ascii].contains(item) == true)
		{
			return true;
		}
		 //Otherwise....
		return false;
	}
	
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
	 * @return - returns number of current collisions.
	 */
	public int collision()
	{
		return collisionCounter;
	}
	
	public LinkedList<String>[] reHash(LinkedList<String>[] arrayLink)  
	{
		
		//create an integer of the same length of the arrayLink.
		int reHashLength = arrayLink.length;
		//create a new ChainingHashTable to rehash to.
		ChainingHashTable reHashed;
		
		//find the next prime of the arrayLink length.
		reHashLength = nextPrime(reHashLength);
		
		//instantiate the new ChainingHashTable.
		reHashed = new ChainingHashTable(reHashLength,this.chainFunctor);
		
		//Step through each slot in the arrayLink.
		for(int pos = 0; pos < arrayLink.length; pos++)
		{
			// If the spot has no linkedlists, step to next position.
			if(arrayLink[pos] == null)
				continue;
			//Add each item in each linkedlist in the array to the new chaininghashtable.
			for(int pos2 = 0; pos2 < arrayLink[pos].size(); pos2++)
			{
				reHashed.add(arrayLink[pos].get(pos2));
			}
		}
		// update variables and return the new array within the chaininghashtable.
		super.lambda =(double) super.size()/thiscapacity;
		thiscapacity = reHashLength;
		return reHashed.storage;
	}
}
