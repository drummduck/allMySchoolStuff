package Lab13;

import java.util.Arrays;

/**
 * A grid object represents the grid part of a life simulation.
 * The grid object keeps track of the state of each square
 * (alive, dead), and allows the user to make one step in the
 * life simulation.
 * <p>
 * 
 * Note that this class does not do any drawing or other I/O.
 * It just represents a grid.
 * 
 * @author pajensen
 */
public class Grid
{
	private boolean[][] grid;
    
    

    
    /**
     * Constructor - creates an empty grid of the
     * specified dimensions.
     * 
     * @param width The width of the new grid
     * @param height The height of the new grid
     */
    public Grid (int width, int height)
    {
grid = new boolean[height][width];
clear();
    }

    /**
     * Returns true if the specified cell in the grid
     * is alive, false otherwise.  If the coordinates
     * are illegal, false is returned.
     * 
     * @param row  a row number
     * @param column a column number
     * @return true iff that cell is alive
     */
    public boolean isAlive (int row, int column)
    {
    	if(row<0 || column <0 || row >= getHeight() || column >= getWidth())
    	{
    		return false;
    	}
return grid[row][column];
    }
    
    /**
     * Sets the state of the specified cell in the
     * grid.
     * 
     * @param row a row number
     * @param column a column number
     * @param isAlive true if the grid cell should be alive
     */
    public void setCellState(int row, int column, boolean isAlive)
    {
grid[row][column] = isAlive;
    }
    
 
    /** 
     * Returns the width of the grid.
     * 
     * @return the width of this grid
     */
    public int getWidth ()
    {
    	
return grid[0].length;
    }

    /** 
     * Returns the height of the grid.
     * 
     * @return the height of this grid
     */
    public int getHeight ()
    {
return grid.length;
    }
    
    /**
     * Clears the grid, all cells marked as
     * dead.
     */
    public void clear ()
    {
for(boolean[] b : grid)
	Arrays.fill(b, false);
    }
    
    /**
     * Performs one 'life' step using the standard rules
     * of life:<p>
     * 
     * Any live cell with fewer than two neighbors dies, as if by loneliness. <br> 
     * Any live cell with more than three neighbors dies, as if by overcrowding. <br>
     * Any live cell with two or three neighbors lives, unchanged, to the next generation. <br>
     * Any dead cell with exactly three neighbors comes to life.<p> 
     * 
     * Care must be taken to make sure the next generation is kept separate from the 
     * current generation.
     */
    public void stepOneGeneration ()
    {
boolean[][] temp = new boolean[getHeight()][getWidth()];

for (int i = 0; i<getHeight();i++)
{
	for(int j = 0; j<getWidth();j++)
	{
		int count = 0;
		if(isAlive(i-1,j-1)) count++;
		if(isAlive(i+1,j+1)) count++;
		if(isAlive(i,j+1)) count++;
		if(isAlive(i,j-1)) count++;
		if(isAlive(i+1,j)) count++;
		if(isAlive(i-1,j)) count++;
		if(isAlive(i-1,j+1)) count++;
		if(isAlive(i+1,j-1)) count++;		
		
		
		
	
	
	if (count == 0 || count == 1)
	{
		temp[i][j]= false;		
	}
	
	else if (count >=4)
	{
		temp[i][j] = false;
	}
	else if (count == 3)
	{
		temp[i][j] = true;
	}
	else temp[i][j] = grid[i][j];
}


grid = temp;



    }
    }
}

