package PS3_4;

public class Garbage_Sort {

	public static void main(String[] args) 
	{
		int[] A = {4,3,4,6,2,1,0,10};
		sort(A, 0, A.length);
		for(int i = 0; i < A.length; i++)
		{
			System.out.println(A[i]);
		}

	}

	public static void sort(int[] A, int lo, int hi)
	{
		int size = hi - lo;
		
		if(size == 2)
		{
			if(A[lo] > A[lo+1])
			{
				int temp = A[lo];
				A[lo] = A[lo+1];
				A[lo+1] = temp;
			}
		}
		
		else if (size > 2)
		{
			int chunk = size / 3;
			sort(A, lo, hi-chunk);
			sort(A, lo+chunk, hi);
			sort(A, lo, hi-chunk);
		}
	}
}
