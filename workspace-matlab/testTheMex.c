#include "mex.h"
#include "matrix.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) 
{
  printf("The number of  Left Hand Statements is %d\n",nlhs);
  printf("The number of Right Hand Statements is %d\n",nrhs);
}
// Use Add-Ons in MATLAB to install MATLAB Support for MinGW-w64 C/C++/FORTRAN Compiler.
//
// Use Code snippet about to test.
//
// For Eclipse to work you need to include the MinGW "bin" directory in environment variable "PATH."
// C:\ProgramData\MATLAB\SupportPackages\R2026a\3P.instrset\mingw_w64.instrset\bin
// in this case.