/*
 ============================================================================
 Name        : xcc.c
 Author      : Paul T. Bergman
 Version     :
 Copyright   : Do the Right Thing.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <xcc.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
   printf("This size of RFLT32 is %lld\n",sizeof(RFLT32) );
   printf("This size of RFLT64 is %lld\n",sizeof(RFLT64) );
   printf("This size of RINT08 is %lld\n",sizeof(RINT08) );
   printf("This size of RINT16 is %lld\n",sizeof(RINT16) );
   printf("This size of RINT64 is %lld\n",sizeof(RINT32) );
   printf("This size of RINT64 is %lld\n",sizeof(RINT64) );
   printf("This size of RXNT08 is %lld\n",sizeof(RXNT08) );
   printf("This size of RXNT16 is %lld\n",sizeof(RXNT16) );
   printf("This size of RXNT64 is %lld\n",sizeof(RXNT32) );
   printf("This size of RXNT64 is %lld\n",sizeof(RXNT64) );
   printf("FOLLOWING MAY NOT BE DEFINED.\n");
   printf("This size of RFLT128 is %lld\n",sizeof(RFLT128) );
	return EXIT_SUCCESS;
}
