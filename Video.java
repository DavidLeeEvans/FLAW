/*
Simple DirectMedia Layer
Java source code (C) 2009-2014 Sergii Pylypenko

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required. 
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

package net.sourceforge.clonekeenplus;
import android.os.Environment;
import javax.microedition.khronos.opengles.GL10;
import javax.microedition.khronos.opengles.GL11;
import javax.microedition.khronos.opengles.GL11Ext;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGL11;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;
import javax.microedition.khronos.egl.EGLSurface;

import java.io.File;
import java.util.concurrent.locks.ReentrantLock;
import java.lang.reflect.Method;
import java.util.LinkedList;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

import android.os.Bundle;
import android.os.Build;
import android.os.Environment;
import android.util.DisplayMetrics;
import android.util.Log;
import android.content.Context;
import android.content.res.Resources;
import android.content.res.AssetManager;
import android.app.Activity;
import android.view.MotionEvent;
import android.view.KeyEvent;
import android.view.InputDevice;
import android.view.Window;
import android.view.WindowManager;
import android.widget.TextView;
import android.widget.Toast;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;
import android.app.PendingIntent;
import android.app.AlarmManager;
import android.content.Intent;
import android.view.View;
import android.view.Display;
import android.net.Uri;
import android.Manifest;
import android.content.pm.PackageManager;
import java.util.Locale;

class Mouse
{
	public static final int LEFT_CLICK_NORMAL = 0;
	public static final int LEFT_CLICK_NEAR_CURSOR = 1;
	public static final int LEFT_CLICK_WITH_MULTITOUCH = 2;
	public static final int LEFT_CLICK_WITH_PRESSURE = 3;
	public static final int LEFT_CLICK_WITH_KEY = 4;
	public static final int LEFT_CLICK_WITH_TIMEOUT = 5;
	public static final int LEFT_CLICK_WITH_TAP = 6;
	public static final int LEFT_CLICK_WITH_TAP_OR_TIMEOUT = 7;
	
	public static final int RIGHT_CLICK_NONE = 0;
	public static final int RIGHT_CLICK_WITH_MULTITOUCH = 1;
	public static final int RIGHT_CLICK_WITH_PRESSURE = 2;
	public static final int RIGHT_CLICK_WITH_KEY = 3;
	public static final int RIGHT_CLICK_WITH_TIMEOUT = 4;

	public static final int SDL_FINGER_DOWN = 0;
	public static final int SDL_FINGER_UP = 1;
	public static final int SDL_FINGER_MOVE = 2;
	public static final int SDL_FINGER_HOVER = 3;

	public static final int ZOOM_NONE = 0;
	public static final int ZOOM_MAGNIFIER = 1;

	public static final int MOUSE_HW_INPUT_FINGER = 0;
	public static final int MOUSE_HW_INPUT_STYLUS = 1;
	public static final int MOUSE_HW_INPUT_MOUSE = 2;

	public static final int MAX_HOVER_DISTANCE = 1024;
	public static final int HOVER_REDRAW_SCREEN = 1024 * 10;
	public static final float MAX_PRESSURE = 1024.0f;
}

abstract class DifferentTouchInput
{
	public abstract void process(final MotionEvent event);
	public abstract void processGenericEvent(final MotionEvent event);

	public static int ExternalMouseDetected = Mouse.MOUSE_HW_INPUT_FINGER;

	public static DifferentTouchInput touchInput = getInstance();

	public static DifferentTouchInput getInstance()
	{
		boolean multiTouchAvailable1 = false;
		boolean multiTouchAvailable2 = false;
		// Not checking for getX(int), getY(int) etc 'cause I'm lazy
		Method methods [] = MotionEvent.class.getDeclaredMethods();
		for(Method m: methods) 
		{
			if( m.getName().equals("getPointerCount") )
				multiTouchAvailable1 = true;
			if( m.getName().equals("getPointerId") )
				multiTouchAvailable2 = true;
		}
		try {
			Log.i("SDL", "Device: " + android.os.Build.DEVICE);
			Log.i("SDL", "Device name: " + android.os.Build.DISPLAY);
			Log.i("SDL", "Device model: " + android.os.Build.MODEL);
			Log.i("SDL", "Device board: " + android.os.Build.BOARD);
			if( android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.ICE_CREAM_SANDWICH )
			{
				//return IcsTouchInput.Holder.sInstance;
				return AutoDetectTouchInput.Holder.sInstance;
			}
			if( android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.GINGERBREAD )
				return GingerbreadTouchInput.Holder.sInstance;
			if (multiTouchAvailable1 && multiTouchAvailable2)
				return MultiTouchInput.Holder.sInstance;
			else
				return SingleTouchInput.Holder.sInstance;
		} catch( Exception e ) {
			try {
				if (multiTouchAvailable1 && multiTouchAvailable2)
					return MultiTouchInput.Holder.sInstance;
				else
					return SingleTouchInput.Holder.sInstance;
			} catch( Exception ee ) {
				return SingleTouchInput.Holder.sInstance;
			}
		}
	}

	private static class SingleTouchInput extends DifferentTouchInput
	{
		private static class Holder
		{
			private static final SingleTouchInput sInstance = new SingleTouchInput();
		}
		@Override
		public void processGenericEvent(final MotionEvent event)
		{
			process(event);
		}
		public void process(final MotionEvent event)
		{
			int action = -1;
			if( event.getAction() == MotionEvent.ACTION_DOWN )
				action = Mouse.SDL_FINGER_DOWN;
			if( event.getAction() == MotionEvent.ACTION_UP )
				action = Mouse.SDL_FINGER_UP;
			if( event.getAction() == MotionEvent.ACTION_MOVE )
				action = Mouse.SDL_FINGER_MOVE;
			if ( action >= 0 )
				DemoGLSurfaceView.nativeMotionEvent( (int)event.getX(), (int)event.getY(), action, 0, 
												(int)(event.getPressure() * Mouse.MAX_PRESSURE),
												(int)(event.getSize() * Mouse.MAX_PRESSURE) );
		}
	}
	private static class MultiTouchInput extends DifferentTouchInput
	{
		public static final int TOUCH_EVENTS_MAX = 16; // Max multitouch pointers

		private class touchEvent
		{
			public boolean down = false;
			public int x = 0;
			public int y = 0;
			public int pressure = 0;
			public int size = 0;
		}
		
		protected touchEvent touchEvents[];
		
		MultiTouchInput()
		{
			touchEvents = new touchEvent[TOUCH_EVENTS_MAX];
			for( int i = 0; i < TOUCH_EVENTS_MAX; i++ )
				touchEvents[i] = new touchEvent();
		}
		
		private static class Holder
		{
			private static final MultiTouchInput sInstance = new MultiTouchInput();
		}

		public void processGenericEvent(final MotionEvent event)
		{
			process(event);
		}
		public void process(final MotionEvent event)
		{
			int action = -1;

			//Log.i("SDL", "Got motion event, type " + (int)(event.getAction()) + " X " + (int)event.getX() + " Y " + (int)event.getY());
			if( (event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_UP ||
				(event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_CANCEL )
			{
				action = Mouse.SDL_FINGER_UP;
				for( int i = 0; i < TOUCH_EVENTS_MAX; i++ )
				{
					if( touchEvents[i].down )
					{
						touchEvents[i].down = false;
						DemoGLSurfaceView.nativeMotionEvent( touchEvents[i].x, touchEvents[i].y, action, i, touchEvents[i].pressure, touchEvents[i].size );
					}
				}
			}
			if( (event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_DOWN )
			{
				action = Mouse.SDL_FINGER_DOWN;
				for( int i = 0; i < event.getPointerCount(); i++ )
				{
					int id = event.getPointerId(i);
					if( id >= TOUCH_EVENTS_MAX )
						id = TOUCH_EVENTS_MAX - 1;
					touchEvents[id].down = true;
					touchEvents[id].x = (int)event.getX(i);
					touchEvents[id].y = (int)event.getY(i);
					touchEvents[id].pressure = (int)(event.getPressure(i) * Mouse.MAX_PRESSURE);
					touchEvents[id].size = (int)(event.getSize(i) * Mouse.MAX_PRESSURE);
					DemoGLSurfaceView.nativeMotionEvent( touchEvents[id].x, touchEvents[id].y, action, id, touchEvents[id].pressure, touchEvents[id].size );
				}
			}
			if( (event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_MOVE ||
				(event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_POINTER_DOWN ||
				(event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_POINTER_UP )
			{
				/*
				String s = "MOVE: ptrs " + event.getPointerCount();
				for( int i = 0 ; i < event.getPointerCount(); i++ )
				{
					s += " p" + event.getPointerId(i) + "=" + (int)event.getX(i) + ":" + (int)event.getY(i);
				}
				Log.i("SDL", s);
				*/
				int pointerReleased = -1;
				if( (event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_POINTER_UP )
					pointerReleased = (event.getAction() & MotionEvent.ACTION_POINTER_INDEX_MASK) >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;

				for( int id = 0; id < TOUCH_EVENTS_MAX; id++ )
				{
					int ii;
					for( ii = 0; ii < event.getPointerCount(); ii++ )
					{
						if( id == event.getPointerId(ii) )
							break;
					}
					if( ii >= event.getPointerCount() )
					{
						// Up event
						if( touchEvents[id].down )
						{
							action = Mouse.SDL_FINGER_UP;
							touchEvents[id].down = false;
							DemoGLSurfaceView.nativeMotionEvent( touchEvents[id].x, touchEvents[id].y, action, id, touchEvents[id].pressure, touchEvents[id].size );
						}
					}
					else
					{
						if( pointerReleased == id && touchEvents[pointerReleased].down )
						{
							action = Mouse.SDL_FINGER_UP;
							touchEvents[id].down = false;
						}
						else if( touchEvents[id].down )
						{
							action = Mouse.SDL_FINGER_MOVE;
						}
						else
						{
							action = Mouse.SDL_FINGER_DOWN;
							touchEvents[id].down = true;
						}
						touchEvents[id].x = (int)event.getX(ii);
						touchEvents[id].y = (int)event.getY(ii);
						touchEvents[id].pressure = (int)(event.getPressure(ii) * Mouse.MAX_PRESSURE);
						touchEvents[id].size = (int)(event.getSize(ii) * Mouse.MAX_PRESSURE);
						DemoGLSurfaceView.nativeMotionEvent( touchEvents[id].x, touchEvents[id].y, action, id, touchEvents[id].pressure, touchEvents[id].size );
					}
				}
			}
		}
	}
	private static class GingerbreadTouchInput extends MultiTouchInput
	{
		private static class Holder
		{
			private static final GingerbreadTouchInput sInstance = new GingerbreadTouchInput();
		}

		GingerbreadTouchInput()
		{
			super();
		}
		public void process(final MotionEvent event)
		{
			int hwMouseEvent =  ((event.getSource() & InputDevice.SOURCE_MOUSE) == InputDevice.SOURCE_MOUSE || Globals.ForceHardwareMouse) ? Mouse.MOUSE_HW_INPUT_MOUSE :
								((event.getSource() & InputDevice.SOURCE_STYLUS) == InputDevice.SOURCE_STYLUS) ? Mouse.MOUSE_HW_INPUT_STYLUS :
								Mouse.MOUSE_HW_INPUT_FINGER;
			if( ExternalMouseDetected != hwMouseEvent )
			{
				ExternalMouseDetected = hwMouseEvent;
				DemoGLSurfaceView.nativeHardwareMouseDetected(hwMouseEvent);
			}
			super.process(event);
			if( !Globals.FingerHover && ExternalMouseDetected == Mouse.MOUSE_HW_INPUT_FINGER )
				return; // Finger hover disabled in settings
			if( (event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_HOVER_MOVE ) // Support bluetooth/USB mouse - available since Android 3.1
			{
				int action;
				// TODO: it is possible that multiple pointers return that event, but we're handling only pointer #0
				if( touchEvents[0].down )
					action = Mouse.SDL_FINGER_UP;
				else
					action = Mouse.SDL_FINGER_HOVER;
				touchEvents[0].down = false;
				touchEvents[0].x = (int)event.getX();
				touchEvents[0].y = (int)event.getY();
				touchEvents[0].pressure = Mouse.MAX_HOVER_DISTANCE;
				touchEvents[0].size = 0;
				//if( event.getAxisValue(MotionEvent.AXIS_DISTANCE) != 0.0f )
				InputDevice device = InputDevice.getDevice(event.getDeviceId());
				if( device != null && device.getMotionRange(MotionEvent.AXIS_DISTANCE) != null &&
					device.getMotionRange(MotionEvent.AXIS_DISTANCE).getRange() > 0.0f )
					touchEvents[0].pressure = (int)((event.getAxisValue(MotionEvent.AXIS_DISTANCE) -
							device.getMotionRange(MotionEvent.AXIS_DISTANCE).getMin()) * Mouse.MAX_PRESSURE / device.getMotionRange(MotionEvent.AXIS_DISTANCE).getRange());
				DemoGLSurfaceView.nativeMotionEvent( touchEvents[0].x, touchEvents[0].y, action, 0, touchEvents[0].pressure, touchEvents[0].size );
			}
			if( (event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_HOVER_EXIT ) // Update screen for finger hover
			{
				touchEvents[0].pressure = Mouse.HOVER_REDRAW_SCREEN;
				touchEvents[0].size = 0;
				DemoGLSurfaceView.nativeMotionEvent( touchEvents[0].x, touchEvents[0].y, Mouse.SDL_FINGER_HOVER, 0, touchEvents[0].pressure, touchEvents[0].size );
			}
		}
		public void processGenericEvent(final MotionEvent event)
		{
			process(event);
		}
	}
	private static class IcsTouchInput extends GingerbreadTouchInput
	{
		float hatX = 0.0f, hatY = 0.0f;
		private static class Holder
		{
			private static final IcsTouchInput sInstance = new IcsTouchInput();
		}
		private int buttonState = 0;
		public void process(final MotionEvent event)
		{
			//Log.i("SDL", "Got motion event, type " + (int)(event.getAction()) + " X " + (int)event.getX() + " Y " + (int)event.getY() + " buttons " + buttonState + " source " + event.getSource());
			int buttonStateNew = event.getButtonState();
			if( buttonStateNew != buttonState )
			{
				for( int i = 1; i <= MotionEvent.BUTTON_FORWARD; i *= 2 )
				{
					if( (buttonStateNew & i) != (buttonState & i) )
						DemoGLSurfaceView.nativeMouseButtonsPressed(i, ((buttonStateNew & i) == 0) ? 0 : 1);
				}
				if( (buttonStateNew & MotionEvent.BUTTON_STYLUS_PRIMARY) != (buttonState & MotionEvent.BUTTON_STYLUS_PRIMARY) )
					DemoGLSurfaceView.nativeMouseButtonsPressed(2, ((buttonStateNew & MotionEvent.BUTTON_STYLUS_PRIMARY) == 0) ? 0 : 1);
				if( (buttonStateNew & MotionEvent.BUTTON_STYLUS_SECONDARY) != (buttonState & MotionEvent.BUTTON_STYLUS_SECONDARY) )
					DemoGLSurfaceView.nativeMouseButtonsPressed(4, ((buttonStateNew & MotionEvent.BUTTON_STYLUS_SECONDARY) == 0) ? 0 : 1);
				buttonState = buttonStateNew;
			}
			super.process(event);
		}
		public void processGenericEvent(final MotionEvent event)
		{
			// Joysticks are supported since Honeycomb, but I don't care about it, because very little devices have it
			if( (event.getSource() & InputDevice.SOURCE_CLASS_JOYSTICK) == InputDevice.SOURCE_CLASS_JOYSTICK )
			{
				// event.getAxisValue(AXIS_HAT_X) and event.getAxisValue(AXIS_HAT_Y) are joystick arrow keys, on Nvidia Shield and some other joysticks
				if( event.getAxisValue(MotionEvent.AXIS_HAT_X) != hatX )
				{
					hatX = event.getAxisValue(MotionEvent.AXIS_HAT_X);
					if( hatX == 0.0f )
					{
						DemoGLSurfaceView.nativeKey(KeyEvent.KEYCODE_DPAD_LEFT, 0, 0);
						DemoGLSurfaceView.nativeKey(KeyEvent.KEYCODE_DPAD_RIGHT, 0, 0);
					}
					else
						DemoGLSurfaceView.nativeKey(hatX < 0.0f ? KeyEvent.KEYCODE_DPAD_LEFT : KeyEvent.KEYCODE_DPAD_RIGHT, 1, 0);
				}
				if( event.getAxisValue(MotionEvent.AXIS_HAT_Y) != hatY )
				{
					hatY = event.getAxisValue(MotionEvent.AXIS_HAT_Y);
					if( hatY == 0.0f )
					{
						DemoGLSurfaceView.nativeKey(KeyEvent.KEYCODE_DPAD_UP, 0, 0);
						DemoGLSurfaceView.nativeKey(KeyEvent.KEYCODE_DPAD_DOWN, 0, 0);
					}
					else
						DemoGLSurfaceView.nativeKey(hatY < 0.0f ? KeyEvent.KEYCODE_DPAD_UP : KeyEvent.KEYCODE_DPAD_DOWN, 1, 0);
				}
				DemoGLSurfaceView.nativeGamepadAnalogJoystickInput(
					event.getAxisValue(MotionEvent.AXIS_X), event.getAxisValue(MotionEvent.AXIS_Y),
					event.getAxisValue(MotionEvent.AXIS_Z), event.getAxisValue(MotionEvent.AXIS_RZ),
					 event.getAxisValue(MotionEvent.AXIS_LTRIGGER), event.getAxisValue(MotionEvent.AXIS_RTRIGGER),
					(hatX == 0.0f && hatY == 0.0f) ? 0 : 1 );
				return;
			}
			// Process mousewheel
			if( event.getAction() == MotionEvent.ACTION_SCROLL )
			{
				int scrollX = Math.round(event.getAxisValue(MotionEvent.AXIS_HSCROLL));
				int scrollY = Math.round(event.getAxisValue(MotionEvent.AXIS_VSCROLL));
				DemoGLSurfaceView.nativeMouseWheel(scrollX, scrollY);
				return;
			}
			super.processGenericEvent(event);
		}
	}
	private static class IcsTouchInputWithHistory extends IcsTouchInput
	{
		private static class Holder
		{
			private static final IcsTouchInputWithHistory sInstance = new IcsTouchInputWithHistory();
		}
		public void process(final MotionEvent event)
		{
			int ptr = 0; // Process only one touch event, because that's typically a pen/mouse
			for( ptr = 0; ptr < TOUCH_EVENTS_MAX; ptr++ )
			{
				if( touchEvents[ptr].down )
					break;
			}
			if( ptr >= TOUCH_EVENTS_MAX )
				ptr = 0;
			//Log.i("SDL", "Got motion event, getHistorySize " + (int)(event.getHistorySize()) + " ptr " + ptr);

			for( int i = 0; i < event.getHistorySize(); i++ )
			{
				DemoGLSurfaceView.nativeMotionEvent( (int)event.getHistoricalX(i), (int)event.getHistoricalY(i),
					Mouse.SDL_FINGER_MOVE, ptr, (int)( event.getHistoricalPressure(i) * Mouse.MAX_PRESSURE ), (int)( event.getHistoricalSize(i) * Mouse.MAX_PRESSURE ) );
			}
			super.process(event);
		}
	}
	private static class CrappyMtkTabletWithBrokenTouchDrivers extends IcsTouchInput
	{
		private static class Holder
		{
			private static final CrappyMtkTabletWithBrokenTouchDrivers sInstance = new CrappyMtkTabletWithBrokenTouchDrivers();
		}
		public void process(final MotionEvent event)
		{
			if( (event.getAction() & MotionEvent.ACTION_MASK) != MotionEvent.ACTION_HOVER_MOVE &&
				(event.getAction() & MotionEvent.ACTION_MASK) != MotionEvent.ACTION_HOVER_EXIT ) // Ignore hover events, they are broken
				super.process(event);
		}
		public void processGenericEvent(final MotionEvent event)
		{
			if( (event.getAction() & MotionEvent.ACTION_MASK) != MotionEvent.ACTION_HOVER_MOVE &&
				(event.getAction() & MotionEvent.ACTION_MASK) != MotionEvent.ACTION_HOVER_EXIT ) // Ignore hover events, they are broken
				super.processGenericEvent(event);
		}
	}
	private static class AutoDetectTouchInput extends IcsTouchInput
	{
		int tapCount = 0;
		boolean hover = false, fingerHover = false, tap = false;
		float hoverX = 0.0f, hoverY = 0.0f;
		long hoverTime = 0;
		float tapX = 0.0f, tapY = 0.0f;
		long tapTime = 0;
		float hoverTouchDistance = 0.0f;

		private static class Holder
		{
			private static final AutoDetectTouchInput sInstance = new AutoDetectTouchInput();
		}
		public void process(final MotionEvent event)
		{
			if( ((event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_UP ||
				(event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_DOWN) )
			{
				tapCount ++;
				if( (event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_UP )
				{
					tap = true;
					tapX = event.getX();
					tapY = event.getY();
					tapTime = System.currentTimeMillis();
					if( hover )
						Log.i("SDL", "Tap tapX " + event.getX() + " tapY " + event.getX());
				}
				else if( hover && System.currentTimeMillis() < hoverTime + 1000 )
				{
					hoverTouchDistance += Math.abs(hoverX - event.getX()) + Math.abs(hoverY - event.getY());
					Log.i("SDL", "Finger down event.getX() " + event.getX() + " hoverX " + hoverX + " event.getY() " + event.getY() + " hoverY " + hoverY + " hoverTouchDistance " + hoverTouchDistance);
				}
			}
			if( tapCount >= 4 )
			{
				int displayHeight = 800;
				try {
					DisplayMetrics dm = new DisplayMetrics();
					MainActivity.instance.getWindowManager().getDefaultDisplay().getMetrics(dm);
					displayHeight = Math.min(dm.widthPixels, dm.heightPixels);
				} catch (Exception eeeee) {}
				Log.i("SDL", "AutoDetectTouchInput: hoverTouchDistance " + hoverTouchDistance + " threshold " + displayHeight / 2 + " hover " + hover + " fingerHover " + fingerHover);
				if( hoverTouchDistance > displayHeight / 2 )
				{
					if( Globals.AppUsesMouse )
						Toast.makeText(MainActivity.instance, "Detected buggy touch panel, enabling workarounds", Toast.LENGTH_SHORT).show();
					touchInput = CrappyMtkTabletWithBrokenTouchDrivers.Holder.sInstance;
				}
				else
				{
					if( fingerHover )
					{
						if( Globals.AppUsesMouse )
							Toast.makeText(MainActivity.instance, "Finger hover capability detected", Toast.LENGTH_SHORT).show();
						// Switch away from relative mouse input
						if( Globals.FingerHover && (Globals.RelativeMouseMovement || Globals.LeftClickMethod != Mouse.LEFT_CLICK_NORMAL) )
						{
							if( Globals.RelativeMouseMovement )
								Globals.ShowScreenUnderFinger = Mouse.ZOOM_MAGNIFIER;
							Globals.RelativeMouseMovement = false;
							Globals.LeftClickMethod = Mouse.LEFT_CLICK_NORMAL;
						}
						Settings.applyMouseEmulationOptions();
					}
					if ( Globals.GenerateSubframeTouchEvents )
						touchInput = IcsTouchInputWithHistory.Holder.sInstance;
					else
						touchInput = IcsTouchInput.Holder.sInstance;
				}
			}
			super.process(event);
		}
		public void processGenericEvent(final MotionEvent event)
		{
			super.processGenericEvent(event);
			if( (event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_HOVER_MOVE ||
				(event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_HOVER_ENTER ||
				(event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_HOVER_EXIT )
			{
				hover = true;
				hoverX = event.getX();
				hoverY = event.getY();
				hoverTime = System.currentTimeMillis();
				if( ExternalMouseDetected == 0 && (event.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_HOVER_MOVE )
					fingerHover = true;
				if( tap && System.currentTimeMillis() < tapTime + 1000 )
				{
					tap = false;
					hoverTouchDistance += Math.abs(tapX - hoverX) + Math.abs(tapY - hoverY);
					Log.i("SDL", "Hover hoverX " + hoverX + " tapX " + tapX + " hoverY " + hoverX + " tapY " + tapY + " hoverTouchDistance " + hoverTouchDistance);
				}
			}
		}
	}
}

class DemoRenderer extends GLSurfaceView_SDL.Renderer
{
	public DemoRenderer(MainActivity _context)
	{
		context = _context;
		Clipboard.get().setListener(context, new Runnable()
		{
			public void run()
			{
				nativeClipboardChanged();
			}
		});
	}
	
	public void onSurfaceCreated(GL10 gl, EGLConfig config)
	{
		Log.i("SDL", "libSDL: DemoRenderer.onSurfaceCreated(): paused " + mPaused + " mFirstTimeStart " + mFirstTimeStart );
		mGlSurfaceCreated = true;
		mGl = gl;
		if( ! mPaused && ! mFirstTimeStart )
			nativeGlContextRecreated();
		mFirstTimeStart = false;
	}

	public void onSurfaceChanged(GL10 gl, int w, int h)
	{
		Log.i("SDL", "libSDL: DemoRenderer.onSurfaceChanged(): paused " + mPaused + " mFirstTimeStart " + mFirstTimeStart + " w " + w + " h " + h);
		if( w < h && Globals.HorizontalOrientation )
		{
			// Sometimes when Android awakes from lockscreen, portrait orientation is kept
			int x = w;
			w = h;
			h = x;
		}
		mWidth = w - w % 2;
		mHeight = h - h % 2;
		mGl = gl;
		nativeResize(mWidth, mHeight, Globals.KeepAspectRatio ? 1 : 0);
	}

	int mLastPendingResize = 0;
	public void onWindowResize(final int w, final int h)
	{
		if (context.isRunningOnOUYA())
			return; // TV screen is never resized, and this event will mess up TV borders
		Log.d("SDL", "libSDL: DemoRenderer.onWindowResize(): " + w + "x" + h);
		mLastPendingResize ++;
		final int resizeThreadIndex = mLastPendingResize;
		context.mGLView.postDelayed(new Runnable()
		{
			public void run()
			{
				// Samsung multiwindow will swap screen dimensions when unlocking the lockscreen, sleep a while so we won't use these temporary values
				if (resizeThreadIndex != mLastPendingResize)
					return; // Avoid running this function multiple times in a row
				int ww = w - w % 2;
				int hh = h - h % 2;
				View topView = context.getWindow().peekDecorView();
				if (topView != null && Globals.ImmersiveMode)
				{
					ww = topView.getWidth() - topView.getWidth() % 2;
					hh = topView.getHeight() - topView.getHeight() % 2;
				}

				Display display = context.getWindowManager().getDefaultDisplay();

				if (mWidth != 0 && mHeight != 0 && (mWidth != ww || mHeight != hh))
				{
					Log.i("SDL", "libSDL: DemoRenderer.onWindowResize(): screen size changed from " + mWidth + "x" + mHeight + " to " + ww + "x" + hh);
					if (Globals.SwVideoMode &&
						(Math.abs(display.getWidth() - ww) > display.getWidth() / 10 ||
						Math.abs(display.getHeight() - hh) > display.getHeight() / 10))
					{
						Log.i("SDL", "Multiwindow detected - enabling screen orientation autodetection");
						Globals.AutoDetectOrientation = true;
						context.setScreenOrientation();
						DemoRenderer.super.ResetVideoSurface();
						DemoRenderer.super.onWindowResize(ww, hh);
					}
					else
					{
						Log.i("SDL", "System button bar hidden - re-init video to avoid black bar at the top");
						DemoRenderer.super.ResetVideoSurface();
						DemoRenderer.super.onWindowResize(ww, hh);
					}
				}
				if (mWidth == 0 && mHeight == 0)
				{
					if ((ww > hh) != (display.getWidth() > display.getHeight()))
					{
						Log.i("SDL", "Multiwindow detected - app window size " + ww + "x" + hh + " but display dimensions are " + display.getWidth() + "x" + display.getHeight());
						Globals.AutoDetectOrientation = true;
					}
				}
				if (Globals.AutoDetectOrientation && (ww > hh) != (mWidth > mHeight))
					Globals.HorizontalOrientation = (ww > hh);
			}
		}, 2000);
	}

	public void onSurfaceDestroyed()
	{
		Log.i("SDL", "libSDL: DemoRenderer.onSurfaceDestroyed(): paused " + mPaused + " mFirstTimeStart " + mFirstTimeStart );
		mGlSurfaceCreated = false;
		mGlContextLost = true;
		nativeGlContextLost();
	};

	public void onDrawFrame(GL10 gl)
	{
		mGl = gl;
		SwapBuffers();

		nativeInitJavaCallbacks();
		
		// Make main thread priority lower so audio thread won't get underrun
		// Thread.currentThread().setPriority((Thread.currentThread().getPriority() + Thread.MIN_PRIORITY)/2);
		
		mGlContextLost = false;

		if( Globals.CompatibilityHacksStaticInit )
			MainActivity.LoadApplicationLibrary(context);
		while( !MainActivity.ApplicationLibraryLoaded )
			try { Thread.sleep(200); } catch (InterruptedException eeee) {}

		Settings.Apply(context);
		Settings.nativeSetEnv( "DISPLAY_RESOLUTION_WIDTH", String.valueOf(Math.max(mWidth, mHeight)) );
		Settings.nativeSetEnv( "DISPLAY_RESOLUTION_HEIGHT", String.valueOf(Math.min(mWidth, mHeight)) ); // In Kitkat with immersive mode, getWindowManager().getDefaultDisplay().getMetrics() return inaccurate height

		accelerometer = new AccelerometerReader(context);
		if( Globals.MoveMouseWithGyroscope )
			startAccelerometerGyroscope(1);
		// Tweak video thread priority, if user selected big audio buffer
		if( Globals.AudioBufferConfig >= 2 )
			Thread.currentThread().setPriority( (Thread.NORM_PRIORITY + Thread.MIN_PRIORITY) / 2 ); // Lower than normal
		// Calls main() and never returns, hehe - we'll call eglSwapBuffers() from native code
	

		final String loc = Locale.getDefault().getLanguage();
		String commandline = Globals.CommandLine + " " + "-l " + loc;
		if( context.getIntent() != null && context.getIntent().getScheme() != null &&
			context.getIntent().getScheme().compareTo(android.content.ContentResolver.SCHEME_FILE) == 0 &&
			context.getIntent().getData() != null && context.getIntent().getData().getPath() != null )
		{
			commandline += " " + context.getIntent().getData().getPath();
		}
		nativeInit( Globals.DataDir,
					commandline,
					( (Globals.SwVideoMode && Globals.MultiThreadedVideo) || Globals.CompatibilityHacksVideo ) ? 1 : 0,
					0 );
		System.exit(0); // The main() returns here - I don't bother with deinit stuff, just terminate process
	}

	public int swapBuffers() // Called from native code
	{
		if( ! super.SwapBuffers() && Globals.NonBlockingSwapBuffers )
		{
			if(mRatelimitTouchEvents)
			{
				synchronized(this)
				{
					this.notify();
				}
			}
			return 0;
		}

		if(mGlContextLost) {
			mGlContextLost = false;
			Settings.SetupTouchscreenKeyboardGraphics(context); // Reload on-screen buttons graphics
			super.SwapBuffers();
		}

		// Unblock event processing thread only after we've finished rendering
		if(mRatelimitTouchEvents)
		{
			synchronized(this)
			{
				this.notify();
			}
		}
		if( context.isScreenKeyboardShown() && !context.keyboardWithoutTextInputShown )
		{
			try {
				Thread.sleep(50); // Give some time to the keyboard input thread
			} catch(Exception e) { };
		}

		// We will not receive onConfigurationChanged() inside MainActivity with SCREEN_ORIENTATION_SENSOR_LANDSCAPE
		// so we need to create a hacky frame counter to update screen orientation, because this call takes up some time
		mOrientationFrameHackyCounter++;
		if( mOrientationFrameHackyCounter > 100 )
		{
			mOrientationFrameHackyCounter = 0;
			context.updateScreenOrientation();
		}

		return 1;
	}

	public void showScreenKeyboardWithoutTextInputField() // Called from native code
	{
		context.showScreenKeyboardWithoutTextInputField(Globals.TextInputKeyboard);
	}

	public void showInternalScreenKeyboard(int keyboard) // Called from native code
	{
		context.showScreenKeyboardWithoutTextInputField(keyboard);
	}

	public void showScreenKeyboard(final String oldText, int unused) // Called from native code
	{
		class Callback implements Runnable
		{
			public MainActivity parent;
			public String oldText;
			public void run()
			{
				parent.showScreenKeyboard(oldText);
			}
		}
		Callback cb = new Callback();
		cb.parent = context;
		cb.oldText = oldText;
		context.runOnUiThread(cb);
	}

	public void hideScreenKeyboard() // Called from native code
	{
		class Callback implements Runnable
		{
			public MainActivity parent;
			public void run()
			{
				parent.hideScreenKeyboard();
			}
		}
		Callback cb = new Callback();
		cb.parent = context;
		context.runOnUiThread(cb);
	}

	public int isScreenKeyboardShown() // Called from native code
	{
		return context.isScreenKeyboardShown() ? 1 : 0;
	}

	public void setScreenKeyboardHintMessage(String s) // Called from native code
	{
		context.setScreenKeyboardHintMessage(s);
	}

	public void startAccelerometerGyroscope(int started) // Called from native code
	{
		accelerometer.openedBySDL = (started != 0);
		if( accelerometer.openedBySDL && !mPaused )
			accelerometer.start();
		else
			accelerometer.stop();
	}

	public String getClipboardText() // Called from native code
	{
		return Clipboard.get().get(context);
	}

	public void setClipboardText(final String s) // Called from native code
	{
		Clipboard.get().set(context, s);
	}

	public void exitApp()
	{
		 nativeDone();
	}

	public void getAdvertisementParams(int params[])
	{
		context.getAdvertisementParams(params);
	}
	public void setAdvertisementVisible(int visible)
	{
		context.setAdvertisementVisible(visible);
	}
	public void setAdvertisementPosition(int left, int top)
	{
		context.setAdvertisementPosition(left, top);
	}
	public void requestNewAdvertisement()
	{
		context.requestNewAdvertisement();
	}

	public boolean cloudSave(final String filename, final String saveId, final String dialogTitle, final String description, final String imageFile, final long playedTimeMs)
	{
		if (context.cloudSave.isSignedIn() && saveId.length() > 0)
		{
			// Do not show progress dialog, run in a parallel thread, so main thread will not be blocked
			new Thread(new Runnable()
			{
				public void run()
				{
					context.cloudSave.save(filename, saveId, dialogTitle, description, imageFile, playedTimeMs);
				}
			}).start();
			return true;
		}

		context.runOnUiThread(new Runnable()
		{
			public void run()
			{
				context.loadingDialog.show();
			}
		});

		boolean ret = context.cloudSave.save(filename, saveId, dialogTitle, description, imageFile, playedTimeMs);

		context.runOnUiThread(new Runnable()
		{
			public void run()
			{
				context.loadingDialog.dismiss();
			}
		});

		return ret;
	}

	public boolean cloudLoad(String filename, String saveId, String dialogTitle)
	{
		context.runOnUiThread(new Runnable()
		{
			public void run()
			{
				context.loadingDialog.show();
			}
		});

		boolean ret = context.cloudSave.load(filename, saveId, dialogTitle);

		context.runOnUiThread(new Runnable()
		{
			public void run()
			{
				context.loadingDialog.dismiss();
			}
		});

		return ret;
	}
	
	public void openExternalApp(String pkgName, String activity, String url)
	{
		try {
			Intent i = new Intent();
			if (url != null && url.length() > 0)
			{
				i.setAction(Intent.ACTION_VIEW);
				i.setData(Uri.parse(url));
			}
			if (pkgName != null && activity != null && pkgName.length() > 0 && activity.length() > 0)
			{
				i.setClassName(pkgName, activity);
			}
			context.startActivity(i);
		} catch (Exception e) {
			Log.i("SDL", "libSDL: cannot start external app: " + e.toString());
		}
	}

	public void restartMyself(String restartParams)
	{
		Intent intent = new Intent(context, RestartMainActivity.class);
		intent.putExtra(RestartMainActivity.SDL_RESTART_PARAMS, restartParams);
		context.startActivity(intent);
		System.exit(0);
	}

	public void setConfigOptionFromSDL(int option, int value)
	{
		Settings.setConfigOptionFromSDL(option, value);
	}

	private int PowerOf2(int i)
	{
		int value = 1;
		while (value < i)
			value <<= 1;
		return value;
	}

	private native void nativeInitJavaCallbacks();
	private native void nativeInit(String CurrentPath, String CommandLine, int multiThreadedVideo, int unused);
	private native void nativeResize(int w, int h, int keepAspectRatio);
	private native void nativeDone();
	private native void nativeGlContextLost();
	public native void nativeGlContextRecreated();
	public native void nativeGlContextLostAsyncEvent();
	public static native void nativeTextInput( int ascii, int unicode );
	public static native void nativeTextInputFinished();
	public static native void nativeClipboardChanged();

	private MainActivity context = null;
	public AccelerometerReader accelerometer = null;
	
	private GL10 mGl = null;
	private EGL10 mEgl = null;
	private EGLDisplay mEglDisplay = null;
	private EGLSurface mEglSurface = null;
	private EGLContext mEglContext = null;
	private boolean mGlContextLost = false;
	public boolean mGlSurfaceCreated = false;
	public boolean mPaused = false;
	private boolean mFirstTimeStart = true;
	public int mWidth = 0;
	public int mHeight = 0;
	int mOrientationFrameHackyCounter = 0;

	public static final boolean mRatelimitTouchEvents = true; //(Build.VERSION.SDK_INT >= Build.VERSION_CODES.FROYO);
}

class DemoGLSurfaceView extends GLSurfaceView_SDL {
	public DemoGLSurfaceView(MainActivity context) {
		super(context);
		mParent = context;
		setEGLConfigChooser(Globals.VideoDepthBpp, Globals.NeedDepthBuffer, Globals.NeedStencilBuffer, Globals.NeedGles2, Globals.NeedGles3);
		mRenderer = new DemoRenderer(context);
		setRenderer(mRenderer);
	}

	@Override
	public boolean onTouchEvent(final MotionEvent event) 
	{
		if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.ICE_CREAM_SANDWICH)
		{
			if (getX() != 0)
				event.offsetLocation(-getX(), -getY());
		}
		DifferentTouchInput.touchInput.process(event);
		if( DemoRenderer.mRatelimitTouchEvents )
		{
			limitEventRate(event);
		}
		return true;
	};

	@Override
	public boolean onGenericMotionEvent (final MotionEvent event)
	{
		DifferentTouchInput.touchInput.processGenericEvent(event);
		if( DemoRenderer.mRatelimitTouchEvents )
		{
			limitEventRate(event);
		}
		return true;
	}
	
	public void limitEventRate(final MotionEvent event)
	{
		// Wait a bit, and try to synchronize to app framerate, or event thread will eat all CPU and we'll lose FPS
		// With Froyo the rate of touch events seems to be limited by OS, but they are arriving faster then we're redrawing anyway
		if((event.getAction() == MotionEvent.ACTION_MOVE ||
			event.getAction() == MotionEvent.ACTION_HOVER_MOVE))
		{
			synchronized(mRenderer)
			{
				try
				{
					mRenderer.wait(300L); // And sometimes the app decides not to render at all, so this timeout should not be big.
				}
				catch (InterruptedException e)
				{
					Log.v("SDL", "DemoGLSurfaceView::limitEventRate(): Who dared to interrupt my slumber?");
					Thread.interrupted();
				}
			}
		}
	}

	public void exitApp() {
		mRenderer.exitApp();
	};

	@Override
	public void onPause() {
		Log.i("SDL", "libSDL: DemoGLSurfaceView.onPause(): mRenderer.mGlSurfaceCreated " + mRenderer.mGlSurfaceCreated + " mRenderer.mPaused " + mRenderer.mPaused + (mRenderer.mPaused ? " - not doing anything" : ""));
		if(mRenderer.mPaused)
			return;
		mRenderer.mPaused = true;
		super.onPause();
		mRenderer.nativeGlContextLostAsyncEvent();
		if( mRenderer.accelerometer != null ) // For some reason it crashes here often - are we getting this event before initialization?
			mRenderer.accelerometer.stop();
	};
	
	public boolean isPaused() {
		return mRenderer.mPaused;
	}

	@Override
	public void onResume() {
		Log.i("SDL", "libSDL: DemoGLSurfaceView.onResume(): mRenderer.mGlSurfaceCreated " + mRenderer.mGlSurfaceCreated + " mRenderer.mPaused " + mRenderer.mPaused + (!mRenderer.mPaused ? " - not doing anything" : ""));
		if(!mRenderer.mPaused)
			return;
		mRenderer.mPaused = false;
		super.onResume();
		if( mRenderer.mGlSurfaceCreated && ! mRenderer.mPaused || Globals.NonBlockingSwapBuffers )
			mRenderer.nativeGlContextRecreated();
		if( mRenderer.accelerometer != null && mRenderer.accelerometer.openedBySDL ) // For some reason it crashes here often - are we getting this event before initialization?
			mRenderer.accelerometer.start();
	};

	DemoRenderer mRenderer;
	MainActivity mParent;

	public static native void nativeMotionEvent( int x, int y, int action, int pointerId, int pressure, int radius );
	public static native int  nativeKey( int keyCode, int down, int unicode );
	public static native void nativeHardwareMouseDetected( int detected );
	public static native void nativeMouseButtonsPressed( int buttonId, int pressedState );
	public static native void nativeMouseWheel( int scrollX, int scrollY );
	public static native void nativeGamepadAnalogJoystickInput( float stick1x, float stick1y, float stick2x, float stick2y, float ltrigger, float rtrigger, int usingHat );
	public static native void nativeScreenVisibleRect( int x, int y, int w, int h );
	public static native void nativeScreenKeyboardShown( int shown );
}
