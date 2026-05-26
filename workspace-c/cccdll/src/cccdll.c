/*
//-----------------------------------------UNCLASSIFIED-------------------------------------------
 Name        : ccc.c
 Author      : pbergman@epsilonsystems.com
 Version     :
 Copyright   : The Good Lord is Watching. Do the Right Thing.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <cccdll.h>
#include <stdio.h>
#include <stdlib.h>

__declspec(dllexport) int
cccdll (void)
{
  puts ("!!!Hello World!!!"); /* prints !!!Hello World!!! */
  printf ("The RFLT32 is size %llu \n", sizeof(RFLT64));
  //return EXIT_SUCCESS;
  return 5;
}

//%------------------------------------------UNCLASSIFIED-------------------------------------------
//% Name: julianDate.m
//%
//% Dscr: Calculates the Julian date.
//%
//% Ins : YYYY - Four digit year.
//%       MM   - Two digit month.
//%       DD   - Two digit day.
//%       HH   - Two digit hour.
//%       MN   - Two digit minute.
//%       SS   - Two digit second.
//%
//% Outs: result - Julian date.
//%
//% Hist: Who   When         What
//%       ptb   11/22/2017   Ported from java code.
//%------------------------------------------UNCLASSIFIED-------------------------------------------
//function result = julianDate(YYYY, MM, DD, HH, MN, SS)
//
//    term01 = 367.0 * YYYY;
//    mm9    = floor((MM + 9.0) / 12.0);
//    term02 = floor(7 * (YYYY + mm9) / 4.0);
//    term03 = floor(275.0 * MM / 9.0);
//    term04 = DD;
//    term05 = 1721013.5;
//    term06 = ((((SS / 60.0) + MN) / 60.0) + HH) / 24;
//    result = (term01 - term02 + term03 + term04 + term05 + term06);
//end


// THE FOLLOWING IS FOR A CODING TEMPLATE ONLY.
// THE FOLLOWING IS NOT CLASSIFIED.
//       1         2         3         4        |5         6         7         8         9
//345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
//-----------------------------------------UNCLASSIFIED-------------------------------------------
//--------------------------------------UNCLASSIFIED//CUI-----------------------------------------
//-----------------------------------------CONFIDENTIAL-------------------------------------------
//--------------------------------------------SECRET----------------------------------------------
//--------------------------------------------ERROR-----------------------------------------------
//-------------------------------------------WARNING----------------------------------------------
//-------------------------------------------MESSAGE----------------------------------------------
/**
 * The UNIVERSE class to hold all UNIVERSAL things.<br>
 *
 * When Who What <br>
 * 03/11/2026 ptb Initial Code.
 */
