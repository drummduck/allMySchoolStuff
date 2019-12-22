package cs1410.Lab12;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.SystemClock;
import android.widget.TextView;

public class Lab12Activity extends Activity {

	Handler myHandler;
	


	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		myHandler = new Handler();
	    Runnable r = new MyAnimator();
	    myHandler.post(r);  // No delay


	}

	private class MyAnimator implements Runnable {
		private int count;

		public void run() {
			 // For debugging ONLY - use
														// strings.xml otherwise
			Labview lv = (Labview) findViewById(R.id.myview);
			lv.setCircleSize(5);
			
			myHandler.postDelayed(this,1);
			
			

		}
	}

}