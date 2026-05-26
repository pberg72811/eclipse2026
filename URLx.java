package org.ieee.jcc.util;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import org.ieee.jcc.util.DEBUG;
import java.net.URL;

//import org.junit.Test;

//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: URLx.java
//
// Desc: Static URL utilities. 
//
// Hist: When       Who  What
//       03/09/2016 ptb  Initial Code.
//------------------------------------------------------------------------------------------------
public class URLx
{

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  private URLx()                                                     // URLx Constructor.
  {                                                                  // Keep non-instantiated.
  }

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  public static BufferedReader open(String urlStr)                   // Method open().
  {                                                                  //
    URL url;
    InputStreamReader isReader = null;
    BufferedReader bufferedReader;
    try
    {
      url = new URL(urlStr);
      isReader = new InputStreamReader(url.openStream(), "UTF-8");
    }
    catch (IOException e)
    {
      String errMsg = DEBUG.ERROR("URL IOEXCEPTION OR SOMETHING.\n");
      System.out.printf(errMsg);
      e.printStackTrace();
    }
    bufferedReader = new BufferedReader(isReader);
    return bufferedReader;
  }

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  public static String read(String urlStr)                           // Method read().
  {                                                                  // Simple version.
    return (URLx.read(urlStr, 1024));                                //
  }                                                                  //---------------------------

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  public static String read(String urlStr, int bufSize)              // Method read().
  {                                                                  // Need bufSize.
    int l;
    String s = "";
    BufferedReader bufReader;
    char c[] = new char[bufSize];

    bufReader = URLx.open(urlStr);                                   // Open for reading.
    try
    {
      while ((l = bufReader.read(c)) > 0)                            // While there is data,
      {                                                              // read the data.
        String tmpStr = new String(c, 0, l);                         //
        s +=tmpStr;                                                  // Concatenate to end of "s".
        //DEBUG.MESSAGEF("s is \n%s\n\n\n",tmpStr);
        //DEBUG.MESSAGEF("l is   %d\n\n\n",l);
      }
      bufReader.close();                                             // Done, close
    }                                                                // BufferedReader.
    catch (IOException e)
    {
      String errMsg = String.format("NOT ABLE TO READ DATA FROM URL %s.\n", urlStr);
      DEBUG.ERRORF(errMsg);
    }
    return s;
  }

  //----------------------------------------UNCLASSIFIED-------------//---------------------------
  public static void main(String[] args)                             // Method main().
  {                                                                  //
    String retStr;
    String urlStr = "http://www.cnn.com";

    DEBUG.MESSAGEF("START\n");
    retStr = URLx.read(urlStr, 1024 * 1024);
    DEBUG.PRINTF("%s ...\n", retStr.substring(0, 1024));
    DEBUG.MESSAGEF("DONE\n");
  }

}

//THE FOLLOWING IS FOR A CODING TEMPLATE ONLY.
//THE FOLLOWING IS NOT CLASSIFIED.
//    1         2         3         4        |5         6         7         8         9
//345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
//-----------------------------------------UNCLASSIFIED-------------------------------------------
//--------------------------------------UNCLASSIFIED//FOUO----------------------------------------
//-----------------------------------------CONFIDENTIAL-------------------------------------------
//--------------------------------------------SECRET----------------------------------------------
//--------------------------------------------ERROR-----------------------------------------------
//-------------------------------------------WARNING----------------------------------------------
//-------------------------------------------MESSAGE----------------------------------------------