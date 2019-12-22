/**
 * Class NightScene - Draws a night scene (just for fun).
 * 
 * @author Nathan Donaldson	
 * @version February 7, 2012
 */
package lab05;

import java.awt.*;
import javax.swing.*;

public class NightScene extends JApplet {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * Paint method for applet.
	 * 
	 * @param g
	 *            the Graphics object for this applet
	 */
	public void paint(Graphics g) {
		// Note that this scene redraws randomly at each repaint,
		// 'tearing' may occur if a window slides in front of the applet.
		// A Random object with a fixed seed would fix this problem,
		// but it's not necessary.

		// Clear the background.

		int width = this.getWidth();
		int height = this.getHeight();
		
		
		

		g.setColor(Color.BLACK);
		g.fillRect(0, 0, width, height);
		
		for(int i = 0; i < 1; i++){
		int x = (int) (Math.random()* this.getWidth());
		int y = (int) (Math.random() * this.getHeight());
		g.setColor(Color.WHITE);
		g.fillOval(x,y,70,70);
		
		g.setColor(Color.BLACK);
		g.fillOval(x, y, 70, 70);
		}
		for (int i = 0; i < 1000; i++) {

			int x = (int) (Math.random()* this.getWidth());
			int y = (int) (Math.random()* this.getHeight());
			g.setColor(Color.WHITE);
			g.fillRect(x, y, 1, 1);
		}

		
		g.setColor(Color.BLUE);
		g.drawLine(0, 700, 1500, 700);
		
		
		
		
	}
}
          