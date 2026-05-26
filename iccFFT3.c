/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccFFT3.c
// Desc: This file contains the code for the DSPUtils routine iccFFT3.
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
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS   INT32 ii, jj, kk;
PERL_PREPROCESS   INT32 idex;
PERL_PREPROCESS   INT32 nBits;
PERL_PREPROCESS   INT32 nWhogi;
PERL_PREPROCESS   FLT32 tempA[2];
PERL_PREPROCESS   FLT32 tempB[2];
PERL_PREPROCESS 
PERL_PREPROCESS /* Find out the number bits we will need for bit reversing. ------------------*/
PERL_PREPROCESS   if      (N ==           2) nBits =  1;
PERL_PREPROCESS   else if (N ==           4) nBits =  2;
PERL_PREPROCESS   else if (N ==           8) nBits =  3;
PERL_PREPROCESS   else if (N ==          16) nBits =  4;
PERL_PREPROCESS   else if (N ==          32) nBits =  5;
PERL_PREPROCESS   else if (N ==          64) nBits =  6;
PERL_PREPROCESS   else if (N ==         128) nBits =  7;
PERL_PREPROCESS   else if (N ==         256) nBits =  8;
PERL_PREPROCESS   else if (N ==         512) nBits =  9;
PERL_PREPROCESS   else if (N ==        1024) nBits = 10;
PERL_PREPROCESS   else if (N ==        2048) nBits = 11;
PERL_PREPROCESS   else if (N ==        4096) nBits = 12;
PERL_PREPROCESS   else if (N ==        8192) nBits = 13;
PERL_PREPROCESS   else if (N ==       16384) nBits = 14;
PERL_PREPROCESS   else if (N ==       32768) nBits = 15;
PERL_PREPROCESS   else if (N ==       65536) nBits = 16;
PERL_PREPROCESS   else if (N ==      131072) nBits = 17;
PERL_PREPROCESS   else if (N ==      262144) nBits = 18;
PERL_PREPROCESS   else if (N ==      524288) nBits = 19;
PERL_PREPROCESS   else if (N ==     1048576) nBits = 20;
PERL_PREPROCESS   else if (N ==     2097152) nBits = 21;
PERL_PREPROCESS   else if (N ==     4194304) nBits = 22;
PERL_PREPROCESS   else if (N ==     8388608) nBits = 23;
PERL_PREPROCESS   else if (N ==    16777216) nBits = 24;
PERL_PREPROCESS   else if (N ==    33554432) nBits = 25;
PERL_PREPROCESS   else if (N ==    67108864) nBits = 26;
PERL_PREPROCESS   else if (N ==   134217728) nBits = 27;
PERL_PREPROCESS   else if (N ==   268435456) nBits = 28;
PERL_PREPROCESS   else if (N ==   536870912) nBits = 29;
PERL_PREPROCESS   else if (N ==  1073741824) nBits = 30;
PERL_PREPROCESS   else if (N == 2147483648U) nBits = 31;
PERL_PREPROCESS   else return;
PERL_PREPROCESS 
PERL_PREPROCESS /* Bit reversal and first stage of FFT. --------------------------------------*/
PERL_PREPROCESS   if( realFlag == FALSE ) // Complex case.
PERL_PREPROCESS   {
PERL_PREPROCESS     for(ii = 0; ii < N; ii+=2)
PERL_PREPROCESS     {
PERL_PREPROCESS       jj = iccFFTBitReverse(ii  , nBits);
PERL_PREPROCESS       kk = iccFFTBitReverse(ii+1, nBits);
PERL_PREPROCESS       tempA[0] = iData[jj*2];
PERL_PREPROCESS       tempA[1] = iData[jj*2+1];
PERL_PREPROCESS       tempB[0] = iData[kk*2];
PERL_PREPROCESS       tempB[1] = iData[kk*2+1];
PERL_PREPROCESS       icc2ptButterflyFLT32_C(tempA, tempB, &oData[ii*2]);
PERL_PREPROCESS     }
PERL_PREPROCESS   }
PERL_PREPROCESS   else // Real case.
PERL_PREPROCESS   {
PERL_PREPROCESS     for(ii = 0; ii < N; ii+=2)
PERL_PREPROCESS     {
PERL_PREPROCESS       jj = iccFFTBitReverse(ii  , nBits);
PERL_PREPROCESS       kk = iccFFTBitReverse(ii+1, nBits);
PERL_PREPROCESS       tempA[0] = iData[jj];
PERL_PREPROCESS       tempB[0] = iData[kk];
PERL_PREPROCESS       icc2ptButterflyFLT32_R(tempA, tempB, &oData[ii*2]);
PERL_PREPROCESS     }
PERL_PREPROCESS   }
PERL_PREPROCESS 
PERL_PREPROCESS /* Finish off the FFT stages. ------------------------------------------------*/
PERL_PREPROCESS   for(ii = 2; ii <=nBits; ii++)
PERL_PREPROCESS   {
PERL_PREPROCESS     nWhogi = N/(1<<ii);
PERL_PREPROCESS     for(jj = 0; jj < nWhogi; jj++)
PERL_PREPROCESS     {
PERL_PREPROCESS       idex = jj*(1<<ii)*2;
PERL_PREPROCESS       iccNptButterflyFLT32(&oData[idex], (1<<ii), ifftFlag);
PERL_PREPROCESS     }
PERL_PREPROCESS   }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: iccFFTINT08_X
// Desc: This routine performs a FFT on INT08 data stream.
//------------------------------------------------------------------------------
VOID iccFFTINT08_X(INT08 *iData,   // Complex Input.
		   FLT32 *oData,   // Complex output.
		   UNT32 N,        // Size of FFT.
		   INT08 realFlag, // Operate on real data.
		   INT08 ifftFlag) // Perform IFFT.
{
//------------------------------- COMMON-CODE  START.
   INT32 ii, jj, kk;
   INT32 idex;
   INT32 nBits;
   INT32 nWhogi;
   FLT32 tempA[2];
   FLT32 tempB[2];
 
 /* Find out the number bits we will need for bit reversing. ------------------*/
   if      (N ==           2) nBits =  1;
   else if (N ==           4) nBits =  2;
   else if (N ==           8) nBits =  3;
   else if (N ==          16) nBits =  4;
   else if (N ==          32) nBits =  5;
   else if (N ==          64) nBits =  6;
   else if (N ==         128) nBits =  7;
   else if (N ==         256) nBits =  8;
   else if (N ==         512) nBits =  9;
   else if (N ==        1024) nBits = 10;
   else if (N ==        2048) nBits = 11;
   else if (N ==        4096) nBits = 12;
   else if (N ==        8192) nBits = 13;
   else if (N ==       16384) nBits = 14;
   else if (N ==       32768) nBits = 15;
   else if (N ==       65536) nBits = 16;
   else if (N ==      131072) nBits = 17;
   else if (N ==      262144) nBits = 18;
   else if (N ==      524288) nBits = 19;
   else if (N ==     1048576) nBits = 20;
   else if (N ==     2097152) nBits = 21;
   else if (N ==     4194304) nBits = 22;
   else if (N ==     8388608) nBits = 23;
   else if (N ==    16777216) nBits = 24;
   else if (N ==    33554432) nBits = 25;
   else if (N ==    67108864) nBits = 26;
   else if (N ==   134217728) nBits = 27;
   else if (N ==   268435456) nBits = 28;
   else if (N ==   536870912) nBits = 29;
   else if (N ==  1073741824) nBits = 30;
   else if (N == 2147483648U) nBits = 31;
   else return;
 
 /* Bit reversal and first stage of FFT. --------------------------------------*/
   if( realFlag == FALSE ) // Complex case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj*2];
       tempA[1] = iData[jj*2+1];
       tempB[0] = iData[kk*2];
       tempB[1] = iData[kk*2+1];
       icc2ptButterflyFLT32_C(tempA, tempB, &oData[ii*2]);
     }
   }
   else // Real case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj];
       tempB[0] = iData[kk];
       icc2ptButterflyFLT32_R(tempA, tempB, &oData[ii*2]);
     }
   }
 
 /* Finish off the FFT stages. ------------------------------------------------*/
   for(ii = 2; ii <=nBits; ii++)
   {
     nWhogi = N/(1<<ii);
     for(jj = 0; jj < nWhogi; jj++)
     {
       idex = jj*(1<<ii)*2;
       iccNptButterflyFLT32(&oData[idex], (1<<ii), ifftFlag);
     }
   }
