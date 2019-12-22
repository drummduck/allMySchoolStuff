package PS4_5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;

public class AutoSink 
{

	public static void main(String[] args) throws IOException 
	{
		//Member variables
		int numberOfCities;
		int numOfHighways;
		int numOfTrips;
		ArrayList<String> sortedArray = new ArrayList<String>();
		Map<String, Vertex> roadMap = new Hashtable<String, Vertex>();	
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		
		//Get the Cities
		String line = buff.readLine();
		numberOfCities = Integer.parseInt(line);
		if(numberOfCities == 0)
		{
			System.out.println("NO");
			return;
		}
		for (int i = 0; i < numberOfCities; i++)
		{
			line = buff.readLine();
			roadMap.put(line.split("\\s")[0], new Vertex(Integer.parseInt(line.split("\\s")[1]), line.split("\\s")[0]));
		}
		
		//Get the highways connected
		line = buff.readLine();
		numOfHighways = Integer.parseInt(line);
		for(int i = 0; i < numOfHighways; i++)
		{
			line = buff.readLine();
			roadMap.get(line.split("\\s")[0]).addCity(line.split("\\s")[1]);
		}
		
		//Topologically sort
		//Vertex temp = (Vertex) roadMap.values().toArray()[0];		
		sortedArray.addAll(dfs(roadMap));
		
		
		//Start doing trips
		line = buff.readLine();
		numOfTrips = Integer.parseInt(line);
		if(numOfTrips == 0)
		{
			System.out.println("NO");
			return;
		}
		
		//Reset all variables in vertex's
		for(String city: sortedArray)
		{
			roadMap.get(city).reset();
		}
		
		for(int i = 0; i < numOfTrips; i++)
		{	
			line = buff.readLine();
			String start = line.split("\\s")[0];
			String end = line.split("\\s")[1];
			if(start.equals(end))
			{
				System.out.println("0");
			}
			else
			{
				int answer = cheapestPath(roadMap, sortedArray, start, end);
				if(answer == -1) System.out.println("NO");
				else System.out.println(answer);
			}
		}
		buff.close();
	}
	
	
	
	public static ArrayList<String> dfs(Map<String, Vertex> map)
	{
		ArrayList<String> sort = new ArrayList<String>();
		for(String x: map.keySet())
		{
			if(!map.get(x).isVisited())
			{
				explore(map, map.get(x), sort);
			}
		}
		
		return sort;
	}
	
	public static ArrayList<String> explore(Map<String, Vertex> map, Vertex v, ArrayList<String> sort)
	{
		v.setVisit(true);
		for(String x: v.getCities())
		{
			if(!map.get(x).isVisited())
			{
				explore(map, map.get(x), sort);
			}			
		}
		 sort.add(0, v.getName());
		
		return sort;
	}
	
	public static int cheapestPath(Map<String, Vertex> map, ArrayList<String> sort, String start, String end)
	{	
		Vertex current = map.get(start);
		if(map.get(start).getCities().size() == 0) return -1;
		if(map.get(end).getCities().size() == 0 && sort.indexOf(map.get(end)) == 0) return -1;
		current.setToll(0);
		Stack<Vertex> stack = new Stack<Vertex>();
		int pos = sort.indexOf(start);
		int min = Integer.MAX_VALUE;
		while(pos < sort.size())
		{
			
			if((pos+1 > sort.size() && !current.getName().equals(end)) || (current.getCities().size() == 0 && !current.getName().equals(end)))
			{
				
				if(current.getCities().size() == 0) current.childDone();
				current.resetToll();
				current = stack.pop();
				current.childDone();
				pos = sort.indexOf(current.getName());
			}
			
			else if(current.getName().equals(end))
			{
				if(map.get(end).getToll() < min)
				{
					min = map.get(end).getToll();
				}
				current.resetToll();
				current = stack.pop();
				current.childDone();
				pos = sort.indexOf(current.getName());
			}
			
			else if(current.isDone())
			{
				
	
				if(current.getName().equals(start))
				{
					if(min == Integer.MAX_VALUE)
					{
						min = -1;
						break;
					}
					
					break;
				}
				
				current.setDone(false);;
				if(pos+1 < sort.size()) pos = sort.indexOf(current.getName()+1);
				else pos = sort.indexOf(current.getName()+1);
				current = stack.pop();
				current.childDone();
				
			}
			
			else if(pos+1 < sort.size() && current.getCities().contains(map.get(sort.get(pos+1)).getName()))
			{
				if(map.get(sort.get(pos+1)).hasVisited(current.getName()))
				{
					pos++;
					continue;
				}
				
				else
				{
					stack.push(current);
					map.get(sort.get(pos+1)).setToll(current.getToll() + map.get(sort.get(pos+1)).getToll());
					map.get(sort.get(pos+1)).visitedFrom(current.getName());
					current = map.get(current.getCity(current.getCities().indexOf(sort.get(pos+1))));
					pos++;
				}
			}
			
			else pos++;
		}
		
		for(String city: sort)
		{
			map.get(city).reset();
		}
		
		return min;
	}

}
