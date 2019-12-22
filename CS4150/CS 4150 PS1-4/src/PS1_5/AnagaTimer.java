package PS1_5;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class AnagaTimer 
{

	//Timer for Anaga for words of length 5
	public static void main(String[] args) throws IOException 
	{
		System.out.println("Test variant N or variant K?");
		
		Scanner s = new Scanner(System.in);
		String line = s.nextLine();
		double currentTime;
		double previousTime = 0;
		
		if(line.equals("N"))
		{
			System.out.println("n\t" + "Time\t\t" + "Delta\t\t" + "Ratio");
			s.close();
		//Do it for the amount of words(roughly) in the dictionary.
			for(int n = 1; n <= 171476; n*=2)
			{
				if(n != 1)
				{
					currentTime = 1/((double)TimeNVariable(n)*(10^9));
					System.out.print(n + "\t");
					System.out.printf("%.9f",currentTime);
					System.out.print("\t");
					System.out.printf("%.9f", currentTime - previousTime);
					System.out.print("\t");
					System.out.printf("%.9f", currentTime/previousTime);
					System.out.print("\n");
					previousTime = currentTime;
				}
				
				else
				{
					currentTime = 1/(TimeNVariable(n)*(10^9));
					System.out.print(n + "\t");
					System.out.printf("%f.9", currentTime);
					System.out.print("\n");
					previousTime = currentTime;
				}
			}
		}
		
		else if(line.equals("K"))
		{
			System.out.println("k\t" + "Time\t\t" + "Delta\t\t" + "Ratio");
			s.close();
			//Do it for longest known word in dictionary
			for(int k = 1; k <= 45; k*=2)
			{
				if(k != 1)
				{
					currentTime = 1/((double)TimeKVariable(k)*(10^9));
					System.out.print(k + "\t");
					System.out.printf("%.9f",currentTime);
					System.out.print("\t");
					System.out.printf("%.9f", currentTime - previousTime);
					System.out.print("\t");
					System.out.printf("%.9f", currentTime/previousTime);
					System.out.print("\n");
					previousTime = currentTime;
				}
				
				else
				{
					currentTime = 1/(TimeKVariable(k)*(10^9));
					System.out.print(k + "\t");
					System.out.printf("%f.9", currentTime);
					System.out.print("\n");
					previousTime = currentTime;
				}
			}
		}
		
		else 
		{
			s.close();
			System.out.println("Must enter an N or K, please try running again.");
		}
	}
	
	public static char getRandLetter(int min, int max)
	{
		int range = (max - min) + 1;
		return (char)((int)(Math.random()*range)+min);

	}
	
	public static long TimeNVariable(int size) throws IOException
	{
		//Maybe use a string or arraylist
		String words = "";
		int repititions = 1;
		long timeStart;
		long timeStop;
		long elapsed;
		long totalAverage;
		long overheadAverage;
		words += Integer.toString(size);
		words += " ";
		words += "5\n";
		
		for(int i = 0; i < size ; i++)
		{
			String word = "";
			for(int k = 0; k < 5; k++)
			{
				word += getRandLetter(97, 122);
			}
			
			words += word;
			words += "\n";
		}
		
		InputStream is;
		
		do
		{	
			repititions *= 2;
			timeStart = System.nanoTime();
			for(int i = 0; i < repititions; i++)
			{
				is = new ByteArrayInputStream(words.getBytes());
				AlgToTime(is);			
			}
			timeStop = System.nanoTime();
			elapsed = timeStop - timeStart;
		}while(elapsed < 1000000000);
		totalAverage = elapsed / repititions;		//SIZE TOO!?
		
		elapsed = 0;
		repititions = 1;
		
		do
		{	
			repititions *= 2;
			timeStart = System.nanoTime();
			for(int i = 0; i < repititions; i++)
			{
				is = new ByteArrayInputStream(words.getBytes());
			}
			timeStop = System.nanoTime();
			elapsed = timeStop - timeStart;
		}while(elapsed < 100000000);
		overheadAverage = elapsed / repititions;
		
		return totalAverage - overheadAverage;
	}
	
	public static long TimeKVariable(int length) throws IOException
	{
		//Maybe use a string or arraylist
		String words = "";
		int repititions = 1;
		long timeStart;
		long timeStop;
		long elapsed;
		long totalAverage;
		long overheadAverage;
		words += "2000 ";
		words += Integer.toString(length);
		words += "\n";
		
		for(int i = 0; i < 2000 ; i++)
		{
			String word = "";
			for(int k = 0; k < length; k++)
			{
				word += getRandLetter(97, 122);
			}
			
			words += word;
			words += "\n";
		}
		
		InputStream is;
		
		do
		{	
			repititions *= 2;
			timeStart = System.nanoTime();
			for(int i = 0; i < repititions; i++)
			{
				is = new ByteArrayInputStream(words.getBytes());
				AlgToTime(is);			
			}
			timeStop = System.nanoTime();
			elapsed = timeStop - timeStart;
		}while(elapsed < 1000000000);
		totalAverage = elapsed / repititions;		//SIZE TOO!?
		
		elapsed = 0;
		repititions = 1;
		
		do
		{	
			repititions *= 2;
			timeStart = System.nanoTime();
			for(int i = 0; i < repititions; i++)
			{
				is = new ByteArrayInputStream(words.getBytes());
			}
			timeStop = System.nanoTime();
			elapsed = timeStop - timeStart;
		}while(elapsed < 100000000);
		overheadAverage = elapsed / repititions;
		
		return totalAverage - overheadAverage;
	}
	
	public static void AlgToTime(InputStream is) throws IOException
	{
		
		//Member variables
		int numofWords;
		int lengthofWords;
		ArrayList<String> dictionary = new ArrayList<String>();
		Set<String> solutions = new HashSet<String>();
		Set<String> rejected = new HashSet<String>();
		
		BufferedReader buff = new BufferedReader(new InputStreamReader(is));
		String line = buff.readLine();
		numofWords = Integer.parseInt(line.split("\\s")[0]);
		lengthofWords = Integer.parseInt(line.split("\\s")[1]);
		while ((line = buff.readLine()) != null && line != "")
		{
			dictionary.add(line);
		}
		buff.close();
		//Sort the word and check for anagram
				for(String word: dictionary)
					{
						String sortedWord;
						//sort the word
						sortedWord = sortWord(word.toCharArray(), 0, word.length()-1);
													
						//Check if word is already in solutions
						if(solutions.contains(sortedWord))
						{
							solutions.remove(sortedWord);
							rejected.add(sortedWord);
						}
						
						//If not contained in either, put in solutions.
						else if(!rejected.contains(sortedWord))
						{
							solutions.add(sortedWord);
						}
					}
				
				//System.out.println(solutions.size());
	}
				
				
			
		public static String sortWord(char word[], int left, int right)
			{
				 
				int midPoint = (left+right)/2;
			    char mid = word[midPoint];

			    int i = left;
			    int j = right;
			 
			    while(i <= j)
			    {	 
			        //word[i] is less than mid and i<right
			        while(((int)word[i] < (int)mid) && i < right)
			        {
			            i++;
			        }
			 
			        //word[i] is greater than mid and j>left
			        while(((int)word[j] > (int)mid) && j > left)
			        {
			            j--;
			        }
			 
			        if(i <= j)
			        {
			        	char temp = word[j];
			        	word[j] = word[i];
			        	word[i] = temp;
			            i++;
			            j--;
			        }
			    }
			    	 
			    if(left<j){
			        sortWord(word,left,j);
			    }
			    if(i<right){
			        sortWord(word,i,right);
			    }
			    
			    String sortedWord = new String(word);
			    return sortedWord;
			}
	}


