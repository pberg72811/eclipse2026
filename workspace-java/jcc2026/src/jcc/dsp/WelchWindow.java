package jcc.dsp;

//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: WelchWindow.java
//
// Desc: A Class that generates a Welch Window.
//
// Hist: When       Who  What
//       03/09/2016 ptb  Initial Code.
//------------------------------------------------------------------------------------------------

import jcc.DEBUG;

public class WelchWindow
{

	double[] value;

	// ---------------------------------------------------------------//--------------------------
	public WelchWindow(int N_)                                        // Create Welch Window.
	{                                                                 //
		int ii;
		double term;
		double numerator;
		double denominator;
		double N = (double) (N_);
		this.value = new double[N_];

		for (ii = 0; ii < N; ii++)
		{
			numerator = ii - 0.5 * (N - 1.0);
			denominator = 0.5 * (N - 1.0);
			term = numerator / denominator;
			value[ii] = 1.0 - (term * term);
		}
	}

	// ---------------------------------------------------------------//--------------------------
	public static void main(String[] args)                            //
	{                                                                 //
		int ii;
		int N = 32;
		WelchWindow window = new WelchWindow(N);
		
		System.out.println(DEBUG.MESSAGE());
		System.out.println(DEBUG.MESSAGE("Hello, from WelchWindow!"));
		System.out.printf("\n");
		System.out.printf("Size of window is %d\n", window.value.length);
		System.out.printf("\n");
		
		for (ii = 0; ii < N; ii++)
		{
			System.out.printf("Window index %02d value %f\n", ii, window.value[ii]);
		}
		
		DEBUG.EXIT("DONE.");
	}

}

// THE FOLLOWING IS FOR A CODING TEMPLATE ONLY.
// THE FOLLOWING IS NOT CLASSIFIED.
//       1         2         3         4        |5         6         7         8         9
//345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
//-----------------------------------------UNCLASSIFIED-------------------------------------------
//--------------------------------------UNCLASSIFIED//FOUO----------------------------------------
//-----------------------------------------CONFIDENTIAL-------------------------------------------
//--------------------------------------------SECRET----------------------------------------------
//--------------------------------------------ERROR-----------------------------------------------
//-------------------------------------------WARNING----------------------------------------------
//-------------------------------------------MESSAGE----------------------------------------------
