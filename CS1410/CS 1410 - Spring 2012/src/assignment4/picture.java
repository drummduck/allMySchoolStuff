package assignment4;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JApplet;

public class picture extends JApplet implements Runnable, MouseListener {

	int sunshine;

	public void init() {

		sunshine = 0;

		this.addMouseListener(this);

		// Start a new thread.

		(new Thread(this)).start();
	}

	public void paint(Graphics g) {
		g.setColor(Color.GREEN);
		g.fillRect(0, 0, getWidth(), getHeight());

		g.setColor(Color.BLUE);
		g.fillRect(0, 0, getWidth(), 300);

		Polygon p = new Polygon();
		p.addPoint(200, 100);
		p.addPoint(-300, 550);
		p.addPoint(500, 550);
		g.setColor(Color.GRAY);
		g.fillPolygon(p);

		Polygon r = new Polygon();
		r.addPoint(400, 120);
		r.addPoint(200, 580);
		r.addPoint(800, 580);
		g.setColor(Color.GRAY);
		g.fillPolygon(r);

		Polygon x = new Polygon();
		x.addPoint(200, 100);
		x.addPoint(60, 225);
		x.addPoint(285, 225);
		g.setColor(Color.WHITE);
		g.fillPolygon(x);

		Polygon y = new Polygon();
		y.addPoint(400, 120);
		y.addPoint(329, 280);
		y.addPoint(540, 280);
		g.setColor(Color.WHITE);
		g.fillPolygon(y);

		Polygon w = new Polygon();
		w.addPoint(1000, 300);
		w.addPoint(800, getHeight());
		w.addPoint(1000, getHeight());
		w.addPoint(1100, 300);
		g.setColor(Color.cyan);
		g.fillPolygon(w);

		g.setColor(Color.yellow);
		g.fillOval(1100, 0, 200, 200);
		
		sunlines(g,1050,50,1080,60);
		sunlines(g,1053,185,1080,170);
		sunlines(g,1156,235,1180,215);
		
		shiny(g);
		
		
	
	}
	
	public void shiny (Graphics g)	{
		
		if (sunshine % 3 == 0){
		sunlines(g,1050,115,1060,115);
		sunlines(g,1120,208,1111,215);}
		
		else {
			
			sunlines(g,1050,50,1080,60);
			sunlines(g,1053,185,1080,170);
			sunlines(g,1156,235,1180,215);
		}
	}

	public void sunlines (Graphics g, int x, int y, int w, int h )
	
	{
		g.setColor(Color.yellow);
		g.drawLine(x, y, w, h);
	
	}

	@Override
	public void run() {
		while (true)
		{
			 try { Thread.sleep(500); } catch (Exception e) { }
			 sunshine++;
			 repaint();
			 
			
		}
		
		

	}

	@Override
	public void mouseClicked(MouseEvent e) {
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