//------------------------------- COMMON-CODE   STOP.
}


VOID iccFFTINT16_X(INT16 *iData,   // Complex Input.
		   FLT32 *oData,   // Complex output.
		   UNT32 N,        // Size of FFT.
		   INT08 realFlag, // Operate on real data.
		   INT08 ifftFlag) // Perform IFFT.
{
//------------------------------- COMMON-CODE  START.
   INT32 ii, jj, kk;
   INT32 idex;
   INT32 nBits;
   INT32 nWhogi;
   FLT32 tempA[2];
   FLT32 tempB[2];
 
 /* Find out the number bits we will need for bit reversing. ------------------*/
   if      (N ==           2) nBits =  1;
   else if (N ==           4) nBits =  2;
   else if (N ==           8) nBits =  3;
   else if (N ==          16) nBits =  4;
   else if (N ==          32) nBits =  5;
   else if (N ==          64) nBits =  6;
   else if (N ==         128) nBits =  7;
   else if (N ==         256) nBits =  8;
   else if (N ==         512) nBits =  9;
   else if (N ==        1024) nBits = 10;
   else if (N ==        2048) nBits = 11;
   else if (N ==        4096) nBits = 12;
   else if (N ==        8192) nBits = 13;
   else if (N ==       16384) nBits = 14;
   else if (N ==       32768) nBits = 15;
   else if (N ==       65536) nBits = 16;
   else if (N ==      131072) nBits = 17;
   else if (N ==      262144) nBits = 18;
   else if (N ==      524288) nBits = 19;
   else if (N ==     1048576) nBits = 20;
   else if (N ==     2097152) nBits = 21;
   else if (N ==     4194304) nBits = 22;
   else if (N ==     8388608) nBits = 23;
   else if (N ==    16777216) nBits = 24;
   else if (N ==    33554432) nBits = 25;
   else if (N ==    67108864) nBits = 26;
   else if (N ==   134217728) nBits = 27;
   else if (N ==   268435456) nBits = 28;
   else if (N ==   536870912) nBits = 29;
   else if (N ==  1073741824) nBits = 30;
   else if (N == 2147483648U) nBits = 31;
   else return;
 
 /* Bit reversal and first stage of FFT. --------------------------------------*/
   if( realFlag == FALSE ) // Complex case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj*2];
       tempA[1] = iData[jj*2+1];
       tempB[0] = iData[kk*2];
       tempB[1] = iData[kk*2+1];
       icc2ptButterflyFLT32_C(tempA, tempB, &oData[ii*2]);
     }
   }
   else // Real case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj];
       tempB[0] = iData[kk];
       icc2ptButterflyFLT32_R(tempA, tempB, &oData[ii*2]);
     }
   }
 
 /* Finish off the FFT stages. ------------------------------------------------*/
   for(ii = 2; ii <=nBits; ii++)
   {
     nWhogi = N/(1<<ii);
     for(jj = 0; jj < nWhogi; jj++)
     {
       idex = jj*(1<<ii)*2;
       iccNptButterflyFLT32(&oData[idex], (1<<ii), ifftFlag);
     }
   }
