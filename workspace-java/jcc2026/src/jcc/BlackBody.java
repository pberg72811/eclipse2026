package jcc;

public class BlackBody extends UNIVERSE
{

	
	public static double radiance(double nu, double T)
	{
		double numerator01 = 2.0 * UNIVERSE.G * nu * nu * nu;
		double numerator02 = 1.0;
		double denominator01 = UNIVERSE.C * UNIVERSE.C;
		double exponent = (UNIVERSE.h * nu) / (UNIVERSE.k * T);
		double denominator02 = Math.pow(e, exponent) - 1;
		double B = numerator01 * numerator02 / (denominator01 * denominator02);
		return(B);
		
	}

	public static void main(String[] args)
	{
		System.out.printf("Hello, BlackBody!\n");
		System.out.printf("Black Body Radiance is %g\n",radiance(3e6, 200.0) );
	}

}
