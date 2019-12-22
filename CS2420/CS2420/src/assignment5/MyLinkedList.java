package assignment5;


import java.util.NoSuchElementException;


/**
 * Represents a generic doubly linked list.
 * 
 * @author Mike Fleming & Nathan Donaldson
 * @param <E> - the type of elements contained in the linked list
 */
public class MyLinkedList<E> implements List<E> 
{
	//Instance variables
		//The size of the list(i.e. the number of nodes besides "head"/"tail" in the list).
	int size;
		//Front end accesor of the list.
	Node head;
		//Back of the list acessesor.
	Node tail;
	
	/**
	 * Constructor.  Creates a blank linked list.
	 */
	public MyLinkedList() 
	{
		E start = null;  //MEH!!!
		E end = null;		//Wish we could come up with a type of data element that would 
													//distinguish head/tail from regular nodes.
		size = 0;
		head = new Node(start);  //May need to revise this implementation
		tail = new Node(end);					//NULL MIGHT THROW NULLPOINTER!!!!
		
			//With and empty Linked-List, have the head and the tail point to each other.
		head.next = tail;
		tail.prev = head;  
	}
	
	/**
	 * @param element - The element to add at the beginning of the list.
	 *  
	 * Inserts the specified element at the beginning of the list.
	 * O(1) for a doubly-linked list.
	 * 
	 */
	public void addFirst(E element) 			//TESTED WITH GET()
	{
			//Addition "Node" declaration.
		Node added;
		
			//If this is the first node being added to the linked list...
		if(size == 0)
		{		//Initialize "added" to "element".
			added = new Node(element); 
				//Update "head.next" pointer.
			head.next = added;
				//Update "tail.prev" pointer.
			tail.prev = added;
				//Increment the size variable of the list.
			size++;
		}	
			//...else if this is not the first "Node" to be added to the list...
		else 
		{		//Initialize "added" to "element".
			added = new Node(element);
				//First point "added" to "head.next" (i.e. point "added" to 
						//the former first item in the list).
			added.next = head.next;
				//Then point point "head.next" to "added".
			head.next = added;
				//Then updated former first node's previous to point to "added".
			added.next.prev = added;		
				//Increment size of list.
			size ++;
		}
	}
	
	/**
	 * @param element - The element to add at the end of the list.
	 * 
	 * Inserts the specified element at the end of the list.
	 * O(1) for a doubly-linked list.
	 */
	public void addLast(E o) 					//TESTED
	{
			//Addition "Node" declaration.
		Node added;
	
			//If this is the first node being added to the linked list...
		if(size == 0)
		{		//..Call "addFirst()" instead.
			addFirst(o);
		}	
	
		else
		{		//initialize added Node.
			added = new Node(o);
				//set new node's previous to node tail points at.
			added.prev = tail.prev;
				//set the node the tail points at next to new node.
			tail.prev.next = added;
				//tail points to new node.
			tail.prev = added;
				//increment size
			size++;
		}
	}

