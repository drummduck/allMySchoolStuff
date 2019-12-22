package Assignment06;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JColorChooser;
import javax.swing.JComponent;

/**
 *This class extends AbstractQuilt class and implements NamedComponent and
 * MouseListener. It draws what is in the paintComponent and sets the return for
 * the NamedComponent Class. It also listens for a MouseClicked event and opens
 * a JColorChooser when clicked to change the color of certain parts of the
 * paintComponent.
 * 
 * @author Nathan Donaldson
 * @version 3/7/12
 */
// Declare global variables and extend and implement classes.
public class Kirby extends AbstractQuilt implements NamedComponent,
		MouseListener {

	private Color myColor;
	private Color newColor;

	// Constructor. Sets global variables and adds mouselistener to this object.
	// Also resizes the square to 100x100.
	public Kirby() {
		this.setPreferredSize(new Dimension(100, 100));
		myColor = (new Color((float) Math.random(), (float) Math.random(),
				(float) Math.random()));
		this.addMouseListener(this);

	}

	// All the drawing is done here.
	public void paintComponent(Graphics g) {

		g.setColor(Color.WHITE);
		g.fillRect(0, 0, getWidth(), getHeight());

		g.setColor(Color.BLACK);
		g.drawRect(0, 0, 99, 99);

		g.setColor(myColor);
		Font f = new Font("arial", Font.BOLD, 24);
		g.setFont(f);
		g.drawString("<(^.^<)", 2, 60);
	}

	// Sets the return of the NamedComponent on this object to a string.
	@Override
	public String getSquareName() {
		String s = "Kirby";
		return s;
	}

	// MouseListener. Opens a color chooser for the color variable to be changed
	// and repaints. If null nothing changes.
	@Override
	public void mouseClicked(MouseEvent e) {
		newColor = JColorChooser.showDialog(this, "Choose Background Color",
				myColor);

		if (newColor != null) {
			myColor = newColor;
		}

		repaint();

	}

	@Override
	public void mouseEntered(MouseEvent e) {
	}

	@Override
	public void mouseExited(MouseEvent e) {
	}

	@Override
	public void mousePressed(MouseEvent e) {
	}

	@Override
	public void mouseReleased(MouseEvent e) {
	}

}
