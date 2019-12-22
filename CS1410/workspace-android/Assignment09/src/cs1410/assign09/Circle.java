package cs1410.assign09;

import java.awt.*;

import android.graphics.Color;
import android.graphics.Point;

/**
 * 
 * @author Nathan Donaldson
 * @version 4/10/12
 * 
 *          This class is used to draw the circles in the view for the
 *          application. Only using the x,y,radius, and color getters from this
 *          class.
 * 
 * 
 */
public class Circle {

	private int radius, x, y;

	private int color = Color.RED;

	/**
	 * Constrruct a new default Circle. The default Circle has x=0, y=0, radius
	 * = 1 and its color is black.
	 */
	public Circle() {
		// Automatic call to Point();
		radius = 1;
	}

	/**
	 * Construct a new Circle at the specified corrdinate, with the specified
	 * radius and color.
	 * 
	 * @param x
	 *            the x coordinate of the new Circle
	 * @param y
	 *            the y coordinate of the new Circle
	 * @param r
	 *            the radius of the new Circle
	 * @param c
	 *            the color of the new Circle
	 */
	public Circle(int x, int y, int r, int c) {
		// Call Point(int x, int y, Color c)
		this.x = x;
		this.y = y;
		radius = r;
		color = c;
	}

	/**
	 * Get the radius of this Circle.
	 * 
	 * @return the radius of this Circle.
	 */
	public int getRadius() {
		return radius;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public int getColor() {
		return color;
	}

	/**
	 * Grow the radius of this Circle by the specified amount.
	 * 
	 * @param gr
	 *            the amount by which to grow the radius.
	 */
	public void grow(int gr) {
		radius = radius + gr;
	}

	/**
	 * Get the area of this Circle.
	 * 
	 * @returm the area of this Circle.
	 */
	public double getArea() {
		return Math.PI * radius * radius;
	}
}
