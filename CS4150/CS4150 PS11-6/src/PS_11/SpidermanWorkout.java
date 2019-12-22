package PS_11;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Map;

public class SpidermanWorkout 
{
	public static void main(String[] args) throws IOException 
	{
		//Read in number of scenarios
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		int numOfScenarios = Integer.parseInt(buff.readLine());
		
		//Do each scenario
		while(numOfScenarios != 0)
		{
			int scenario;
			scenario = Integer.parseInt(buff.readLine());
			int[][] distanceMatrix = new int[41][1000];
			
			//Fill distance matrix with max values to start
			for(int[] row : distanceMatrix) Arrays.fill(row, Integer.MAX_VALUE);
			
			//Set starting point
			distanceMatrix[0][0] = 1;
			int[] distances = new int[41];
			String line = buff.readLine();
			int currentDistance;
			
			//Create distance array for scenario
			for(int i = 0; i < scenario; i++) distances[i] = Integer.parseInt(line.split("\\s")[i]);

			//Set max and min heights for each level distance step.
			for(int i = 1; i <= scenario; ++i)
			{
				currentDistance = distances[i-1];
				for(int j = 0; j+currentDistance < 1000; ++j) if(distanceMatrix[i-1][j] < Integer.MAX_VALUE) distanceMatrix[i][j+currentDistance] = Math.max(distanceMatrix[i-1][j], j+currentDistance);
				for(int j = currentDistance; j < 1000; ++j) if(distanceMatrix[i-1][j] < Integer.MAX_VALUE) distanceMatrix[i][j-currentDistance] = Math.min(distanceMatrix[i][j-currentDistance], distanceMatrix[i-1][j]);	
			}
			
			//Current scenario we are on
			if(distanceMatrix[scenario][0] < Integer.MAX_VALUE)
			{
				StringBuilder s = new StringBuilder();
				s.setLength(scenario);
				//Set the max height of the scenario for checking
				int maxHeight = distanceMatrix[scenario][0];
				int currentHeight = 0;
				
				//Go through each element in array and run it through distance matrix to figure out what
				//String to print out.
				for(int i = scenario-1; i >= 0; --i)
				{
					int down = currentHeight - distances[i];
					int up = currentHeight + distances[i];
					
					if(0 <= down && down < 1000 && distanceMatrix[i][down] <= maxHeight)
					{
						currentHeight = down;
						s.setCharAt(i, 'U');
					}
					
					else
					{
						currentHeight = up;
						s.setCharAt(i, 'D');
					}
				}
				
				System.out.println(s.toString());
				numOfScenarios--;
			}
			
			else 
			{
				System.out.println("IMPOSSIBLE");
				numOfScenarios--;
			}
		}
	}

}
