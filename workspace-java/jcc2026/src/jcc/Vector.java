package jcc;

//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: jcc.util.Vector.java
//
// Desc: Vector class and methods.
//
// Hist: When       Who  What
//       07/15/2016 ptb  Initial Code.
//------------------------------------------------------------------------------------------------

//-----------------------------------------UNCLASSIFIED--------------//---------------------------
public class Vector                                                  //
{                                                                    //
  public double x = 0.0;
  public double y = 0.0;
  public double z = 0.0;

  public Vector()                                                    // Constructor.
  {                                                                  //
    this.zero();
  }

  public Vector(Vector v)                                            // Constructor.
  {                                                                  //
    this.x = v.x;
    this.y = v.y;
    this.z = v.z;
  }

  public Vector(double x, double y, double z)                        // Constructor.
  {                                                                  //
    this.x = x;
    this.y = y;
    this.z = z;
  }

  public Vector(double x, double y, double z, double t)              // Constructor.
  {                                                                  //
    this.x = x;
    this.y = y;
    this.z = z;
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public void zero()                                                 // Set Vector to zero.
  {                                                                  //
    this.x = 0.0;
    this.y = 0.0;
    this.z = 0.0;
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public double mag()                                                // Get Magnitude of Vector.
  {                                                                  //
    double m = this.x * this.x + this.y * this.y + this.z * this.z;
    return (Math.sqrt(m));
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public void norm()                                                 // Normalize Vector.
  {                                                                  //
    double mag = this.mag();
    this.x = this.x / mag;
    this.y = this.y / mag;
    this.z = this.z / mag;
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public Vector norm_copy()                                          // Normalize Vector copy.
  {                                                                  //
    double mag = this.mag();
    Vector v = new Vector(this);
    v.x = this.x / mag;
    v.y = this.y / mag;
    v.z = this.z / mag;
    return (v);
  }

//  //---------------------------------------UNCLASSIFIED--------------//---------------------------
//  public void rotx(double theta)                                     // Rotate around X.
//  {                                                                  //
//    Matrix m1 = new Matrix(this);
//    Matrix m2 = m1.rotx(theta);
//    this.x = m2.data[0];
//    this.y = m2.data[1];
//    this.z = m2.data[2];
//  }
//
//  //---------------------------------------UNCLASSIFIED--------------//---------------------------
//  public Vector rotx_copy(double theta)                              // Rotate around X and copy.
//  {                                                                  //
//    Vector v = new Vector();
//    Matrix m1 = new Matrix(this);
//    Matrix m2 = m1.rotx(theta);
//    v.x = m2.data[0];
//    v.y = m2.data[1];
//    v.z = m2.data[2];
//    return (v);
//  }

//  //---------------------------------------UNCLASSIFIED--------------//---------------------------
//  public void roty(double theta)                                     // Rotate around Y.
//  {                                                                  //
//    Matrix m1 = new Matrix(this);
//    Matrix m2 = m1.roty(theta);
//    this.x = m2.data[0];
//    this.y = m2.data[1];
//    this.z = m2.data[2];
//  }
//
//  //---------------------------------------UNCLASSIFIED--------------//---------------------------
//  public Vector roty_copy(double theta)                              // Rotate around Y and copy.
//  {                                                                  //
//    Vector v = new Vector();
//    Matrix m1 = new Matrix(this);
//    Matrix m2 = m1.roty(theta);
//    v.x = m2.data[0];
//    v.y = m2.data[1];
//    v.z = m2.data[2];
//    return (v);
//  }
//
//  //---------------------------------------UNCLASSIFIED--------------//---------------------------
//  public void rotz(double theta)                                     // Rotate around Z.
//  {                                                                  //
//    Matrix m1 = new Matrix(this);
//    Matrix m2 = m1.rotz(theta);
//    this.x = m2.data[0];
//    this.y = m2.data[1];
//    this.z = m2.data[2];
//  }

/*  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public Vector rotz_copy(double theta)                              // Rotate around Z and copy.
  {                                                                  //
Vector v = new Vector();
Matrix m1 = new Matrix(this);
Matrix m2 = m1.rotz(theta);
v.x = m2.data[0];
v.y = m2.data[1];
v.z = m2.data[2];
return (v);
  }*/

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public String strFrmt()                                            // Print Vector in a +8.2f
  {                                                                  // format.
    String frmt = "%+8.2f";
    String s = strFrmt(frmt);
    return (s);
  }

  public String strFrmt(String frmt)                                 // Print Vector in specified
  {                                                                  // format.
    String s = "\n";
    s += String.format(frmt, this.x);
    s += String.format(frmt, this.y);
    s += String.format(frmt, this.z);
    return (s);
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public static Vector add(Vector A, Vector B)                       // Vector Add.
  {                                                                  //
    Vector C = new Vector();
    C.x = A.x + B.x;
    C.x = A.y + B.y;
    C.x = A.z + B.z;
    return C;
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public static Vector sub(Vector A, Vector B)                       // Vector Subtract.
  {                                                                  //
    Vector C = new Vector();
    C.x = A.x - B.x;
    C.x = A.y - B.y;
    C.x = A.z - B.z;
    return C;
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public static double dot(Vector A, Vector B)                       // Vector dot product.
  {                                                                  //
    double sum = 0.0;
    sum += A.x * B.x;
    sum += A.y * B.y;
    sum += A.z * B.z;
    return sum;
  }

//  //---------------------------------------UNCLASSIFIED--------------//---------------------------
//  public static Vector cross(Vector A, Vector B)                     // Matrix cross product.
//  {                                                                  //
//    Matrix ma = new Matrix(A);
//    Matrix mb = new Matrix(B);
//    Matrix mc = Matrix.cross(ma, mb);
//    Vector v = new Vector();
//    v.x = mc.data[0];
//    v.y = mc.data[1];
//    v.z = mc.data[2];
//    return (v);
//  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public double lat()                                                //
  {                                                                  //
    double hyp = this.mag();
    double res = Math.atan(this.z / hyp);
    return (res);
  }

  //---------------------------------------UNCLASSIFIED--------------//---------------------------
  public double lon()                                                //
  {                                                                  //
    double res = Math.atan2(this.y, this.x);
    return (res);
  }

  //---------------------------------------UNCLASSIFIED-------------------------------------------
  // main
  //----------------------------------------------------------------------------------------------
  public static void main(String[] args)
  {
    //    Vector A = new Vector(3, 1);
    //    A.set(0, 0, 0.1);
    //    A.set(1, 0, 0.2);
    //    A.set(2, 0, 0.3);
    //    DEBUG.MESSAGEF(" Test A %s\n", A.strFrmt());
    //
    //    Vector B = new Vector(1, 3);
    //    B.set(0, 0, 0.1);
    //    B.set(0, 1, 0.2);
    //    B.set(0, 2, 0.3);
    //    DEBUG.MESSAGEF(" Test B %s\n", B.strFrmt());
    //
    //    Vector C = new Vector(3, 3);
    //    C.identity();
    //    DEBUG.MESSAGEF(" Test C %s\n", C.strFrmt());
    //
    //    Vector D = A.rotx(.707);
    //    DEBUG.MESSAGEF(" Test D %s\n", D.strFrmt());
    //
    //    double[][] R =
    //    {
    //        { 0, 1, 2, 3 },
    //        { 3, 2, 1, 0 } };
    //    DEBUG.MESSAGEF(" Test R.length %d\n", R.length);
    //    DEBUG.MESSAGEF(" Test R.length %d\n", R[0].length);
    //
    //    Vector E = new Vector(3, 2);
    //    E.set(0, 0, 0.1);
    //    E.set(1, 0, 0.2);
    //    E.set(2, 0, 0.3);
    //    E.set(0, 1, 0.4);
    //    E.set(1, 1, 0.5);
    //    E.set(2, 1, 0.6);
    //    Vector F = E.transpose();
    //    DEBUG.MESSAGEF(" Test E %s\n", E.strFrmt());
    //    DEBUG.MESSAGEF(" Test F %s\n", F.strFrmt());

    DEBUG.MESSAGE(" DONE \n");
  }

}