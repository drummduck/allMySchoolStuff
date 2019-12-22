package Lab08;

import java.awt.Graphics;
import java.awt.Color;

/**
 * Circle objects represent a circle shape drawn to the screen at a particular
 * position with some size and color.
 * 
 * @author Peter Jensen
 * @version Spring 2012
 */
public class Rect extends Shape {
	// Instance variables.

	
	private int width, height;

	/**
	 * Constructor - initializes the position, diameter, and color of this
	 * circle object.
	 * 
	 * @param x
	 *            the x coordinate of this object's position
	 * 
	 * @param y
	 *            the y coordinate of this object's position
	 * 
	 * @param width
	 *            the width of this rectangle.
	 * 
	 * @param height
	 *            the height of this rectangle.
	 * 
	 * @param color
	 *            the color of this circle
	 */
    public Rect (int x, int y, int width,int height, Color color)
    {
	// Call the superclass constructor.  This must be the first statement
	//   in this constructor.
	
	super (x, y, color);
	
	// Save the size.
	
	this.width= width;
	this.height = height;
    }

	/**
	 * Changes the position of this shape by the specified amount. Note that
	 * this does not set the position absolutely, the deltas specify how far to
	 * move the shape from its current position.
	 * 
	 * @param deltaX
	 *            how far to move the shape horizontally
	 * 
	 * @param deltaY
	 *            how far to move the shape vertically
	 */
	

	/**
	 * Draws the circle at it's current position and color to the specified
	 * graphics object.
	 * 
	 * @param g
	 *            the graphics object (where to draw to)
	 */
	public void draw(Graphics g) {
		g.setColor(color);
		g.fillRect(x, y, width, height);
	}

	/**
	 * Returns true if the coordinates are within the circle.
	 * 
	 * @param targetX
	 *            an x coordinate
	 * 
	 * @param targetY
	 *            a y coordinate
	 * 
	 * @return true if the coordinates are within the shape
	 */
	public boolean isInside(int targetX, int targetY) {
		int cx = x + height/2; // Calculate the center point
		int cy = y + width/2;

		int deltaX = cx - targetX; // Calculate the deltas to the click
		int deltaY = cy - targetY;

		return  targetX > x &&  targetX <(x+width) && targetY > y &&  targetY<(y+height);
	}
}
