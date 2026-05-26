package jcc;

//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: DEBUG.java
//
// Desc: A Class containing debug methods.
//
// Hist: When       Who  What
//       03/09/2016 ptb  Initial Code.
//------------------------------------------------------------------------------------------------

import java.io.PrintStream;

public class DEBUG
{

	private DEBUG()
	{
	}

	// ---------------------------------------------------------------//---------------------------
	public static String lineNumber()                                 // Returns line number.
	{                                                                 //
		int ln = Thread.currentThread().getStackTrace()[4].getLineNumber();
		String lineNumber = String.format("%03d", ln);
		return (lineNumber);
	}

	// ---------------------------------------------------------------//---------------------------
	public static String fileName()                                   // Returns file name.
	{                                                                 //
		String fnString = Thread.currentThread().getStackTrace()[4].getFileName();
		return (fnString);
	}

	// ---------------------------------------------------------------//--------------------------
	public static String fnln()                                       // Returns file name.
	{                                                                 //
		String fnln = "[" + fileName() + ":" + lineNumber() + "]";
		return (fnln);
	}

	// ---------------------------------------------------------------//--------------------------
	public static void EXITx()                                        // Method EXIT().
	{                                                                 //
		EXIT("DONE.");
	}

	// ---------------------------------------------------------------//--------------------------
	public static void EXIT(String format, Object... args)            //
	{                                                                 //
		format = "****EXIT***" + TIME.currentTimeString() + fnln() + ": " + format;
		System.out.println(System.out.format(format + "\n", args));
		System.exit(0);
	}

	// ---------------------------------------------------------------//--------------------------
	public static String MESSAGE()                                    // Method MESSAGE().
	{                                                                 //
		String str = "";
		str = "**MESSAGE**:" + TIME.currentTimeString() + fnln();
		return (str);
	}

	// ---------------------------------------------------------------//--------------------------
	public static String MESSAGE(String msg)                          //
	{                                                                 //
		String str = "";
		str = "**MESSAGE**:" + TIME.currentTimeString() + fnln() + ": " + msg;
		return (str);
	}

	// ---------------------------------------------------------------//--------------------------
	public static PrintStream MESSAGE(String format, Object... args) //
	{                                                                 //
		format = "**MESSAGE**:" + TIME.currentTimeString() + fnln() + ": " + format;
		return (System.out.format(format, args));
	}

	// ---------------------------------------------------------------//--------------------------
	public static void main(String[] args)                            //
	{                                                                 //
		int x = 4;
		System.out.println(MESSAGE());
		System.out.println(MESSAGE("HEY, this is a message."));
		System.out.println(MESSAGE("HEY, this is a message and x = %d.", x));

		EXIT("DONE.");
	}

}

// THE FOLLOWING IS FOR A CODING TEMPLATE ONLY.
// THE FOLLOWING IS NOT CLASSIFIED.
//       1         2         3         4        |5         6         7         8         9
//345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
//-----------------------------------------UNCLASSIFIED-------------------------------------------
//--------------------------------------UNCLASSIFIED//FOUO----------------------------------------
//-----------------------------------------CONFIDENTIAL-------------------------------------------
//--------------------------------------------SECRET----------------------------------------------
//--------------------------------------------ERROR-----------------------------------------------
//-------------------------------------------WARNING----------------------------------------------
//-------------------------------------------MESSAGE----------------------------------------------
