package assignment5;

import java.util.NoSuchElementException;

/**
 * Represents a generic stack (Last in, first out).
 * 
 * @author Nathan Donaldson & Mike Fleming
 * @param <E> - the type of elements contained in the stack
 */
public class MyStack<E> 
{
	private MyLinkedList<E> linkedListStack;

	public MyStack() 
	{
		linkedListStack = new MyLinkedList<E>();
	}

	/**
	 * Removes all of the elements from the stack.
	 */
	public void clear() 
	{		//Call MyLinkedList's "clear()" method.
		linkedListStack.clear(); 
	}

	/**
	 * Returns true if the stack contains no elements.
	 */
	public boolean isEmpty() 
	{
			//Call MyLinkedList's "isEmpty()" method.
		return linkedListStack.isEmpty();
	}

	/**
	 * Returns the item at the top of the stack without removing it from the stack. 
	 * Throws NoSuchElementException if the stack is empty.
	 */
	public E peek() throws NoSuchElementException 
	{		//Call MyLinkedList's "getLast()" method.
		E item = linkedListStack.getLast();		

		return item;
	}

	/**
	 * Returns and removes the item at the top of the stack. Throws
	 * NoSuchElementException if the stack is empty.
	 */
	public E pop() throws NoSuchElementException 
	{		//Call MyLinkedList's "removeLast()" method.
		E item = linkedListStack.removeLast();			
		return item;
	}

	/**
	 * Pushes the input item onto the top of the stack.
	 */
	public void push(E item) 
	{		//Call MyLinkedList's "addLast()" method.
		linkedListStack.addLast(item);
	}

	/**
	 * Returns the number of items in the stack.
	 */
	public int size() 
	{
		//Call MyLinkedList's "size()" method.
		return linkedListStack.size();
	}
	
	/**
	 * Returns an array containing all of the elements in this list in proper sequence 
	 * (from first to last element).
	 * O(N) for a doubly-linked list.
	 */
	public Object[] toArray() 
	{		//Call MyLinkedList's "toArray()" method.
		Object[] result = linkedListStack.toArray();		
		return result;
	}
}
