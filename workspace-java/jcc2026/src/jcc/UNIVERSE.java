package jcc;

public class UNIVERSE
{

	public final static double G = 6.67430e-11;      // m3 kg-1 s-2
	public final static double h = 6.62607015e-34;   // Joule * seconds
	public final static double C = 299792458.0;      // Meters / second
	public final static double e = 2.718281828459045;
	public final static double k = 1.380649e-23;
	public final static double DE2RA = Math.PI / 180.0;
	public final static double RA2DE = 180.0 / Math.PI;
	public final static double TWOPI = 2.0 * Math.PI;
	
	public static void help()
	{
		String helpStr = 
				  "public final static double G = 6.67430e-11;      // m3 kg-1 s-2\r\n"
				+ "public final static double h = 6.62607015e-34;   // Joule * seconds\r\n"
				+ "public final static double C = 299792458.0;      // Meters / second\r\n"
				+ "public final static double e = 2.718281828459045;\r\n"
				+ "public final static double k = 1.380649e-23;\r\n"
				+ "public final static double DE2RA = Math.PI / 180.0;\r\n"
				+ "public final static double RA2DE = 180.0 / Math.PI;\r\n"
				+ "public final static double TWOPI = 2.0 * Math.PI";
				System.out.printf(helpStr); 
	}

	public static void main(String[] args)
	{
		System.out.printf("Hello, Universe!\n");
		System.out.printf("The UNIVERSAL Gravitation Constant is %9.7g\n", G);
		System.out.printf("The Plank's Constant               is %9.7g\n", h);
		System.out.printf("The Speed of Light                 is %9.7g\n", C);
		System.out.printf("The Limit of Compound Interest     is %9.7g\n", e);
	}

}
