package ps6_6;

import java.util.Comparator;

public class IntersectionComparator implements Comparator<Intersection> 
{

	@Override
	public int compare(Intersection arg0, Intersection arg1) 
	{
		if(arg0.getFactor() < arg1.getFactor()) return 1;
		else if(arg0.getFactor() > arg1.getFactor()) return -1;
		else return 0;
	}

}
