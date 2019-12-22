package lab04;

import java.util.Scanner;

/**
 * This program asks the user to input a word, and then the program detects the
 * following:
 * <p>
 * - The first occurrence of the letter 'a' in the word.<br>
 * - The first character that occurs more than once in the word.<br>
 * - The first repeated character in the word.
 * <p>
 * 
 * Uppercase letters in the user's input will be treated as if they were
 * lowercase.
 * 
 * @author Nathan Donaldson
 * @version Spring 2012
 */
public class WordPatterns {
	/**
	 * The entry point for this application. This method is called when the
	 * application is launched or run from the command line.
	 * 
	 * @param args
	 *            An array of arguments (if any) from the command line.
	 */
	public static void main(String[] args) {
		// A few variables.

		String userInput; // Must be outside the loop body to
		// be used in the condition.

		Scanner keyboard = new Scanner(System.in); // We repeatedly scan for
													// words, so
		// create one Scanner here instead
		// of creating a new Scanner each time
		// through the loop.

		// Get a word from the user, loop until the user enters '0'.

		// A do-while loop. Notice the condition is at the END of the
		// loop. The loop body will always execute the first time, but
		// it may not execute a second time. (This loop style is rarely used.)

		do {
			// Prompt the user, get a word from the user.

			System.out.print("Enter a word, or 0 to exit: ");
			userInput = keyboard.next();
			userInput = userInput.toLowerCase();

			// Analyze the word, print out results.

			System.out.println();
			System.out.println("Results for word " + userInput);
			int value = indexOfMultipleCharacter(userInput);
			System.out.println(userInput.charAt(value));
			// Analysis code will go here.

		} while (userInput.equals(0));

		int firstA;
		firstA = findAfter(userInput, 'a', 0);
		if (firstA != -1)
			System.out.println("The first 'a' is at position " + firstA + ".");
		else
			System.out.println(userInput + " does not contain an 'a'.");

		
		
		// All done, print a message and exit.

		System.out.println("Goodbye.");

		return; // Not needed, method will return anyways. This is
		// just an example.
	}

	/**
	 * This method searches through a target string and finds the position of
	 * the first occurrence of the specified character. The method returns the
	 * position of the specified character, or -1 if not found. (Note that it is
	 * guaranteed that the return value will either be -1, or it will be greater
	 * than or equal to the specified position.)
	 * 
	 * @param target
	 *            A String to search through.
	 * @param c
	 *            A character to look for.
	 * @param position
	 *            The position of the first character to check.
	 * @return The first index of the character, or -1.
	 */
	public static int findAfter(String target, char c, int position) {
		// Loop from position to the end of the String. If the
		// character is found, return its index.

		// Print the position of the first 'A' or 'a' in the String.

		for (int i = position; i == target.length(); i++)
			if (target.charAt(i) == c)
				return i;

		// If execution gets this far, the character was not
		// found. Return -1 to indicate this.

		return -1;
	}

	/**
	 * Returns the index of the first character in the word where that character
	 * occurs more than once. For example, in the word 'singing', 'i' is the
	 * first character that occurs more than once in the word. Returns -1 if no
	 * character occurs more than once in the word.
	 * 
	 * @param word
	 *            The word to search for multiple characters
	 * @return The index of the first character that appears at least twice, or
	 *         -1 if none.
	 */
	public static int indexOfMultipleCharacter(String word) {
		for (int i = 0; i < word.length(); i++) {
			char c = word.charAt(i);
			if (findAfter(word, c, i + 1) > 0)

				return i;
		}

		return -1;
	}

}