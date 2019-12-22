package PS9_5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Map;

/*You are planning a drive along the Yellow Brick Road from Munchkinland to Emerald City. There are n+1 hotels along the route, numbered 0 through n. 

Hotel 0 is in Munchkinland and hotel nn is in Emerald City.

The distance in miles from Munchkinland to hotel i is distance[i], where 0=distance[0]<distance[1]<…<distance[n]. The first hotel is in Munchkinland 

and is (of course) zero miles from Munchkinland, and the final hotel is in Emerald City.

You start in Munchkinland on the morning of day 1, having stayed in the Munchkinland hotel the night before. At the end of each day you must stay in 

one of the hotels; at the end of the last day you must stay in the Emerald City hotel; you may never turn around and drive back toward Munchkinland.

The Good Witch of the North is paying for your trip. She doesn’t want you to drive too far each day (that isn’t safe) or too little each day (that’s 

too expensive). She wants you to drive approximately 400 miles each day, so she makes the following deal. Each day you will drive some distance x to 

reach a hotel. You will owe her a penalty of (400-x)^2 cents for that day. At the end of the trip you will owe her the sum of all the penalties you 

have amassed.

You, of course, want to minimize the total penalty. For example, suppose distance = [0, 350, 450, 825].

The optimal strategy is to drive to hotel 2 on the first day (penalty 2500) and then to hotel 3 the second day (penalty 625), for a total penalty of 

3125 cents.

On the other hand, suppose distance = [0, 350, 450, 700].

The optimal strategy is to drive to hotel 1 on the first day (penalty 2500) and then hotel 3 the second day (penalty 2500), for a total penalty of 5000 

cents.

Given an array of distances, you are to determine the minimum possible penalty that can accumulate when driving from Munchkinland to Emerald City.

Input
The first line contains n, where 1<=n<=1000. The next n+1 lines give the elements of the hotel distance array described above. The first element is 0; 

each successive element is larger than its predecessor; the last element is less than 30000.

Output
Produce a single line of input that contains the minimum penalty for the trip.

Sample Input 1	Sample Output 1
3				3125
0
350
450
825

Sample Input 2	Sample Output 2
3				5000
0
350
450
700
*/
public class underTheRainbow 
{
	public static void main(String[] args) throws IOException 
	{
		int hotels;
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		Map<Integer, Integer> cache = new Hashtable<Integer, Integer>();
		ArrayList<Integer> distances = new ArrayList<Integer>();
		String line = buff.readLine();
		hotels = Integer.parseInt(line);
		
		//Read in arguments and make arrayList tree
		for(int i = 0; i <= hotels; i++)
		{
			line = buff.readLine();
			distances.add(Integer.parseInt(line));
		}
	
		System.out.println(recursiveSolution(distances, 0, 0, cache));
		buff.close();
	}
	
	//My recursion algorithm, tail recursion. Add penalty all the way to end then recurse up, keeping track of the minimum of each tree.
	//Memoized by keeping track of the min of each tree and subtracting the above penalty
	public static int recursiveSolution(ArrayList<Integer> distances, int hotel, int penalty, Map<Integer, Integer> cache)
	{
		int tempMin = 0;
		int subPenalty;
		int minReturn = Integer.MAX_VALUE;
				
		//Check if tree has been calculated. Since above the tree could have a different value, you had to subtract it when adding it to the cache.
		//Therefore when pulling it off, we add the penalty we currently have to that tree.
		if(cache.containsKey(hotel))
		{
			return cache.get(hotel) + penalty;
		}
		
		//End of the tree, just return the penalty value sent in.
		if(hotel == distances.size() - 1)
		{
			return penalty;
		}
		
		//Calculate the penalty of the next stage and recursively go to next stage			
		for(int i = hotel+1; i < distances.size(); i++)  
		{
			subPenalty = (int) Math.pow((400 - (distances.get(i) - distances.get(hotel))), 2);
			tempMin = recursiveSolution(distances, i, penalty+subPenalty, cache);
			minReturn = Math.min(minReturn, tempMin);
		}
		
		//Put tree in cache minus the penalty of above the tree, that gives the cost of the tree.
		cache.put(hotel, minReturn - penalty);

		return minReturn;
	}
	
	//Joe's recursive algorithm. Goes to very bottom of tree and adds while going up. Works better for memoization.
	public static int recursiveSolution2(ArrayList<Integer> distances, int hotel, Map<Integer, Integer> cache)
	{
		int tempMin = 0;
		int minReturn = Integer.MAX_VALUE;
		
		if(hotel == distances.size() - 1) return 0;
		
		if(cache.get(hotel) != null)
		{
			return cache.get(hotel);
		}
		
		for(int i = hotel+1; i < distances.size(); i++)  
		{	
			tempMin = recursiveSolution2(distances, i, cache) + (int) Math.pow((400 - (distances.get(i) - distances.get(hotel))), 2);
			minReturn = Math.min(minReturn, tempMin);
		}
		
		cache.put(hotel, minReturn);
		return minReturn;
	}

}
