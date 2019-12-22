package PS_11;

public class Tuple 
{

	private int height;
	private String trip;
	
	public Tuple(int height, String trip) 
	{
		this.height = height;
		this.trip = trip;
	}
	
	public void setHeight(int height)
	{
		this.height = height;
	}
	
	public void setTrip(String trip)
	{
		this.trip = trip;
	}
	
	public int getHeight()
	{
		return height;
	}
	
	public String getTrip()
	{
		return trip;
	}
	
	public void setBoth(int height, String trip)
	{
		this.height = height;
		this.trip = trip;
	}
	
	@Override
	public boolean equals(Object o)
	{
		if(o == this) return true;
		
		else if(!(o instanceof Tuple))
		{
			return false;
		}
		
		else
		{
			Tuple tuple = (Tuple) o;
			
			if(tuple.height == this.height && tuple.trip == this.trip) return true;
			
			else return false;
		}	
	}
	
	@Override
	public int hashCode()
	{
		 int result = 17;
	        result = 31 * result + height;
	        if(trip != "") result = 31 * result + (int)trip.charAt(0);
	        if(trip != "") result = 31 * result + (int)trip.charAt(trip.length()-1);
	        return result;
	}

}
