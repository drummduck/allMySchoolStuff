package Assignment05;
/**
 * 
 * This is a tester for the Fraction class.
 * 
 * Tests reduction, addition, subtraction, multiplication, division, getDenominator(),
 * and getNumerator().
 * 
 * 
 * 
 * @author Nathan Donaldson
 * @version 2/21/12
 *
 */
public class test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Fraction f = new Fraction(4,-6);
		Fraction g = new Fraction (2,8);
		Fraction a = new Fraction (3,-16);
		Fraction r = new Fraction (-10,20);
		Fraction p = new Fraction (-18,16);

	

		
			//Reduction
			System.out.println(f);
			System.out.println(g);
			System.out.println(r);
		
		
			//Addition
			System.out.println(f.add(g));
			System.out.println(a.add(r));
			System.out.println(r.add(p));
			
		
		
			//Subtraction
			System.out.println(r.subtract(p));
			System.out.println(r.subtract(f));
			System.out.println(g.subtract(p));

		
		

			// Division

			System.out.println(a.divide(r));
			System.out.println(a.divide(g));
			System.out.println(r.divide(p));
			
		
			//Multiplication
			System.out.println(f.multiply(g));
			System.out.println(a.multiply(g));
			System.out.println(a.multiply(p));
			
			//Retrieve Denominator
			
			System.out.println(f.getDenominator());
			System.out.println(g.getDenominator());
			System.out.println(a.getDenominator());
			
			
			
			
			//Retrieve Numerator
			
		System.out.println(f.getNumerator());
		System.out.println(g.getNumerator());
		System.out.println(a.getNumerator());
	}


}

