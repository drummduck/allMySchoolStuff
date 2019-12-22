package assign09.namespace;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

public class AnimateView extends View {

	float X=0;
	float Y=10;
	Paint paint;
	
	
	public AnimateView(Context context, AttributeSet attributes){
		super(context,attributes);
		
	}
	
	public void onDraw ( Canvas canvas){
		
		
		super.onDraw(canvas);
		
		Paint paint = new Paint();
		paint.setColor(Color.GREEN);
		paint.setStrokeWidth(10);
		paint.setStyle(Paint.Style.STROKE);
		
		canvas.drawCircle(X, Y, 30, paint);
		canvas.drawCircle(X+10, Y+10, 30,paint);		
		if(X<canvas.getWidth()){
		X=X+10;
		}
		else{
			
			Y=Y+10;
			X=0;
		}
		invalidate();
		
	
	}
	
}
