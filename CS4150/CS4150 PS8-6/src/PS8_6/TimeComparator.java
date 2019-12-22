package PS8_6;

import java.util.Comparator;

public class TimeComparator implements Comparator<Customer>
{
	@Override
	public int compare(Customer arg0, Customer arg1) 
	{
		if(arg0.getTime() > arg1.getTime()) return -1;
		else if(arg0.getTime() < arg1.getTime()) return 1;
		else
		{
			if(arg0.getCash() < arg1.getCash()) return 1;
			else if(arg0.getCash() > arg1.getCash()) return -1;
			else return 0;
		}
	}
}