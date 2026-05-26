//package org.ieee.jcc.util;

//import org.ieee.jcc.util.DEBUG;

//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: Time.java
//
// Desc: Time functions for java.
//
// Hist: When       Who  What
//       11/11/2015 ptb  Initial Code.
//------------------------------------------------------------------------------------------------
public class Time
{
  final static double SecondsPerSiderealDay = 86400.0;
  final static double RevsPerSiderealDay    = 1.00273790934;
  final static double IGREG1                = (15 + 31 * (10 + 12 * 1582));
  final static double JulianSeconds1950     = 210235608000.0;
  final static double JulianSeconds1970     = 210866760000.0;

  private Time()
  {
  }

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  public static double currentJulianDate()                           // Method
  {                                                                  // currentJulianDate().
    GregCal cal = new GregCal();
    double JD = julianDate(cal.yy, cal.mm + 1, cal.dd, cal.hh, cal.mn, cal.ss);
    return (JD);
  }

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  public static double currentMilliSecond()                          // Method
  {                                                                  // currentMilliSecond().
    return ((double) System.currentTimeMillis());
  }

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  public static double currentNanoseconds()                          // Method
  {                                                                  // currentNanoseconds().
    return (((double) System.nanoTime()));
  }

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  public static double currentSecondsJulian()                        // Method
  {                                                                  // currentSecondsJulian().
    double ans = currentSecondsUnix();
    return (JulianSeconds1970 + ans);
  }

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  public static double currentSecondsMidas()                         // Method
  {                                                                  // currentSecondsMidas().
    double ans = currentSecondsUnix();
    return (JulianSeconds1970 - JulianSeconds1950 + ans);
  }

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  public static double currentSecondsUnix()                          // Method
  {                                                                  // currentSecondsUnix().
    return (((double) System.currentTimeMillis()) / 1000.0);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static String currentTimeString()                           // Method currentTimeString.
  {                                                                  // 
    GregCal cal = new GregCal();
    String YY = String.format("%04d", cal.yy);
    String MM = String.format("%02d", cal.mm + 1);
    String DD = String.format("%02d", cal.dd);
    String HH = String.format("%02d", cal.hh);
    String MN = String.format("%02d", cal.mn);
    String SS = String.format("%06.3f", cal.ss);
    String str = YY + ":" + MM + ":" + DD + "::" + HH + ":" + MN + ":" + SS;

    return (str);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static double unixSeconds(int yy, int mm, int dd, int hh, int mn, double dss)
  {                                                                  // Method epochSeconds().
    double epoch;
    int ss = (int) dss;
    GregCal cal = new GregCal();
    cal.clear();
    cal.set(yy, mm - 1, dd, hh, mn, ss);
    epoch = ((double) cal.getTimeInMillis()) / 1000.0;
    return (epoch);
  }
  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static double currentPhiGrn()                               // Method currentPhiGrn.
  {                                                                  //
    return (currentSecondsJulian());
  }
  
  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static double getPhiGrn(double jseconds)                    // Method getPhiGrn.
  {                                                                  // Needs Julian Seconds.
    double jDays = jseconds / SecondsPerSiderealDay;
    double UT = (jDays + 0.5) - Math.floor(jDays + 0.5);
    jDays = jDays - UT;
    double TU = (jDays - 2451545.0) / 36525.0;
    double GMST = 24110.54841 + TU * (8640184.812866 + TU * (0.093104 - TU * 6.2E-06));
    GMST = (GMST + SecondsPerSiderealDay * RevsPerSiderealDay * UT) % (SecondsPerSiderealDay);
    double phiGrn = 2 * Math.PI * (GMST / SecondsPerSiderealDay);
    return (phiGrn);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static double julianDate(int yy, int mm, int dd, int hh, int mn, double ss)
  {                                                                  // Method julianDate().
    double YY = (double) yy;
    double MM = (double) mm;
    double DD = (double) dd;
    double HH = (double) hh;
    double MN = (double) mn;
    double SS = (double) ss;
    double term01 = 367.0 * YY;
    double mm9 = Math.floor((MM + 9.0) / 12.0);
    double term02 = Math.floor(7 * (YY + mm9) / 4.0);
    double term03 = Math.floor(275.0 * MM / 9.0);
    double term04 = DD;
    double term05 = 1721013.5;
    double term06 = ((((SS / 60.0) + MN) / 60.0) + HH) / 24;
    return (term01 - term02 + term03 + term04 + term05 + term06);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static double julianSeconds(int yy, int mm, int dd, int hh, int mn, double dss)
  {                                                                  // Method julianSeconds().
    double js;
    js = unixSeconds(yy, mm, dd, hh, mn, dss) + JulianSeconds1970;
    return (js);
  }

  //---------------------------------------UNCLASSIFIED-------------------------------------------
  // main
  //----------------------------------------------------------------------------------------------
  public static void main(String[] args)
  {
    DEBUG.MESSAGEF(DEBUG.MESSAGE("START\n"));
    System.out.println("HELLO");
    System.out.println(System.currentTimeMillis());
    DEBUG.MESSAGEF("%024.8f\n", currentSecondsUnix());
    DEBUG.MESSAGEF("%024.8f\n", currentSecondsMidas());
    DEBUG.MESSAGEF("%024.8f\n", currentSecondsJulian());
    DEBUG.MESSAGEF("%12.10f\n", getPhiGrn(currentSecondsJulian()));
    DEBUG.MESSAGEF("%12.10f\n", getPhiGrn(1466018339));
    DEBUG.MESSAGEF("%024.8f\n", currentNanoseconds());
    DEBUG.MESSAGEF("%024.8f\n", currentNanoseconds() / 1e9);
    DEBUG.MESSAGEF("%024.8f\n", currentNanoseconds() / 1e9 / 60.0);
    DEBUG.MESSAGEF("%024.8f\n", currentJulianDate());
    DEBUG.MESSAGEF("%024.8f\n", julianDate(1996, 10, 26, 14, 20, 0));
    DEBUG.MESSAGEF("%024.8f\n", julianSeconds(1996, 10, 26, 14, 20, 0));
    DEBUG.MESSAGEF("%024.8f\n", julianSeconds(2016, 7, 21, 21, 0, 0));
    DEBUG.MESSAGEF("%024.8f\n", unixSeconds(1996, 10, 26, 14, 20, 0));
    DEBUG.MESSAGEF("%024.8f\n", unixSeconds(2016, 7, 21, 21, 0, 0));
    DEBUG.MESSAGEF("%024.8f\n", norad2UnixSeconds(8, 255));
    DEBUG.MESSAGEF("%024.8f\n", norad2JulianSeconds(8, 255));
    DEBUG.MESSAGEF("%024.8f\n", currentSecondsJulian());
    DEBUG.MESSAGEF("%s\n", currentTimeString());
    DEBUG.MESSAGEF("DONE\n");
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static double norad2UnixSeconds(int yy, double day)         // Method
  {                                                                  // norad2EpochSeconds().
    if (yy < 50)
    {
      yy = 2000 + yy;
    }
    else
    {
      yy = 1900 + yy;
    }

    double tmp = unixSeconds(yy, 1, 1, 0, 0, 0);
    double js = tmp + (day - 1) * 86400;

    return (js);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static double norad2JulianSeconds(int yy, double day)       // Method
  {                                                                  // norad2JulianSeconds().
    double js;
    js = norad2UnixSeconds(yy, day) + JulianSeconds1970;
    return (js);
  }

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  public static void toSleep(int mills)                              // Method toSleep().
  {                                                                  //
    try
    {
      Thread.sleep(mills);
    }
    catch (InterruptedException e)
    {
      DEBUG.MESSAGEF("I CAN'T SLEEP!\n");
      e.printStackTrace();
    }
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