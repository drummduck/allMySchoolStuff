package assignment8;

import java.util.*;

/**
 * An abstract class facilitating the implementation of a concrete hash table. 
 * @author Paymon Saebi & ??
 *
 */
public abstract class HashTable implements Set<String> 
{
	public double lambda;
	 public int size;
	
	
	/**
	 * Ensures that this set contains all items in the specified collection.
	 * 
	 * @param items
	 *            - the collection of items whose presence is ensured in this
	 *            set
	 * @return true if this set changed as a result of this method call (that
	 *         is, if any item in the input collection was actually inserted);
	 *         otherwise, returns false
	 */
	public final boolean addAll(Collection<? extends String> items) 
	{
		
		boolean addallbool = false;
		//Add each item in the collection to this table.
		for(String e: items)
		{
		
			this.add(e);
			addallbool =  true;
		}
		return addallbool;
	}
	/**
	 * Determines if for each item in the specified collection, there is an item
	 * in this set that is equal to it.
	 * 
	 * @param items
	 *            - the collection of items sought in this set
	 * @return true if for each item in the specified collection, there is an
	 *         item in this set that is equal to it; otherwise, returns false
	 */
	public final boolean containsAll(Collection<? extends String> items) 
	{
		
		boolean containsbool = false;
		//Step through each item in the collection and see if it is in this table.
		for(String e: items)
		{
			if(this.contains(e))
			{
				containsbool = true;
			}
			
			else
				return false;
		}
		
		return containsbool;
	}
	/**
	 * Returns true if this set contains no items.
	 */
	public final boolean isEmpty() 
	{
		//Check to see if this table has any items in it.
		if(size == 0)
			return true;
		else
			return false;
	}
	/**
	 * Returns the number of items in this set.
	 */
	public final int size() 
	{
		return size;
	}
}
