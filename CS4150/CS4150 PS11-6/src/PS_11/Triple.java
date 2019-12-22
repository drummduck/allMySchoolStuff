package PS_11;

public class Triple 
{
	private int position;
	private int total;
	private boolean up;
	
	public Triple(int position, int max, boolean up) 
	{
		this.position = position;
		this.total = total;
		this.up = up;
	}
	
	public int getPosition()
	{
		return position;
	}
	
	public int getTotal()
	{
		return total;
	}
	
	public boolean getUp()
	{
		return up;
	}
	
	public void setPosition(int position)
	{
		this.position = position;
	}
	
	public void setTotal(int total)
	{
		this.total = total;
	}
	
	public void setUp(boolean up)
	{
		this.up = up;
	}
	
	@Override
	public boolean equals(Object o)
	{
		if(o == this) return true;
		
		else if(!(o instanceof Triple))
		{
			return false;
		}
		
		else
		{
			Triple triple = (Triple) o;
			
			if(triple.getPosition() == position && triple.getTotal() == total && triple.getUp() == up) return true;
			
			else return false;
		}	
	}

	
	@Override
	public int hashCode()
	{
		 int result = 17;
	        result = 31 * result + position;
	        result = 31 * result + total;
	        return result;
	}

}
