package Assignment10;

import java.util.*;

/**
 * This is an example for CS 1410 - It is a simple Queue data structure
 * implemented using a singly-linked list.
 * <p>
 * 
 * This example demonstrates linked lists and generics. It has been fully
 * commented and reorganized for clarity.
 * <p>
 * 
 * Note - any data of any single type can be stored in this list, including
 * null. Care must be taken because data values may be null. (I have added code
 * to handle this in the Node inner class.)
 * 
 * @author Nathan Donaldson
 * 
 * @version 04/18/2012
 */
public class Queue<E> {
	// Instance variables

	private Node head; // Points to (refers to) the first node in the list, or
						// null if none.
	private Node tail; // Points to (refers to) the last node in the list, or
						// null if none.

	private int size; // The number of elements (nodes) in the list.

	/**
	 * This constructor initializes the queue to an empty state. (The head and
	 * tail reference 'null', and the size is set to 0.)
	 */
	public Queue() {
		this.head = null;
		this.tail = null;
		this.size = 0;
	}

	/**
	 * Returns the number of elements in this queue.
	 * 
	 * @return the number of elements in this queue
	 */
	public int size() {
		return size;
	}

	/**
	 * Adds an element to the end (the back) of the queue.
	 * 
	 * @param data
	 *            the data to be enqueued
	 */
	public void enqueue(E data) {
		// Create a new node with the data. This node
		// will be linked in to the list at the end of the list.

		Node n = new Node(data);

		// If the list is not empty, just link the new node
		// in after the tail.

		if (tail != null)
			tail.next = n;

		// The end of the list is changed to reference the new node.

		n.previous = tail;
		tail = n;

		// If the list was empty, the head should also reference this new node.

		if (head == null)
			head = n;

		// The list has had a node added - increase its size.

		size++;
	}

	/**
	 * Removes an element from the start (the front) of the queue.
	 * 
	 * @return the data stored at the start of the queue
	 * 
	 * @throws NoSuchElementException
	 *             if the queue is empty
	 */
	public E dequeue() {
		// If the queue is empty, throw an exception.

		if (size == 0)
			throw new NoSuchElementException("Cannot remove an element from an empty queue.");

		// Get the data from the node at the front of the list. Note that we
		// know
		// the head will be non-null, the queue is not empty if we get here.

		E temp = head.data;

		// Point the head to the next node in the list. This causes the first
		// node
		// to become unreferenced, and it will be discarded by the garbage
		// collector.

		head = head.next;

		// The list has shrunk, change the size.

		size--;

		// If the list is now empty, both the head and tail should point to
		// null.
		// (Note that the head already would contain null, we don't need to
		// change it again.)

		if (size == 0)
			tail = null;

		// Return the data that was stored at the front of the queue.

		return temp;
	}

	/**
	 * Removes the specified element from the list. If the data does not exist
	 * in the list, the queue is not changed. If the data occurs multiple times
	 * in the list, only the first occurrence is removed.
	 * 
	 * @param data
	 *            the data element to be removed
	 */
	public void remove(E data) {
		// Keep track of a 'current' node (or position) in the list, as
		// well as the node that links to this node.

		Node current = head;
		Node previous = null;

		// As long as 'current' has not reached the end of the list, and
		// as long as it is not referencing a node that contains the
		// data we want to remove, loop and advance through the list.

		while (current != null && !current.containsData(data)) {
			previous = current;
			current = current.next;
		}

		// If the element was not found, bail.

		if (current == null)
			return;

		// If the element was at the start of the list, just advance
		// the head. Otherwise, unlink it from the list.

	    
        if (previous == null)
            head = current.next;
        else if (current.data.equals(data))
        previous.next = current.next;
      

		// An element has been removed, adjust the size appropriately.

		size--;

		// If the last element was removed, adjust the tail appropriately.

		if (current == tail)
			tail = previous;
	}

	/**
	 * Inserts the specified element into the list immediately before the
	 * specified placeholder data. If the placeholder data is not in the list,
	 * no action is taken. The inserted data element will be nearer to the start
	 * of the list than the placeholder. If the placeholder element occurs
	 * multiple times in the list, the data element will be inserted before the
	 * first occurrence of the placeholder.
	 * 
	 * @param placeholder
	 *            the data element to search for
	 * 
	 * @param data
	 *            the data element to insert
	 */
	public void insertBefore(E placeholder, E data) {
		
		// Keeps track of current position, previous position, and the replacement node.

		Node current = head;
		Node previous = null;
		Node replacement = new Node(data);

		
		// If the current node does not contain null or the placeholder,
		// advance current and previous.
		
		while (current != null && !current.containsData(placeholder)) {
			previous = current;
			current = current.next;
		}

		// If placeholder was not found, bail out.
		
		if (current == null) {
			return;
		}
		
		// If placeholder is found, then the new node's next points to the current
		// node and the new node's previous points to previous. The current node's previous
		// points to the replacement node and the previous node's next points to the new node.
		
		
	if(previous == null && current.data.equals(placeholder))
	{
		
		current.previous = replacement;
		previous = replacement;
		replacement.next = current;
		head = replacement;
		
		size++;
	}
		
	else if (current.data.equals(placeholder)) {
			replacement.next = current;
			replacement.previous = previous;
			current.previous = replacement;
			previous.next = replacement;

			size++;
		}
	

	}

