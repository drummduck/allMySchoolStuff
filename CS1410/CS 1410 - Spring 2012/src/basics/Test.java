package basic;


import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

public class read {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		JFileChooser chooser;

		chooser = new JFileChooser();
		chooser.showOpenDialog(null);

		File f;
		f = chooser.getSelectedFile();

		if (f == null)
			return;

	try{
			Scanner in = new Scanner(f);
			String x = in.nextLine();
			String y = in.next();
			System.out.println(x);
	
	String dollar = "$";
	if (y.equals(dollar))
		System.out.println(y.substring(1));
	}
		
catch (IOException e){}}}
	