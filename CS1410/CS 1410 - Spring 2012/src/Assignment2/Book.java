package Assignment2;

/** This application asks the user for a word to be input and then asks the user
 * to pick a .txt file for that word to be searched in.
 * The application executes and returns the number of total words, the number of words
 * matching the users input word, the average amount of letters used in words, and the amount
 * of characters used within the .txt file.
 * 
 * @author Nathan Donaldson
 * @version 01/26/2012
 * 
 */

// imports the applications used within this application.
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

public class Book {

	public static void main(String[] args) {
		{

			// Creates a menu for user-input, the user input is
			// assigned to a variable.
			String name;

			name = JOptionPane.showInputDialog(null,
					"Enter a word (without spaces) to search"
							+ " for in a book.\n");
			// If the user decides to cancel entering a word, the application is
			// terminated.
			if (name == null)
				return;
			// The user variable is then converted to all lowercase.
			name = name.toLowerCase();

			// The fileChooser type is assigned a variable.
			JFileChooser chooser;

			chooser = new JFileChooser();
			// The file chooser opens.
			chooser.showOpenDialog(null);

			// The user picks a .txt file to be scanned for the word they input.
			File f;
			f = chooser.getSelectedFile();
			// If the user decides to cancel picking a file, the application is
			// terminated.
			if (f == null)
				return;

			try {
				// Scanner is assigned a variable and scans the file that was
				// chosen.
				Scanner in = new Scanner(f);
				int total_words = 0;
				int match_to_input = 0;
				double base_length = 0;
				double characters = 0;

				while (in.hasNext()) {
					// Counts words in book and takes average of word lengths as
					// well
					// as adds the total amount of characters within the .txt
					// file.
					String words;
					// Scans each word.
					words = in.next();
					// Reassigns the words to lowercase.
					words = words.toLowerCase();
					// A count is assigned so that we know how many words are in
					// the book.
					total_words = total_words + 1;
					// Scans each word and gets the character length of each
					// word.
					characters = words.length();
					// Adds up all of the characters used in the book.
					base_length = base_length + characters;

					// Scans the reassigned variable word (which is now the book
					// in lowercase)
					// and checks the user input word to see how many of the
					// word are in the book.
					if (words.equals(name)) {
						match_to_input = match_to_input + 1;
					}

					// I understand the logic on what to do. I have to scan each
					// word. I would have
					// 2 separate loops that scan the words in the document or
					// the lowercase document i reassigned
					// to the variable words. When each word is compared to the
					// input word it should reassign
					// that word and compare that word to other words until the
					// word gets to its lowest point in the alphabetic order.
					// I just don't understand how to assign the word that is
					// alphabetically checked (and that is
					// before or after the input word) to a variable so that it
					// can be checked with each word to see
					// if it is alphabetically before or after. I spent a full 2
					// days on this and tried getting help from TA's
					// If someone could just show me i would probably understand
					// it. Lab queue's are full so there is a limited
					// amount of help everyday. I tried looking in the
					// references and google. I just cant figure it out.
					// I can only put so much time into this so here is the best
					// i got. Please dont give me a bad score :(

					// String before = "";
					// int compare_to_name = words.compareTo(name);
					// int compare_to_before = words.compareTo(before);
					// if (compare_to_name < 0 && compare_to_before >
					// compare_to_name || before.equals (""));{
					// before = words;

					// String afterwords = "";
					// int compare_to_name_after = words.compareTo(name);
					// int compare_to_before_after = words.compareTo(before);
					// if(compare_to_name_after > 0 && compare_to_before_after <
					// compare_to_name || afterwords.equals(""));{
					// afterwords = words;

				}
				// Takes total character count and divides by the total amount
				// of words for the
				// average amount of letters used in each word.
				double average = (base_length / total_words);

				// Displays an informative message: number of total words, the
				// number of words
				// matching the users input word, the average amount of letters
				// used in words, and the amount
				// of characters used within the .txt file.
				String message = "There are " + total_words
						+ " word(s) in the file.\n";
				message = message + "There are " + match_to_input
						+ "match(es) of the word " + name + ".\n";
				message = message + "The average word length is " + average
						+ " characters per word.\n";
				message = message + "There are " + (int) base_length
						+ " characters in this text.\n";
				message = message + "The word ______ comes before " + name
						+ " alphabetically.\n";
				message = message + "The word ______ comes after " + name
						+ " alphabetically.";

				JOptionPane.showMessageDialog(null, message);

				// Closes the try loop.
				in.close();
			}
			// Resists the throwing of error messages.
			catch (IOException e) {
			}

			{
			}
		}
	}
}
	