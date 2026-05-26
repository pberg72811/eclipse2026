package jcc;

//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: EarthToSun.java
//
// Desc: Time functions for java.
//
// Hist: When       Who  What
//       11/11/2015 ptb  Initial Code.
//------------------------------------------------------------------------------------------------

public class EarthToSun extends GEOCENTRIC
{

	public final static double EARTH_MASS = 1.98855e30;

	//---------------------------------------------------------------//---------------------------
	private EarthToSun()                                             //
	{                                                                //

	}

	//---------------------------------------------------------------//---------------------------
	public static Vector positionVector()                            // Method positionVector().
	{                                                                //
		GregCal cal = new GregCal();
		Vector v = positionVector(cal.yy, cal.mm + 1, cal.dd, cal.hh, cal.mn, cal.ss);
		return (v);
	}

	//---------------------------------------------------------------//---------------------------
	public static Vector positionVector(                             //
			int yy, int mm, int dd, int hh, int mn, double ss)       //
	{                                                                // Method positionVector().
		double TUT1, TTDB;
		double r, rx, ry, rz;
		double Term2, Term3;
		double eclipticLatitude;
		double meanAnomalyOfSun;
		double meanLongitudeOfSun;
		double obliquityOfEcliptic;
		double res[] = new double[3];

		TUT1 = (TIME.getJulianDate(yy, mm, dd, hh, mn, ss) - 2451545.0) / 36525;
		meanLongitudeOfSun = 280.460 + 36000.770 * TUT1;
		meanLongitudeOfSun = meanLongitudeOfSun % 360.0;
		if (meanLongitudeOfSun < 0)
		{
			meanLongitudeOfSun = meanLongitudeOfSun + 360.0;
		}

		TTDB = TUT1;

		meanAnomalyOfSun = 357.5277233 + 35999.050 * TTDB;
		meanAnomalyOfSun = meanAnomalyOfSun % 360.0;
		if (meanAnomalyOfSun < 0)
		{
			meanAnomalyOfSun = meanAnomalyOfSun + 360.0;
		}

		Term2 = 1.914666471 * Math.sin(meanAnomalyOfSun * DE2RA);
		Term3 = 0.019994643 * Math.sin(2 * meanAnomalyOfSun * DE2RA);
		eclipticLatitude = meanLongitudeOfSun + Term2 + Term3;

		Term2 = 0.016708617 * Math.cos(meanAnomalyOfSun * DE2RA);
		Term3 = 0.000139589 * Math.cos(2 * meanAnomalyOfSun * DE2RA);
		r = 1.000140612 - Term2 - Term3;

		obliquityOfEcliptic = 23.439291 - 0.0130042 * TTDB;
		obliquityOfEcliptic = obliquityOfEcliptic % 360.0;
		if (obliquityOfEcliptic < 0)
		{
			obliquityOfEcliptic = obliquityOfEcliptic + 360.0;
		}

		rx = r * Math.cos(eclipticLatitude * DE2RA);
		ry = r * Math.cos(obliquityOfEcliptic * DE2RA) * Math.sin(eclipticLatitude * DE2RA);
		rz = r * Math.sin(obliquityOfEcliptic * DE2RA) * Math.sin(eclipticLatitude * DE2RA);
		res[0] = rx;
		res[1] = ry;
		res[2] = rz;
		Vector v = new Vector(rx, ry, rz);
		return (v);
	}

	//---------------------------------------------------------------//---------------------------
	public static void main(String[] args)                           //
	{                                                                //
		Vector v = null;
		v = EarthToSun.positionVector(1994, 4, 2, 0, 0, 0.0);
		DEBUG.MESSAGE("Sun Pos 19940402:000000\n");
		DEBUG.MESSAGE("Sun Posx = %12.8f\n", v.x);
		DEBUG.MESSAGE("Sun Posy = %12.8f\n", v.y);
		DEBUG.MESSAGE("Sun Posz = %12.8f\n", v.z);

		v = EarthToSun.positionVector();
		DEBUG.MESSAGE("Sun Pos Now.\n");
		DEBUG.MESSAGE("Sun Posx = %12.8f\n", v.x);
		DEBUG.MESSAGE("Sun Posy = %12.8f\n", v.y);
		DEBUG.MESSAGE("Sun Posz = %12.8f\n", v.z);

		System.out.printf(DEBUG.MESSAGE("START\n"));
		System.out.println("HELLO");
		System.out.println(System.currentTimeMillis());
		System.out.printf(DEBUG.MESSAGE("DONE\n"));
		//new Sun().sayHello();  // invoke the native method
	}
}