package PS4_2;

public class Quicksort_thing {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public static int f(int[] A, int k)
	{
		int sum = 0;
		int stop = partition(A, select(A, k));
		return stop;
	}
	
	public static int partition(int[] A, int k)
	{
		int[] B = A.clone();
		return select(B, k);
	}
	
	public static int select(int[] A, int k)
	{
		int [] B = A.clone();
		for(int i = 0; i <= B.length; i++)
		{
			int meow = A[i];
			for(int j = i; j <= B.length; j++)
			{
				if(meow > A[j])
				{
					A[i] = A[j];
					A[j] = meow;
				}
			}
		}
		return A[k];
	}
}
