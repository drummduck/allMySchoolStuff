package ps6_6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Hashtable;
import java.util.Map;
import java.util.PriorityQueue;

public class GetShorty 
{

	public static void main(String[] args) throws IOException 
	{
		//Member variables
		int numOfCorridors = 0;
		int numOfIntersections = 0;
		Map<Integer, Intersection> dungeon = new Hashtable<Integer, Intersection>();
		
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		String line;
		boolean start = true;
		int m = 0;
		int testCount = 0;
		while ((line = buff.readLine()) != null && line != "")
		{
			if(start == true)
			{
				numOfIntersections = Integer.parseInt(line.split("\\s")[0]);
				numOfCorridors = Integer.parseInt(line.split("\\s")[1]);
				
				if(numOfIntersections == 0 && numOfCorridors == 0) break;
				
				for(int i = 0; i < numOfIntersections; i++)
				{
					dungeon.put(i, new Intersection(i));
				}
				start = false;
				m = 1;
			}
			
			else if(m <= numOfCorridors)
			{
				dungeon.get(Integer.parseInt(line.split("\\s")[0])).addCorridor(dungeon.get(Integer.parseInt(line.split("\\s")[1])), Double.parseDouble(line.split("\\s")[2]));
				dungeon.get(Integer.parseInt(line.split("\\s")[1])).addCorridor(dungeon.get(Integer.parseInt(line.split("\\s")[0])), Double.parseDouble(line.split("\\s")[2]));

				m++;
			}
			
			if(m > numOfCorridors)
			{
				bestPath(dungeon, dungeon.get(0));
				testCount++;
				if(testCount == 20) break;
				dungeon = new Hashtable<Integer, Intersection>();
				start = true;
			}
		}
		buff.close();
	}
	
	
	public static void bestPath(Map<Integer, Intersection> dungeon, Intersection intersection)
	{
		
//		for(Corridor x: intersection.getCorridors())
//		{
//			x.getNext().setFactor(Double.POSITIVE_INFINITY);
//			//x.getNext().setPrevious(null);
//		}
		
		intersection.setFactor(1);
		PriorityQueue<Intersection> queue = new PriorityQueue<>(new IntersectionComparator());
		Hashtable<Integer, Intersection> popped = new Hashtable<Integer, Intersection>();
		queue.add(intersection);
		Intersection current = null;
		
		while(!queue.isEmpty())
		{
			if(!popped.containsKey(queue.peek().getId()))
			{
				current = queue.poll();
				popped.put(current.getId(), current);
			}
			else
			{
				queue.poll();
				continue;
			}
			for(Corridor x: current.getCorridors())
			{
				if((x.getNext().getFactor() < current.getFactor() * x.getWeight()) || (x.getNext().getFactor() == Double.POSITIVE_INFINITY))
				{
					x.getNext().setFactor(current.getFactor() * x.getWeight());
					//x.getNext().setPrevious(current);
					queue.add(x.getNext());
				}
			}
		}
		if(dungeon.get(dungeon.size()-1).getFactor() == Double.POSITIVE_INFINITY) System.out.println("1.0000");
		else
		{
			BigDecimal a = new BigDecimal(new DecimalFormat("0.0000").format(dungeon.get(dungeon.size()-1).getFactor()));
			a.setScale(4, RoundingMode.UP);
			System.out.println(a.toString());
		}
	}

}
