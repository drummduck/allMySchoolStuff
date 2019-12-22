package cs1410.assign09;

/**
 * @author Nathan Donaldson
 * @version 4/10/12
 * 
 * 
 * This class creates various buttons and views to interact with. Listeners are added for all buttons, and their actions are stated in
 * the listener method. The textview changes color along with the color changed in the view when one of the buttons is pushed. When the view
 * is clicked the run method will constantly draw circles that are created in the view.
 * 
 */

import java.util.Random;

import android.R.color;
import android.app.Activity;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.os.SystemClock;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class Assignment09Activity extends Activity implements
		android.view.View.OnClickListener {

	private Button Small; // Objects and instance variables declared.
	private Button Medium;
	private Button Large;
	private Button ChangeColor;
	private Button Reset;
	private TextView Title;
	private int n = 5;
	private cs1410.assign09.Assignment09view assignment09view;
	private Random awesome = new Random();
	Handler myHandler;

	@Override
	public void onCreate(Bundle savedInstanceState) {

		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		myHandler = new Handler(); // handles what is in the view.
		Runnable r = new MyAnimator();
		myHandler.post(r); // No delay

		Small = (Button) findViewById(R.id.button3); // Buttons and views are
														// assigned to XML
														// buttons and views for
														// activity.
		Medium = (Button) findViewById(R.id.button4);
		Large = (Button) findViewById(R.id.button5);
		ChangeColor = (Button) findViewById(R.id.button1);
		Reset = (Button) findViewById(R.id.button2);
		assignment09view = (cs1410.assign09.Assignment09view) findViewById(R.id.myview);
		Title = (TextView) findViewById(R.id.textView1);

		Title.setTextColor(Color.RED); // original title color.

		Small.setOnClickListener(this); // Listeners for the buttons.
		Medium.setOnClickListener(this);
		Large.setOnClickListener(this);
		ChangeColor.setOnClickListener(this);
		Reset.setOnClickListener(this);

	}

	public void setN(int newsize) { // sets n to a new variable when button is
									// clicked. onClick determines size.
		this.n = newsize;
	}

	public void onClick(View v) {

		if (v == Small) { // change size of circles to small when Small button
							// is clicked.
			setN(2);

		}

		else if (v == Medium) { // change size of circles to medium when Medium
								// button is clicked.
			setN(5);
		}

		else if (v == Large) { // change size of circles to large when Large
								// button is clicked.
			n = 10;
		}

		else if (v == ChangeColor) {

			int x = Color.rgb(awesome.nextInt(255), // Change color to random
													// color using random object
													// when button is clicked.
					awesome.nextInt(255), awesome.nextInt(255));
			assignment09view.setColor(x);
			Title.setTextColor(x);

		}

		else if (v == Reset) { // Clears the view when Reset is clicked.
			assignment09view.erase();
			assignment09view.setColor(Color.RED);
			Title.setTextColor(Color.RED);
		}

		else {
			n = 5;

		}
	}

	private class MyAnimator implements Runnable {

		public void run() { // Runs in the view when view is clicked. Constantly
							// refreshes.

			Assignment09view lv = (Assignment09view) findViewById(R.id.myview);
			lv.setCircleSize(n);

			myHandler.postDelayed(this, 1);

		}
	}

}
