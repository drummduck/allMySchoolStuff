package PS8_6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Bank {
	
	public static void main(String[] args) throws IOException 
	{
		int numOfPeople;
		int maxTime = -1;
		Customer customer;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String line = reader.readLine();
		numOfPeople = Integer.parseInt(line.split("\\s")[0]);
		Map<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
		ArrayList<Integer> cashValues= new ArrayList<Integer>();
		PriorityQueue<Customer> timeQueue = new PriorityQueue<Customer>(new TimeComparator());


		for(int i = 0; i < numOfPeople; i++)
		{
			line = reader.readLine();
			timeQueue.add(new Customer(Integer.parseInt(line.split("\\s")[0]), Integer.parseInt(line.split("\\s")[1])));
			if(Integer.parseInt(line.split("\\s")[1]) > maxTime) maxTime = Integer.parseInt(line.split("\\s")[1]);
		}
		
		int time = maxTime;
		
		while(!timeQueue.isEmpty())
		{
			
			customer = timeQueue.poll();
			
			if(customer.getTime() != time)
			{
				Collections.sort(cashValues, new CashComparator());
				map.put(time, cashValues);
				time = customer.getTime();
				cashValues = new ArrayList<Integer>();
			}
			
			if(timeQueue.isEmpty())
			{
				cashValues.add(customer.getCash());
				Collections.sort(cashValues, new CashComparator());
				map.put(time, cashValues);	
				break;
			}
			
			cashValues.add(customer.getCash());
		}
				
		greed(map, maxTime);
		
		reader.close();
	}
	
	public static void greed(Map<Integer, ArrayList<Integer>> map, int maxTime)
	{
		int total = 0;
		PriorityQueue<Integer> queue = new PriorityQueue<Integer>(new CashComparator());
		
		for(int i = maxTime; i > -1; i--)
		{
			if(map.containsKey(i))
			{
				queue.addAll(map.get(i));
				total += queue.poll();
			}
		}
		
		System.out.println(total);
	}
}
