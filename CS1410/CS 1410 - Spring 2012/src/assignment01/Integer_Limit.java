package assignment01;

/**
 * This program takes the Hailstone Sequence and figures out which number
 * counting up from zero creates a negative integer or the limit of the type
 * integer.
 * 
 * @author Nathan Donaldson
 * @version 01/19/2012
 * 
 */

public class Integer_Limit {

	public static void main(String[] args) {

		int Y = 1;
		int divisor = 2;
		int factorCount = 0;

		// As long as Y is greater than zero,
		// It goes through both of the while loops.
		while (Y > 0) {
			int n = Y;

			while (divisor <= n) {

				if (n % divisor == 0) {
					factorCount = factorCount + 1;
					n = n / 2;
				}

				else if (n % divisor == 1) {
					factorCount = factorCount + 1;
					n = (n * 3) + 1;
					if (n < 0)
						break;
				}
			}
			// Y gets reassigned everytime to figure out which number creates a
			// negative integer.
			// Once N reaches a negative number the Y count is printed out.
			Y = Y + 1;
			if (n < 0)
				break;
			System.out.println(Y);

		}
		{
			System.out.print("The Integer " + Y);
			System.out.print(" cannot have its hailstone sequence computed using int variables.");
		}
	}
}


