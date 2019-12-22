package PS8_6;

public class Customer 
{
	int cash;
	int time;

	public Customer(int cash, int time) 
	{
		this.cash = cash;
		this.time = time;
	}

	public int getCash()
	{
		return cash;
	}
	
	public int getTime()
	{
		return time;
	}
	
	public void setCash(int cash)
	{
		this.cash = cash;
	}
	
	public void setTime(int time)
	{
		this.time = time;
	}

}
