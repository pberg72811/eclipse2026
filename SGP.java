package org.ieee.jcc.astro;

import java.util.ArrayList;
import java.util.List;

import org.ieee.jcc.util.DEBUG;
import org.ieee.jcc.util.Time;
import org.ieee.jcc.util.Filex;
import org.ieee.jcc.util.URLx;
import org.ieee.jcc.util.Vector;
import org.ieee.jcc.util.Mathx;

//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: SGP.java
//
// Desc: Simplified General Perturbations (SGP) to calculate orbital state vectors.
//
// Hist: When       Who  What
//       04/28/2016 ptb  Initial Code.
//
// http://www.satview.org/?sat_id=20580U
// curl http://celestrak.com/NORAD/elements/tle-new.txt > /tmp/SGP/satlist
//------------------------------------------------------------------------------------------------
public class SGP implements java.io.Serializable
{
  /**
   * 
   */
  private static final long serialVersionUID = 1L;

  final static double       DE2RA            = Mathx.DE2RA;
  final static double       RA2DE            = Mathx.RA2DE;
  final static double       TWOPI            = Mathx.TWOPI;

  final static double       E6A              = 1.0E-6;
  final static double       PIO2             = 1.570796326794897;
  final static double       QO               = 120.0;
  final static double       SO               = 78.0;
  final static double       TWOTHRD          = 2.0 / 3.0;
  final static double       X3PIO2           = 4.712388980384690;
  final static double       XJ2              = 1.082616E-3;
  final static double       XJ3              = -0.253881E-5;
  final static double       XJ4              = -1.65597E-6;
  final static double       XKE              = 0.743669161E-1;
  final static double       XKMPER           = 6378.135;
  final static double       XMNPDA           = 1440.0;
  final static double       AE               = 1.0;

  final static double       CK2              = 5.413080e-4;
  final static double       CK4              = 0.62098875e-6;
  final static double       QOMS2T           = 1.88027916e-9;
  final static double       S                = 1.01222928;

  final static double       KEP              = 3.986008e5;
  final static double       J2               = 0.0010826;

