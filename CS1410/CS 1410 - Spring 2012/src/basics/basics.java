package basics;
/**
 * This short example shows how to compare two strings and how
 * to get the length of a string.
 * 
 * @author Peter Jensen
 * @version January 20, 2012
 */

public class examples
{
    public static void main (String[] args)
    {
        // Create a couple of strings.
        
        String a = "Hello";
        String b = "Hi";
        
        // This example (added after class) shows how to get the length of a string.
        
        int x;
        x = a.length();  // Gets the length of the string object, stores it in x.
        
        // Compare two strings for alphabetic order.  Note: lowercase
        //   letters are considered 'later than' or after all uppercase
        //   letters.
        //
        // An integer is returned that corresponds to the outcome of the
        //   lexicographic (alphabetic) comparison:
        //
        // result < 0  if a < b 
        // result = 0  if a == b
        // result > 0  if a > b
                
        int result = a.compareTo(b);
        
        // Display the results.
        
        if (a.compareTo(b) < 0)
            System.out.println(a + " comes before " + b);
        else
            System.out.println(a + " comes at or after " + b);
        
    }

}
