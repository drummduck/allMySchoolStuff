package Assignment07;

import java.awt.Color;
import java.awt.Rectangle;
import java.io.File;
import java.util.Arrays;

/**
 * This class is an application that tests the methods in the ArrayExercises
 * class.
 * 
 * @author (your name)
 * @version (a version number or a date)
 */
public class ArrayExercisesClient {
	/**
	 * The application entry point. The application thoroughly tests the
	 * ArrayExercises class static methods.
	 * 
	 * @param args
	 *            not used
	 */
	public static void main(String[] args) {
		/*
		 * Tests for method #1 - public static int count (String[] values,
		 * String target)
		 */

		// A test block. Notice the { and } surrounding this
		// code. This way, we can cut and paste the block
		// and reuse the same variable names. (The variables
		// are local to the BLOCK.)
		{
			// Declare the needed variables.

			String target = "Hello";
			String[] data = new String[] { "Hello", "Hi", "Goodbye", "Hello",
					"Goodbye", "Hello" };

			// call the testing method.
			int count = ArrayExercises.count(data, target);

			// Output the results.

			System.out.print(Arrays.toString(data));
			System.out.println(" contains exactly " + count
					+ " occurrences of the word " + target);
		}

		// PLACE ANOTHER TEST HERE FOR METHOD #1. (Hint - just cut-and-paste
		// the above code and modify it. Try counting "Goodbye" instead.
		{
			String target = "Hi";
			String[] data = new String[] { "Hello", "Hi", "Goodbye", "Hello",
					"Goodbye", "Hello" };

			// call the testing method.
			int count = ArrayExercises.count(data, target);

			// Output the results.

			System.out.print(Arrays.toString(data));
			System.out.println(" contains exactly " + count
					+ " occurrences of the word " + target);
		}
		/* Tests for method #2 - public static void sort (int[] data) */
		{
			int data[] = new int[] { 1, 4, 5, 7, 6, 2, 3, 8, 9 };

			ArrayExercises.sort(data);

			System.out.println(Arrays.toString(data)
					+ "Should now be in decending order");

			// Hint - follow the same pattern as for the tests above.
			// Declare variables, set up data and make the call, output results.
		}
		/*
		 * Tests for method #3 - public static void replace (Object[] list,
		 * Object original, Object replacement)
		 */
		{
			Object[] list = new Object[] { Color.BLACK, Color.ORANGE, Color.RED };

			ArrayExercises.replace(list, Color.BLACK, Color.WHITE);

			System.out.println(Arrays.toString(list));
		}
		/*
		 * Tests for method #4 - public static Color[] remove (Color[] pixels,
		 * Color target)
		 */
		{
			Color[] color = new Color[] { Color.BLACK, Color.ORANGE, Color.RED,
					Color.PINK };
			ArrayExercises.remove(color, Color.RED);
			System.out.println(Arrays.toString(color));
		}

		/*
		 * Tests for method #5 - public static double[] computeAreas (double[]
		 * widths, double[] heights)
		 */
		{
			double[] width = new double[] { 2, 6, 5, 3, 4, 5, 6, 8 };
			double[] height = new double[] { 2.5, 4.6, 2.3, 2, 5, 6, 7, 8 };
			double[] area = ArrayExercises.computeAreas(width, height);

			System.out.println(Arrays.toString(area));
		}

		/* The above tests are all that is required for the lab. */

		/*
		 * Tests for method #6 - public void Character[] reverseOrder
		 * (Character[] symbols).
		 */
		{
			Character[] fudge = new Character[] { 'y', 't', 'e', 'y', 'd' };
			ArrayExercises.reverseOrder(fudge);
			System.out.println(Arrays.toString(fudge));
		}

		/* Tests for method #7 - public static int[] histogram(int[] ages). */
		{
		int[] poop = new int[] { 4, 0, 2, 3, 3, 2, 1, 3, 4, 6, 2, 5, 3, 3, 2 };
		int[] coolboobs52 = ArrayExercises.histogram(poop);
		System.out.println(Arrays.toString(coolboobs52));
		}
		/* Tests for method #8 - public static File[] getUnique(File[] files). */
		File a = new File("alpha");
        File b = new File("beta");
        File c = new File("charlie");
        File d = new File("delta");
        File e = new File("epsilon");
        File f = new File("foxtrot");
        File g = new File("golf");
        File h = new File("hotel");
        File i = new File("india");
        File j = new File("juliet");
        File k = new File("kilo");
        File l = new File("lima");
		{
			File[] turkey = new File[]{a,b,c};
			
			System.out.println(Arrays.toString(ArrayExercises.getUnique(turkey)));
		}
		/*Tests for method #9 - public static Rectangle findSmallest(Rectangle[] rectangles)*/
		
		Rectangle r0 = new Rectangle(0, 10);
		Rectangle r20 = new Rectangle(2, 10);
		Rectangle[] ham = new Rectangle[]{r0,r20,r0};
		
		System.out.println((ArrayExercises.findSmallest(ham)));
	}

}

