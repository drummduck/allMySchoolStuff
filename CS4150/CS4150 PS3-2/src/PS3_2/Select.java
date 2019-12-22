package PS3_2;

import java.lang.reflect.Array;

public class Select {

	public static void main(String[] args) {
		
	int[] A = {2, 5, 7, 22};
	int[] B = {7, 8, 9, 14};
	
	System.out.println(find(A, 0, A.length-1, B, 0, B.length-1, 4));

	}
	
	public static int find(int[] A, int loA, int hiA, int[] B, int loB, int hiB, int k)
	{
		
		if(hiA < loA)
		{
			return B[k-loA];
		}
		
		if(hiB < loB)
		{
			return A[k-loB];
		}
		
		
		int i = (loA + hiA)/2;
		int j = (loB + hiB)/2;
		
		if(A[i] > B[j])
		{
			if(k <= i+j) return find(A, i, hiA-1, B, loB, hiB, k);
			
			else return find(A, loA, hiA, B, j+1, hiB, k);
		}
		
		else
		{
			if(k <= i+j) return find(A, loA, hiA, B, loB, j-1, k);
			
			else return find(A, i+1, hiA, B, loB, hiB, k);
		}
		
	}

}
