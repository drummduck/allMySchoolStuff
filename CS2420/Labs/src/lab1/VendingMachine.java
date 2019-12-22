package lab1;

//Nathan Donaldson
//CS 2420/Sec-001
//Lab 12:55 - 2:00

public class VendingMachine {

	static double computeChange(int selection, double funds)

	// This method is called to compute the difference in the amount of funds
	// compared
	// to the amount of the selected item. If the funds arent sufficient it lets
	// the user know.
	// If the selection isnt valid it lets the user know.
	{
		double change = 0.0;

		if (selection == 1)
		// If 1 is selected.
		{
			if (funds < 0.75)
			// If funds arent sufficient.
			{
				System.out.println("Insufficient Funds");
				return change;
			}
			change = funds - 0.75;
		}

		if (selection == 2)
		// If 2 is selected.
		{
			if (funds < 0.35)
			// If funds arent sufficient.
			{
				System.out.println("Insufficient Funds");
				return change;
			}
			change = funds - 0.35;
		}

		if (selection == 3)
		// If 3 is selected.
		{
			if (funds < 1.25)
			// If funds arent sufficient.
			{
				System.out.println("Insufficient Funds");
				return change;
			}
			change = funds - 1.25;
		}

		if (selection < 1 || selection > 3)
		// If selection isnt available
		{
			System.out.println("Invalid Selection");

		}

		return change;

	}

	public static void main(String[] args) {

		// Tests

		System.out.println("purchasing item 2 with $1.50...");
		System.out.println("returns " + "$" + computeChange(2, 1.50));

		System.out.println("purchasing item 3 with $.75...");
		System.out.println("returns " + "$" + computeChange(3, .75));

		System.out.println("purchasing item 4 with $10.00...");
		System.out.println("returns " + "$" + computeChange(4, 10.00));

		System.out.println("purchasing item 1 with $5.00...");
		System.out.println("returns " + "$" + computeChange(1, 5.00));

		System.out.println("purchasing item 2 with $.35...");
		System.out.println("returns " + "$" + computeChange(2, .35));

		System.out.println("purchasing item 1 with $1000000.00...");
		System.out.println("returns " + "$" + computeChange(1, 1000000.00));
	}

}
