package PS3_3;

import java.math.BigInteger;

public class binaryStuff {

	public static void main(String[] args) 
	{
		int x = dec2bin("1235");
		System.out.println(x);
	}
	
	public static int pwr2bin(int pwr)
	{
		int z;
		if(pwr == 1) return (int) Math.pow(10, pwr);
		
		else  
		{
			z = pwr2bin(pwr/2);			
			return z*z;
		}
	}
	
	public static int dec2bin(String dec)
	{
		if(dec.length() == 1) return Integer.parseInt(dec);
		else
		{
			String decL = dec.substring(0, dec.length()/2);
			String decR = dec.substring(dec.length()/2, dec.length());
			return dec2bin(decL)*pwr2bin(dec.length()/2) + dec2bin(decR);
		}
	}

}
