package assignment8;

public class MediocreHashFunctor implements HashFunctor {

	@Override
	public int hash(String item) {
		
		int sum = 0;
		
		char[] itemArray = item.toCharArray();
		
		for(int letter = 0; letter < item.length(); letter ++)
		{
			sum += itemArray[letter];
		}
		return  Math.abs(sum);
	}
}
