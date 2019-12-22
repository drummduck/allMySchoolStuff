package Lab08;

import java.awt.Graphics;
import java.awt.Color;

abstract public class Shape
{
   protected int x;
   protected int y;
   protected Color color;
    
   public Shape (int x, int y, Color color)
   {
	this.x = x;
	this.y = y;
	this.color = color;
   }

   public void move (int deltaX, int deltaY)
   {
	x = x + deltaX;
	y = y + deltaY;
   }

    abstract public boolean isInside (int targetX, int targetY);

    abstract public void draw (Graphics g);
}