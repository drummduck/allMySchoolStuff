package ps6_6;

public class Corridor 
{

	private Intersection next;
	private double weight;
	
	public Corridor(Intersection inNext, double inWeight) 
	{
		next = inNext;
		weight = inWeight;
	}
	
	public double getWeight()
	{
		return weight;
	}
	
	public Intersection getNext()
	{
		return next;
	}
}
