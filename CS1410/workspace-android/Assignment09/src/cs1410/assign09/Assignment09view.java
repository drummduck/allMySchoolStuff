package cs1410.assign09;

/** 
 * @author Nathan Donaldson
 * @version 4/10/12
 * 
 * 
 * This view creates circle objects and puts them into an array of circles. 
 * Circles are then drawn on the canvas extracting the variables out of each circle array object.
 * 
 */

import java.util.ArrayList;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import android.graphics.drawable.ShapeDrawable;
import android.graphics.drawable.shapes.OvalShape;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

public class Assignment09view extends View {
	ArrayList<Circle> listOfShapeDrawables = new ArrayList<Circle>(); // Instance
																		// variables.
	float circleSize;
	int x;
	int y;

	public int color = Color.RED; // Starting color to draw with.

	public Assignment09view(Context context, AttributeSet attributes)

	{
		super(context, attributes);
	}

	public void setColor(int newpaint) {
		this.color = newpaint; // Constructor Method
	}

	public void erase() {
		listOfShapeDrawables.clear(); // Clears the view.
	}

	public void onDraw(Canvas canvas) {

		// Create a paint object to define drawing colors, styles, etc.
		Paint background = new Paint();
		background.setColor(Color.WHITE);

		canvas.drawRect((float) 0, (float) 0, (float) canvas.getWidth(),
				(float) canvas.getHeight(), background);

		Paint paint = new Paint();
		paint.setColor(color);

		// Draw to the canvas, and use our 'paint' to style the drawings.
		for (Circle c : listOfShapeDrawables) {
			Paint turkey = new Paint();
			turkey.setColor(c.getColor());

			canvas.drawCircle(c.getX(), c.getY(), c.getRadius(), turkey);
		}

	}

	public void setCircleSize(float size) {
		circleSize = size;
		invalidate(); // Forces a redraw sometime soon
	}

	public boolean onTouchEvent(MotionEvent event) {

		x = (int) event.getX(); // x-coordinate where user clicked.
		y = (int) event.getY(); // y-coordinate where user clicked.

		Circle myCircle = new Circle(x, y, (int) circleSize, color); // Creates
																		// the
																		// circle
																		// from
																		// the
																		// circle
																		// Class.

		listOfShapeDrawables.add(myCircle); // Adds circle to arraylist.

		invalidate();

		// Return 'true' to indicate that no further event processing
		// is required (the event was captured by the view).

		return true;
	}

}
