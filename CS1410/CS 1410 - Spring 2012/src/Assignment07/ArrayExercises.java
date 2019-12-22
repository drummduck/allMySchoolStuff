package Assignment07;

/* No other imports are allowed. */
import java.awt.Color;
import java.awt.Rectangle;
import java.io.File; /* No other imports are allowed. */
import java.util.NoSuchElementException;

/**
 * This class is a collection of static methods for processing arrays. There are
 * no instance or static variables, and none are allowed.
 * <p>
 * 
 * This class is part of the lab for March 6, 2012 and for programming
 * assignment #7.
 * <p>
 * 
 * When completing the lab or the assignment, students may not use any Java
 * library methods for sorting or searching through arrays.
 * <p>
 * 
 * @author ***Nathan Donaldson***
 * @version ***3/5/12***
 */

public class ArrayExercises {
	/**
	 * This method counts and returns how many times the target string occurs in
	 * the array. For this method, two strings are considered the same if they
	 * contain exactly the same text.
	 * <p>
	 * 
	 * <p>
	 * <b>The TA will help you write this method in lab.</b>
	 * 
	 * @param values
	 *            An array of String references
	 * @param target
	 *            A target String object
	 * @return The number of strings in the array that equal the target
	 * @throws NullPointerException
	 *             If values is null
	 */
	public static int count(String[] values, String target) {
		int count = 0;
		for (String s : values)
			if (s.equals(target))
				count++;
		return count;
	}

	/**
	 * This method sorts the elements in the data array in descending order.
	 * (The largest element will be placed in position 0.)
	 * <p>
	 * 
	 * Note that this method does not have a return type - the data array is
	 * sorted 'in place'.
	 * <p>
	 * 
	 * <p>
	 * <b>The TA will help you write this method in lab.</b>
	 * 
	 * @param data
	 *            The array to be sorted
	 * @throws NullPointerException
	 *             If data is null
	 */
	public static void sort(int[] data) {
		for (int i = 0; i < data.length - 1; i++) {
			int max = data[i];
			int index = i;
			for (int j = i + 1; j < data.length; j++)
				if (data[j] > max) {
					max = data[j];
					index = j;
				}
			data[index] = data[i];
			data[i] = max;
		}

	}

	/**
	 * This method examines the elements in the array and replaces all
	 * occurrences of the original object with the replacement object.
	 * <p>
	 * 
	 * For this method, two objects are considered equal if they refer to the
	 * same object. Note that either the original object, the replacement
	 * object, or any of the objects in the list may be null.
	 * <p>
	 * 
	 * This method does not have a return type - the list array is modified
	 * directly.
	 * <p>
	 * 
	 * <p>
	 * <b>You will write this method in lab.</b>
	 * 
	 * @param list
	 *            An array of Object references
	 * @param original
	 *            The object to be replaced
	 * @param replacement
	 *            The replacement object
	 * @throws NullPointerException
	 *             If list is null
	 */
	public static void replace(Object[] list, Object original,
			Object replacement) {

		for (int i = 0; i < list.length; i++) {
			if (list[i].equals(original)) {
				list[i] = replacement;
			}
		}
	}

	/**
	 * This method creates and returns a new array that contains all the colors
	 * stored in the original array, except those colors that are equal to the
	 * target. For this method, two colors are equal if they represent the same
	 * color.
	 * <p>
	 * 
	 * Note that target may be null, and pixels may contain null elements. Two
	 * null elements will be considered equal.
	 * <p>
	 * 
	 * <p>
	 * <b>You will write this method in lab.</b>
	 * 
	 * @param pixels
	 *            An array of Color references
	 * @param target
	 *            The Color object to be removed
	 * @throws NullPointerException
	 *             If pixels is null
	 */
	public static Color[] remove(Color[] pixels, Color target) {
		Color[] fred;
		if (pixels == null || target == null) {
			throw new NoSuchElementException("Illegal: Needs both an array of colors and a color target. ");
		}

		if (pixels == null && target == null) {
			return pixels;
		}
		int removecount = 0;
		for (int i = 0; i < pixels.length; i++) {
			if (pixels[i].equals(target)) {
				removecount++;

				i++;
			}

		}
		int j = 0;
		fred = new Color[pixels.length-removecount];
		for( int i = 0; i < pixels.length;i++)
		{
			if (pixels[i].equals(target))
			{
				continue;
			}
			fred[j]=pixels[i];
			j++;

		}
		return fred;





	}

	/**
	 * This method computes and returns the area of several rectangular regions.
	 * For a rectangle i, width[i] specifies the width of the rectangle, and
	 * height[i] specifies the height of the rectangle. A new array is created
	 * (that is the same size as the width and height arrays) and the area of
	 * each rectangle is computed and placed in this array. (Area of rectangle i
	 * would be stored in the ith position in the array.) The array is then
	 * returned.
	 * <p>
	 * 
	 * This method assumes that the widths and heights are positive.
	 * <p>
	 * 
	 * Note that width and height arrays must be the same size.
	 * <p>
	 * 
	 * <p>
	 * <b>You will write this method in lab.</b>
	 * 
	 * @param widths
	 *            An array of rectangle widths
	 * @param heights
	 *            An array of rectangle heights
	 * @return An array of rectangle areas
	 * @throws NullPointerException
	 *             If widths or heights is null
	 * @throws ArrayIndexOutOfBoundsException
	 *             If widths or heights are not the same size
	 */
	public static double[] computeAreas(double[] widths, double[] heights) {

		if(widths == null || heights == null)
		{
			throw new NullPointerException("Needs both a width and height array.");
		}

		if(widths.length != heights.length)
		{
			throw new ArrayIndexOutOfBoundsException("Arrays need to be equal in length.");	
		}

		double[] area = new double[widths.length];

		for (int i = 0; i<widths.length||i<heights.length; i++)
		{
			area[i] = widths[i]*heights[i];
		}

		return area;
	}

