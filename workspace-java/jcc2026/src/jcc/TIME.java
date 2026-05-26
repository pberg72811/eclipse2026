package jcc;

//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: TIME.java
//
// Desc: A Class containing debug methods.
//
// Hist: When       Who  What
//       03/09/2016 ptb  Initial Code.
//------------------------------------------------------------------------------------------------
import java.time.Instant;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.TimeZone;

//------------------------------------------------------------------------------------------------
public class TIME extends GEOCENTRIC
{
	final static double JulianSeconds1970 = 210866760000.0;
	final static double RevsPerSiderealDay = 1.00273790934;
	final static double SecondsPerSiderealDay = 86400.0;

	//---------------------------------------------------------------//---------------------------
	public static double current1970Seconds()                        // Return current time in
	{                                                                // 1970 seconds.
		Instant now = Instant.now();
		long posixMilliSeconds = now.toEpochMilli();
		double posixSeconds = ((double) posixMilliSeconds) / 1000.0;
		return (posixSeconds);
	}

	//---------------------------------------------------------------//---------------------------
	public static double currentJulianDate()                         // Return formated current
	{                                                                // time string.
		GregCal cal = new GregCal();

		double JD = getJulianDate(cal.yy, cal.mm + 1, cal.dd, cal.hh, cal.mn, cal.ss);

		return (JD);
	}

	//---------------------------------------------------------------//---------------------------
	public static double currentPhiGrn()                             // Return Earth's rotational
	{                                                                // angle.
		double current1970 = current1970Seconds();
		double jseconds = current1970 + 210866760000.0;
		double phiGrn = getPhiGrn(jseconds);
		return (phiGrn);
	}

	//---------------------------------------------------------------//---------------------------
	public static String currentTimeString()                         // Return formated current
	{                                                                // time string.
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

	//---------------------------------------------------------------//---------------------------
	public static double get1970Seconds(                             // Return 1970 Seconds,
			int yy, int mm, int dd, int hh, int mn, double dss)      // given, year, month, day
	{                                                                // hour, minute, seconds.
		double epoch;
		int ss = (int) dss;
		GregCal cal = new GregCal();
		cal.clear();
		cal.set(yy, mm - 1, dd, hh, mn, ss);
		epoch = ((double) cal.getTimeInMillis()) / 1000.0;
		return (epoch);
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

	//---------------------------------------------------------------//---------------------------
	public static double getJulianDate(                              // Return Julian Date
			int yy, int mm, int dd, int hh, int mn, double ss)       // given, year, month, day
	{                                                                // hour, minute, seconds.
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

	//---------------------------------------------------------------//---------------------------
	public static String getTimeString(                              // Ret. formated time string
			int yy, int mm, int dd, int hh, int mn, double dss)      // given, year, month, day
	{                                                                // hour, minute, seconds.
		String YY = String.format("%04d", yy);
		String MM = String.format("%02d", mm);
		String DD = String.format("%02d", dd);
		String HH = String.format("%02d", hh);
		String MN = String.format("%02d", mn);
		String SS = String.format("%06.3f", dss);
		String str = YY + ":" + MM + ":" + DD + "::" + HH + ":" + MN + ":" + SS;

		return (str);
	}

	// --------------------------------------------------------------//---------------------------
	public static void main(String[] args)                           // Main method for quick
	{                                                                // test.
		System.out.printf("Hello, TIME!\n");
		System.out.printf("The UNIVERSAL Gravitation Constant is %g\n", G);
		System.out.printf("Current 1970 Seconds   is: %f\n", current1970Seconds());
		System.out.printf("Get 1970 Seconds       is: %f\n", get1970Seconds(2002, 5, 3, 0, 0, 0.0));
		System.out.printf("Current Date           is: %s\n", currentTimeString());
		System.out.printf("Random  Date           is: %s\n", getTimeString(2002, 5, 3, 0, 0, 0.0));
		System.out.printf("Random Julian  Date    is: %f\n", getJulianDate(2002, 5, 3, 0, 0, 0.0));
		System.out.printf("Current Julian Date    is: %f\n", currentJulianDate());
		System.out.printf("Current Rotation Angle is: %f\n", currentPhiGrn());
	}

}

//------------------------------------------------------------------------------------------------
class GregCal extends GregorianCalendar
{
	static final long serialVersionUID = 42L;

	public int yy;

	public int mm;

	public int dd;

	public int hh;

	public int mn;

	public double ss;

	//----------------------------------------------------------------//---------------------------
	public GregCal()                                                  //
	{                                                                 //
		super();
		this.setTimeZone(TimeZone.getTimeZone("GMT"));
		yy = this.get(Calendar.YEAR);
		mm = this.get(Calendar.MONTH);
		dd = this.get(Calendar.DATE);
		hh = this.get(Calendar.HOUR_OF_DAY);
		mn = this.get(Calendar.MINUTE);
		ss = this.getSeconds();
	}

	// ---------------------------------------------------------------//---------------------------
	public double getTimeInSeconds()                                 // getTimeInSeconds.
	{                                                                 //
		double sec = this.getTimeInMillis() / 1000.0;                  // Milliseconds/1000.0
		return (sec);                                                  // and return.
	}

	// ---------------------------------------------------------------//---------------------------
	public double getWholeSeconds()                                   // Method getWholeSeconds().
	{                                                                 //
		double ss = this.get(Calendar.SECOND);                         // Just cast seconds to
		return (ss);                                                   // double and return.
	}

	// ---------------------------------------------------------------//---------------------------
	public double getFractionalSeconds()                              // Method
	{                                                                 // getFractionalSeconds().
		double ss = this.getTimeInSeconds();                           //
		double ws = Math.floor(ss);                                    // Isolated the fractional
		double fs = ss - ws;                                           // part of the seconds
		return (fs);                                                   // and return.
	}

	// ---------------------------------------------------------------//---------------------------
	public double getSeconds()                                        // Method getSeconds().
	{                                                                 //
		double ss;                                                     //
		ss = this.getWholeSeconds() + this.getFractionalSeconds();     // Return whole seconds plus
		return (ss);                                                   // fractional seconds.
	}

	// ---------------------------------------------------------------//---------------------------
	public static void main(String[] args)
	{
		DEBUG.MESSAGE("DONE\n");
	}

}