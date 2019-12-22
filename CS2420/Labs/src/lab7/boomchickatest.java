package lab7;

import junit.framework.TestCase;

public class boomchickatest extends TestCase {

	public void testboom()
	{
		boomchicka meow = new boomchicka();
		
		boomchicka.generateRandomDotFile("meow", 10);
	}

}