	/**
	 * Inserts the specified element into the list immediately after the
	 * specified placeholder data. If the placeholder data is not in the list,
	 * no action is taken. The data element will be nearer to the end of the
	 * list than the placeholder. If the placeholder element occurs multiple
	 * times in the list, the data element will be inserted after the first
	 * occurrence of the placeholder.
	 * 
	 * @param placeholder
	 *            the data element to search for
	 * 
	 * @param data
	 *            the data element to insert
	 */
	public void insertAfter(E placeholder, E data) {
		
		// Keeps track of current position, previous position, and the replacement node.
		
		Node current = head;
		Node previous = null;
		Node replacement = new Node(data);

		// If the current node does not contain null or the placeholder,
		// advance current and previous.
		
		while (current != null && !current.containsData(placeholder)) {
			previous = current;
			current = current.next;
		}

		// If placeholder was not found, bail out.
		
		if (current == null) {
			return;
		}
		
		// If the data is found, point new node's next to the current node's next
		// and point the new node's previous to the current node. Also point the current
		// node's next node's previous to the new node and point the current node's next
		// to the new node.
		
		if(previous == null && current.data.equals(placeholder))
		{
			current.next = replacement;
			replacement.previous = current;
			tail = replacement;
			size++;
		}
		else if (current == tail && current.data.equals(placeholder))
		{
			current.next = replacement;
			replacement.previous = current;
			tail = replacement;
			
			size++;
		}
		
		else if (current.data.equals(placeholder)) {
			replacement.next = current.next;
			replacement.previous = current;
			current.next.previous = replacement;
			current.next = replacement;

		// Increase the size.
			size++;
		}
		
		
		
		
		
		
		if (current == tail) {
			tail = previous;
		}

	}

	/**
	 * This class defines 'node' objects, which are the parts of the linked list
	 * used in the queue class above. A single Queue object may create and link
	 * together many Node objects.
	 * <p>
	 * 
	 * Note that this class is inside of the Queue class. The class is private
	 * because we only want to use it within the Queue class.
	 * <p>
	 * 
	 * In the in-class demo, nodes were designed to be singly-linked (forward
	 * only). This assignment requires you to convert the Queue and the Node
	 * classes to use / represent a doubly-linked list. Nodes will have two
	 * references, one that points forwards, and one that points backwards.
	 * <p>
	 * 
	 * @author Peter Jensen
	 */
	private class Node {
		// Instance variables.

		private E data; // The data stored in the node.
		private Node next;// A reference to the next node in the list, or null
		// if none.
		private Node previous;

		/**
		 * Creates a node containing the specified data, and linking to nothing.
		 * 
		 * @param data
		 *            the data to store in this node
		 */
		public Node(E data) {
			this.data = data;
			this.next = null;
			this.previous = null;
		}

		/**
		 * Returns true if this node contains the specified data. This is just a
		 * helper method to make it easier to allow null values to be stored in
		 * the queue. Nulls can be safely compared with this method.
		 * 
		 * @param data
		 *            a data element to compare to the data in this node
		 * 
		 * @return true if the data elements are equal, false otherwise
		 */
		public boolean containsData(E data) {
			if (this.data == null || data == null)
				return this.data == data;
			else
				return this.data.equals(data);
		}
	}

	/**
	 * ToString method that prints out the data in the queue first forwards and
	 * then backwards.
	 * 
	 * 
	 */
	public String toString() {

		// Empty strings and references for the head and tail of the queue.
		Node end = tail;
		Node current = head;
		String output = "";
		String forwards = "";
		String backwards = "";
		String outputtwo = "";

		// Count to to determine when to stop traversing queue and adding to output;
		int count = 0;
		
		while (current != null) {
			
			//Traverses Queue forwards and prints out the data to console.
			
			output = output + current.data + (count < size - 1 ? "," : "");
			current = current.next;
			

			// Traverses Queue backwards and prints out the data to console.
			
			outputtwo = outputtwo + end.data + (count < size - 1 ? "," : "");
			end = end.previous;
			count++;

		}
		forwards = "[" + output + "]";
		backwards = "[" + outputtwo + "]";
		

		return "Forwards: " + forwards + "\n" + "Backwards: " + backwards;
		
		

	}
}
