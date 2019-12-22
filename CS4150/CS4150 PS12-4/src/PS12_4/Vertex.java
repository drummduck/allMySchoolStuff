package PS12_4;

import java.util.ArrayList;
import java.util.PriorityQueue;

public class Vertex 
{
	private PriorityQueue<Edge> edges;
	private int total;
	private int id;
	private boolean visited;
	
	public Vertex(int id) 
	{
		this.id = id;
		visited = false;
		edges = new PriorityQueue<Edge>(new EdgeComparator());
		total = 0;
	}
	
	public int getId() {return id;}
	
	public PriorityQueue<Edge> getEdges() {return edges;}
	
	public int getTotal() {return total;}
	
	public boolean getVisited() {return visited;}
	
	public void setId(int id) {this.id = id;}
	
	public void setEdges(PriorityQueue<Edge> edges) {this.edges = edges;}
	
	public void setTotal(int total) {this.total = total;}
	
	public void setVistited(boolean visited) {this.visited = visited;}
	
	public void addEdge(Edge edge) {edges.add(edge);}
	
	public void removeEdge(Edge edge) {edges.remove(edge);}
	
	public int getLightestEdge() {return edges.peek().getWeight();}
	
	public int getEdgesSize() {return edges.size();}
	
	
	
	
	@Override
	public boolean equals(Object o)
	{
		if(o == this) return true;
		
		else if(!(o instanceof Vertex)) return false;
		
		else
		{
			Vertex v = (Vertex) o;
			
			if(v.id == this.id) return true;
			else return false;
		}
	}
}