	/**
	 * Inserts the specified element at the specified position in the list.
	 * Throws IndexOutOfBoundsException if index is out of range.
	 * O(N) for a doubly-linked list.
	 * 
	 * @param index - the index the added Node will be inserted to.
	 * @param element - the value of the inserted Node.
	 */
	public void add(int index, E element) throws IndexOutOfBoundsException   
	{	
			//If we are adding an item for the first time,
				//or if we are trying to insert an item into the first position(0) into a
					//non-empty list...
		if ((size == 0 && index == 0) || (size == 1 && index == 0)) 
		{ 		// ...call addFirst instead
			addFirst(element);
				//Be done.
			return;
		} 	//Else if we are trying to insert an item at a position that is one greater than 
				//the current position of the current last item, AND if the desired position
					//of insertion is non-negative...
		else if (index == size  && index >= 0) 	//LEAVE AS IS UNLESS PAYMON SAYS OTHERWISE.
		{		//...call addLast instead.
			addLast(element);
				//Insertion successful, be done.
			return;
		}
			//BUT if the desired index of insertion is negative,
					//or if the the desired index of insertion is 2 positions greater
						//than the current position of the last item in the list...
		if (index < 0 || index > size) 
		{ 		//...throw exception.
			throw new IndexOutOfBoundsException();
		}
			// Addition "Node" declaration.
		Node added;

			// create a dummy node to use as an indexer.
		Node dummy = head.next;
			// create node to be added at certain index.
		added = new Node(element);
			// while the position is not past the index....
		for (int pos = 0; pos <= size - 1; pos++) 
		{
					// if the position equals the index.... 
			if (pos == index) {
					// set new node previous to dummy.
				added.prev = dummy.prev;
					// set new node next to dummy.next.
				added.next = dummy;
					// make the item after dummy's previous point to dummy.
				dummy.prev.next = added;
					// set dummy's next to the new node.
				dummy.prev = added;
					// Increment list "size".
				size++;
				return;
			}
				// set the dummy node to dummy.next(i.e. increment position).
			dummy = dummy.next;
		}
	}
	

	/**
	 * Returns the first element in the list.
	 * Throws NoSuchElementException if the list is empty.
	 * O(1) for a doubly-linked list.
	 * 
	 * @return E - the element of the returned Node.
	 */
	public E getFirst() throws NoSuchElementException 
	{		//If the list is empty...
		if(size ==0)
				//...throw exception.
			throw new NoSuchElementException();		//TESTED
		else
		{
			//E item = head.next.data;
			return (E) head.next.data;		//HIGHLY SUSPECT
		}
	}

	/**
	 * Returns the last element in the list.
	 * Throws NoSuchElementException if the list is empty.
	 * O(1) for a doubly-linked list.
	 * 
	 * @return E - The element of the last Node in the list.
	 */
	public E getLast() throws NoSuchElementException 
	{
			//If the list is empty...
		if(size ==0)
				//...throw exception.
			throw new NoSuchElementException();		//TESTED 
		return (E) tail.prev.data;		//HIGHLY SUSPECT
	}

	/**
	 * Returns the element at the specified position in the list.
	 * Throws IndexOutOfBoundsException if index is out of range.
	 * O(N) for a doubly-linked list.
	 * 
	 * @param index - the index of the requested Node.
	 * 
	 * @return E - The element of the returned Node.
	 */
	public E get(int index) throws IndexOutOfBoundsException 				//TESTED
	{		//if the index is smaller than zero or larger than the size of the list...
		if(index < 0 || index >= size)
		{		//...throw exception.
			throw new IndexOutOfBoundsException();
		}
			//Make and indexer node.
		Node dummy = head.next;
			//Make an indexer variable.
		int nodeIndexer = 0;
			//While the indexer node is within the bounds of the list...
			//Call getFirst if requested index is 0
		if(index == 0)
			getFirst();
			//If the the requested index is the last index...
		if(index == size-1)
				//...call "getlast()".
			getLast();
		
		while(nodeIndexer<= size) 
		{		//If the current position equals parameter "index".
			if(index == nodeIndexer)
			{		//Break out of the loop.
				break;
			}
			else {
				//Otherwise look at the next Node.
				dummy = dummy.next;
					//Increment indexer.
				nodeIndexer ++;
			}
		}
			//Return the data at the current node.
		return dummy.data;  //HOPE THIS WORKS
	}