//------------------------------- COMMON-CODE   STOP.
}

VOID iccFFTINT32_X(INT32 *iData,   // Complex Input.
		   FLT32 *oData,   // Complex output.
		   UNT32 N,        // Size of FFT.
		   INT08 realFlag, // Operate on real data.
		   INT08 ifftFlag) // Perform IFFT.
{
//------------------------------- COMMON-CODE  START.
   INT32 ii, jj, kk;
   INT32 idex;
   INT32 nBits;
   INT32 nWhogi;
   FLT32 tempA[2];
   FLT32 tempB[2];
 
 /* Find out the number bits we will need for bit reversing. ------------------*/
   if      (N ==           2) nBits =  1;
   else if (N ==           4) nBits =  2;
   else if (N ==           8) nBits =  3;
   else if (N ==          16) nBits =  4;
   else if (N ==          32) nBits =  5;
   else if (N ==          64) nBits =  6;
   else if (N ==         128) nBits =  7;
   else if (N ==         256) nBits =  8;
   else if (N ==         512) nBits =  9;
   else if (N ==        1024) nBits = 10;
   else if (N ==        2048) nBits = 11;
   else if (N ==        4096) nBits = 12;
   else if (N ==        8192) nBits = 13;
   else if (N ==       16384) nBits = 14;
   else if (N ==       32768) nBits = 15;
   else if (N ==       65536) nBits = 16;
   else if (N ==      131072) nBits = 17;
   else if (N ==      262144) nBits = 18;
   else if (N ==      524288) nBits = 19;
   else if (N ==     1048576) nBits = 20;
   else if (N ==     2097152) nBits = 21;
   else if (N ==     4194304) nBits = 22;
   else if (N ==     8388608) nBits = 23;
   else if (N ==    16777216) nBits = 24;
   else if (N ==    33554432) nBits = 25;
   else if (N ==    67108864) nBits = 26;
   else if (N ==   134217728) nBits = 27;
   else if (N ==   268435456) nBits = 28;
   else if (N ==   536870912) nBits = 29;
   else if (N ==  1073741824) nBits = 30;
   else if (N == 2147483648U) nBits = 31;
   else return;
 
 /* Bit reversal and first stage of FFT. --------------------------------------*/
   if( realFlag == FALSE ) // Complex case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj*2];
       tempA[1] = iData[jj*2+1];
       tempB[0] = iData[kk*2];
       tempB[1] = iData[kk*2+1];
       icc2ptButterflyFLT32_C(tempA, tempB, &oData[ii*2]);
     }
   }
   else // Real case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj];
       tempB[0] = iData[kk];
       icc2ptButterflyFLT32_R(tempA, tempB, &oData[ii*2]);
     }
   }
 
 /* Finish off the FFT stages. ------------------------------------------------*/
   for(ii = 2; ii <=nBits; ii++)
   {
     nWhogi = N/(1<<ii);
     for(jj = 0; jj < nWhogi; jj++)
     {
       idex = jj*(1<<ii)*2;
       iccNptButterflyFLT32(&oData[idex], (1<<ii), ifftFlag);
     }
   }
