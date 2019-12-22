package ps6_6;

import java.util.ArrayList;
import java.util.Collections;

public class Intersection 
{	
	private ArrayList<Corridor> Corridors;
	private int id;
	private double factor;
	//private Intersection previous;
	
//    DecimalFormat twoDForm = new DecimalFormat("#.####");
//    return Double.valueOf(twoDForm.format(d));

	public Intersection(int inId) 
	{
		Corridors = new ArrayList<Corridor>();
		id = inId; 
	}
	
	public void addCorridor(Intersection next, double weight)
	{
			Corridors.add(new Corridor(next, weight));
			Collections.sort(Corridors, new CorridorComparator());
			factor = Double.POSITIVE_INFINITY;	
	}
	
	public ArrayList<Corridor> getCorridors()
	{
		return Corridors;
	}
	
//	public void setPrevious(Intersection intersection)
//	{
//		previous = intersection;
//	}
	
	public void setFactor(double fact)
	{
		factor = fact;
	}
	
	public int getId()
	{
		return id;
	}
	
	public double getFactor()
	{
		return factor;
	}
	
//	public Intersection getPrevious()
//	{
//		return previous;
//	}
	
	
	
}
