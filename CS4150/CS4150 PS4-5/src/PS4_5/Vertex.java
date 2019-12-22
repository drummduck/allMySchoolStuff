package PS4_5;

import java.util.ArrayList;

public class Vertex 
{

	private int toll;
	private ArrayList<String> cities;
	private ArrayList<String> cameFrom;
	private int preNum;
	private int postNum;
	private int childCount;
	private boolean visited;
	private boolean done;
	private String name;
	private int defaultToll;
	
	public Vertex(int inToll, String inName) 
	{
		toll = inToll;
		defaultToll = inToll;
		visited = false;
		done = false;
		cities = new ArrayList<String>();
		cameFrom = new ArrayList<String>();
		childCount = 0;
		name = inName;
	}
	
	public ArrayList<String> getCities()
	{
		return cities;
	}
	
	public int getToll()
	{
		return toll;
	}
	
	public void setDone(boolean fred)
	{
		done = fred;
	}
	
	public String getCity(int cityIndex)
	{
		return cities.get(cityIndex);
	}
	
	public void addCity(String city)
	{
		cities.add(city);
	}
	
	public int getPre()
	{
		return preNum;
	}
	
	public int getPost()
	{
		return postNum;
	}
	
	public void setToll(int inToll)
	{
		toll = inToll;
	}
	
	public void setPre(int preIn)
	{
		preNum = preIn;
	}
	
	public void setPost(int postIn)
	{
		postNum = postIn;
		done = true;
	}
	
	public boolean isVisited()
	{
		return visited;
	}
	
	public boolean isDone()
	{
		return done;
	}
	
	public void childDone()
	{
		childCount++;
		if(childCount >= cities.size()) done = true;
	}
	
	
	public String getName()
	{
		return name;
	}
	
	public void setVisit(boolean set)
	{
		visited = set;
	}
	
	public void resetToll()
	{
		toll = defaultToll;
	}
	
	public void reset()
	{
		toll = defaultToll;
	    childCount = 0;
		done = false;
		visited = false;
		cameFrom.clear();
	}
	
	public boolean visitedFrom(String city)
	{
		if(cameFrom.contains(city))
		{
			return true;
		}
		
		else
		{
			cameFrom.add(city);
			return false;
		}
	}
	
	public boolean hasVisited(String city)
	{
		if(cameFrom.contains(city)) return true;
		else return false;
	}
	

}
