package ps6_6;

import java.util.Comparator;

public class CorridorComparator implements Comparator<Corridor> {

	@Override
	public int compare(Corridor arg0, Corridor arg1) {
		if(arg0.getNext().getId() < arg1.getNext().getId()) return -1;
		else if(arg0.getNext().getId() > arg1.getNext().getId()) return 1;
		else return 0;
	}

}
