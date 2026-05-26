//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: xcc.h
//
// Desc: A top level header file for "C."
//
// Hist: When       Who  What
//       02/25/2015 ptb  Initial Code.
//       08/14/2025 ptb  Updated.
//------------------------------------------------------------------------------------------------
#ifndef XCC_H
#define XCC_H
 
#ifdef __cplusplus 
extern "C" { 
#endif

// Includes
//------------------------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------------------------
#define PI     3.141592653589793
#define TWOPI  6.283185307179586
#define DE2RA  0.017453292519943
#define RA2DE 57.2957795130823

// Type Defines
//------------------------------------------------------------------------------------------------
typedef void /*                 */ VOID;
typedef char /*                 */ CHAR08;
typedef unsigned char /*        */ BOOL08;
typedef unsigned char /*        */ BYTE08;
typedef float /*                */ RFLT32;
typedef double /*               */ RFLT64;
typedef long double /*          */ RFLT128;
typedef signed char /*          */ RINT08;
typedef signed short int /*     */ RINT16;
typedef signed long int /*      */ RINT32;
typedef signed long long int /* */ RINT64;
typedef unsigned char /*        */ RXNT08;
typedef unsigned short int /*   */ RXNT16;
typedef unsigned long int /*    */ RXNT32;
typedef unsigned long long int/**/ RXNT64;
typedef const char /*           */ CCHAR08;

typedef struct // COMPLEX INT08
{
RINT08 r;
RINT08 i;
} CINT08;

typedef struct // COMPLEX INT16
{
RINT16 r;
RINT16 i;
} CINT16;

typedef struct // COMPLEX INT32
{
RINT32 r;
RINT32 i;
} CINT32;

typedef struct // COMPLEX INT64
{
RINT64 r;
RINT64 i;
} CINT64;

typedef struct // COMPLEX RFLT32
{
RFLT32 r;
RFLT32 i;
} CFLT32;

typedef struct // COMPLEX RFLT64
{
RFLT64 r;
RFLT64 i;
} CFLT64;

typedef struct // COMPLEX RFLT128
{
RFLT128 r;
RFLT128 i;
} CFLT128;

typedef struct // VECTOR VFLT32
{
RFLT32 i;
RFLT32 j;
RFLT32 k;
} VFLT32;

typedef struct // VECTOR VFLT64
{
RFLT64 i;
RFLT64 j;
RFLT64 k;
} VFLT64;

// End preprocessor directive.
//------------------------------------------------------------------------------------------------
#ifdef __cplusplus 
} 
#endif 
 
#endif //XCC_H

//THE FOLLOWING IS NOT CLASSIFIED.
//       1         2         3         4         5         6         7         8         9
//345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
//                                              ][
//-----------------------------------------UNCLASSIFIED-------------------------------------------
//--------------------------------------UNCLASSIFIED//FOUO----------------------------------------
//-----------------------------------------CONFIDENTIAL-------------------------------------------
//--------------------------------------------SECRET----------------------------------------------