package PS5_6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

public class rumorMill {

	public static void main(String[] args) throws IOException 
	{
		
		//Member variables
		int numOfStudents;
		int numOfFriendPairs;
		int numOfReports;
		Map<String, Student> students = new Hashtable<String, Student>();
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		
		//Create student Map
		String line = buff.readLine();
		numOfStudents = Integer.parseInt(line);
		for(int i = 0; i < numOfStudents; i++)
		{
			line = buff.readLine();
			students.put(line, new Student(line));
		}
		
		//Add friends together
		line = buff.readLine();
		numOfFriendPairs = Integer.parseInt(line);
		for(int i = 0; i < numOfFriendPairs; i++)
		{
			line = buff.readLine();
			students.get(line.split("\\s")[0]).addFriend(line.split("\\s")[1]);
			students.get(line.split("\\s")[1]).addFriend(line.split("\\s")[0]);
		}
		
		ArrayList<String> sortedKeys=new ArrayList<String>(students.keySet());
		sortedKeys.sort(String.CASE_INSENSITIVE_ORDER);
		
		//Create reports
		line = buff.readLine();
		numOfReports = Integer.parseInt(line);
		for(int i = 0; i < numOfReports; i++)
		{
			line = buff.readLine();
			bfs(students.get(line), students, sortedKeys);
			if(i != numOfReports-1) System.out.print("\n");
		}
		
		buff.close();

	}
	
	
	public static void bfs(Student student, Map<String, Student> map, ArrayList<String> sortedKeys)
	{
		Queue<String> q = new LinkedList<String>();
		ArrayList<String> level = new ArrayList<String>();
		String output;
		Student current = student;
		boolean start = true;
		int count = 0;
		current.setVisited(true);
		q.add(current.getName());
		while(!q.isEmpty())
		{
			current = map.get(q.poll());
			level.add(current.getName());
			current.getFriends().sort(String.CASE_INSENSITIVE_ORDER);
			for(String friend: current.getFriends())
			{
				if(!map.get(friend).isVisited())
				{	
					q.add(friend);
					map.get(friend).setVisited(true);
				}
			}
			if(start == true)
			{
				level.sort(String.CASE_INSENSITIVE_ORDER);
				output = Arrays.toString(level.toArray()).replace("[", "").replace("]", "").replace(",", "");			
				count = 0;
				if(!q.isEmpty())
				{
					q.add(" ");
					System.out.print(output + " ");
				}
				else System.out.print(output);
				output = "";
				level.clear();
				start = false;
			}
			
			else if(q.peek().equals(" "))
			{
				q.poll();
				level.sort(String.CASE_INSENSITIVE_ORDER);
				output = Arrays.toString(level.toArray()).replace("[", "").replace("]", "").replace(",", "");
				count = 0;
				if(!q.isEmpty())
				{
					q.add(" ");
					System.out.print(output + " ");
				}
				else System.out.print(output);
				output = "";
				level.clear();
				}

		}
		
		for(String x: sortedKeys)
		{
			if(map.get(x).isVisited()) map.get(x).setVisited(false);
			else
			{
				System.out.print(" " + x);
			}
		}
		
	}

}
