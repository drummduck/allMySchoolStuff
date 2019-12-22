package assignment9;

import java.util.Comparator;

public class TaskComparator implements Comparator<SystemTask> {

	@Override
	public int compare(SystemTask o1, SystemTask o2) {
		SystemTask comp1 = o1;
		SystemTask comp2 = o2;

		if (comp1.getPriorityGroup() > comp2.getPriorityGroup()) // EH!? YES?
																	// NO? EH!?
		{
			return 1;
		} else if (comp1.getPriorityGroup() < comp2.getPriorityGroup()) {
			return -1;
		}

		else {

			if (comp1.getPriorityLevel() > comp2.getPriorityLevel()) {
				return 1;
			}

			else if (comp1.getPriorityLevel() < comp2.getPriorityLevel()) {
				return -1;
			} else
				return 0;
		}

	}

}