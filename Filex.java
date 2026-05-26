package jcc.utl;

import java.io.IOException;
import java.io.RandomAccessFile;

//-----------------------------------------UNCLASSIFIED-------------------------------------------
/**
*** A class for handling files based on RandomAccessFile class.
**/
public class Filex extends RandomAccessFile
{
  //-----------------------------------------------------------------//---------------------------
  public Filex(String name, String mode)  throws IOException         // Filex Constructor.
  {                                                                  // Keep non-instantiated.
    super(name,mode);
  }
  
  //-----------------------------------------------------------------//---------------------------
  public static void main(String[] args)
  {
    char c;
    long ii;
    Filex theFile;
    long fl;
    String path = "C:\\Users\\pbergman\\GIT202X\\pmt2026\\data.h5";
    System.out.printf("This is a test.");

    try
    {
      theFile = new Filex(path,"r");
      fl = theFile.length();
      System.out.printf("Xotal bytes read: %d\n",fl);
      for (ii=0; ii<fl; ii++)
      {
        c = theFile.readChar();
        if (c=='b')
        {
          System.out.printf("%d\n",ii);
        }
      }
    }
    catch (IOException e)
    {
      // e.printStackTrace();
    }
    
    System.out.printf("77777777777777\n");

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
