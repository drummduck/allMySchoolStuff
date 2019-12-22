package Assignment06;
/**
 * This is an abstract class that is extended to all of the shape classes. This class extends
 * JPanel and makes it so the shape classes are able to draw. It shares the Mouselistener and
 * Color Chooser. 
 * 
 * FOR TA: I STARTED THIS AND HAD ALL OF THE SHAPE CLASS BACKGROUNDS SET TO WHITE.
 * I CAME BACK THE NEXT DAY AND HADN'T CHANGED ANYTHING AND THE BACKGROUNDS WOULD NOT SET TO WHITE.
 * I ASKED TA FOR HELP BUT THE DIDNT KNOW WHAT WAS WRONG. SO INSTEAD I HAD A RECTANGLE FILL
 * THE BACKGROUND OF EACH 100X100 SQUARE.
 * 
 * @author Nathan Donaldson
 * @version 3/7/12
 */
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JColorChooser;
import javax.swing.JPanel;

abstract class AbstractQuilt extends JPanel implements MouseListener {

	protected JColorChooser chooser = new JColorChooser();
	protected Color color;

	@Override
	public Dimension getMinimumSize() {
		return new Dimension(100, 100);
	}

	@Override
	public Dimension getPreferredSize() {
		return new Dimension(100, 100);
	}

	@Override
	public Dimension getMaximumSize() {
		return new Dimension(100, 100);
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub

	}

}
