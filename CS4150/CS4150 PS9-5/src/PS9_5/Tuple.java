package PS9_5;

public class Tuple
{ 
	  public int x; 
	  public int y;
	  
	  public Tuple(int x,int y) 
	  { 
	    this.x = x; 
	    this.y = y; 
	  }
	  
	  @Override
	    public boolean equals(Object o) {

	        if (o == this) return true;
	        if (!(o instanceof Tuple)) {
	            return false;
	        }

	        Tuple tuple = (Tuple) o;

	        if(tuple.x == this.x && tuple.y == this.y) return true;
	        else return false;
	    }

	    //Idea from effective Java : Item 9
	    @Override
	    public int hashCode() {
	        int result = 17;
	        result = 31 * result + x;
	        result = 31 * result + y;
	        return result;
	    }
}