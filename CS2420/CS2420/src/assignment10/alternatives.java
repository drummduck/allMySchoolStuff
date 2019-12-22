package assignment10;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;

import assignment10.alternatives.Word;

public class alternatives {
	
	public ArrayList outputArray = new ArrayList();
	public HashMap hashy;
	public PriorityQueue<Word> queue = new PriorityQueue<Word>();
	
	
	
	public void deletion(String input)
	{
		outputArray.add("deletions:");
		String original = input.toLowerCase();		//Suspect
		StringBuilder sbuild = new StringBuilder(original);
		String output;
		for(int pos = 0; pos < input.length();pos++)   //< or <=?
		{
		sbuild = new StringBuilder(original);
		output = sbuild.deleteCharAt(pos).toString();
		outputArray.add(output);
		
		
		//COMPARE THIS STRING TO FILE!
		//If the alternative is true, add to priority queue.
		//If not move to next alternative.
		
		}
	
		
		
		
	}
	
	public void transposition(String input)
	{
		outputArray.add("transpositions:");
		char holder;
		String initial = input.toLowerCase();
		String original = initial;
		for(int pos = 0; pos < input.length(); pos++)
		{
			
			original = initial;  	//Suspect
			holder = original.charAt(pos);
			original.replace(original.charAt(pos),original.charAt(pos + 1));
			
			original.replace(original.charAt(pos + 1), holder);      //May not have to set variable to input.
			outputArray.add(original);
			
			//COMPARE THIS STRING TO FILE!
			//If the alternative is true, add to priority queue.
			//If not move to next alternative.
			
		}
	}
	
	public void substitution(String input)
	{
		outputArray.add("substitutions:");
		String initial = input.toLowerCase();
		String original = initial;
		String alternative;
		int asciiRange = 97;
		
		for(int pos = 0; pos < original.length(); pos++)
		{
			while(asciiRange < 123)
			{
				alternative = original.replace(original.charAt(pos), (char)asciiRange);
				outputArray.add(alternative);
				
				//Check for alternative validity
					//if it is valid, add it to the PQ.
				
				asciiRange++;
				original = initial;
			}
			
			asciiRange = 97;
		}
		
	}
	
	public void insertion(String input)
	{
		outputArray.add("insertions:");
		String original = input.toLowerCase();
		StringBuilder alternativePenetration = new StringBuilder(original);
		String alternative;
		int asciiRange = 97;
		
		for(int pos = 0; pos < input.length(); pos++)
		{
			while(asciiRange < 123)
			{
				alternative = alternativePenetration.insert(pos, (char)asciiRange).toString();
				outputArray.add(alternative);
				
				//Check for alternative validity
					//if it is valid, add it to the PQ.
				
				
				alternativePenetration = new StringBuilder(original);
				asciiRange++;
			}
			
			asciiRange = 97; 
		}
		
	}
	
	
	
	
	public class Word {
		
		public String word;
		public int frequency;
		
		public void Word(String inputWord, int inputFrequency)
		{
			word = inputWord;
			frequency = inputFrequency;
		}
	}
	
	public class Wordcompare implements Comparator<Word>
	{

		@Override
		public int compare(Word o1 , Word o2) {
			
			if(o1.frequency > o2.frequency)
			return 1;
			
			else if(o1.frequency < o2.frequency)
				return -1;
			
			else
			{
				if(o1.word.compareTo(o2.word) > 1)
					return 1;
				
				else if(o1.word.compareTo(o2.word) < 0)
					return -1;
				
				else
					return 0;
			}
			
			
		}
		
	}

}
