package lab02;

import java.util.Scanner;

public class Experiments {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int input = 0;

		boolean userInputIsOK = false;

		while (!userInputIsOK) // Loop as long as the user input is NOT ok
		{
			// Get input from the user

			System.out.print("Enter a number between 3 and 5 inclusive: ");
			// input = in.nextInt();

			// Test the input for validity
			// If valid, set userInputIsOK to true

			if (in.hasNextInt())
				input = in.nextInt();
			else
				in.next(); // Get non-integer input, don't bother storing it.

			if (input >= 3 && input <= 5)
				userInputIsOK = true;
			{
				int value = (int) (Math.random() * input); // A type cast -
															// converts the
															// double to an int

				System.out.println(value);
				{// Have the user type in two words

					String firstWord, secondWord;

					System.out.print("Enter a word: ");
					firstWord = in.next();

					System.out.print("Enter another word: ");
					secondWord = in.next();

					if (firstWord.equals(secondWord))
						System.out.println("The words " + firstWord + " and "
								+ secondWord + " are equal.");
					else
						System.out.println("The words " + firstWord + " and "
								+ secondWord + " are not equal.");
				}
			}
		}

	}

	{

	}

}