//------------------------------- COMMON-CODE   STOP.
}

VOID iccFFTUNT08_X(UNT08 *iData,   // Complex Input.
		   FLT32 *oData,   // Complex output.
		   UNT32 N,        // Size of FFT.
		   INT08 realFlag, // Operate on real data.
		   INT08 ifftFlag) // Perform IFFT.
{
//------------------------------- COMMON-CODE  START.
   INT32 ii, jj, kk;
   INT32 idex;
   INT32 nBits;
   INT32 nWhogi;
   FLT32 tempA[2];
   FLT32 tempB[2];
 
 /* Find out the number bits we will need for bit reversing. ------------------*/
   if      (N ==           2) nBits =  1;
   else if (N ==           4) nBits =  2;
   else if (N ==           8) nBits =  3;
   else if (N ==          16) nBits =  4;
   else if (N ==          32) nBits =  5;
   else if (N ==          64) nBits =  6;
   else if (N ==         128) nBits =  7;
   else if (N ==         256) nBits =  8;
   else if (N ==         512) nBits =  9;
   else if (N ==        1024) nBits = 10;
   else if (N ==        2048) nBits = 11;
   else if (N ==        4096) nBits = 12;
   else if (N ==        8192) nBits = 13;
   else if (N ==       16384) nBits = 14;
   else if (N ==       32768) nBits = 15;
   else if (N ==       65536) nBits = 16;
   else if (N ==      131072) nBits = 17;
   else if (N ==      262144) nBits = 18;
   else if (N ==      524288) nBits = 19;
   else if (N ==     1048576) nBits = 20;
   else if (N ==     2097152) nBits = 21;
   else if (N ==     4194304) nBits = 22;
   else if (N ==     8388608) nBits = 23;
   else if (N ==    16777216) nBits = 24;
   else if (N ==    33554432) nBits = 25;
   else if (N ==    67108864) nBits = 26;
   else if (N ==   134217728) nBits = 27;
   else if (N ==   268435456) nBits = 28;
   else if (N ==   536870912) nBits = 29;
   else if (N ==  1073741824) nBits = 30;
   else if (N == 2147483648U) nBits = 31;
   else return;
 
 /* Bit reversal and first stage of FFT. --------------------------------------*/
   if( realFlag == FALSE ) // Complex case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj*2];
       tempA[1] = iData[jj*2+1];
       tempB[0] = iData[kk*2];
       tempB[1] = iData[kk*2+1];
       icc2ptButterflyFLT32_C(tempA, tempB, &oData[ii*2]);
     }
   }
   else // Real case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj];
       tempB[0] = iData[kk];
       icc2ptButterflyFLT32_R(tempA, tempB, &oData[ii*2]);
     }
   }
 
 /* Finish off the FFT stages. ------------------------------------------------*/
   for(ii = 2; ii <=nBits; ii++)
   {
     nWhogi = N/(1<<ii);
     for(jj = 0; jj < nWhogi; jj++)
     {
       idex = jj*(1<<ii)*2;
       iccNptButterflyFLT32(&oData[idex], (1<<ii), ifftFlag);
     }
   }
