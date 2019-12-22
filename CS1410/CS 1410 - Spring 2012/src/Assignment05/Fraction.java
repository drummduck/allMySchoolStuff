package Assignment05;

/**
 * Fraction objects each represent a single rational number in the form:
 * 
 * numerator / denominator
 * 
 * Fraction objects will store their fraction in most-reduced form.
 * 
 * If a fraction object is negative, the numerator will be negative.
 * 
 * If a fraction object contains zero for the denominator, then an execption is
 * thrown.
 * 
 * @author Nathan Donaldson
 * @version February 21, 2012
 */
public class Fraction {
	// Instance variables.

	private long num, den;

	// Methods.

	/**
	 * Constructor - This method is called when 'new' objects are created. given
	 * the two parameters, it will create two longs as long as the second one
	 * is not equal to zero. It will also simplify the two numbers and get the GCD when
	 * put back into fraction form.
	 */
	public Fraction(long n, long d) {
		if (d == 0)
			throw new RuntimeException("Zero denominators not allowed.");

		long gcd = n;
		long remainder = d ;
		

		while (remainder != 0)
		{
			
			long  temp = remainder;
			remainder = gcd % remainder;
			gcd = temp;
			
		}

		if (d < 0) {
			n= n * -1;
			d = d * -1;
		}

		gcd = Math.abs(gcd);
		this.num = n/gcd;
		this.den = d/gcd;

	}

	public Fraction(long n) {
		long d = 1;

		this.num = n;
		this.den = d;
	}

	/**
	 * Accessor methods - simple methods to access variable values. Receives
	 * them from the above method and then returns the result.
	 */
	public long getDenominator() {
		return this.den;
	}

	public long getNumerator() {
		return this.num;
	}

	/**
	 * Takes the current fraction and adds it to another fraction that is
	 * currently stored already and called for addition. Cross multiplies the numerator
	 * and denominator and adds them up for the new numerator and multiplies the denominators
	 * for the new denominator.
	 */
	public Fraction add(Fraction right) {
		long numOne = (this.num * right.den) + (right.num * this.den);
		long numTwo = (this.den * right.den);


	

		return new Fraction(numOne, numTwo);
	}

	/**
	 * Takes the current fraction and subtracts it from another fraction that is
	 * currently stored already and called for subtraction. Does cross multiplication
	 * for the numerator and subtracts the difference then multiplies the denominators 
	 * for the denominator.
	 */
	public Fraction subtract(Fraction right) {

		long numOne = (this.num * right.den) - (right.num * this.den);
		long numTwo = (this.den * right.den);


		

		return new Fraction(numOne, numTwo);
	}

	/**
	 * Takes the current fraction and multiplies it by another fraction that is
	 * currently stored already and called for multiplication. Multiplies the
	 * numerators and multiplies the denominators and returns the result.
	 */
	public Fraction multiply(Fraction right) {

		long numOne = this.num * right.num;
		long numTwo = this.den * right.den;



		

		return new Fraction(numOne, numTwo);
	}

	/**
	 * Takes the current fraction and divides it by another fraction that is
	 * currently stored already and called for division. Multiplies the
	 * numerators and denominators and returns the result.
	 */
	public Fraction divide(Fraction right)

	{
		Fraction result;
		result = new Fraction(this.num * right.den, this.den * right.num);

		return result;
	}

	/**
	 * Automatically called by Java whenever our object should be converted to a
	 * string.
	 */
	public String toString() {

		return num + "/" + den;
	}
}
