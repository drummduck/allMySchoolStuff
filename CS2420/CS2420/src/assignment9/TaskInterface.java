package assignment9;

import java.io.File;
import java.io.InputStreamReader;
import java.util.Scanner;

/**
 * Represents a priority queue of generically-typed items. 
 * The queue is implemented as a min heap. 
 * The min heap is implemented implicitly as an array.
 * 
 * @author Paymon Saebi & Nathan Donaldson & Mike Fleming
 */
public class TaskInterface 
{
	public static void main(String[] args) 
	{ 			
		File tasks = null;
		
		//If there are more than one argument or none, print a message and return
		if(args.length > 1)
		{
			
			System.err.println("Incorrect number of arguments!");
			return;
		}
		
		tasks = new File(args[0]);
		
		//If the file is invalid then print a message and return
		if(tasks.isFile() == false)
		{
			System.err.println("Unable to use the file!");
			return;
		}
	
	
		
		
		
		
		TaskComparator cmp = new TaskComparator();
		TaskManager manager = new TaskManager(tasks,cmp);
		
		manager.populateTasks();
			
		
		Scanner scanner = new Scanner(new InputStreamReader(System.in));
		
		System.out.println("System task manager is initialized ...\n");		
		System.out.println("Current task: " + manager.nextTask());
				
		while(true)
		{				
	        String input = scanner.nextLine();	 	        
	       	        
	        if(input.equals("task"))
	        {
	        	System.out.println("Current task: " + manager.getTask());
	        }
	        
	        else if(input.equals("next"))
	        {
	        	System.out.println("Current task: " + manager.nextTask());
	        }
	        
	        else if(input.equals("exit")) 
	        {
	        	System.out.println("\nSystem task manager has exited ...");
	        	return;
	        }	
	        
	        if(manager.isDone())
	        {
	        	System.out.println("\nAll tasks are done, Have a nice day...");
	        	return;
	        }
		}
	}	
}