//------------------------------- COMMON-CODE   STOP.
}


VOID iccFFTUNT16_X(UNT16 *iData,   // Complex Input.
		   FLT32 *oData,   // Complex output.
		   UNT32 N,        // Size of FFT.
		   INT08 realFlag, // Operate on real data.
		   INT08 ifftFlag) // Perform IFFT.
{
//------------------------------- COMMON-CODE  START.
   INT32 ii, jj, kk;
   INT32 idex;
   INT32 nBits;
   INT32 nWhogi;
   FLT32 tempA[2];
   FLT32 tempB[2];
 
 /* Find out the number bits we will need for bit reversing. ------------------*/
   if      (N ==           2) nBits =  1;
   else if (N ==           4) nBits =  2;
   else if (N ==           8) nBits =  3;
   else if (N ==          16) nBits =  4;
   else if (N ==          32) nBits =  5;
   else if (N ==          64) nBits =  6;
   else if (N ==         128) nBits =  7;
   else if (N ==         256) nBits =  8;
   else if (N ==         512) nBits =  9;
   else if (N ==        1024) nBits = 10;
   else if (N ==        2048) nBits = 11;
   else if (N ==        4096) nBits = 12;
   else if (N ==        8192) nBits = 13;
   else if (N ==       16384) nBits = 14;
   else if (N ==       32768) nBits = 15;
   else if (N ==       65536) nBits = 16;
   else if (N ==      131072) nBits = 17;
   else if (N ==      262144) nBits = 18;
   else if (N ==      524288) nBits = 19;
   else if (N ==     1048576) nBits = 20;
   else if (N ==     2097152) nBits = 21;
   else if (N ==     4194304) nBits = 22;
   else if (N ==     8388608) nBits = 23;
   else if (N ==    16777216) nBits = 24;
   else if (N ==    33554432) nBits = 25;
   else if (N ==    67108864) nBits = 26;
   else if (N ==   134217728) nBits = 27;
   else if (N ==   268435456) nBits = 28;
   else if (N ==   536870912) nBits = 29;
   else if (N ==  1073741824) nBits = 30;
   else if (N == 2147483648U) nBits = 31;
   else return;
 
 /* Bit reversal and first stage of FFT. --------------------------------------*/
   if( realFlag == FALSE ) // Complex case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj*2];
       tempA[1] = iData[jj*2+1];
       tempB[0] = iData[kk*2];
       tempB[1] = iData[kk*2+1];
       icc2ptButterflyFLT32_C(tempA, tempB, &oData[ii*2]);
     }
   }
   else // Real case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj];
       tempB[0] = iData[kk];
       icc2ptButterflyFLT32_R(tempA, tempB, &oData[ii*2]);
     }
   }
 
 /* Finish off the FFT stages. ------------------------------------------------*/
   for(ii = 2; ii <=nBits; ii++)
   {
     nWhogi = N/(1<<ii);
     for(jj = 0; jj < nWhogi; jj++)
     {
       idex = jj*(1<<ii)*2;
       iccNptButterflyFLT32(&oData[idex], (1<<ii), ifftFlag);
     }
   }
//------------------------------- COMMON-CODE   STOP.
}

