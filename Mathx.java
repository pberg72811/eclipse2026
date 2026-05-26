package org.ieee.jcc.util;

import org.ieee.jcc.util.DEBUG;

//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: Mathx.java
//
// Desc: Additional tools for numerics.
//
// Hist: When       Who  What
//       04/28/2016 ptb  Initial Code.
//------------------------------------------------------------------------------------------------
public class Mathx
{
  public final static double DE2RA = Math.PI / 180.0;
  public final static double RA2DE = 180.0 / Math.PI;
  public final static double TWOPI = 2.0 * Math.PI;

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  private Mathx()                                                    //
  {                                                                  //

  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static double[] linspace(double d1, double d2, int n)       // Method linspace().
  {                                                                  //
    int ii;
    int m = n - 1;
    double[] x = new double[n];
    double delta = (d2 - d1) / (double) (n - 1);
    for (ii = 0; ii < m; ii++)
    {
      x[ii] = d1 + ((double) (ii)) * delta;
    }
    x[0] = d1;
    x[m] = d2;
    return (x);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static double magnitude(double[] vector)                    //
  {                                                                  //
    int ii;
    double sum = 0.0;
    for (ii = 0; ii < vector.length; ii++)
    {
      sum += vector[ii] * vector[ii];
    }

    return (Math.sqrt(sum));
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static double str2double(String str)                        //
  {                                                                  //
    double val = 0;
    try
    {
      val = Double.parseDouble(str);
    }
    catch (NumberFormatException e)
    {
      DEBUG.ERRORF("Number Format Exception\n");
      e.printStackTrace();
      System.exit(1);

    }
    return (val);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static int str2integer(String str)                          //
  {                                                                  //
    int val = 0;
    try
    {
      val = Integer.parseInt(str);
    }
    catch (NumberFormatException e)
    {
      DEBUG.ERRORF("Number Format Exception\n");
      e.printStackTrace();
      System.exit(1);

    }
    return (val);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static long str2long(String str)                            //
  {                                                                  //
    long val = 0;
    try
    {
      val = Long.parseLong(str);
    }
    catch (NumberFormatException e)
    {
      DEBUG.ERRORF("Number Format Exception\n");
      e.printStackTrace();
      System.exit(1);

    }
    return (val);
  }

  //---------------------------------------UNCLASSIFIED-------------------------------------------
  // main
  //----------------------------------------------------------------------------------------------
  public static void main(String[] args)
  {
    DEBUG.MESSAGEF("DONE\n");
  }

}

//THE FOLLOWING IS FOR A CODING TEMPLATE ONLY.
//THE FOLLOWING IS NOT CLASSIFIED.
//    1         2         3         4        |5         6         7         8         9
//345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
//-----------------------------------------UNCLASSIFIED-------------------------------------------
//--------------------------------------UNCLASSIFIED//FOUO----------------------------------------
//-----------------------------------------CONFIDENTIAL-------------------------------------------
//--------------------------------------------SECRET----------------------------------------------
//--------------------------------------------ERROR-----------------------------------------------
//-------------------------------------------WARNING----------------------------------------------
//-------------------------------------------MESSAGE----------------------------------------------