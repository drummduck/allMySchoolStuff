package Lab10;

import java.io.*;
import java.util.*;

/**
 * This application just sorts a list of person objects in various ways.
 * 
 * @author (Nathan Donaldson)
 * @version Spring 2012
 */
public class Application {
	public static final int n = 50; // This constant determines how many Person
									// objects

	// are printed to the console.

	public static void main(String[] args) {
		try {
			ArrayList<Person> list;
			list = new ArrayList();
			// Create an ArrayList to hold the person objects.
			// Name the variable 'list'.

			File f = new File("data.txt");
			// Open the data file.
			Scanner in = new Scanner(f);
			// Read in all the data, create Person objects, and add them to the
			// array list.
			while (in.hasNext()) {
				list.add(new Person(in.next(), in.nextInt(), in.nextDouble()));
			}

			// Close the data file.
			in.close();

			// Print the first N person objects to the console.

			String message = "First " + n + " people in the data file:";
			System.out.println(message);
			for (int i = 0; i < message.length(); i++)
				System.out.print("-");
			System.out.println();
			for (int i = 0; i < n; i++) {
				Person p = list.get(i);
				System.out.println(p);
			}
			System.out.println();

			Collections.sort(list, new PersonScoreComparator());
			// Sort the list of Person objects by descending score (highest
			// score first).
			// In case of ties, sort tied elements in order of ascending names.
			// (Names are unique.)
			Collections.sort(list, new PersonAgeComparator());
			// Print the first N person objects to the console.

			// Sort the list of Person objects in order of ascending age (lowest
			// age first).
			// In case of ties, sort tied elements in order of ascending scores.
			// If both
			// ages and scores are tied, sort tied elements in order of
			// descending names.

			// Print the first N person objects to the console.
		} catch (IOException e) {
			System.out.println("An I/O exception terminated this application.");
			System.out.println("Reason: " + e.getMessage());
		}
	}

	private static class PersonScoreComparator implements Comparator<Person> {

		@Override
		public int compare(Person arg0, Person arg1) {

			if (arg0.getscore() > arg1.getscore()) {
				return -1;
			} else if (arg0.getscore() < arg1.getscore()) {
				return 1;
			} else {
				return arg0.getname().compareTo(arg1.getname());
			}
		}

	}

	private static class PersonAgeComparator implements Comparator<Person> {

		@Override
		public int compare(Person arg0, Person arg1) {
			if (arg0.getage() > arg1.getage()) {

				return -1;
			}

			else if (arg0.getage() < arg1.getage()) {
				return 1;
				
			} else {
				return arg0.getscore()compareTo(arg1.getscore());
			}
		}
	}
}