	/**
	 * This method reverses 'in place' the elements in the array. Reversing is
	 * defined as moving the elements in the array such that the first element
	 * becomes the last element, the second element becomes the second to last
	 * element, etc.
	 * <p>
	 * 
	 * <p>
	 * <b>You will write this method as part of programming assignment #7.</b>
	 * 
	 * @param symbols
	 *            An array that will be reversed.
	 */
	public static void reverseOrder(Character[] symbols) {
		Character[] glyphs = new Character[symbols.length];
		int j=0;
		for(int i = symbols.length-1; i>-1; i--)
		{
			glyphs[j]=symbols[i];
			j++;
		}
		for(int i = 0; i < symbols.length; i++)
		{
			symbols[i] = glyphs[i];
		}
	}

	/**
	 * This method counts how many times each value appears in the ages list,
	 * and returns an array of these counts. (If 16 occurs 12 times in the ages
	 * array, then the returned array will contain a twelve in the seventeenth
	 * element of the array.) This method assumes that age values will be
	 * non-negative and small.
	 * <p>
	 * 
	 * The size of the returned list is determined by the maximum value stored
	 * in the ages list. The size of the returned list will be one greater than
	 * the maximum value stored in the ages list.
	 * <p>
	 * 
	 * <p>
	 * <b>You will write this method as part of programming assignment #7.</b>
	 * 
	 * @param ages
	 *            A list ages
	 * @return An array of counts, each element corresponds to one age
	 */

	public static int[] histogram(int[] ages) {
		int max = 0;
		for(int i = 0; i<ages.length;i++)
		{

			if (max < ages[i])
			{
				max = ages[i];
			}


		}

		int [] histogram = new int[max+1];
		for(int i=0;i<histogram.length; i++)
		{
			int count = 0;
			for (int j = 0;j<ages.length;j++)
			{
				if(ages[j] == i)
				{
					count++;
				}
			}

			histogram[i]=count;
		}
		return histogram;
	}

	/**
	 * This method creates and returns a new array that contains a list of the
	 * unique File objects that occur in the files array. For this method, File
	 * objects are the same if they are equal using the .equals method.
	 * <p>
	 * 
	 * The size of the returned list is determined by the number of unique items
	 * in the original list. The order of the items in the returned list is
	 * unspecified.
	 * <p>
	 * 
	 * The files array must not contain null.
	 * <p>
	 * 
	 * <p>
	 * <b>You will write this method as part of programming assignment #7.</b>
	 * 
	 * @param files
	 *            An array of File objects, possibly containing duplicates
	 * @return An array of unique File objects
	 * @throws NullPointerException
	 *             If files is null or contains null
	 */
	public static File[] getUnique(File[] files) {

		if (files.length < 1 )
		{	
			return files;

		}
		
		for (int i = 0; i<files.length;i++)
		{
			if(files[i] == null)
			{
				throw new NullPointerException("Must be an array of non-null file objects.");
			}
		}


		File[] orange = new File[files.length];
		File[] poop = new File[files.length];
		for(int i = 0; i<files.length; i++)
		{
			orange[i] = files[i];
			poop[i] = files[i];
		}
		
		for(int i = 0; i<orange.length; i++)
		{
			for(int j = i+1 ; j<orange.length; j++)
			{		

				if (orange[i] == null || orange[j] == null)
				{
					continue;
				}

				if(orange[i].equals(orange[j]))
				{
					orange[j] = null;
				}



			}
		}

		int max = 0;
		for(int i = 0; i<orange.length; i++)
		{
			int count = 0;
			for(int j = 0; j<orange.length; j++)
			{
				if(orange[i] != null)
				{
					if(orange[i].equals(orange[j]))
					{
						

						count++;
					}


				}
			}
			max = max+count;
		}



		
		File[] pasta = new File[max];
		pasta[0] = orange[0];
		int pastacount = 0;
		for(int i = 0; i<orange.length;i++)
		{

			if(orange[i] == null)
			{
				continue;
			}
			else
			{
				pasta[pastacount] = orange[i];
				pastacount++;
			}
		}
		System.out.println(pasta.length);
		
		return pasta;
	}





	/**
	 * This method finds and returns the smallest rectangle in the array. The
	 * smallest rectangle is defined as the one with the smallest area. If two
	 * rectangles have the same smallest area, the one that occurs last in the
	 * array is returned.
	 * <p>
	 * 
	 * This method requires that the rectangles array must not contain null.
	 * <p>
	 * 
	 * <p>
	 * <b>You will write this method as part of programming assignment #7.</b>
	 * 
	 * @param rectangles
	 *            An array of rectangle objects
	 * @return The smallest rectangle in the array
	 * @throws NullPointerException
	 *             If rectangles is null or rectangles contains null
	 */
	public static Rectangle findSmallest(Rectangle[] rectangles) {


		if (rectangles == null)
		{
			throw new NullPointerException ("Must be an array of non-null rectangle objects.");
		}

		Rectangle smallestRectangle = null;
		double smallestArea = Integer.MAX_VALUE;

		for(int i = 0; i<rectangles.length;i++)
		{
			double width = rectangles[i].getWidth();
			double height = rectangles[i].getHeight();
			double area = width * height;
			if(area <= smallestArea && area > -1)	
			{
				smallestArea = area;
				smallestRectangle = rectangles[i];

			}

		}
		return smallestRectangle;
	}
}
