package lab4;

public class BetterRandomGenerator implements RandomNumberGenerator {

	 private java.util.Random random_generator_ = new java.util.Random();

	  public int next_int(int max) 
	  {
	    return this.random_generator_.nextInt(max);
	  }

	  public void set_seed(long seed) 
	  {
		  
	    this.random_generator_.setSeed((long) (seed*Math.random()));
	  }

	@Override
	public void set_constants(long const1, long const2) {
		
		const1 = (long) Math.random();
		const2 = (long) Math.random();
		
		
	}
	}


