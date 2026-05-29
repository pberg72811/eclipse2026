#utf-8√
'''
#-------------------------------------------UNCLASSIFIED------------------------------------------
#  File: UNIVERSE.py
# 
#  Desc: A Base class for signals, both time series and frequency.
# 
#  Hist: When       Who  What
#        01/04/2019 ptb  Initial Code.
#-------------------------------------------------------------------------------------------------
'''

#--------------------------------------------------------------------#----------------------------
class UNIVERSE( ):                                                   #
	"""
	A Base class for UNIVERSE.
	"""
	#_fs:  dt.RINT64 = 0;                                               #
	#_ts:  dt.RFLT64 = 0.0;                                             #
	#_phs: dt.RFLT64 = 0.0;                                             #

	@staticmethod
	def helloThere():
		"""
		Hello, UNIVERSE.
		"""
		print("Hello, UNIVERSE.");
	
#-------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------
#-----------------------------------------UNCLASSIFIED---------------#----------------------------
if __name__ == '__main__':  
	import sys;
	from xpy.UNIVERSE import UNIVERSE as UNI
	pathList = sys.path;
	for item in pathList:
		print(item)
	UNIVERSE.helloThere();
	print(UNI.G);
#end-if