	/**
	 * Removes and returns the first element from the list.
	 * Throws NoSuchElementException if the list is empty.
	 * O(1) for a doubly-linked list.
	 * 
	 * @return E - The element of the removed Node.
	 */
	public E removeFirst() throws NoSuchElementException 
	{		//First thing, assign the first .data in the list to "item".
		E item = getFirst();		
			//If we are removing the last remaining item in the list...			//TESTED
		if(size ==1) 
		{
				//Assign the value of the last node to be removed to a temporary "Node".
			Node returnLast = new Node(getLast());			//UNTESTED
			//...clear the list.
		clear();
			//Return the value of the temporary "Node".
		return returnLast.data;							//UNTESTED
		}
			//Else if we are trying to remove from an empty list...
		else if(size == 0) 
		{		//...throw exception.
			throw new NoSuchElementException();		//TESTED BUT UNCOVERAGED because of getFirst method.
		}
			//...else if we are not removing from and empty list, or a list with only one item in it...
		else
		{		//Point "head.next" to the second item in the list.
			head.next = head.next.next;
				//Now that the second item in the list has been moved to the front of the line,
					//point its prev to null.
			head.next.prev = null;				//SUSPECT 
				//decrement size.
			size --;
		}
			//If the item could be removed, return it.
		return item;	
	}

	/**
	 * Removes and returns the last element from the list.
	 * Throws NoSuchElementException if the list is empty.
	 * O(1) for a doubly-linked list.
	 * 
	 * @return E - The element of the removed Node.
	 */
	public E removeLast() throws NoSuchElementException 		//TESTED
	{		//First thing, assign the last .data in the list to "item".
		E item = getLast();		 
			//If we are removing the last remaining item in the list...
		if(size ==1) 
		{
				//Assign the value of the last node to be removed to a temporary "Node".
			Node returnLast = new Node(getLast());			//UNTESTED
			//...clear the list.
		clear();
			//Return the value of the temporary "Node".
		return returnLast.data;							//UNTESTED
		}
			//Else if we are trying to remove from an empty list...
		else if(size == 0)
		{		//...throw exception.
			throw new NoSuchElementException();
		}		//...else if we are not removing from and empty list, 
					//or a list with only one item in it...
		else 
		{		//Point "tail.prev" to the second to last node in the list.
			tail.prev = tail.prev.prev;
				//Now that the last node in the list is halfway removed, 
					//point the updated last item's next to null.
			tail.prev.next = null;		//SUSPECT.     //or tail.prev.prev.next ???
				//Decrement size.
			size --;
		}
			//Return the removed item.
		return item;
	}

	/**
	 * Removes and returns the element at the specified position in the list.
	 * Throws IndexOutOfBoundsException if index is out of range.
	 * O(N) for a doubly-linked list.
	 * 
	 * @param index - The index of the Node to be removed.
	 * @return E - The element of the removed Node.
	 */
	public E remove(int index) throws IndexOutOfBoundsException 	//TESTED
	{		
			// If index is smaller or larger than the linkedlist....
		if(index >= size || index < 0)
		{
				// ...throw an IndexOutOfBoundsException.
			throw new IndexOutOfBoundsException();
		}
		
		if(size ==1) 
		{
				//Assign the value of the last node to be removed to a temporary "Node".
			Node returnLast = new Node(getLast());			//UNTESTED
			//...clear the list.
		clear();
			//Return the value of the temporary "Node".
		return returnLast.data;							//UNTESTED
		}

			// If the index being removed is the first item in the list....
		if(index == 0)
		{
				// ...call removeFirst and return the item returned from it.
			return removeFirst();
		}
		
		if(index == size-1)
		{
			return removeLast();
		}
		
			// Create dummy node for indexing.
		Node dummy = head.next;
		
			// Go through the linkedlist.
		for(int pos = 0; pos <= size-1; pos++)
		{
				// If position equals index sent in....
			if(pos == index)
			{
					//...point previous of dummy's next item to dummy's previous.
				dummy.next.prev = dummy.prev;
					//...point next of dummy's previous item to dummy's next.
				dummy.prev.next = dummy.next;
				
					// Decrement size
				size--;
					// return the data of dummy.
				return dummy.data;
			}
				// Increment dummy along linkedlist.
			dummy = dummy.next;
		}
			// This should never be reached.
		return dummy.data;
	}

