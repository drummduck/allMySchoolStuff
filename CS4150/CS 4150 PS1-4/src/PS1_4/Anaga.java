//Nathan Donaldson
//CS 4150
//1/17/17
package PS1_4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

//Anaga reads from input, 2 integers and words terminated by a new line.
//First integer is the number of words
//Second integer is the length of the words
public class Anaga 
{

	public static void main(String[] args) throws IOException
	{
		//Member variables
		int numofWords;
		int lengthofWords;
		ArrayList<String> dictionary = new ArrayList<String>();
		Set<String> solutions = new HashSet<String>();
		Set<String> rejected = new HashSet<String>();
		
		
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
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
		
		System.out.println(solutions.size());
	}
	
	static String sortWord(char word[], int left, int right){
		 
		int midPoint = (left+right)/2;
	    char mid = word[midPoint];
//	    word[midPoint] = word[left];
	   // word[left] = mid;
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
