package stupid;

public class fraction {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		 int gcd = 4;
		   int remainder = 16;

		    while (remainder != 0)
		    {
		       int temp = remainder;
		        remainder = gcd % remainder;
		        gcd = temp;
		    }
System.out.println(remainder);

	}

}
