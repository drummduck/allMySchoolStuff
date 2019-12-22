/**
 * This applet is an example of how to draw shapes to the
 * screen using a Graphics object.  The drawing takes up 
 * about 500x700 pixels of screen space, you may need to resize
 * the display window.
 * 
 * @author Peter Jensen
 * @version February 6, 2012
 */
package lab05;

import java.awt.*;
import javax.swing.JApplet;

public class awesome extends JApplet
{
    /**
     * This function redraws the applet window.  It is our
     * job to implement this function to draw the screen.  It will
     * be called (but not by you) whenever the screen needs redrawing.
     * 
     * @param g   a graphics object that represents the screen
     */
    public void paint (Graphics g)
    {
        // Clear the background.
        
        int width = this.getWidth();
        int height = this.getHeight();
        
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, width, height);  // x, y, width, height
        
        // Draw some text.
        
        Font f = new Font ("arial", Font.BOLD, 24);
        
        g.setColor(Color.YELLOW);
        g.setFont(f);
        g.drawString("Shape demo", 20, 30);
        
        // Draw some shapes
        // (Look up the Graphics function calls to see the meaning of the parameters.)
        
        Color c = new Color (1.0f, 0.0f, 1.0f); // Specified as floats
        g.setColor(c);
        g.drawRect( 50, 50, 200, 50);
        g.fillRect(300, 50, 200, 50);
        
        g.setColor(new Color ((float) Math.random(),(float) Math.random(), (float) Math.random()));
        g.drawOval( 50, 150, 200, 50);
        g.fillOval(300, 150, 200, 50);
     
        g.setColor(new Color(1.0f, 0.5f, 0.8f));
        g.drawRoundRect( 50, 250, 200, 50, 40, 20);
        g.fillRoundRect(300, 250, 200, 50, 40, 20);
        
        g.setColor(Color.CYAN);
        g.drawArc( 50, 350, 200, 50, 45, 90);
        g.fillArc(300, 350, 200, 50, 90, 45);
        
        g.setColor(Color.RED);
        g.drawLine(50, 450, 250, 500);
        
        Polygon p = new Polygon();
        p.addPoint(300, 550);
        p.addPoint(400, 550);
        p.addPoint(350, 600);
        g.fillPolygon(p);  // You can also use drawPolygon
    }
}
