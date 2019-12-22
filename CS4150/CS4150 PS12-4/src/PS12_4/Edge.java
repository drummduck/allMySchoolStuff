package PS12_4;

public class Edge 
{
	private int weight;
	private Vertex fromVertex;
	private Vertex toVertex = null;
	
	public Edge(int weight, Vertex fromVertex, Vertex toVertex) 
	{
		this.weight = weight;
		this.fromVertex = fromVertex;
		this.toVertex = toVertex;
	}
	
	public int getWeight() {return weight;}
	
	public Vertex getFromVertex() {return fromVertex;}
	
	public Vertex getToVertex() {return toVertex;}
	
	public void setWeight(int weight) {this.weight = weight;}
	
	public void setFromVertex(Vertex fromVertex) {this.fromVertex = fromVertex;}
	
	public void setToVertex(Vertex toVertex) {this.toVertex = toVertex;}
	
	
}
