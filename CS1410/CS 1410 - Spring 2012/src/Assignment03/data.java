package Assignment03;

/**
 *
 * @author Nathan Donaldson
 * @version 2/3/12
 *
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import java.io.IOException;

public class data {

	// This method asks the user to choose a file. It then scans that file
	// and sends it to Read_Line to be read. If the first word in the file = SUMMARY
	// it sends the execution to the method Return_Read_Summary to read the BUY or SELL
	// transactions and adds it to a total. The summary total is also taken during this time
	// so that it may later be compared to all of the sub-summaries.
	// When there is no longer any text to read, it takes the total added up and compares it
	// to the base summary. If it is equal it returns a message box that indicates there are no
	// errors. Otherwise it opens a message box with what date the wrong summary is and what the
	// actual total and what the summary total is.
	public static void main(String[] args) throws IOException {
		JFileChooser chooser;

		chooser = new JFileChooser();
		chooser.showOpenDialog(null);

		File f;
		f = chooser.getSelectedFile();

		Scanner in;
		if (f == null)
			return;

		try {
			in = new Scanner(f);
			Read_Line(in);
		}

		catch (FileNotFoundException e) {
			e.printStackTrace();

		}
		JOptionPane.showMessageDialog(null, "There are no arithmetic errors.");
	}

	// Scans the file. If the word scanned equals SUMMARY then it sends it to the
	// Return_Read_Summary method. Otherwise it adds up the BUY or SELL transactions
	// and stores it in a variable.
	public static int Read_Line(Scanner in) {
		String Start_ReadLine = "SUMMARY";
		String x = in.next();
		if (Start_ReadLine.equals(x)) {
			return Return_Read_Summary(in);
		}

		else {
			String date = in.next();
			String amount = in.next();
			amount = amount.substring(1);
			int pennies = (int) Math.round(Double.parseDouble(amount) * 100);
			return pennies;
		}

	}

	// If the word in the file equals SUMMARY the execution is sent to this method where
	// the summary information is stored and used for the ending dialog message and the
	// comparison with the total amount. If the total and summary total are equal
	// then it sends it back to the main method to complete the execution.
	// If it does not equal them, it opens up a dialog box with information.
	public static int Return_Read_Summary(Scanner in) {

		String date = in.next();
		String amount = in.next();
		amount = amount.substring(1);
		int Summary = (int) Math.round(Double.parseDouble(amount) * 100);
		int Entries = in.nextInt();
		int totalAmount = 0;
		for (int i = 0; i < Entries; i++) {
			int money = Read_Line(in);
			totalAmount += money;
		}

		if (totalAmount == Summary)
			return totalAmount;

		else {
			double awesome = (double) Summary;
			double rad = (double) totalAmount;
			String message = "Summary error on " + date + "\n";
			message = message + "Amount is " + "$" + (rad / 100) + ","
					+ " Should be " + "$" + (awesome / 100);
			JOptionPane.showMessageDialog(null, message);

			System.exit(0);
			return 0;
		}
	}
}
