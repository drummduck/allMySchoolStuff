package lab9;

import java.util.Comparator;
import java.util.PriorityQueue;

public class lab9class implements Comparator<Integer>{

	@Override
	public int compare(Integer o1, Integer o2) {

		if(o1 <  o2)
		{
			return 1;
		}
		
		else if(o1 > o2)
		{
			return -1;
		}
		else
			return 0;
	}

	

}
