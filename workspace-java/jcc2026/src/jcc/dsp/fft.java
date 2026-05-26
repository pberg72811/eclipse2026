package jcc.dsp;
//-----------------------------------------UNCLASSIFIED-------------------------------------------
//File: TIME.java
//
//Desc: A Class containing debug methods.
//
//Hist: When       Who  What
//    03/09/2016 ptb  Initial Code.
//------------------------------------------------------------------------------------------------
public class fft
{
	int nBits;
	
	public fft(long N, boolean realFlag, boolean ifftFlag)
	{
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
	   else if (N == 2147483648L) nBits = 31;
	   }
	
//	VOID fft(INT08 *iData,     // Complex Input.
//			   FLT32 *oData,   // Complex output.
//			   UNT32 N,        // Size of FFT.
//			   INT08 realFlag, // Operate on real data.
//			   INT08 ifftFlag) // Perform IFFT.
}
