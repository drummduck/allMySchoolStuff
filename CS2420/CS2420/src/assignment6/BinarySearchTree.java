package assignment6;

import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.NoSuchElementException;



/**
 * 
 * @author Nathan Donaldson & Michael Fleming.
 *
 * @param <Type>
 */
public class BinarySearchTree<Type extends Comparable<? super Type>> implements
		SortedSet<Type> {
	// The root node of the BST.
	BinaryNode root;
	// no need for this as far as add is concerned,
	// we may need it for remove though....
	// BinaryNode dummy = root;

		// Represents the size of the list
	private int size = 0;

	BinarySearchTree() {
		// As done in the example code, and I quote:

		// "* Note that a no-parameter constructor BinarySearchTree() in(is)
		// needed for the class, which creates an empty BST."

		// It does not say to leave the constructor empty.
		root = null;
	}

	/**
	 * Ensures that this set contains the specified item.
	 * 
	 * @param item
	 *            - the item whose presence is ensured in this set
	 * @return true if this set changed as a result of this method call (that
	 *         is, if the input item was actually inserted); otherwise, returns
	 *         false
	 * @throws NullPointerException
	 *             if the item is null
	 */
	@Override
	public boolean add(Type item) {
			//If the incoming item is null...
		if(item == null)
		{		//...throw exception.
			throw new NullPointerException();
		}
			// If this is the first node to be added to the tree...
		if (root == null) { // ...then designate said node as the root of the
							// tree.
			root = new BinaryNode(item);
			// Increment size of tree.
			size++;
			// Return true for successful addition to the tree.
			return true;
		}

		else {
			if (addRecursive(item, root) == true)
				// If the "addRecursive" method returns true,
				// then return true for successful addition to the tree.
				return true;
			// ...else return false for unsuccessful addition to tree.
			else
				return false;
		}
	}

	
	private boolean addRecursive(Type item, BinaryNode node) { 
		// If item to be added already present in tree...
		if (item.compareTo(node.data) == 0)
			// ...return false for unsuccessful addition to tree.
			return false;
		// if item of node to be added is less than the current node...
		if (item.compareTo(node.data) < 0) {
			// ...and if the current node has an empty slot on its left...
			if (node.left == null) {
				// then add the node to be added to said slot.
				node.left = new BinaryNode(item);
				// Increment size of tree.
				size++;
				// Return true for successful addition to the tree.
				return true;
			}
			// But if there is not an empty slot on the left...
			else { // recurse.
				addRecursive(item, node.left);
			}
		}
		// else if the node to be added needs to go on the right of the current node...
		else {
			// ...and if there is an empty slot on the right of the current node...
			if (node.right == null) { 
				// ...then add the node to be added to the empty slot on the right.
				node.right = new BinaryNode(item);
				// Increment size of tree.
				size++;
				// Return true for successful addition to the tree.
				return true;
			} // But if the slot on the right is occupied...
			else { // ...recurse.
				addRecursive(item, node.right);
			}
		}
		// This is a band aid for my lack of comprehension of the problem at hand. But it seems to be working.
		return false;
	}

	
	 /**
	   * Ensures that this set contains all items in the specified collection.
	   * 
	   * @param items
	   *          - the collection of items whose presence is ensured in this set
	   * @return true if this set changed as a result of this method call (that is,
	   *         if any item in the input collection was actually inserted);
	   *         otherwise, returns false
	   * @throws NullPointerException
	   *           if any of the items is null
	   */
	@Override
	public boolean addAll(Collection<? extends Type> items) {
			//Boolean flag that keeps track of "this" being changed.
		boolean hasChanged = false;
			//Walk through "items"...
		for(Type item: items)
		{		//...call add on each "item".
			if(this.add(item) == true)
			{		//If call to add method returns true, 
						//change boolean flag to true.
				hasChanged = true;
			}
		}	//Return boolean flag.
		return hasChanged;
	}

	/**
	 * Removes all items from this set. The set will be empty after this method
	 * call.
	 */
	@Override
	public void clear() 
	{
			// Set the root to null.
		root = null;
			//Empty tree has zero items.
		size = 0;
	}

	/**
	 * Determines if there is an item in this set that is equal to the specified
	 * item.
	 * 
	 * @param item
	 *            - the item sought in this set
	 * @return true if there is an item in this set that is equal to the input
	 *         item; otherwise, returns false
	 * @throws NullPointerException
	 *             if the item is null
	 */
	@Override
	public boolean contains(Type item) {
		
			//If the incoming item equals null...
		if(item == null)
		{		//...throw exception.
			throw new NullPointerException();		
		}
		// Recursive method call(driver).
		return searchRecursive(item, root);
	}

	private boolean searchRecursive(Type s, BinaryNode n) {
		// Reached the bottom of the tree
		if (n == null)
			return false;

		// Found the item at this node
		if (s.equals(n.data))
			return true;

		// Otherwise, search in left or right subtree
		if (s.compareTo(n.data) < 0) {
			return searchRecursive(s, n.left);
		} else {
			return searchRecursive(s, n.right);
		}
	}
	/**
	   * Determines if for each item in the specified collection, there is an item
	   * in this set that is equal to it.
	   * 
	   * @param items
	   *          - the collection of items sought in this set
	   * @return true if for each item in the specified collection, there is an item
	   *         in this set that is equal to it; otherwise, returns false
	   * @throws NullPointerException
	   *           if any of the items is null
	   */
	@Override
	public boolean containsAll(Collection<? extends Type> items) {
			//Boolean flag.
	boolean  containsAllBoolean = false;
		//For each item in "items"...
	for(Type o: items)
	{		//..if "this" contains said item...
		if(this.contains(o) == true)
		{		//Switch the boolean flag to true.
			containsAllBoolean = true;
		}
			//Else if  any item in "items" is not contained within this...
		else if(this.contains(o) == false)
		{		//...switch boolean flag to false.
			containsAllBoolean = false;
				//if the boolean flag is every switched to false, break out of the loop.
			break;
		}
	}		//return the current state of the boolean.
		return containsAllBoolean;
	}

	/**
	 * Returns the first (i.e., smallest) item in this set.
	 * 
	 * @throws NoSuchElementException
	 *             if the set is empty
	 */
	@Override
	public Type first() throws NoSuchElementException {
		// If tree is empty....
		if (size == 0) 
		{
			// ...Throw an exception.
			throw new NoSuchElementException("Tree is empty, no such item."); 
		}
		// Return the smallest data.
		return root.getLeftmostNode().data;
	}

	/**
	 * Returns true if this set contains no items.
	 */
	@Override
	public boolean isEmpty() {
		// If tree is empty....
		if (size == 0) {
			// ...Return true
			return true;
		}
		return false;
	}

	/**
	 * Returns the last (i.e., largest) item in this set.
	 * 
	 * @throws NoSuchElementException
	 *             if the set is empty
	 */
	@Override
	public Type last() throws NoSuchElementException {
		// If the tree is empty....
		if (size == 0) {
			// ...Throw an exception.
			throw new NoSuchElementException("Tree is empty, no such item.");
		}
		// Return the largest data.
		return root.getRightmostNode().data;
	}
	/**
	   *Removes specified item out of the BinarySearchTree.
	   * 
	   * @param item
	   *          - the item to be removed.
	   * @return True if the item was removed successfully.
	   * 
	   */
	@Override
	public boolean remove(Type item) {
		//Remove driver method.
		return removeRecursive(item, root);
	}
	
	private boolean removeRecursive(Type s, BinaryNode n)
	{
		
		//If current node equals item to be removed....
		 if(n.data.equals(s))
		{
			 // If node left of current isnt null and node right of current isnt null....
			if(n.left != null && n.right != null)
			{
				// ...set current data to successor data.
				n.data = n.right.getLeftmostNode().data;
				// ...Recursively call to remove the successor.
				return removeRecursive(n.data,n.right);
			}
			// If left node of current equals null and right node of current does not equal null....
			else if (n.left == null && n.right != null)
			{
				// ...set current data to successor.
				n.data = n.right.getRightmostNode().data;
				// ...Recursively call to remove the successor.
				return removeRecursive(n.data,n.left);
			}
			// If right node of current equals null and left node of current equals null....
			else if (n.right == null && n.left == null)
			{
				// You are at the root....empty the list.
				clear();
				// decrement size.
				size--;
				
				// return true;
				return true;
			}
			
		}
		// If right node of current doesnt equal null and the data of that node equals the item to be removed....
		  if(n.right != null && n.right.data.equals(s))
		{
			  // If the node right of the right node of current equals null and the node left of the right node of current equals null....
			if(n.right.right == null && n.right.left == null)
			{
				// ...Break the link to the right node.
				n.right = null; 
				// Decrement size.
				size--;
				// return true.
				return true;
			}
			// If the left node of the right node of current doesnt equal null and the right node of the right node of current equals null....
			else if (n.right.left != null && n.right.right == null)
			{
				// ...Break the link to the right node and set it to left node of the right node.
				n.right = n.right.left;
				// decrement size.
				size--;
				// return true;
				return true;
			}
			// If the right node of the right node of current doesnt equal null and the left node of the right node of current equals null....
			else if (n.right.right != null && n.right.left == null)
			{
				// ...Break the link to the right node and set it to the right node of the right node.
				n.right = n.right.right;
				// Decrement size.
				size--;
				// Return true.
				return true;
			}
		}
		// If left node of current doesnt equal null and its data is the item we want to remove....
		 if (n.left != null && n.left.data.equals(s))
		{
			 // If the right node of the left node equals null and the left node of the left node of current equals null....
			if(n.left.right == null && n.left.left == null)
			{
				// ...Break tie to left node.
				n.left = null;
				// Decrement size.
				size--;
				// Return true;
				return true;
			}
			// If the left node of the left node of current isnt null and the right node of the left node of current equals null....
			else if(n.left.left != null && n.left.right == null)
			{
				// ...Break tie with left node and make left node of that node the left of current.
				n.left = n.left.left;
				// Decrement size.
				size--;
				// Return true.
				return true;
			}
			// If the right node of the left node of currrent doesnt equal null and the left node of the right node of current equals null....
			else if(n.left.right != null && n.left.left == null)
			{
				// ...Break tie with left node and set that nodes right to current's left.
				n.left = n.left.right;
				// Decremtn Size.
				size--;
				// Return true.
				return true;
			}
		}
		
	
		// If item is less then current data....
		if (s.compareTo(n.data)<0 && n.left != null)
		{
			// ...Move current node to left.
			return removeRecursive(s,n.left);
		}
		// If item is greater then current data....
		if (s.compareTo(n.data)>0 && n.right != null)
		{
			// ...Move current node to right.
			return removeRecursive(s,n.right);
		}
		// If nothing meet requirements. Removed item does not exist and so remove returns false.
		return false;
	}
	  /**
	   * Ensures that this set does not contain any of the items in the specified
	   * collection.
	   * 
	   * @param items
	   *          - the collection of items whose absence is ensured in this set
	   * @return true if this set changed as a result of this method call (that is,
	   *         if any item in the input collection was actually removed);
	   *         otherwise, returns false
	   * @throws NullPointerException
	   *           if any of the items is null
	   */
	@Override
	public boolean removeAll(Collection<? extends Type> items) {
		
		boolean removeBoolean = false;
		
		for(Type o: items)
		{
			if(this.remove(o) == true)
			{
				removeBoolean = true;
			}
			
			else if(this.remove(o) == false)
			{
				continue;
			}
		}
		return true;
	}
	
	// Driver for writing this tree to a dot file
		public void writeDot(String filename)
		{
			try 
			{
				// PrintWriter(FileWriter) will write output to a file
				PrintWriter output = new PrintWriter(new FileWriter(filename));
				
				// Set up the dot graph and properties
				output.println("digraph BST {");
				output.println("node [shape=record]");
				
				if(root != null)
					writeDotRecursive(root, output);
				// Close the graph
				output.println("}");
				output.close();
			}
			catch(Exception e){e.printStackTrace();}
		}

		
		// Recursive method for writing the tree to  a dot file
		private void writeDotRecursive(BinaryNode n, PrintWriter output) throws Exception
		{
			output.println(n.data + "[label=\"<L> |<D> " + n.data + "|<R> \"]");
			if(n.left != null)
			{
				// write the left subtree
				writeDotRecursive(n.left, output);
				
				// then make a link between n and the left subtree
				output.println(n.data + ":L -> " + n.left.data + ":D" );
			}
			if(n.right != null)
			{
				// write the left subtree
				writeDotRecursive(n.right, output);
				
				// then make a link between n and the right subtree
				output.println(n.data + ":R -> " + n.right.data + ":D" );
			}		
		}

	/**
	 * Returns the number of items in this set.
	 */
	@Override
	public int size() {

		return size;
	}

	@Override
	public ArrayList<Type> toArrayList() {
		// Make an empty ArrayList
		ArrayList<Type> toArray = new ArrayList<Type>();
		// Make reference to root node.
		BinaryNode toArraynode = this.root;
		
		
		// Return the toArray that is filled with method DFT.
		return DFT(toArraynode,toArray);
		
		
	}
	private ArrayList<Type> DFT (BinaryNode n, ArrayList<Type> s) 
	{
		// Stop if n == null. Start going back up tree for right side.
		if(n == null)
			return s;
		// Recursively call DFT for n.left.
	DFT(n.left, s);
	
	// add data of n to s.
	s.add(n.data);
	
	// Recursively call DFT for n.right.
	DFT(n.right, s);
	// Return ArrayList.
	return s;
	}

	// YOU CAN USE THE PRIVATE CLASS BELOW AS YOUR NODE FOR ASSIGNMENT 6
	/**
	 * Represents a general binary tree node. Each binary node contains data, a
	 * left child, and a right child, and a parent.
	 * 
	 * This would make a good node class for a BinarySearchTree implementation
	 * 
	 */
	private class BinaryNode {
		// Since the outer BST class declares <Type>, we can use it here without
		// redeclaring it for BinaryNode
		Type data;

		BinaryNode left;

		BinaryNode right;

		// Adding a parent reference breaks the definition of a tree,
		// but some people find it makes BST management easier.
		// If you choose to use them, remember to update parent pointers
		// when adding/removing nodes!
		BinaryNode parent;

		/**
		 * Construct a new node with known children
		 * 
		 */
		public BinaryNode(Type _data, BinaryNode _left, BinaryNode _right) {
			data = _data;
			left = _left;
			right = _right;
		}

		/**
		 * Construct a new node with no children
		 * 
		 */
		public BinaryNode(Type _data) {
			this(_data, null, null);
		}

		/**
		 * Construct a new node with a known parent
		 * 
		 */
		public BinaryNode(Type _data, BinaryNode _parent) {
			this(_data, null, null);
			parent = _parent;
		}

		/**
		 * Getter method.
		 * 
		 * @return the node data.
		 */
		public Type getData() {
			return data;
		}

		/**
		 * Setter method.
		 * 
		 * @param _data
		 *            - the node data to be set.
		 */
		public void setData(Type _data) {
			data = _data;
		}

		/**
		 * Getter method.
		 * 
		 * @return the left child node.
		 */
		public BinaryNode getLeft() {
			return left;
		}

		/**
		 * Setter method.
		 * 
		 * @param _left
		 *            - the left child node to be set.
		 */
		public void setLeft(BinaryNode _left) {
			left = _left;
		}

		/**
		 * Getter method.
		 * 
		 * @return the right child node.
		 */
		public BinaryNode getRight() 
		{
			return right;
		}

		/**
		 * Setter method.
		 * 
		 * @param _right
		 *            - the right child node to be set.
		 */
		public void setRight(BinaryNode _right) {
			right = _right;
		}

		/**
		 * Getter method.
		 * 
		 * @return the parent of this node.
		 */
		public BinaryNode getParent() {
			return parent;
		}

		/**
		 * Setter method.
		 * 
		 * @param _parent
		 *            - the parent node to be set.
		 */
		public void setParent(BinaryNode _parent) {
			parent = _parent;
		}

		/**
		 * Number of children Use this to help figure out which BST deletion
		 * case to perform
		 * 
		 * @return The number of children of this node
		 */
		public int numChildren() {
			int numChildren = 0;

			if (getLeft() != null)
				numChildren++;
			if (getRight() != null)
				numChildren++;

			return numChildren;
		}

		/**
		 * @return The leftmost node in the binary tree rooted at this node.
		 */
		public BinaryNode getLeftmostNode() {
			// Base case, done for you
			if (getLeft() == null)
				return this; // returns "this" node

			return this.left.getLeftmostNode();
		}

		/**
		 * @return The rightmost node in the binary tree rooted at this node.
		 */
		public BinaryNode getRightmostNode() {
			// Base case, done for you
			if (getRight() == null)
				return this; // returns "this" node

			return this.right.getRightmostNode();
		}

		/**
		 * This method applies to binary search trees only (not general binary
		 * trees).
		 * 
		 * @return The successor of this node.
		 * 
		 *         The successor is a node which can replace this node in a
		 *         case-3 BST deletion. It is either the smallest node in the
		 *         right subtree, or the largest node in the left subtree.
		 */
		public BinaryNode getSuccessor() {
			// FILL IN - do not return null
			return this.right.getLeftmostNode();
		}

		/**
		 * @return The height of the binary tree rooted at this node. The height
		 *         of a tree is the length of the longest path to a leaf node.
		 *         Consider a tree with a single node to have a height of zero.
		 * 
		 *         The height of a tree with more than one node is the greater
		 *         of its two subtrees' heights, plus 1
		 */
		public int height() {
			// dual recursion, gfind the height of the tree, look at both sides,
			// which ever one is bigger equals the height of tree
			// two integer variables to keep track: left/right. for every level
			// you go down return and incremnt upon going back up,
			// then call math.max() to comparer left and right.
			// FILL IN - do not return -1

			if (this.left == null && this.right == null)
				return 0;

			int leftHeight = 0;
			int rightHeight = 0;

			if (this.left != null)
				leftHeight = left.height();

			if (this.right != null)
				rightHeight = right.height();

			return Math.max(leftHeight, rightHeight) + 1;
		}
	}
}
