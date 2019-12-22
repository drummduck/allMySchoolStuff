package PS5_6;

import java.util.ArrayList;

public class Student 
{
	ArrayList<String> friends;
	String name;
	boolean visited;
	
	public Student(String studentName) 
	{
		friends = new ArrayList<String>();
		name = studentName;
		visited = false;
	}
	
	public void addFriend(String friend)
	{
		friends.add(friend);
	}
	
	public ArrayList<String> getFriends()
	{
		return friends;
	}
	
	public String getName()
	{
		return name;
	}
	
	public void setVisited(boolean val)
	{
		visited = val;
	}
	
	public boolean isVisited()
	{
		return visited;
	}

}
