package cs1410.Lab12;

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


public class Labview extends View
{
	ArrayList<Circle> listOfShapeDrawables = new ArrayList<Circle>();
	float circleSize;
	 int x = 100;
	 int y = 100;
	 int r;
	 int q;
    public Labview (Context context, AttributeSet attributes)
   
    {
        super(context, attributes);
    }


public void onDraw (Canvas canvas)
{
	
    // Create a paint object to define drawing colors, styles, etc.

    Paint paint = new Paint();
    paint.setColor(Color.RED);
    paint.setTextSize(30);
    paint.setAntiAlias(true);
    paint.setStrokeWidth(5);
    

    // Draw to the canvas, and use our 'paint' to style the drawings.
    for(Circle c : listOfShapeDrawables)
    {

	    canvas.drawCircle(c.getX(), c.getY(), c.getRadius(), paint);
    }
    
    

}
public void setCircleSize(float size)
{
    circleSize = size;
    invalidate();  // Forces a redraw sometime soon
}

public boolean onTouchEvent(MotionEvent event)
{
	
	    x = (int)event.getX();  // x-coordinate where user clicked.
	    y = (int)event.getY();  // y-coordinate where user clicked.
	    
	    Circle myCircle = new Circle(x, y, (int) circleSize);
	    
	    listOfShapeDrawables.add(myCircle);
    
     invalidate();
     


    // Return 'true' to indicate that no further event processing
    //  is required (the event was captured by the view).

    return true;
}

}