	/**
	 * Returns the index of the first occurrence of the specified element in the list, 
	 * or -1 if this list does not contain the element.
	 * O(N) for a doubly-linked list.
	 * 
	 * @param element - The element of the requested Node.
	 */
	public int indexOf(E element) 	//TESTED
	{		
			// Create an indexer node.
		Node dummy = head.next;
		
			// Traverse the linkedlist
		for(int pos = 0; pos <= size-1; pos++)
		{
				// If the indexer data equals the element searched for....
			if(dummy.data.equals(element))
			{
					// ... return the position index.
				return pos;
			}
					// Increment the indexer node.
				dummy = dummy.next;
		}
			// Return -1 if the item was not found.
		return -1;
	}

	/**
	 * Returns the index of the last occurrence of the specified element in this list, 
	 * or -1 if this list does not contain the element.
	 * O(N) for a doubly-linked list.
	 */
	public int lastIndexOf(E element) 	//TESTED
	{		
			// Create a dummy node.
		Node dummy = head.next;
			// Create an integer that keeps track of last known position of found element.
		int lastknownindex = -1;
			// Traverse the linkedlist.
		for(int pos = 0; pos <= size-1; pos++)
		{
				// if the dummy data equals the element we are searching for....
			if(dummy.data.equals(element))
			{
					//...set the tracker to that position.
				lastknownindex = pos;
			}
				// increment dummy node.
			dummy = dummy.next;
		}
			//return the tracker integer.
		return lastknownindex;
	}

	/**
	 * Returns the number of elements in this list.
	 * O(1) for a doubly-linked list.
	 */
	public int size() 
	{
		return this.size;		//TESTED
	}

	/**
	 * Returns true if this collection contains no elements.
	 * O(1) for a doubly-linked list.
	 */
	public boolean isEmpty() 
	{		//If the list in question resembles a brand new list...
		if(head.next == tail && tail.prev == head)
			return true;						//TESTED
		else
			return false;
	}
	
	/**
	 * Removes all of the elements from this list.
	 * O(1) for a doubly-linked list.
	 */
	public void clear() 
	{
			//Simply set the list back to the way a "MyLinkedList" comes fresh out of the
				//"MyLinkedList" constructor.
		head.next = tail;
		tail.prev = head;	//TESTED
			//Set size to 0.
		size = 0;
	}
	
	/**
	 * Returns an array containing all of the elements in this list in proper sequence 
	 * (from first to last element).
	 * O(N) for a doubly-linked list.
	 */
	public Object[] toArray() 
	{				
		Object[] result = null;
			//If the list is empty...
		if(size == 0)
		{		//...make an empty list.
			result = new Object[0];
				//Return the empty list;
			return result;
		}
			//Else if the list is not empty...
		else
		{		//Initialize and indexer "Node".
			Node indexer = head.next;
				//Initialize return array to size of list.
			result = new Object[size - 1];
				//Initialize and position indexer.		//GETTING OUT OF BOUNDS WITH ARRAY SIZE 6.
			int addIndexer = 0;
				//While indexer is less than the size of the list.
			while(addIndexer < size -1)
			{		//Add the ".data" position by position.
				result[addIndexer] = indexer.data;
					//Increment position indexer.
				addIndexer ++;
					//Increment indexer "Node".
				indexer = indexer.next; 
			}
				//Return the array representation of the linked list.
			return result;
		}
	}
	
	/**
	 * Responsible for constructing Node objects capable for use in a 
	 * doubly linked list.
	 * 
	 * @author Michael Fleming & Nathan Donaldson.
	 */
	private class Node 
	{		//A slot in the node that holds a value.
		E data;
			//Pointers that make double linking possible.
		Node next;
		Node prev;
		
			//"Node" is constructed with a passed in "element", "Node's" ".next" & ".prev"
				//pointers are, by default, set to null.
		public Node(E element)
		{
			this.data = element;
			this.next = null;
			this.prev = null;
		}		
	}	
}
