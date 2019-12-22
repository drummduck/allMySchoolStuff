package assignment8;

public class BadHashFunctor implements HashFunctor {

	@Override
	public int hash(String item) {
			//Return the length of the string.
		return Math.abs(item.length());
	}

}
