package PS10_4;

//This class holds 3 values, overrides the equals() and hashcode() methods as well.
public class Triple 
{
	public int row;
	public int closeDoor;
	public int doorsToClose;
	
	public Triple(int row, int closeDoor, int doorsToClose) 
	{
		this.row = row;
		this.closeDoor = closeDoor;
		this.doorsToClose = doorsToClose;
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
			
			if(triple.row == this.row && triple.closeDoor == this.closeDoor && triple.doorsToClose == this.doorsToClose) return true;
			
			else return false;
		}	
	}
	
	@Override
	public int hashCode()
	{
		 int result = 17;
	        result = 31 * result + row;
	        result = 31 * result + closeDoor;
	        result = 31 * result + doorsToClose;
	        return result;
	}
}
