/*---------------------------------------------------------------------------
  QN code testing and verification
  student copy
---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
#include <math.h>

#define LOOP_DELAY (1<<27)

// QN math functions which pass the number of bits "n" 
#define Qn_MULTIPLY(A,B,n) ((A>>(n/2))*(B >>(n-(n/2))))
#define Qn_DIVIDE(A,B,n) ((int) (((long int)(A)<<n)/(B) ))

// QN math and printing functions
void  printBinary(unsigned num, short N);
int  floatToFixed(double x, int n);
float fixedToFloat(int x, int n); 

/*---------------------------------------------------------------------------
  QN testing framework 
---------------------------------------------------------------------------*/
int main(int argc, char *argv[]) {
   // QN testing variables, add more as necessary
   double fnum1, fnum2, fnum3;
   int  qnum1, qnum2, qnum3, qnval;
   clock_t  time1, time2;
   unsigned i;
   
   //------------------------------------------------------------------------
   // Print data on sizes  
   //------------------------------------------------------------------------
   printf("Integers are %ld bits long\n", 8*sizeof(int));

   //------------------------------------------------------------------------
   // Prove floating point has limits 
   //------------------------------------------------------------------------
   double sum;
   double num = 10.0;
   sum = DBL_EPSILON + num;
   printf("Double Precision floating point number is '%e'\n",10.0);
   printf("Sum is '%e'", sum);
   if (sum == num){
	printf("Epsilon value '%e' didn't add\n",DBL_EPSILON);
   }
   else{
   	printf("The addition worked, the sum is '%e'\n", sum);
   }
   
   //------------------------------------------------------------------------
   // Examine the conversion utilities
   //------------------------------------------------------------------------
   printf("\nConversion test\n");
   qnum1 = floatToFixed(0.0,0);
   printf("Fixed point of '%f' is '%i'\n",0.0,qnum1);
   printf("Binary of %f is ",0.0 );
   printBinary(qnum1,16);
   fnum2 = fixedToFloat(qnum1,0);
   printf("Floating point of '%i' is '%f'\n\n\n\n",qnum1,fnum2); 
   
   qnum1 = floatToFixed(12.25,3);
   printf("Fixed point of '%f' is '%i'\n",12.25,qnum1);
   printf("Binary of %f is ",12.25 );
   printBinary(qnum1,16);
   fnum2 = fixedToFloat(qnum1,3);
   printf("Floating point of '%i' is '%f'\n\n\n\n",qnum1,fnum2); 

   qnum1 = floatToFixed(12.0625,3);
   printf("Fixed point of '%f' is '%i'\n",12.0625,qnum1);
   printf("Binary of %f is ",12.0625 );
   printBinary(qnum1,16);
   fnum2 = fixedToFloat(qnum1,3);
   printf("Floating point of '%i' is '%f'\n\n\n\n",qnum1,fnum2); 

   qnum1 = floatToFixed(12.0625,4);
   printf("Fixed point of '%f' is '%i'\n",12.0625,qnum1);
   printf("Binary of %f is ",12.0625 );
   printBinary(qnum1,16);
   fnum2 = fixedToFloat(qnum1,4);
   printf("Floating point of '%i' is '%f'\n\n\n\n",qnum1,fnum2); 

   
   //------------------------------------------------------------------------
   // Examine the division utilities
   //------------------------------------------------------------------------   
   printf("\nDivision test\n");
   qnum1 = floatToFixed(-.0625,18);
   qnum2 = floatToFixed(-.0625,18);
   //printf("%i", qnum2);
   fnum1 = -.0625;
   fnum2 = 1;
   //printf("fnum\tqnum(dec)\tqnum1 (float)\t qnum2 (float)\n");
   //printf("%f\t%i\t%f\t%f\n",fnum1,qnum1,-0.625,-0.625);
   printf("fnum1\t\tqnum1\t\tqnum2\t\tqnum(float)\n");
   while ( (qnum1 != 0) || (qnum2 != 0)){
	qnum1 = qnum1/2;
	qnum2 = Qn_DIVIDE(qnum2,floatToFixed(2.0,18),18);
	fnum1 = fnum1/2.0;
	fnum2 = fixedToFloat(qnum2,18);
   
   //printf("fnum1\t\tqnum1\t\tqnum2");
   printf("%f\t\t%i\t\t%i\t\t%f\n",fnum1,qnum1,qnum2,fnum2);
   //printf("qnum2: %i\n", qnum2);
   //printf("fnum2: %f\n", fnum1);
   //printf("Absoulte values:\n");
   //printf("fnum1\t\tqnum1\t\tqnum2"); 
   //printf("%f\t\t%i\t\t%i",abs(qnum1),abs(qnum2),fabs(fnum1));
   //printf("qnum1: %i\n", abs(qnum1));
   //printf("qnum2: %i\n", abs(qnum2));
   //printf("fnum2: %f\n", fabs(fnum1));
   }
   printf("Absoulte values:\n");
   printf("fnum1\t\tqnum1\t\tqnum2\t\tqnum(float)\n");
   qnum1 = floatToFixed(-.0625,18);
   qnum2 = floatToFixed(-.0625,18);
   fnum1 = -.0625;
   while ( (qnum1 != 0) || (qnum2 != 0)){
        qnum1 = qnum1/2;
        qnum2 = Qn_DIVIDE(qnum2,floatToFixed(2.0,18),18);
        fnum1 = fnum1/2.0;
        fnum2 = fixedToFloat(qnum2,18);    
   //printf("fnum1\t\tqnum1\t\tqnum2");
   printf("%f\t\t%i\t\t%i\t\t%f\n",fabs(fnum1),abs(qnum1),abs(qnum2),fabs(fnum2));
   }
   //printf("qnum2: %i\n", qnum2);
   //   //printf("fnum2: %f\n", fnum1);
   //      printf("Absoulte values:\n");  
   //         printf("fnum1\t\tqnum1\t\tqnum2");
   //            printf("%f\t\t%i\t\t%i",abs(qnum1),abs(qnum2),fabs(fnum1));
   //               //printf("qnum1: %i\n", abs(qnum1));
   //                  //printf("qnum2: %i\n", abs(qnum2));
   //                     //printf("fnum2: %f\n", fabs(fnum1));
   //                        }
   //
   //------------------------------------------------------------------------
   // Examine the multiplication utilities
   //------------------------------------------------------------------------   
   printf("\nMultiplication test\n");
   qnum1 = floatToFixed(64.125,18);
   qnum2 = floatToFixed(0.755,18);
   qnum3 = Qn_MULTIPLY(qnum1,qnum2,18);
   printf("%i x %i = %i\n", qnum1,qnum2,qnum3); 
   printf("64.125 x 0.755 = %f\n", 64.125*0.755); 
   
   float x = 1.0;
   float y = (x*(x*(x-.0001)-676.0)+.0676);
   printf("F(x) = x**3 ‐.0001x**2 ‐ 676X + .0676\n");
   printf("F(1) = %f\n",y);
   float ii = pow(x,3) - pow(x,(2/10000)) - (676*x) + (169/2500);
   printf("F(x) = x**3 ‐x**2/10000 ‐ 676X + 169/25\n");
   printf("F(1) = %f\n",ii);

   //------------------------------------------------------------------------
   // Implement floating point scientific equations two different ways
   // using normal fractions and using decimal fractions
   //------------------------------------------------------------------------


   printf("\nComplex calculations test\n");
   int z = floatToFixed(1,18);
   qnum1 = floatToFixed((z*(z*(z-.0001)-676.0)+.0676),18);
   printf("F(x) = x**3 ‐.0001x**2 ‐ 676X + .0676\n");
   printf("F(1) in Qn evaluation  = %i\n",qnum1);   



  // printf("\nComplex calculations test\n");

   
   //---------------------------------------------------------------------
   // Implement QN scientific equations: x**3-.0001x**2-676X+.0676
   //------------------------------------------------------------------------   
  
   // print all 3 answers

   
   //------------------------------------------------------------------------
   // Examine the performance 
   //------------------------------------------------------------------------
   printf("\nPerformance test\n");
   float n = 3.1415;
   float p = -674.9325;
   qnum1 = floatToFixed(n,18);
   qnum2 = floatToFixed(p,18);
   // Floating point addition
   time1 = clock();
   for(i = 0; i < LOOP_DELAY; i++) {
      float sum = n + p;

      // Insert your addition here
   }
   time1 = clock()-time1;
   
   // QN addition
   time2 = clock();
   for(i = 0; i < LOOP_DELAY; i++) {
      qnval = qnum1 + qnum2; 

      // Insert your addition here
   }
   time2 = clock()-time2;
   
   // Print out the clicks and who was faster
   printf("Float addition time: %ld\nQn addition time: %ld\n",time1,time2);
   if (time1 > time2){
      printf("Float addition was faster than the QN addition\n");
   }
   else{
      printf("QN addition was faster than the Float addition\n");
   }   
   // Floating multiplication
   time1 = clock();
   for(i = 0; i < LOOP_DELAY; i++) {
      sum = n * p; 


      // Insert your addition here
   }
   time1 = clock()-time1;
   
   // QN multiplication
   time2 = clock();
   for(i = 0; i < LOOP_DELAY; i++) {
      qnval = Qn_MULTIPLY(qnum1,qnum2,18);



      // Insert your addition here
   }
   time2 = clock()-time2;
   
   printf("Float multiplication time: %ld\nQn multiplication time: %ld\n",time1,time2);
   // Print out the clicks and who was faster
   if (time1 > time2){
      printf("Float multiplication was faster than the QN multiplication\n");
   }
   else{
      printf("QN multiplication was faster than the Float multiplication\n");
   }

   return(0);
}


/*---------------------------------------------------------------------------
  This prints a number in character binary bracketed by [..]
  
  Where: unsigned num - number to print
         short N      - number of bits to print
         
  Returns: nothing
  Error handling: none
----------------------------------------------------------------------------*/
void printBinary(unsigned num, short N) { 
   unsigned i; 
   printf("\t[");
   
   for (i = 1 << (N-1); i > 0; i = i >> 1) {
      (num & i)? printf("1"): printf("0");
    }        
   printf("]\n");
   return;
} 


/*---------------------------------------------------------------------------
  This convert from Float to FP(Qn) 
  
  Where: double x  - number to convert
         int qnval - number of bits to use
         
  Returns: int    - QN encoded number
  Error handling: none
----------------------------------------------------------------------------*/
int floatToFixed(double x, int qnval) { 
   return( x * (double)(1 << qnval) );            
} 

/*---------------------------------------------------------------------------
  This converts from FP(Qn) to Float
  
  Where: int x     - number to convert
         int qnval - number of bits to use
         
  Returns: float   - converted number
  Error handling: none
----------------------------------------------------------------------------*/
float fixedToFloat(int x, int qnval) { 
   return((double)x / (double) (1 << qnval));
}

