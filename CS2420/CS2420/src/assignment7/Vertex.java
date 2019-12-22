package assignment7;

import java.util.LinkedList;
import java.util.Iterator;

public class Vertex implements Comparable<Vertex>
{
	private String name; // used to id the Vertex
	private LinkedList<Edge> adj; // adjacency list  
	private Vertex previous;
	private boolean isVisited;
	private double distance_from_start;
	public int indegree;
	
	public Vertex(String _name) 
	{
	    this.name = _name;
	    this.adj = new LinkedList<Edge>();
	    previous = null;
	    isVisited = false;
	    distance_from_start = 0.0;
	    indegree = 0;
	}
	
	public String getName() 
	{
	    return name;
	}
	
	public void addEdge(Vertex otherVertex) 
	{
	    adj.add(new Edge(otherVertex));
	    otherVertex.indegree ++;
	    
	}
	
	public Iterator<Edge> edges() 
	{
	    return adj.iterator();
	}
	  
	public void setDistanceFromStart(double distance)
	{
		this.distance_from_start = distance;  
	}
	  
	public double getDistanceFromStart()
	{
		  return this.distance_from_start;
	}
	
	public void setVisited(boolean status)
	{
		  this.isVisited = status;
	}
	  
	public boolean getVisited()
	{
		  return this.isVisited;
	}
	  
	public LinkedList<Edge> getEdges()
	{
		  return this.adj;
	}
	  
	public void setPrevious(Vertex prev)
	{
		  this.previous = prev;
	}
	  
	public Vertex getPrevious()
	{
		  return this.previous;
	}
	  
	public String toString() 
	{
	    String s = "Vertex " + name + " adjacent to ";
	    Iterator<Edge> itr = adj.iterator();
	    while (itr.hasNext())
	      s += itr.next() + "  ";
	    return s;
  	}
	

	@Override
	public int compareTo(Vertex arg0) 
	{		
		double diff =  this.getDistanceFromStart() - arg0.getDistanceFromStart();
		if(diff > 0)
			return 1;
		else if (diff < 0)
			return -1;
		else
			return 0;
	}
}
