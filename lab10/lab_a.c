/*-----------------------------------------------------------------------
  Simple program to dump IEEE single precision floating point numbers
  student copy
-----------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGN_MASK	0x80000000
#define SIGN_SHIFT      31  
#define EXPONENT_MASK   0x7F800000  
#define EXPONENT_SHIFT	23    
#define EXPONENT_BIAS   127  
#define SIGNIFICAND_MASK  0x007FFFFF

void ieeePrint(float fnum);

int main(int argc, char * argv[]) {
   
      // Must have a number
   if (2 == argc) {
      ieeePrint(atof(argv[1]));
   }
   else {
      printf("This decodes IEEE single precision numbers\n");
      printf("Error: Syntax is: %s number\n", argv[0]);
   }

   return(0);
}


void ieeePrint(float fnum) {
   int sign, exponent, significand;
   
   // We require a union because won't let us mask floating point
   union Ieee{
	float fnum;
	int num;

   }ieee;
   ieee.fnum = fnum;	
   sign = ieee.num & SIGN_MASK;	
   sign = sign >> SIGN_SHIFT;
   exponent = ieee.num & EXPONENT_MASK;
   exponent = exponent >> EXPONENT_SHIFT;
   exponent = exponent - EXPONENT_BIAS;
   significand = ieee.num & SIGNIFICAND_MASK;
   significand = significand << 1;
   // Break the floating point item into the proper parts

   
   printf("Number %f => Bin sign:%d Dec exponent:%d  Hex significant: .%x\n", ieee.fnum, sign, exponent, significand);
   return;
}

