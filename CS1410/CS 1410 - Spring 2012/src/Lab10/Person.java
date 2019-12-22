package Lab10;

/**
 * A person object represents a single person.  Each
 * person has a name, age, and score.
 * 
 * @author (Nathan Donaldson) 
 * @version Spring 2012
 */
public class Person
{
	private String name;
	private int age;
	private double score;
	
	public Person(String name, int age, double score)
	{
		this.name = name;
		this.age = age;
		this.score = score;
		
	}
	
	 public String getname()
	 {
		
		return name;
		 
	 }
	 
	 public int getage()
	 {
		 return age;
	 }
	 
	 public double getscore()
	 {
		 return score;
	 }
    
	 public String toString ()
	 {
		 return String.format("%15s %4d %3.1f", name, age, score); 
	 }
}

