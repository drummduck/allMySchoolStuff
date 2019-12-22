package Lab07;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * This application is a simulation of a simple hand-held calculation. GUI
 * components are used for input and output.
 * 
 * @author *** Your name here ***
 * @version Spring 2012
 */
public class CalculatorApplication {
	static public void main(String[] args) {

		// Create the window.

		JFrame window = new JFrame("Nifty Calculator");
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// Get the content panel for the window. We will add our
		// GUI controls to this container. Set the layout to use
		// BorderLayout.

		Container content = window.getContentPane();
		content.setLayout(new BorderLayout());

		// Create, customize, and add the calculator components.
		// First, create a number display and add it to the north in
		// the window.

		JTextField numberDisplay = new JTextField("0", 15);
		numberDisplay.setForeground(Color.BLACK);
		numberDisplay.setBackground(Color.WHITE);
		numberDisplay.setFont(new Font("Courier", Font.BOLD, 24));
		numberDisplay.setHorizontalAlignment(SwingConstants.RIGHT);
		numberDisplay.setEditable(false);
		content.add(numberDisplay, BorderLayout.NORTH);

		// Create a panel to hold the number buttons. Set it
		// to use GridLayout. Add it to the south side of the
		// main window.
		JPanel buttonPanel = new JPanel();
		buttonPanel.setLayout(new GridLayout(4, 4));
		window.add(buttonPanel, BorderLayout.SOUTH);

		// Create the buttons, add them to the panel.
		JButton one = new JButton("1");
		buttonPanel.add(one);

		JButton two = new JButton("2");
		buttonPanel.add(two);

		JButton three = new JButton("3");
		buttonPanel.add(three);

		JButton four = new JButton("4");
		buttonPanel.add(four);

		JButton five = new JButton("5");
		buttonPanel.add(five);

		JButton six = new JButton("6");
		buttonPanel.add(six);

		JButton seven = new JButton("7");
		buttonPanel.add(seven);

		JButton eight = new JButton("8");
		buttonPanel.add(eight);

		JButton nine = new JButton("9");
		buttonPanel.add(nine);

		JButton zero = new JButton("0");
		buttonPanel.add(zero);

		JButton clear = new JButton("C");
		buttonPanel.add(clear);

		JButton equals = new JButton("=");
		buttonPanel.add(equals);

		JButton times = new JButton("x");
		buttonPanel.add(times);

		JButton divide = new JButton("/");
		buttonPanel.add(divide);

		JButton plus = new JButton("+");
		buttonPanel.add(plus);

		JButton minus = new JButton("-");
		buttonPanel.add(minus);

		// Create an object to listen to button events.

		CalculatorListener calc = new CalculatorListener(numberDisplay);

		// Have the object listen to events from every button.

		one.addActionListener(calc);
		
		two.addActionListener(calc);
		
		three.addActionListener(calc);
		
		four.addActionListener(calc);
		
		five.addActionListener(calc);
		
		six.addActionListener(calc);
		
		seven.addActionListener(calc);
		
		eight.addActionListener(calc);
		
		nine.addActionListener(calc);
		
		zero.addActionListener(calc);
		
		clear.addActionListener(calc);
		
		equals.addActionListener(calc);
		
		times.addActionListener(calc);
		
		divide.addActionListener(calc);
		
		plus.addActionListener(calc);
		
		minus.addActionListener(calc);

		
		// Force the window to compute its own size.
		window.pack();

		// Make the window unresizeable, visible.

		window.setResizable(false);
		window.setVisible(true);

		// Main method terminates, the window remains visible.
	}

}
