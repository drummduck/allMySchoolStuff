package PS10_4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Map;
/*
 * A long art gallery has 2N2N rooms. The gallery is laid out as NN rows of 2 rooms side-by-side. Doors connect all adjacent rooms
 *  (north-south and east-west, but not diagonally). The curator has been told that she must close off kk of the rooms because of staffing cuts. 
 *  Visitors must be able to enter using at least one of the two rooms at one end of the gallery, proceed through the gallery, and exit from at least 
 *  one of the two rooms at the other end. Therefore, the curator must not close off any two rooms that would block passage through the gallery. That 
 *  is, the curator may not block off two rooms in the same row or two rooms in adjacent rows that touch diagonally. Furthermore, she has determined 
 *  how much value each room has to the general public, and now she wants to close off those kk rooms that leave the most value available to the 
 *  public, without blocking passage through the gallery.
 *  
 *  ______
 *  | 7| 8|
 *  ------
 *  |4*| 9|
 *  ------
 *  |3*| 7|
 *  ------
 *  | 5| 9|
 *  ------
 *  | 7|2*|
 *  ------
 *  |10| 3|
 *  ------
 *  |0*|10|
 *  ------
 *  |3*| 2|
 *  ------
 *  | 6| 3|
 *  ------
 *  | 7| 9|
 *  ______
 *  Figure 1: The art gallery shows an optimal solution to the third sample input problem. The starred rooms show those that should be closed.
 *  
 *  Input
Input will consist of multiple problem instances (galleries). Each problem instance will begin with a line containing two integers N and k, 
where 3<=N<=200 gives the number of rows, and 0<=k<=N gives the number of rooms that must be closed off. This is followed by N rows of two 
integers, giving the values of the two rooms in that row. Each room’s value v satisfies 0<=v<=100. A line containing 0 0 will follow the last 
gallery.

Output
For each gallery, output the amount of value that the general public may optimally receive, one line per gallery.

Sample Input 1	Sample Output 1
6 4				17
3 1
2 1
1 2
1 3
3 3
0 0
0 0

Sample Input 2	Sample Output 2
4 3				17
3 4
1 1
1 1
5 6
0 0

Sample Input 3	Sample Output 3
10 5			102
7 8
4 9
3 7
5 9
7 2
10 3
0 10
3 2
6 3
7 9
0 0

 */
public class NarrowArtGallery 
{
	public static void main(String[] args) throws IOException 
	{
		int rows;
		int doorsToClose;
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		Map<Triple, Integer> cache = new Hashtable<Triple,Integer>();
		String line = buff.readLine();
		rows = Integer.parseInt(line.split("\\s")[0]);
		doorsToClose = Integer.parseInt(line.split("\\s")[1]);
		int[][] gallery = new int[rows][2];
		
		for(int i = 0; i < rows; i++)
		{
			line = buff.readLine();
			gallery[i][0] = Integer.parseInt(line.split("\\s")[0]);
			gallery[i][1] = Integer.parseInt(line.split("\\s")[1]);
		}
		
		System.out.println(maxValue(0, -1, doorsToClose, gallery, cache));
	}
	
	//This method recursively calls itself to find the greatest possible value of gallery rooms given the amount of rooms you should close. As
	//Well as the restriction of which door to keep open for each possible case in the recursion. Dynamic programming used.
	public static int maxValue(int row, int keepOpen, int doorsToClose, int[][] gallery, Map<Triple, Integer> cache)
	{
		//If cached, return
		if(cache.containsKey(new Triple(row, keepOpen, doorsToClose))) return cache.get(new Triple(row, keepOpen, doorsToClose));
		//Return negative INF if its not a valid option of rooms, return 0 if it works.
		else if(row == gallery.length)
		{
			if (doorsToClose == 0) return 0;
			else	return Integer.MIN_VALUE;
		}	
		
		int zeroValue;
		int oneValue;
		int negativeOneValue;
		int returnValue;
		//All possibilities when keeping door 0 open.
		if(keepOpen == 0)
		{
			returnValue = gallery[row][0] + maxValue(row+1, 0, doorsToClose-1, gallery, cache);
			returnValue = Math.max(returnValue, gallery[row][0] + gallery[row][1] + maxValue(row+1, -1, doorsToClose, gallery, cache));
			cache.put(new Triple(row, keepOpen, doorsToClose), returnValue);
			return returnValue;
		}
		//All possibilities when keeping door 1 open
		else if(keepOpen == 1)
		{
			returnValue = gallery[row][1] + maxValue(row+1, 1, doorsToClose-1, gallery, cache);
			returnValue = Math.max(returnValue, gallery[row][0] + gallery[row][1] + maxValue(row+1, -1, doorsToClose, gallery, cache));
			cache.put(new Triple(row, keepOpen, doorsToClose), returnValue);
			return returnValue;
		}
		//All possibilities otherwise
		else
		{
			returnValue = gallery[row][0] + maxValue(row+1, 0, doorsToClose-1, gallery, cache);
			returnValue = Math.max(returnValue, gallery[row][1] + maxValue(row+1, 1, doorsToClose-1, gallery, cache));
			returnValue = Math.max(returnValue, gallery[row][0] + gallery[row][1] + maxValue(row+1, -1, doorsToClose, gallery, cache));
			cache.put(new Triple(row, keepOpen, doorsToClose), returnValue);
			return returnValue;
		}
	}
}
