package assignment7;

public class Edge 
{
  private Vertex other; // 2nd vertex in Edge 

  public Edge(Vertex _other) 
  {
    this.other = _other;
  }

  public Vertex getOtherVertex() 
  {
    return other;
  }

  public String toString() 
  {
    return other.getName();
  }
}