VOID iccFFTUNT32_X(UNT32 *iData,   // Complex Input.
		   FLT32 *oData,   // Complex output.
		   UNT32 N,        // Size of FFT.
		   INT08 realFlag, // Operate on real data.
		   INT08 ifftFlag) // Perform IFFT.
{
//------------------------------- COMMON-CODE  START.
   INT32 ii, jj, kk;
   INT32 idex;
   INT32 nBits;
   INT32 nWhogi;
   FLT32 tempA[2];
   FLT32 tempB[2];
 
 /* Find out the number bits we will need for bit reversing. ------------------*/
   if      (N ==           2) nBits =  1;
   else if (N ==           4) nBits =  2;
   else if (N ==           8) nBits =  3;
   else if (N ==          16) nBits =  4;
   else if (N ==          32) nBits =  5;
   else if (N ==          64) nBits =  6;
   else if (N ==         128) nBits =  7;
   else if (N ==         256) nBits =  8;
   else if (N ==         512) nBits =  9;
   else if (N ==        1024) nBits = 10;
   else if (N ==        2048) nBits = 11;
   else if (N ==        4096) nBits = 12;
   else if (N ==        8192) nBits = 13;
   else if (N ==       16384) nBits = 14;
   else if (N ==       32768) nBits = 15;
   else if (N ==       65536) nBits = 16;
   else if (N ==      131072) nBits = 17;
   else if (N ==      262144) nBits = 18;
   else if (N ==      524288) nBits = 19;
   else if (N ==     1048576) nBits = 20;
   else if (N ==     2097152) nBits = 21;
   else if (N ==     4194304) nBits = 22;
   else if (N ==     8388608) nBits = 23;
   else if (N ==    16777216) nBits = 24;
   else if (N ==    33554432) nBits = 25;
   else if (N ==    67108864) nBits = 26;
   else if (N ==   134217728) nBits = 27;
   else if (N ==   268435456) nBits = 28;
   else if (N ==   536870912) nBits = 29;
   else if (N ==  1073741824) nBits = 30;
   else if (N == 2147483648U) nBits = 31;
   else return;
 
 /* Bit reversal and first stage of FFT. --------------------------------------*/
   if( realFlag == FALSE ) // Complex case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj*2];
       tempA[1] = iData[jj*2+1];
       tempB[0] = iData[kk*2];
       tempB[1] = iData[kk*2+1];
       icc2ptButterflyFLT32_C(tempA, tempB, &oData[ii*2]);
     }
   }
   else // Real case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj];
       tempB[0] = iData[kk];
       icc2ptButterflyFLT32_R(tempA, tempB, &oData[ii*2]);
     }
   }
 
 /* Finish off the FFT stages. ------------------------------------------------*/
   for(ii = 2; ii <=nBits; ii++)
   {
     nWhogi = N/(1<<ii);
     for(jj = 0; jj < nWhogi; jj++)
     {
       idex = jj*(1<<ii)*2;
       iccNptButterflyFLT32(&oData[idex], (1<<ii), ifftFlag);
     }
   }
//------------------------------- COMMON-CODE   STOP.
}

VOID iccFFTFLT32_X(FLT32 *iData,   // Complex Input.
		   FLT32 *oData,   // Complex output.
		   UNT32 N,        // Size of FFT.
		   INT08 realFlag, // Operate on real data.
		   INT08 ifftFlag) // Perform IFFT.
{
//------------------------------- COMMON-CODE  START.
   INT32 ii, jj, kk;
   INT32 idex;
   INT32 nBits;
   INT32 nWhogi;
   FLT32 tempA[2];
   FLT32 tempB[2];
 
 /* Find out the number bits we will need for bit reversing. ------------------*/
   if      (N ==           2) nBits =  1;
   else if (N ==           4) nBits =  2;
   else if (N ==           8) nBits =  3;
   else if (N ==          16) nBits =  4;
   else if (N ==          32) nBits =  5;
   else if (N ==          64) nBits =  6;
   else if (N ==         128) nBits =  7;
   else if (N ==         256) nBits =  8;
   else if (N ==         512) nBits =  9;
   else if (N ==        1024) nBits = 10;
   else if (N ==        2048) nBits = 11;
   else if (N ==        4096) nBits = 12;
   else if (N ==        8192) nBits = 13;
   else if (N ==       16384) nBits = 14;
   else if (N ==       32768) nBits = 15;
   else if (N ==       65536) nBits = 16;
   else if (N ==      131072) nBits = 17;
   else if (N ==      262144) nBits = 18;
   else if (N ==      524288) nBits = 19;
   else if (N ==     1048576) nBits = 20;
   else if (N ==     2097152) nBits = 21;
   else if (N ==     4194304) nBits = 22;
   else if (N ==     8388608) nBits = 23;
   else if (N ==    16777216) nBits = 24;
   else if (N ==    33554432) nBits = 25;
   else if (N ==    67108864) nBits = 26;
   else if (N ==   134217728) nBits = 27;
   else if (N ==   268435456) nBits = 28;
   else if (N ==   536870912) nBits = 29;
   else if (N ==  1073741824) nBits = 30;
   else if (N == 2147483648U) nBits = 31;
   else return;
 
 /* Bit reversal and first stage of FFT. --------------------------------------*/
   if( realFlag == FALSE ) // Complex case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj*2];
       tempA[1] = iData[jj*2+1];
       tempB[0] = iData[kk*2];
       tempB[1] = iData[kk*2+1];
       icc2ptButterflyFLT32_C(tempA, tempB, &oData[ii*2]);
     }
   }
   else // Real case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj];
       tempB[0] = iData[kk];
       icc2ptButterflyFLT32_R(tempA, tempB, &oData[ii*2]);
     }
   }
 
 /* Finish off the FFT stages. ------------------------------------------------*/
   for(ii = 2; ii <=nBits; ii++)
   {
     nWhogi = N/(1<<ii);
     for(jj = 0; jj < nWhogi; jj++)
     {
       idex = jj*(1<<ii)*2;
       iccNptButterflyFLT32(&oData[idex], (1<<ii), ifftFlag);
     }
   }
