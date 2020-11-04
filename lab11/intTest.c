/**************************************************************************
  intTest.c - for students
  This program demonstrates the speed advantages of integer versus floating
  point math.
 12/28/2015 - R. Repka  Initial version
 10/12/2016 - R. Repka  Switched to PRINT_RTIMER() macro
 03/25/2018 - R. Repka  Switched to timing macros 
**************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ClassErrors.h"
#include "rootfinding.h"
#include "Timers.h"

/****************************************************************************
  Use this to define the number of iterations in your performance measurements
  ----------- You will need to adjust this number  --------
****************************************************************************/
#define ITERATIONS   (50000)

/* Optional verbose flag, compile with -DVERBOSE or not */
#ifdef VERBOSE
   #undef VERBOSE 
   #define VERBOSE (1)
#else 
   #define VERBOSE (0)
#endif

/****************************************************************************
  Remember to set the QN value in rootfinding.h
****************************************************************************/

/************************************************************************
   Simple code to test Qn performance vs floating point  
************************************************************************/
int main(int argc, char* argv[])
    {
    double Result;          /* The result from floating point calculation   */
    long  iResult;          /* The result from floating point calculation   */
    
    /* The bisection guesses and tolerance value                        */
    double a = -25.0;
    double b = 25.0;
    double tol= 0.000001;

    /* You many need to modify the timing code for your macro implementation! */
    DECLARE_TIMER(timer);
    DECLARE_REPEAT_VAR(tloop)

    /************************************************************************
     Run the Qn format test 
    ************************************************************************/
    /* You many need to modify the timing code for your macro implementation! */
    START_TIMER(timer);
    BEGIN_REPEAT_TIMING(ITERATIONS,tloop)
         iResult = ibisection(&iPoly, FLOAT_TO_FIX(a),FLOAT_TO_FIX(b),FLOAT_TO_FIX(tol),VERBOSE);
    END_REPEAT_TIMING
    STOP_TIMER(timer);

    if(iNAN == iResult)
        {
        fprintf(stderr, "Qn %d bisection couldn't find a root. \n", QN);
        exit(99);
        }
    else
        {
        fprintf(stderr, "Found the root %f using Qn %d bisection.\n",
                        FIX_TO_FLOAT(iResult ), QN);
        }      
    PRINT_TIMER(timer);
    PRINT_RTIMER(timer, ITERATIONS);

    /************************************************************************
     Run the floating point format test 
    ************************************************************************/
    RESET_TIMER(timer);
    START_TIMER(timer);
    BEGIN_REPEAT_TIMING(ITERATIONS,tloop)
        Result = bisection(&rPoly,a,b,tol,VERBOSE);
    END_REPEAT_TIMING
    STOP_TIMER(timer);

    if(NAN == Result)
        {
        fprintf(stderr, "Float bisection couldn't find a root. \n");
        exit(99);
        }
    else
        {
        fprintf(stderr, "Found the root %f using float bisection.\n",
                        Result);
        }

    PRINT_TIMER(timer);
    PRINT_RTIMER(timer, ITERATIONS);
    
    /* Display the percentage error */
    printf("%f\n",FIX_TO_FLOAT(iResult));
    Result = fabs( (FIX_TO_FLOAT(iResult)-Result) / Result) * 100;
    fprintf(stderr, "Qn %d error= %f\n", QN, Result);
    return 0;
    } /* End main */   
    
    

/******************************************************************************
 Purpose: Finds a root of scalar, non-linear function f using the integer 
 bisection  method. a and b make up the initial bracket to start bisecting from.
 Only implement this after you have the floating point function implemented
 
 Where: ifunc1arg f - INTEGER function whose root is to be determined
                      must take a single argument of type long and return
        long a      - initial Qn root bracket guess
        long b      - initial Qn root bracket guess
        long atol   - absolute Qn error termination tolerance,
        int verb    - verbose flag, 1 = TRUE, 0 = FALSE
        
Returns: long - the root refined to the desired tolerance or NAN
Errors:  prints a message and returns with NAN                 
******************************************************************************/
long ibisection(ifunc1arg f, long a, long b, long atol, int verb)
{
    int MaxItter = 10000;
    int ItterCnt = 0;

    while (ItterCnt < MaxItter) {
        long mid = Qn_DIVIDE( (a + b), FLOAT_TO_FIX(2.0));
        long fb = f( b );
        long fmid = f(mid);

        if (verb) {
            printf("iter:%d | a:%f | b:%f | x:%f | err:%f \n",
                   ItterCnt,
                   FIX_TO_FLOAT(a),
                   FIX_TO_FLOAT(b),
                   FIX_TO_FLOAT(mid),
                   FIX_TO_FLOAT(Qn_DIVIDE((b - a), FLOAT_TO_FIX(2))));
        }
        //printf("fb = %f\nfmid = %f\n",FIX_TO_FLOAT(fb),FIX_TO_FLOAT(fmid));
        if (fb * fmid >= 0) {
            b = mid;
        } else {
            a = mid;
        }

        if ( b-a <= atol){
            return a;
        }

        ItterCnt += 1;
    }

    if (verb) {
        fprintf(stderr, "The root was not found within 10000 itterations\n");
    }
    return iNAN;
}
    
/*---------------------------------------------------------------------------
  This function implements the real polynomial equation to be solved.  
  
  Where:   double x - the value to evaluate
  Returns: double - the value of the function at the point
  Errors:  none
---------------------------------------------------------------------------*/
double rPoly(double x){
    // x**3-.0001x**2-676X+.0676
    return(x*(x*(x-.0001)-676.0)+.0676);
}


/*---------------------------------------------------------------------------
  This function implements the integer polynomial equation to be solved.  
  
  Where:    long x - the value to evaluate
  Returns: long - the value of the function at the point
  Errors:  none
---------------------------------------------------------------------------*/
long iPoly(long x){
    /* Implement return(x**3-.0001x**2-676X+.0676) as Qn code */
    //long one = x*x*x;
    //long two = x*x;
    //long three = x;
    // covert the coefficients to QN format
    long second = FLOAT_TO_FIX(.0001);
    long third = FLOAT_TO_FIX(676.0);
    long fourth = FLOAT_TO_FIX(.0676);
    //equation for x**3-.0001x**2-676X+.0676 in QN format
    long y = (x*x*x) - MUL_FIX(second,(x*x)) - MUL_FIX(third,x) + fourth;
    return(y);

}
