package assignment01;
/** This program takes the input of the user (only a positive integer) and places into a hailstone sequence. 
 * Once the number input equals one it will terminate the sequence and tell the user how many times it ran through
 * the operations and tell what the original input was.
 * 
 * @author Nathan Donaldson
 * @version 01/19/2012
 */
import java.util.Scanner;

public class HailstoneSequence {

	public static void main(String[] args) {
 
		Scanner in = new Scanner(System.in); 
		int N = 0;
		// Asks the user to input a number. as long as the number is greater than 0 it will move on.
		boolean userInputIsOK = false;

		while (!userInputIsOK) {
			System.out.println("Enter a positive integer: ");
			N = in.nextInt();

			if (N > 0)
				userInputIsOK = true;
			if (N < 0)
				System.out.println("This is not a positive integer!");
		}
		int divisor = 2;
		int factorCount = 0;
		int n = N;
        // Takes the input and reassigns it to another variable. 
		// The variable keeps getting reassigned as it runs through the sequence.
		while (divisor <= n) {

			if (n % divisor == 0)
				{factorCount = factorCount + 1;
			n = n / 2;
			System.out.println(n);}

			else if (n % divisor == 1)
			{	factorCount = factorCount + 1;
			n = (n * 3) + 1;
			System.out.println(n);}
		}
		System.out.println("Number of Iterations: " + factorCount);
		System.out.println("Initial Value: " + N);
	}

}