//------------------------------- COMMON-CODE   STOP.
}

VOID iccFFTFLT64_X(FLT64 *iData,   // Complex Input.
		   FLT32 *oData,   // Complex output.
		   UNT32 N,        // Size of FFT.
		   INT08 realFlag, // Operate on real data.
		   INT08 ifftFlag) // Perform IFFT.
{
//------------------------------- COMMON-CODE  START.
   INT32 ii, jj, kk;
   INT32 idex;
   INT32 nBits;
   INT32 nWhogi;
   FLT32 tempA[2];
   FLT32 tempB[2];
 
 /* Find out the number bits we will need for bit reversing. ------------------*/
   if      (N ==           2) nBits =  1;
   else if (N ==           4) nBits =  2;
   else if (N ==           8) nBits =  3;
   else if (N ==          16) nBits =  4;
   else if (N ==          32) nBits =  5;
   else if (N ==          64) nBits =  6;
   else if (N ==         128) nBits =  7;
   else if (N ==         256) nBits =  8;
   else if (N ==         512) nBits =  9;
   else if (N ==        1024) nBits = 10;
   else if (N ==        2048) nBits = 11;
   else if (N ==        4096) nBits = 12;
   else if (N ==        8192) nBits = 13;
   else if (N ==       16384) nBits = 14;
   else if (N ==       32768) nBits = 15;
   else if (N ==       65536) nBits = 16;
   else if (N ==      131072) nBits = 17;
   else if (N ==      262144) nBits = 18;
   else if (N ==      524288) nBits = 19;
   else if (N ==     1048576) nBits = 20;
   else if (N ==     2097152) nBits = 21;
   else if (N ==     4194304) nBits = 22;
   else if (N ==     8388608) nBits = 23;
   else if (N ==    16777216) nBits = 24;
   else if (N ==    33554432) nBits = 25;
   else if (N ==    67108864) nBits = 26;
   else if (N ==   134217728) nBits = 27;
   else if (N ==   268435456) nBits = 28;
   else if (N ==   536870912) nBits = 29;
   else if (N ==  1073741824) nBits = 30;
   else if (N == 2147483648U) nBits = 31;
   else return;
 
 /* Bit reversal and first stage of FFT. --------------------------------------*/
   if( realFlag == FALSE ) // Complex case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj*2];
       tempA[1] = iData[jj*2+1];
       tempB[0] = iData[kk*2];
       tempB[1] = iData[kk*2+1];
       icc2ptButterflyFLT32_C(tempA, tempB, &oData[ii*2]);
     }
   }
   else // Real case.
   {
     for(ii = 0; ii < N; ii+=2)
     {
       jj = iccFFTBitReverse(ii  , nBits);
       kk = iccFFTBitReverse(ii+1, nBits);
       tempA[0] = iData[jj];
       tempB[0] = iData[kk];
       icc2ptButterflyFLT32_R(tempA, tempB, &oData[ii*2]);
     }
   }
 
 /* Finish off the FFT stages. ------------------------------------------------*/
   for(ii = 2; ii <=nBits; ii++)
   {
     nWhogi = N/(1<<ii);
     for(jj = 0; jj < nWhogi; jj++)
     {
       idex = jj*(1<<ii)*2;
       iccNptButterflyFLT32(&oData[idex], (1<<ii), ifftFlag);
     }
   }
//------------------------------- COMMON-CODE   STOP.
}







                      
                     
/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*-------------------------------UNCLASSIFIED---------------------------------*/


