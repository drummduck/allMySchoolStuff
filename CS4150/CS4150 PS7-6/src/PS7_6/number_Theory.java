package PS7_6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;

//This class is a tester class for modular arithmetic. Including Modular exponents, gcd, modular inverse(Euclid), prime(fermats theorem)
//and RSA
public class number_Theory 
{
	private static boolean bool = false;
	public static void main(String[] args) throws IOException 
	{
		//This reads in a specific formatted set of commands for the calculations
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		String line;

		while((line = buff.readLine()) != "" && line != null)
		{
			if(line.split("\\s")[0].equals("gcd"))
			{
				System.out.println(gcd(Long.parseLong(line.split("\\s")[1]), Long.parseLong(line.split("\\s")[2])));
			}
			
			else if(line.split("\\s")[0].equals("exp"))
			{
				System.out.println(exp(Long.parseLong(line.split("\\s")[1]), Long.parseLong(line.split("\\s")[2]), Long.parseLong(line.split("\\s")[3])));
			}
			
			else if(line.split("\\s")[0].equals("inverse"))
			{
				long x = inverse(Long.parseLong(line.split("\\s")[1]), Long.parseLong(line.split("\\s")[2]));
				if(x == Long.MAX_VALUE) System.out.println("none");
				else System.out.println(x);
			}
			
			else if(line.split("\\s")[0].equals("isprime"))
			{
				isPrime(Long.parseLong(line.split("\\s")[1]));
			}
			
			else if(line.split("\\s")[0].equals("key"))
			{
				key(Long.parseLong(line.split("\\s")[1]), Long.parseLong(line.split("\\s")[2]));
			}
			
			else break;
		}
		
		buff.close();
		
	}
	
	//Computes the GCD of two numbers
	public static long gcd(long l, long m)
	{
		if(m == 0) return l;
		
		else return gcd(m, l%m);
	}
	
	//Finds the modular exponent: (x^y)mod(n)
	public static long exp(long x, long y, long n)
	{
		long z;
		if(y == 0) return 1;
		
		else
		{
			z = exp(x, y/2, n);
			
			if((y%2) == 0) return (long)((z*z)%n);
			
			else return (long)(((z*z)%n)*((x%n))%n);		
		}
	}
	
	//Finds the modular inverse of a number using Euclids Extended algorithm: (a^-1)mod(n)
	public static long inverse(long a, long n)
	{
		long[] tempArray = ee(a, n);
		
		if(tempArray[2] == 1) 
		{
			if((tempArray[0]%n) < 0) return (tempArray[0]%n)+n;
			else return tempArray[0]%n;
		}
		
		else return Long.MAX_VALUE;
	}
	
	//Euclids Extended Algorithm, which returns  [x, y, d] such that d = gcd(a,b) and ax + by = d
	public static long[] ee(long a, long b)
	{
		if(b == 0)
		{
			long[] tempArray = {1, 0, a};
			return tempArray;
		}
		
		else
		{
			long[] tempArray = ee(b, a%b);
			long[] tempArray2 = {tempArray[1], tempArray[0] - ((a/b)*tempArray[1]), tempArray[2]};
			return tempArray2;
		}
		
	}
	
	//Determines if number is prime using Fermats test, with a values 2, 3, and 5: (a^(p-1))mod(p)
	public static void isPrime(long p)
	{
	
		if(exp(2, p-1, p) != 1) 
		{
			System.out.println("no");
			return;
		}

		if(exp(3, p-1, p) != 1) 
		{
			System.out.println("no");
			return;
		}
		
		if(exp(5, p-1, p) != 1) 
		{
			System.out.println("no");
			return;
		}
		
		System.out.println("yes");
	}
	
	//Computes the Modulus, public exponent, and private exponent for RSA algorithm.
	public static void key(long p, long q)
	{
		System.out.print((p*q) + " ");
		long fi = (p-1)*(q-1);
		long e;
		for(long i = 2; ; i++)
		{
			if(gcd(fi,i) == 1)
			{
				System.out.print(i + " ");
				e = i;
				break; 
			}
		}
		
		System.out.println(inverse(e,fi));
	}
	


}
