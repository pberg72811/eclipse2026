/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccFFT2.c
// Desc: This file contains the code for the DSPUtils routine iccFFT2.
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
// Rout: iccFFTINT08_R
// Desc: This routine performs a real FFT on INT08 data stream.
//------------------------------------------------------------------------------
VOID iccFFTINT08_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  
  iccFFTINT08_X((INT08 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTINT08_C
// Desc: This routine performs a complex FFT on INT08 data stream.
//------------------------------------------------------------------------------
VOID iccFFTINT08_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTINT08_X((INT08 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTINT16_R
// Desc: This routine performs a real FFT on INT16 data stream.
//------------------------------------------------------------------------------
VOID iccFFTINT16_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTINT16_X((INT16 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTINT16_C
// Desc: This routine performs a complex FFT on INT16 data stream.
//------------------------------------------------------------------------------
VOID iccFFTINT16_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTINT16_X((INT16 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTINT32_R
// Desc: This routine performs a real FFT on INT32 data stream.
//------------------------------------------------------------------------------
VOID iccFFTINT32_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTINT32_X((INT32 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTINT32_C
// Desc: This routine performs a complex FFT on INT32 data stream.
//------------------------------------------------------------------------------
VOID iccFFTINT32_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTINT32_X((INT32 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTUNT08_R
// Desc: This routine performs a real FFT on UNT08 data stream.
//------------------------------------------------------------------------------
VOID iccFFTUNT08_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTUNT08_X((UNT08 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTUNT08_C
// Desc: This routine performs a complex FFT on UNT08 data stream.
//------------------------------------------------------------------------------
VOID iccFFTUNT08_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTUNT08_X((UNT08 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTUNT16_R
// Desc: This routine performs a real FFT on UNT16 data stream.
//------------------------------------------------------------------------------
VOID iccFFTUNT16_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTUNT16_X((UNT16 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTUNT16_C
// Desc: This routine performs a complex FFT on UNT16 data stream.
//------------------------------------------------------------------------------
VOID iccFFTUNT16_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTUNT16_X((UNT16 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTUNT32_R
// Desc: This routine performs a real FFT on UNT32 data stream.
//------------------------------------------------------------------------------
VOID iccFFTUNT32_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTUNT32_X((UNT32 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTUNT32_C
// Desc: This routine performs a complex FFT on UNT32 data stream.
//------------------------------------------------------------------------------
VOID iccFFTUNT32_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTUNT32_X((UNT32 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTFLT32_R
// Desc: This routine performs a real FFT on FLT32 data stream.
//------------------------------------------------------------------------------
VOID iccFFTFLT32_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTFLT32_X((FLT32 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTFLT32_C
// Desc: This routine performs a complex FFT on FLT32 data stream.
//------------------------------------------------------------------------------
VOID iccFFTFLT32_C(VOID  *iData, // Complex Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTFLT32_X((FLT32 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTFLT64_R
// Desc: This routine performs a real FFT on FLT64 data stream.
//------------------------------------------------------------------------------
VOID iccFFTFLT64_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTFLT64_X((FLT64 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: iccFFTFLT64_C
// Desc: This routine performs a complex FFT on FLT64 data stream.
//------------------------------------------------------------------------------
VOID iccFFTFLT64_C(VOID  *iData, // Complex Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  iccFFTFLT64_X((FLT64 *)iData,oData,N,FALSE,FALSE);
}


//------------------------------------------------------------------------------
// Rout: iccIFFTINT08_R
// Desc: This routine performs a real IFFT on INT08 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID iccIFFTINT08_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTINT08_X((INT08 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTINT08_C
// Desc: This routine performs a complex IFFT on INT08 data stream.
//------------------------------------------------------------------------------
VOID iccIFFTINT08_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTINT08_X((INT08 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTINT16_R
// Desc: This routine performs a real IFFT on INT16 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID iccIFFTINT16_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTINT16_X((INT16 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTINT16_C
// Desc: This routine performs a complex IFFT on INT16 data stream.
//------------------------------------------------------------------------------
VOID iccIFFTINT16_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTINT16_X((INT16 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTINT32_R
// Desc: This routine performs a real IFFT on INT32 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID iccIFFTINT32_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTINT32_X((INT32 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTINT32_C
// Desc: This routine performs a complex IFFT on INT32 data stream.
//------------------------------------------------------------------------------
VOID iccIFFTINT32_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTINT32_X((INT32 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTUNT08_R
// Desc: This routine performs a real IFFT on UNT08 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID iccIFFTUNT08_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTUNT08_X((UNT08 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTUNT08_C
// Desc: This routine performs a complex IFFT on UNT08 data stream.
//------------------------------------------------------------------------------
VOID iccIFFTUNT08_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTUNT08_X((UNT08 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTUNT16_R
// Desc: This routine performs a real IFFT on UNT16 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID iccIFFTUNT16_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTUNT16_X((UNT16 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTUNT16_C
// Desc: This routine performs a complex IFFT on UNT16 data stream.
//------------------------------------------------------------------------------
VOID iccIFFTUNT16_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTUNT16_X((UNT16 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTUNT32_R
// Desc: This routine performs a real IFFT on UNT32 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID iccIFFTUNT32_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTUNT32_X((UNT32 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTUNT32_C
// Desc: This routine performs a complex IFFT on UNT32 data stream.
//------------------------------------------------------------------------------
VOID iccIFFTUNT32_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTUNT32_X((UNT32 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTFLT32_R
// Desc: This routine performs a real IFFT on FLT32 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID iccIFFTFLT32_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTFLT32_X((FLT32 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTFLT32_C
// Desc: This routine performs a complex IFFT on FLT32 data stream.
//------------------------------------------------------------------------------
VOID iccIFFTFLT32_C(VOID  *iData, // Complex Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTFLT32_X((FLT32 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTFLT64_R
// Desc: This routine performs a real IFFT on FLT64 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID iccIFFTFLT64_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTFLT64_X((FLT64 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: iccIFFTFLT64_C
// Desc: This routine performs a complex IFFT on FLT64 data stream.
//------------------------------------------------------------------------------
VOID iccIFFTFLT64_C(VOID  *iData, // Complex Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  iccFFTFLT64_X((FLT64 *)iData,oData,N,FALSE,TRUE);
}
                        
/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*-------------------------------UNCLASSIFIED---------------------------------*/


