package Lab07;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * Objects of this class control the GUI calculator.  The
 * object(s) built from this class keep track of the numbers
 * and operations, and they respond to button presses from
 * the calculator buttons.
 * 
 * @author *** Your name here *** 
 * @version Spring 2012
 */
public class CalculatorListener implements ActionListener
{
    // Instance variables
    
    private JTextField display;
    private char lastOperation;
    private double lastNumber;
    private boolean numberStarted;
    
    /**
     * Constructor - initializes the state of the calculator.
     * 
     * @param display the calculator's numeric display GUI component
     */
    public CalculatorListener (JTextField display)
    {
        this.display = display;  // We need access to the number display object.
        
        // Clear the calculator.
        
        
        lastNumber = 0.0;
        numberStarted = false;        
        display.setText ("0");
    }
    
    /**
     * Adds a digit to the display (if the display
     * is not full.)  If a number was not started, this
     * starts a number.
     * 
     * @param d   a digit character
     */
    public void addDigit (char d)
    {
        String text = display.getText();
        
        if (!numberStarted)
        {
            text = ""; 
            numberStarted = d != '0';
        }
        
        if (text.length() >= 15)
            return;
            
        text += d;
        display.setText (text);
    }
    
    /**
     * ActionListener - listens to the button actions.
     * The appropriate action is taken (for the calculator)
     * based on which button is pressed.
     * 
     * @param e  an action event (created by a JButton)
     */
    public void actionPerformed (ActionEvent e)
    {
        // Get the name of the button to determine the
        //   operation.  This is usually a bad idea,
        //   it is better to get the source of the event
        //   and compare object references.  Lab is too
        //   short for that technique.  ;)
        
        Object sourceOfEvent = e.getSource();           // Get the source object of the event.
        JButton sourceButton = (JButton) sourceOfEvent; // Change our view of the reference
        String buttonLabel = sourceButton.getText();    // Get the button label.
        char operation = buttonLabel.charAt(0);         // Get the first character of the label.

        // Do the appropriate operation for this button.

        switch (operation)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                addDigit (operation);
                return;
            case 'C':
                lastOperation = 'C';
                lastNumber = 0.0;
                numberStarted = false;        
                display.setText ("0");
                return;
            case '+':
            
            	
            case '-':
            	
            	
            case 'x':
            	
            	
            case '/':
            	
            	
            case '=':
            	
            	
                // Do the PREVIOUS operation.  First, extract the number.
                
                double currentNumber = Double.parseDouble(display.getText());
               
                
                // Next, do the operation.
                
                if (lastOperation == '+')
                    currentNumber = lastNumber + currentNumber;
                    
                // Display the result, clear the number entry flag.

                if (lastOperation == '-')
                	currentNumber = lastNumber - currentNumber;
                
                if (lastOperation == 'x')
                	currentNumber = lastNumber * currentNumber;
                
                if(lastOperation == '/')
                	currentNumber = lastNumber / currentNumber;
                
                numberStarted = false;        
                display.setText ("" + currentNumber);
                
                
                	
                
                // Save the operation and result as the last operation and result.
                
                lastNumber = currentNumber;
                lastOperation = operation;
        }
    }    
}
