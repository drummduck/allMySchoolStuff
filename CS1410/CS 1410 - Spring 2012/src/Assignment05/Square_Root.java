package Assignment05;
/**
 * This application takes a prime number and finds it's square root.
 * 
 * @author Nathan Donaldson
 * @version 2/21/12
 * 
 * 
 */
import java.util.Scanner;
public class Square_Root {
	
	
	

	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		long s= 0;
		System.out.println("Enter a number to find its square root: ");
		
		

		s=(long)in.nextInt();
		
		
		long z =0;
		long y = 0;
		double square_root=0;
		Fraction x = new Fraction (s,2);
		for (int i = 0; i < 4; i++)
		{ 
			x = (x.divide(new Fraction(2))).add((new Fraction(s)).divide(x.multiply(new Fraction(2))));


			z = x.getDenominator();

			y = x.getNumerator();
		}
		if((double)y/z > 0){
			square_root = (double)y/z;}

		if((double)y/z < 0);{

			System.out.println(square_root);}

	}

}


