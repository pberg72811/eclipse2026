/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccFFT1.c
// Desc: This file contains the code for the DSPUtils routine iccFFT1.
// Hist: When       Who  What
//       07/27/2001 ptb  Initial Code.
//       03/27/2003 ptb  Cleaned up Code.
//       04/06/2004 ptb  FFT1, FFT2, FFT3.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "dsp_utils.h" 
 
/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: iccFFTBitReverse
// Desc: This routine performs bit reversing for FFT addressing.
// Hist: x needs to be UNT32 not UNT16. ptb 10/22/2004.
//------------------------------------------------------------------------------
UNT32 iccFFTBitReverse(INT32 iidex,    //Index to reverse
		       INT32 nBits)    //Number of bits to base reversal on.
{
  UNT16 n;
  UNT32 x;
  UNT32 table[31]=
  {
    0x00000002,0x00000004,0x00000008,0x000000010,
    0x00000020,0x00000040,0x00000080,0x000000100,
    0x00000200,0x00000400,0x00000800,0x000001000,
    0x00002000,0x00004000,0x00008000,0x000010000,
    0x00020000,0x00040000,0x00080000,0x000100000,
    0x00200000,0x00400000,0x00800000,0x001000000,
    0x02000000,0x04000000,0x08000000,0x010000000,
    0x20000000,0x40000000,0x80000000
  };
  if(nBits<0)   XMC_ERROR_STDOUT("Negative bit number.");
  if(nBits>=32) XMC_ERROR_STDOUT("Bit number to big.");
  x = 0;
  for( n = 0; n < nBits; n++)
  {
    //printf("%d", iidex%table[n]>>n);
    x = x|(((iidex%table[n])>>n)<<(nBits-n-1)); //Impressive isn't it.
  }
  return(x);
}

//------------------------------------------------------------------------------
// Rout: icc2ptButterflyFLT32_R
// Desc: This routine performs a 2 point FFT butterfly calculation for real data.
//------------------------------------------------------------------------------
VOID icc2ptButterflyFLT32_R(FLT32 *iData0,  //Real input.
			    FLT32 *iData1,  //Real input.
			    FLT32 *oData)   //Complex output.
{
  oData[0] = iData0[0]+iData1[0];
  oData[1] = 0;
  oData[2] = iData0[0]-iData1[0];
  oData[3] = 0;
}

//------------------------------------------------------------------------------
// Rout: icc2ptButterflyFLT32_C
// Desc: This routine performs a 2 point FFT butterfly calculation for complex data.
//------------------------------------------------------------------------------
VOID icc2ptButterflyFLT32_C(FLT32 *iData0, //Complex input.
			    FLT32 *iData1, //Complex input.
			    FLT32 *oData)  //Complex output.
{
  oData[0] = iData0[0]+iData1[0];
  oData[1] = iData0[1]+iData1[1];
  oData[2] = iData0[0]-iData1[0];
  oData[3] = iData0[1]-iData1[1];
}

//------------------------------------------------------------------------------
// Rout: iccNptButterflyFLT32
// Desc: This routine performs a N point FFT butterfly calculation.
//------------------------------------------------------------------------------
VOID iccNptButterflyFLT32(FLT32 *iData,   // Complex input.
			  INT32 N,        // Number of points.
			  INT08 ifftFlag) // IFFT flag.
{
  INT32 ii;
  FLT32 W=TWOPI/N;
  FLT32 wr,xr,yr,tr;
  FLT32 wi,xi,yi,ti;
  if(ifftFlag==TRUE) W = -W;

  for(ii = 0; ii < N; ii+=2)
  {
    wr =  cos(W*((FLT32)ii)*0.5); // Change "/2.0" to "*0.5".
    wi = -sin(W*((FLT32)ii)*0.5); // Change "/2.0" to "*0.5".
    xr = iData[ii];
    xi = iData[ii+1];
    yr = iData[N+ii];
    yi = iData[N+ii+1];
    tr = yr*wr - yi*wi;
    ti = yr*wi + yi*wr;

    iData[ii  ] = xr+tr;
    iData[ii+1] = xi+ti;

    iData[N+ii  ] = xr-tr;
    iData[N+ii+1] = xi-ti;
  }
}                                                                                                                                                           
/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*-------------------------------UNCLASSIFIED---------------------------------*/


