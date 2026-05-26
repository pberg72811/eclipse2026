//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: xcc_EARTH.h
//
// Desc: Header file for Earth stuff.
//
// Hist: When       Who  What
//       11/10/2025 ptb  Initial Code.
//------------------------------------------------------------------------------------------------
#ifndef XCC_EARTH_H
#define XCC_EARTH_H
 
#ifdef __cplusplus 
extern "C" { 
#endif

// Includes
//------------------------------------------------------------------------------------------------
#include "xcc.h"

// Defines
//------------------------------------------------------------------------------------------------
// Type Defines
//------------------------------------------------------------------------------------------------
RFLT64 XCC_EARTH_TU                    = 13.44685206374;            // TU for Earth.
RFLT64 XCC_EARTH_FLATTENING            =  1.0/298.257;              // Vallado pg. 138
RFLT64 XCC_EARTH_TILT                  =       23.5;                // Degrees relative to orbital plane.
RFLT64 XCC_EARTH_RADIUS                =  6378136.3;                // Almanac Supplement p 151.
RFLT64 XCC_EARTH_ACCELERATIONG         =        9.8;                // Meters/sec^2
RFLT64 XCC_EARTH_SECONDSPERDAY         =    86400.0;                // Seconds
RFLT64 XCC_EARTH_CIRCUMFERENCE         = 40075016.7;                // Meters 2*pi*RADIUS
RFLT64 XCC_EARTH_MASS                  = 5.97219e24;                // Kg
    
RFLT64 XCC_EARTH_SEMIMAJORAXIS         = 6378137;                   // From MATLAB WGS84 page.
RFLT64 XCC_EARTH_SEMIMINORAXIS         = 6356752.31424518;          // SEMIMINORAXIS is a derived quantity.
RFLT64 XCC_EARTH_INVERSEFLATTENING     = 298.257223563;             // 
RFLT64 XCC_EARTH_ECCENTRICITY          = 0.0818191908426215;        // 

RFLT64 XCC_EARTH_JULIANSECONDS1970     = 210866760000;
RFLT64 XCC_EARTH_JULIANSECONDS1950     = 210235608000;
RFLT64 XCC_EARTH_SecondsPerSiderealDay = 86164.1;
RFLT64 XCC_EARTH_SecondsPerSolarDay    = 86400.0;

// End preprocessor directive.
//------------------------------------------------------------------------------------------------
#ifdef __cplusplus 
} 
#endif 
 
#endif // XCC_EARTH_H

//THE FOLLOWING IS NOT CLASSIFIED.
//       1         2         3         4         5         6         7         8         9
//345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
//                                              ][
//-----------------------------------------UNCLASSIFIED-------------------------------------------
//--------------------------------------UNCLASSIFIED//FOUO----------------------------------------
//-----------------------------------------CONFIDENTIAL-------------------------------------------
//--------------------------------------------SECRET----------------------------------------------