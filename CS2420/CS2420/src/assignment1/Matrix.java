package assignment1;

public class Matrix {
	int numRows;
	int numColumns;
	int data[][];
	
	// Constructor with data for new matrix (automatically determines dimensions)
	public Matrix(int d[][])
	{
		numRows = d.length; // d.length is the number of 1D arrays in the 2D array
		if(numRows == 0)
			numColumns = 0;
		else
			numColumns = d[0].length; // d[0] is the first 1D array
		data = new int[numRows][numColumns]; // create a new matrix to hold the data
		// copy the data over
		for(int i=0; i < numRows; i++) 
			for(int j=0; j < numColumns; j++)
				data[i][j] = d[i][j];
	}
	
	@Override // instruct the compiler that we do indeed intend for this method to override the superclass' (Object) version
	public boolean equals(Object o)
	{
		if(!(o instanceof Matrix)) // make sure the Object we're comparing to is a Matrix
			return false;
		Matrix m = (Matrix)o; // if the above was not true, we know it's safe to treat 'o' as a Matrix
		
		
		for(int i=0;i<numRows;i++){
			for(int j = 0;j<numColumns;j++)
			{
				if(this.data[i][j]==m.data[i][j])
					continue;
				else if(this.data[i][j]!=m.data[i][j])
					return false;
			}
		}
		return true; 
	}
	
	@Override // instruct the compiler that we do indeed intend for this method to override the superclass' (Object) version
	public String toString()
	{
		
		
		String str = "";
		for(int i=0;i<(numRows);i++)
		{
			for (int j=0; j<(numColumns);j++)
			{
				str =str + data[i][j] + " ";
			}
			
			str = str + "\n";
		}
			
		return str;


		 }
		
		
	
	
	
	public Matrix times(Matrix m)
	{
		/*
		 * TODO: replace the below return statement with the correct code, 
		 *  This function must check if the two matrices are compatible for multiplication, if not, return null.
		 *  If they are compatible, determine the dimensions of the resulting matrix, and fill it in with
		 *  the correct values for matrix multiplication
		 */
		return null; // placeholder
	}
	
	public Matrix plus(Matrix m)
	{
		/*
		 * TODO: replace the below return statement with the correct code, 
		 *  This function must check if the two matrices are compatible for addition, if not, return null.
		 *  If they are compatible, create a new matrix and fill it in with
		 *  the correct values for matrix addition
		 */
		return null; // placeholder
	}
}
