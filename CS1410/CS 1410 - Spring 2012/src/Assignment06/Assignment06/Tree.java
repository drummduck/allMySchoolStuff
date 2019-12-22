package Assignment06;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.Polygon;
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
public class Tree extends AbstractQuilt implements NamedComponent,
		MouseListener {

	private Color myColor;
	private Color newColor;

	// Constructor. Sets global variables and adds mouselistener to this object.
	// Also resizes the square to 100x100.
	public Tree() {
		this.setPreferredSize(new Dimension(100, 100));
		myColor = Color.BLUE;
		this.addMouseListener(this);

	}

	// All the drawing is done here.
	public void paintComponent(Graphics g) {

		g.setColor(Color.WHITE);
		g.fillRect(0, 0, getWidth(), getHeight());

		g.setColor(Color.BLACK);
		g.drawRect(0, 0, 99, 99);

		g.setColor(Color.BLACK);
		g.fillRect(14, 45, 10, 20);

		Polygon f = new Polygon();
		f.addPoint(20, 25);
		f.addPoint(3, 50);
		f.addPoint(35, 50);
		g.setColor(myColor);
		g.fillPolygon(f);

		Polygon p = new Polygon();
		p.addPoint(20, 10);
		p.addPoint(5, 30);
		p.addPoint(35, 30);
		g.setColor(myColor);
		g.fillPolygon(p);

		g.setColor(Color.BLACK);
		g.fillRect(64, 75, 10, 20);

		Polygon n = new Polygon();
		n.addPoint(70, 55);
		n.addPoint(53, 80);
		n.addPoint(85, 80);
		g.setColor(myColor);
		g.fillPolygon(n);

		Polygon r = new Polygon();
		r.addPoint(70, 40);
		r.addPoint(55, 60);
		r.addPoint(85, 60);
		g.setColor(myColor);
		g.fillPolygon(r);

	}

	// Sets the return of the NamedComponent on this object to a string.
	@Override
	public String getSquareName() {
		String s = "Tree";
		return s;
	}

	// MouseListener. Opens a color chooser for the color variable to be changed
	// and repaints.If null nothing changes.
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
