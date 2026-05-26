"""
#-------------------------------------------UNCLASSIFIED------------------------------------------
#  File: xpy.UNIVERSE.py
#
#  Desc: A class for UNIVERSE stuff
#
#  Hist: When       Who  What
#        05/07/2026 ptb  Initial Code.
#-------------------------------------------------------------------------------------------------
"""
import time

from xpy.GEOCENTRIC import GEOCENTRIC


class TIME(GEOCENTRIC):
  """---------------------------------------------------------------------------------------------
  A TIME class.
  """

  def __init__(self):
    """
    """
  # end-df
# end-classd


def current1970Seconds():
  """---------------------------------------------------------------------------------------------
  Return the current time in 1970 epoch seconds.
  """
  sec = time.time();
  return (sec)

# end-def


if __name__ == "__main__":
    """-------------------------------------------------------------------------------------------
    """
    print("Current 1970 seconds is %f\n" % current1970Seconds())
