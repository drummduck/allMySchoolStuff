package assignment01;
/** Basic loop that counts up to the limit of the type integer.
 * 
 * @author Nathan Donaldson
 * @version 01/19/2012
 *
 */
public class Simple_Loop {

	public static void main(String[] args) {
		int x = 0;
		int y = -1;
		// As long as x does not equal y,
		// it will add one to x and reassign it and reloop.
		while (x != y)
			x = x + 1;
		
		System.out.println("Loop has finished.");

	}

}