  int                       iFlag;
  char                      classi;
  String                    name;
  int                       number;
  double                    XMO;
  double                    XNODEO;
  double                    OMEGAO;
  double                    EO;
  double                    XINCL;
  double                    XNO;
  double                    XNDT2O;
  double                    XNDD6O;
  double                    BSTAR;
  double                    EPOCH;
  double                    TIME;
  public Vector             p;
  public Vector             v;
  public Vector             a;
  public double             m;

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public SGP(String[] tleLines)                                      //
  {                                                                  //
    if ((tleLines.length != 2) && (tleLines.length != 3))
    {
      String excepMsg = "";
      excepMsg += "Two Line Elements needs Two or Three Lines. (SAY WHAT!?)\n\n";
      excepMsg += "For the three line case:\n";
      excepMsg += "The first line is satellite name and was not originally\n";
      excepMsg += "part of the Two Line Element (TLE) set.\n";
      throw new RuntimeException(excepMsg);
    }
    //           1         2         3         4         5
    // 0123456789012345678901234567890123456789012345678901234567890123456789
    // ISS (ZARYA)             
    // 1 25544U 98067A   16119.85984381  .00004381  00000-0  72767-4 0  9993
    // 2 25544  51.6444 304.0877 0001973  78.1121  60.1077 15.54362508997303
    // TIANGONG 1              
    // 1 37820U 11053A   16119.59866188  .00015755  00000-0  18184-3 0  9997
    // 2 37820  42.7629 183.6620 0012005  56.7410  93.0239 15.61589364262823
    //           1         2         3         4         5
    // 0123456789012345678901234567890123456789012345678901234567890123456789
    // TEST 01
    // 1 88888U     1A   80275.98708465  .00073094  13844-3  66816-4 0     8
    // 2 88888  72.8435 115.9689 0086731  52.6988 110.5714 16.05824518   105
    int yy;
    double dd;
    double TEMP;
    String tempStr;
    String tle00Str;
    String tle01Str;
    String tle02Str;

    if (tleLines.length == 2)
    {
      tle00Str = tleLines[0].trim().substring(2, 7);
      tle01Str = tleLines[0].trim();
      tle02Str = tleLines[1].trim();
    }
    else
    {
      tle00Str = tleLines[0].trim();
      tle01Str = tleLines[1].trim();
      tle02Str = tleLines[2].trim();
    }

    name = tle00Str;
    tempStr = tle01Str.substring(2, 7);
    number = ivo(tempStr);
    classi = tle01Str.charAt(7);
    yy = ivo(tle01Str.substring(18, 20));
    dd = dvo(tle01Str.substring(20, 32));
    EPOCH = Time.norad2JulianSeconds(yy, dd);
    TIME = EPOCH;
    tempStr = tle01Str.substring(33, 43);
    XNDT2O = dvo(tempStr);
    tempStr = tle01Str.substring(44, 52);
    tempStr = handleImpliedDecimal(tempStr);
    XNDD6O = dvo(tempStr);
    tempStr = tle01Str.substring(53, 61);
    tempStr = handleImpliedDecimal(tempStr);
    BSTAR = dvo(tempStr);

    XINCL = dvo(tle02Str.substring(8, 16));
    XNODEO = dvo(tle02Str.substring(17, 25));
    EO = dvo("0." + tle02Str.substring(26, 33));
    OMEGAO = dvo(tle02Str.substring(34, 42));
    XMO = dvo(tle02Str.substring(43, 51));
    XNO = dvo(tle02Str.substring(52, 64));

    XNODEO = XNODEO * DE2RA;                                         // Degree to radian.
    OMEGAO = OMEGAO * DE2RA;                                         // Degree to radian.
    XMO = XMO * DE2RA;                                               // Degree to radian.
    XINCL = XINCL * DE2RA;                                           // Degree to radian.
    TEMP = TWOPI / XMNPDA / XMNPDA;                                  // Condition the
    XNO = XNO * TEMP * XMNPDA;                                       // Mean Anomaly.
    XNDT2O = XNDT2O * TEMP;                                          // First Time Derivative.
    XNDD6O = XNDD6O * TEMP / XMNPDA;                                 // Second Time Derivative.

    p = new Vector();
    v = new Vector();
    a = new Vector();

    updateDelta(0);
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public static String handleImpliedDecimal(String str)              //
  {                                                                  //
    String retstr = null;
    if (str.substring(0, 1) == "-")
    {
      retstr = "-0." + str.substring(1).replace("-", "e-").replace("+", "e+");
    }
    else
    {
      retstr = "0." + str.substring(1).replace("-", "e-").replace("+", "e+");
    }
    return (retstr);
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public static double dvo(String strValue)                          // Method dvo().
  {                                                                  // Double Value Of (DVO).
    double res = 0.0;
    try
    {
      res = Double.valueOf(strValue);                                // <-- dvo.
    }
    catch (NumberFormatException e)
    {
      DEBUG.ERRORF("Number Format Exception\n");
      e.printStackTrace();
      System.exit(1);
    }
    return (res);
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public static int ivo(String strValue)                             // Method ivo().
  {                                                                  // Integer Value Of (IVO).
    int res = 0;
    try
    {
      res = Integer.valueOf(strValue);                                // <-- ivo.
    }
    catch (NumberFormatException e)
    {
      DEBUG.ERRORF("Number Format Exception\n");
      e.printStackTrace();
      System.exit(1);
    }
    return (res);
  }
  
  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public void current()                                              // Method current().
  {                                                                  //
    double deltaSeconds = Time.currentSecondsJulian() - EPOCH;
    updateDelta(deltaSeconds);
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public void update(double newTimeSeconds)                          // Method update().
  {                                                                  //
    double deltaSeconds = (newTimeSeconds - EPOCH);
    updateDelta(deltaSeconds);
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public void updateDelta(double deltaSeconds)                       // Method updateDelta().
  {                                                                  //
    double TSINCE = deltaSeconds / 60.0;                             // Calculation uses minutes.
    double C1 = CK2 * 1.5;
    double C2 = CK2 / 4.0;
    double C3 = CK2 / 2.0;
    double C4 = XJ3 * Math.pow(AE, 3) / (4.0 * CK2);
    double COSIO = Math.cos(XINCL);
    double SINIO = Math.sin(XINCL);
    double A1 = Math.pow((XKE / XNO), TWOTHRD);
    double powTerm = Math.pow((1.0 - (EO * EO)), 1.5);
    double D1 = C1 / A1 / A1 * (3.0 * COSIO * COSIO - 1.0) / powTerm;
    double AO = A1 * (1.0 - (1.0 / 3.0 * D1) - D1 * D1 - (134.0 / 81.0 * D1 * D1 * D1));
    double PO = AO * (1.0 - (EO * EO));
    double QpO = AO * (1.0 - EO);
    double XLO = XMO + OMEGAO + XNODEO;
    double D1O = C3 * SINIO * SINIO;
    double D2O = C2 * (7. * COSIO * COSIO - 1.);
    double D3O = C1 * COSIO;
    double D4O = D3O * SINIO;
    double PO2NO = XNO / (PO * PO);
    double OMGDT = C1 * PO2NO * (5. * COSIO * COSIO - 1.);
    double XNODOT = -2. * D3O * PO2NO;
    double C5 = .5 * C4 * SINIO * (3. + 5. * COSIO) / (1. + COSIO);
    double C6 = C4 * SINIO;

    // UPDATE FOR SECULAR GRAVITY AND ATMOSPHERIC DRAG
    //--------------------------------------------------------------------------------------------
    double A = XNO + (2.0 * XNDT2O + 3.0 * XNDD6O * TSINCE) * TSINCE;
    A = AO * Math.pow((XNO / A), TWOTHRD);
    double E = E6A;

    if (A > QpO)
    {
      E = 1.0 - QpO / A;
    }

    double P = A * (1. - E * E);
    double XNODES = XNODEO + XNODOT * TSINCE;
    double OMGAS = OMEGAO + OMGDT * TSINCE;
    double term01 = XNO + OMGDT + XNODOT;
    double term02 = XNDT2O + XNDD6O * TSINCE;
    double rslt01 = term01 + term02 * TSINCE;
    double XLS = (XLO + rslt01 * TSINCE) % TWOPI;

    // LONG PERIOD PERIODICS
    //--------------------------------------------------------------------------------------------
    double AXNSL = E * Math.cos(OMGAS);
    double AYNSL = E * Math.sin(OMGAS) - C6 / P;
    double XL = (XLS - C5 / P * AXNSL) % TWOPI;

    // SOLVE KEPLERS EQUATION
    //--------------------------------------------------------------------------------------------
    double U = (XL - XNODES) % TWOPI;
    double EO1 = U;
    double TEM2 = 0.0;
    double TEM5 = 1.0;
    double ITEM3 = 0.0;
    double SINEO1 = 0.0;
    double COSEO1 = 0.0;

    while ((Math.abs(TEM5) >= E6A) || (ITEM3 < 10.0))
    {
      SINEO1 = Math.sin(EO1);
      COSEO1 = Math.cos(EO1);
      ITEM3 = ITEM3 + 1.0;
      TEM5 = 1.0 - COSEO1 * AXNSL - SINEO1 * AYNSL;
      TEM5 = (U - AYNSL * COSEO1 + AXNSL * SINEO1 - EO1) / TEM5;
      TEM2 = Math.abs(TEM5);
      if (TEM2 > 1.0)
      {
        TEM5 = TEM2 / TEM5;
      }
      EO1 = EO1 + TEM5;
    }

    // SHORT PERIOD PRELIMINARY QUANTITIES
    //--------------------------------------------------------------------------------------------
    double ECOSE = AXNSL * COSEO1 + AYNSL * SINEO1;
    double ESINE = AXNSL * SINEO1 - AYNSL * COSEO1;
    double EL2 = AXNSL * AXNSL + AYNSL * AYNSL;
    double PL = A * (1.0 - EL2);
    double PL2 = PL * PL;
    double R = A * (1.0 - ECOSE);
    double RDOT = XKE * Math.sqrt(A) / R * ESINE;
    double RVDOT = XKE * Math.sqrt(PL) / R;
    double TEMP = ESINE / (1.0 + Math.sqrt(1.0 - EL2));
    double SINU = A / R * (SINEO1 - AYNSL - AXNSL * TEMP);
    double COSU = A / R * (COSEO1 - AXNSL + AYNSL * TEMP);
    double SU = Math.atan2(SINU, COSU);

    // UPDATE FOR SHORT PERIODICS
    //--------------------------------------------------------------------------------------------
    double SIN2U = (COSU + COSU) * SINU;
    double COS2U = 1.0 - 2.0 * SINU * SINU;
    double RK = R + D1O / PL * COS2U;
    double UK = SU - D2O / PL2 * SIN2U;
    double XNODEK = XNODES + D3O * SIN2U / PL2;
    double XINCK = XINCL + D4O / PL2 * COS2U;

    // ORIENTATION VECTORS
    //--------------------------------------------------------------------------------------------
    double SINUK = Math.sin(UK);
    double COSUK = Math.cos(UK);
    double SINNOK = Math.sin(XNODEK);
    double COSNOK = Math.cos(XNODEK);
    double SINIK = Math.sin(XINCK);
    double COSIK = Math.cos(XINCK);
    double XMX = -SINNOK * COSIK;
    double XMY = COSNOK * COSIK;
    double UX = XMX * SINUK + COSNOK * COSUK;
    double UY = XMY * SINUK + SINNOK * COSUK;
    double UZ = SINIK * SINUK;
    double VX = XMX * COSUK - COSNOK * SINUK;
    double VY = XMY * COSUK - SINNOK * SINUK;
    double VZ = SINIK * COSUK;

    // POSITION AND VELOCITY
    //--------------------------------------------------------------------------------------------
    p.x = RK * UX;
    p.y = RK * UY;
    p.z = RK * UZ;

    v.x = RDOT * UX;
    v.y = RDOT * UY;
    v.z = RDOT * UZ;

    v.x = RVDOT * VX + v.x;
    v.y = RVDOT * VY + v.y;
    v.z = RVDOT * VZ + v.z;

    p.x = p.x * XKMPER / AE;
    p.y = p.y * XKMPER / AE;
    p.z = p.z * XKMPER / AE;
    v.x = v.x * XKMPER / AE * XMNPDA / 86400.0;
    v.y = v.y * XKMPER / AE * XMNPDA / 86400.0;
    v.z = v.z * XKMPER / AE * XMNPDA / 86400.0;

    TIME = deltaSeconds + EPOCH;

  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public double lat()                                                //
  {                                                                  //
    return (p.lat());
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public double lon()                                                //
  {                                                                  //
    double res = p.lon() - Time.getPhiGrn(TIME);
    if (res < 0)
    {
      res += TWOPI;
    }
    return (res);
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public double alt()                                                //
  {                                                                  //
    double res = p.mag() - XKMPER;
    return (res);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static List<SGP> fileSatList()                              // Method fileSatList().
  {                                                                  //
    // curl http://celestrak.com/NORAD/elements/tdrss.txt   > /tmp/SGP/satlist
    // curl http://celestrak.com/NORAD/elements/beidou.txt >> /tmp/SGP/satlist
    List<SGP> sgpList = fileSatList("/tmp/SGP/satlist");
    return (sgpList);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static List<SGP> fileSatList(String filePath)               // Method fileSatList().
  {                                                                  //
    List<SGP> sgpList = new ArrayList<SGP>();
    String[] tlePage = Filex.read(filePath).split("\n");
    sgpList = satList(tlePage);
    return (sgpList);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static List<SGP> webSatList(String tleURLStr)               // Method webSatList().
  {                                                                  //
    List<SGP> sgpList = new ArrayList<SGP>();
    String[] tlePage = URLx.read(tleURLStr).split("\n");
    sgpList = satList(tlePage);
    return (sgpList);
  }

  //-----------------------------------------------------------------//-------UNCLASSIFIED--------
  public static List<SGP> satList(String[] tlePage)                  // Method satList().
  {                                                                  // Generate sat list.
    int ii = 0;
    int jj = 0;
    //int kk = 0;
    String[] tleLines;

    List<SGP> sgpList = new ArrayList<SGP>();
    
    if (tlePage[0].length() < 69)                                    // Check if 3 line TLE
    {                                                                // or 2 line TLE.
      tleLines = new String[3];                                      //
    }                                                                // !!! Need to develop
    else                                                             // !!! the reset of this.
    {                                                                //
      tleLines = new String[2];                                      //
    }                                                                //---------------------------

    for (jj = 0; jj < tlePage.length; jj++)
    {
      if (ii == 0)
      {
        tleLines[0] = tlePage[jj];
        ii++;
      }
      else if (ii == 1)
      {
        tleLines[1] = tlePage[jj];
        ii++;
      }
      else if (ii == 2)
      {
        tleLines[2] = tlePage[jj];
        //DEBUG.MESSAGEF("INDEX is %d %d.\n", jj, kk);
        sgpList.add(new SGP(tleLines));
        ii = 0;
        //kk++;
        tleLines[0] = "";
        tleLines[1] = "";
        tleLines[2] = "";
      }
      else
      {
        DEBUG.MESSAGEF("INTERESTING\n");
      }
    }

    return (sgpList);
  }

  //---------------------------------------UNCLASSIFIED-------------------------------------------
  // main
  //----------------------------------------------------------------------------------------------
  public static void main(String[] args)
  {
    SGP testSat = null;
    String[] tleLines = new String[2];
    String[] tleLinex = new String[3];
    tleLines[0] = "1 88888U     1A   80275.98708465  .00073094  13844-3  66816-4 0     8";
    tleLines[1] = "2 88888  72.8435 115.9689 0086731  52.6988 110.5714 16.05824518   105";
    tleLinex[0] = "TEST 01";
    tleLinex[1] = "1 88888U     1A   80275.98708465  .00073094  13844-3  66816-4 0     8";
    tleLinex[2] = "2 88888  72.8435 115.9689 0086731  52.6988 110.5714 16.05824518   105";

    testSat = new SGP(tleLines);
    testSat.updateDelta(0);
    DEBUG.MESSAGEF("testSat.px is %+016.8f.\n", testSat.p.x);
    DEBUG.MESSAGEF("testSat.py is %+016.8f.\n", testSat.p.y);
    DEBUG.MESSAGEF("testSat.pz is %+016.8f.\n", testSat.p.z);
    DEBUG.MESSAGEF("testSat.vx is %+016.8f.\n", testSat.v.x);
    DEBUG.MESSAGEF("testSat.vy is %+016.8f.\n", testSat.v.y);
    DEBUG.MESSAGEF("testSat.vz is %+016.8f.\n", testSat.v.z);
    testSat = new SGP(tleLinex);
    testSat.updateDelta(360 * 60);
    DEBUG.MESSAGEF("testSat.px is %+016.8f.\n", testSat.p.x);
    DEBUG.MESSAGEF("testSat.py is %+016.8f.\n", testSat.p.y);
    DEBUG.MESSAGEF("testSat.pz is %+016.8f.\n", testSat.p.z);
    DEBUG.MESSAGEF("testSat.vx is %+016.8f.\n", testSat.v.x);
    DEBUG.MESSAGEF("testSat.vy is %+016.8f.\n", testSat.v.y);
    DEBUG.MESSAGEF("testSat.vz is %+016.8f.\n", testSat.v.z);
    testSat.updateDelta(1440 * 60);
    DEBUG.MESSAGEF("testSat.px is %+016.8f.\n", testSat.p.x);
    DEBUG.MESSAGEF("testSat.py is %+016.8f.\n", testSat.p.y);
    DEBUG.MESSAGEF("testSat.pz is %+016.8f.\n", testSat.p.z);
    DEBUG.MESSAGEF("testSat.vx is %+016.8f.\n", testSat.v.x);
    DEBUG.MESSAGEF("testSat.vy is %+016.8f.\n", testSat.v.y);
    DEBUG.MESSAGEF("testSat.vz is %+016.8f.\n", testSat.v.z);

    List<SGP> sgpList = SGP.webSatList("http://celestrak.com/NORAD/elements/stations.txt");
    SGP sat = sgpList.get(3);
    sat.current();
    DEBUG.MESSAGEF("sat px is %s.\n", sat.name);
    DEBUG.MESSAGEF("sat px is %f.\n", sat.p.x);
    DEBUG.MESSAGEF("sat py is %f.\n", sat.p.y);
    DEBUG.MESSAGEF("sat pz is %f.\n", sat.p.z);
    DEBUG.MESSAGEF("sat p.mag is %f.\n", sat.p.mag());
    DEBUG.MESSAGEF("sat alt is %f.\n", sat.p.mag() - XKMPER);
    sat = sgpList.get(0);
    sat.current();
    DEBUG.MESSAGEF("sat px is %s.\n", sat.name);
    DEBUG.MESSAGEF("sat px is %f.\n", sat.p.x);
    DEBUG.MESSAGEF("sat py is %f.\n", sat.p.y);
    DEBUG.MESSAGEF("sat pz is %f.\n", sat.p.z);
    DEBUG.MESSAGEF("sat lat is %+09.4f.\n", sat.lat());
    DEBUG.MESSAGEF("sat lon is %+09.4f.\n", sat.lon());
    DEBUG.MESSAGEF("sat lat is %+09.4f.\n", sat.lat() * RA2DE);
    DEBUG.MESSAGEF("sat lon is %+09.4f.\n", sat.lon() * RA2DE);
    DEBUG.MESSAGEF("sat lon is %+09.4f.\n", sat.lon() * RA2DE - 360);
    DEBUG.MESSAGEF("sat alt is %+09.4f.\n", sat.alt());

    //sgpList = SGP.fileSatList();
    sgpList = SGP.webSatList("http://celestrak.com/NORAD/elements/visual.txt");
    sat = sgpList.get(1);
    sat.current();
    DEBUG.MESSAGEF("sat px is %s.\n", sat.name);
    DEBUG.MESSAGEF("sat px is %f.\n", sat.p.x);
    DEBUG.MESSAGEF("sat py is %f.\n", sat.p.y);
    DEBUG.MESSAGEF("sat pz is %f.\n", sat.p.z);
    DEBUG.MESSAGEF("sat lat is %+09.4f.\n", sat.lat());
    DEBUG.MESSAGEF("sat lon is %+09.4f.\n", sat.lon());
    DEBUG.MESSAGEF("sat lat is %+09.4f.\n", sat.lat() * RA2DE);
    DEBUG.MESSAGEF("sat lon is %+09.4f.\n", sat.lon() * RA2DE);
    DEBUG.MESSAGEF("sat lon is %+09.4f.\n", sat.lon() * RA2DE - 360);
    DEBUG.MESSAGEF("sat alt is %+09.4f.\n", sat.alt());

    DEBUG.MESSAGEF("Done\n");

  }

}