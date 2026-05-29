"""
#-------------------------------------------UNCLASSIFIED------------------------------------------
#  File: xpy.GEOCENTRIC.py
#
#  Desc: A class for GEOCENTRIC stuff
#
#  Hist: When       Who  What
#        05/07/2026 ptb  Initial Code.
#-------------------------------------------------------------------------------------------------
"""
from xpy.HELIOCENTRIC import HELIOCENTRIC
from math import sin;
from math import cos;


def sph2cart(az,elev,r):
   """--------------------------------------------------------------------------------------------
   Spherical to Cartesian. 
   """
   print(az)
   print(elev)
   print(r)
   z = r * sin(elev);
   rcoselev = r * cos(elev);
   x = rcoselev * cos(az);
   y = rcoselev * sin(az);
   
   x_y_z = (x,y,z);
   return(x_y_z);

class GEOCENTRIC(HELIOCENTRIC):
   """--------------------------------------------------------------------------------------------
   A GEOCENTRIC class.
   """
   
   def __init__(self):
      """
      """
      
      # end-def
   # end-class
   
   
if __name__ == "__main__":
   """--------------------------------------------------------------------------------------------
   """
