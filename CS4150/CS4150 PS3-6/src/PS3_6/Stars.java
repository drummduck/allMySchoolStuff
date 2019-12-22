package PS3_6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Stars 
{

	public static void main(String[] args) throws IOException 
	{
		int d;
		int numOfStars;
		ArrayList<Star> PU = new ArrayList<Star>();
				
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		String line = buff.readLine();
		d = Integer.parseInt(line.split("\\s")[0]);
		numOfStars = Integer.parseInt(line.split("\\s")[1]);
		while ((line = buff.readLine()) != null && !line.isEmpty())
		{
			Star tempStar = new Star(Integer.parseInt(line.split("\\s")[0]), Integer.parseInt(line.split("\\s")[1]));;
			PU.add(tempStar);
		}
		buff.close();
		
		int output = biggestGalaxySize(PU, d);
		
		if(output == -1) System.out.println("NO");
		else System.out.println(output);
	}
	
	public static int biggestGalaxySize(ArrayList<Star> u, int d)
	{
		int count = 0;
		Star activeStar = null;
		
		for(int i = 0; i < u.size(); i++)
		{
			if(count == 0)
			{
				activeStar = u.get(i);
				count++;
			}
			
			else
			{
				if((Math.pow(activeStar.xPos - u.get(i).xPos, 2) + Math.pow(activeStar.yPos - u.get(i).yPos, 2)) <= Math.pow(d, 2)) count++;
				else count--;
			}
		}
		
		if(count == 0)
		{
			return -1;
		}
		
			
		else
		{
			count = 1;
			for(int i = 0; i < u.size(); i++)
			{
				if((Math.pow(activeStar.xPos - u.get(i).xPos, 2) + Math.pow(activeStar.yPos - u.get(i).yPos, 2)) == 0) continue;

				if((Math.pow(activeStar.xPos - u.get(i).xPos, 2) + Math.pow(activeStar.yPos - u.get(i).yPos, 2)) <= Math.pow(d, 2)) count++;
			}
		}
		
		if(count > u.size()/2) return count;
		else return -1;
		
	}

}
