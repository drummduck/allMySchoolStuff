/**
 * This applet draws a smiley face wherever the user clicks.  Also,
 * if the user types 'omg' after clicking on the applet, the expression
 * on the face changes.
 * 
 * This applet shows:
 *   0. How to use object variables (also called instance variables)
 *   1. How to listen to mouse and key events
 *   2. How to use a threads to animate an applet
 *   
 * @author Peter Jensen
 * @version February 13, 2012 
 */
package assignment4;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.*;
import javax.swing.JApplet;

public class art extends JApplet implements Runnable, MouseListener, KeyListener
{
    // Object variables go here.
    
    int userX, userY;
    int blinkTime;
    String allTypedKeys;
    
    /**
     * The init method is automatically called once, only when the applet object is started.
     */
    public void init ()
    {
        userX = 100;
        userY = 100;
        blinkTime = 0;
        allTypedKeys = "";
        
        this.addMouseListener(this);
        this.addKeyListener(this);
        
        // Start a new thread.
        
        (new Thread(this)).start();
    }
    
    /**
     * The paint method is automatically called whenever the window
     * needs to be redrawn.
     * 
     * @param g   a graphics object representing the screen
     */
    public void paint (Graphics g)
    {     
        // Clear the background.
        
        g.setColor(Color.GRAY);
        g.fillRect(0, 0, getWidth(), getHeight());
        
        // Call the method to draw the art
        
        drawSmiley(g, userX, userY);
    }
    
    /**
     * This private helper method draws a art on a graphics
     * object at the given coordinates.
     * 
     * @param g   a graphics object representing the screen
     * @param x   the x coordinate
     * @param y   the y coordinate
     */
    private void drawSmiley (Graphics k, int x, int y)
    {
        // Draw a art face.
        
        k.setColor(Color.WHITE);
        k.drawRect(x + 0, y + 0, 100, 100);
        
        // Head
       
        k.setColor(new Color(0.9f, 0.8f, 0.3f));
        k.fillOval(x + 0, y + 0, 100, 100);
       
        // Eyes
       
        if (blinkTime % 3 == 0)
        {
            k.setColor(Color.BLACK);
            k.fillRect(x + 23, y + 28, 7, 2);
            k.fillRect(x + 68, y + 28, 7, 2);
        }
        else
        {
            k.setColor(Color.WHITE);
            k.fillRect(x + 23, y + 23, 7, 7);
            k.fillRect(x + 68, y + 23, 7, 7);
           
            k.setColor(Color.ORANGE.darker().darker());
            k.fillRect(x + 28, y + 28, 2, 2);
            k.fillRect(x + 73, y + 28, 2, 2);
        }
        
        // Nose
       
        k.setColor(Color.BLACK);
        k.drawOval(x + 45, y + 45, 10, 10);
       
        // Mouth
       
        k.setColor(new Color(0.5f, 0.0f, 0.0f));
       
        if (allTypedKeys.endsWith("omg"))
            k.drawOval(x + 40, y + 60, 20, 20);
        else
        {
            k.drawArc(x + -10, y + -45, 120, 120, 240, 60);
            k.drawArc(x + -10, y + -44, 120, 120, 240, 60);
        }
    }
    
    public void mouseEntered  (MouseEvent e) { }
    public void mouseExited   (MouseEvent e) { }
    public void mouseClicked  (MouseEvent e) { }
    public void mouseReleased (MouseEvent e) { }
    
    public void mousePressed  (MouseEvent e) 
    { 
        userX = e.getX() - 50;
        userY = e.getY() - 50;
        repaint();  // Causes paint to eventually be called.
    }

    
    public void keyPressed (KeyEvent e)
    {
        allTypedKeys = allTypedKeys + e.getKeyChar();
        
        repaint();        
    }

    
    public void keyReleased (KeyEvent e)
    {
       
        
    }

   
    public void keyTyped (KeyEvent e)
    {
       
        
    }

    
    public void run ()
    {
        while (true)
        {
            try { Thread.sleep(1000); } catch (Exception e) { }
            
            blinkTime++;
            repaint();
        }
        
    }
    
}
