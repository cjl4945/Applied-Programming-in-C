/***************************************************************************
  Student framework for root finding algorithms for bisection, newton, and secant.
   
  11/10/2015   R. Repka - Initial version
  12/28/2015 - R. Repka - added integer solution features
***************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ClassErrors.h"
#include "rootfinding.h"


/******************************************************************************
 Purpose: Finds a root of scalar, nonlinear function f using the bisection  
 method. a and b make up the initial bracket to start bisecting from.
 
 Where: func1arg f  - function whose root is to be determined
                      must take a single argument of type double and return
        double a    - initial root bracket guess
        double b    - initial root bracket guess
        double atol - absolute error termination tolerance,
        int verb    - verbose flag, 1 = TRUE, 0 = FALSE
        
Returns: double - the root refined to the desired tolerance or NAN
Errors:  prints a message and returns with NAN                    
******************************************************************************/
double bisection(func1arg f, double a, double b, double atol, int verb)
{
    int MaxItter = 10000;
    int ItterCnt = 0;

    while (ItterCnt < MaxItter) {
        double mid = (a + b) / 2;
        double fb = f(b);
        double fmid = f(mid);

        if (verb) {
            printf("iter:%d | a:%f | b:%f | x:%f | err:%f \n", ItterCnt, a, b, mid, (b - a)/2);
        }

        if (fb * fmid >= 0) {
            b = mid;
        } else {
            a = mid;
        }

        if (b - a <= atol){
            return a;
        }

        ItterCnt += 1;
    } 

    if (verb) {
        fprintf(stderr, "The root was not found within %i itterations\n"\
, MaxItter);
    }
    return NAN;
}


/******************************************************************************
 Purpose: Finds a root of function f using the newton method. x0 is the initial 
 guess,  df is the derivative of function f , Nmax is the maximum number
  of iterations, atol is the tolerance, and verb will turn a verbose print* out

  Where: func1arg f  - function whose root is to be determined
                       must take single argument of type double and return
                       single value of type double
         func1arg df - derivative of function whose root is to be determined
                       must take single argument of type double and return
                       single value of type double
         double x0   - initial guess for location of root
         int Nmax    - maximum number of iterations to achieve convergence
         double atol - absolute error convergence tolerance
         int verb    - verbose flag, 1 = TRUE, 0 = FALSE

Returns: double - the root refined to the desired tolerance or NAN
Errors:  prints a message and returns with NAN      
******************************************************************************/
double newton(func1arg f, func1arg df, double x0, int Nmax, double atol, int verb)
{
    double fun; // f(x)
    double der; // f'(x)
    double x1;  // x value as determine by newtons method

    int ItterCnt = 0;
    while (ItterCnt < Nmax) {
        fun = f(x0);
        der = df(x0);

        x1 = x0-fun/der;
       
        if (verb) {
            printf("iter:%d | x0:%f | x1:%f | err:%f \n", ItterCnt, x0, x1, (x1 - x0)/2);
        } 

        if (fabs(x1-x0) / fabs(x1) < atol) {
            return x0; 
        }
    

        x0 = x1;
        ItterCnt += 1;
    } // end while
 
    if (verb) {
        fprintf(stderr, "The root was not found within %d itterations\n", Nmax);
    }
    return NAN;
	
}


/******************************************************************************
 Purpose: Finds a root of function f using the secant method. x0 and x1 are 
 the two initial guesses used to find the first tangent.
 
 Where: func1arg f  - function whose root is to be determined
                       must take single argument of type double and return
                       single value of type double
         double x0   - initial guess for location of root
         double x1   - another initial guess for location of root
         int Nmax    - maximum number of iterations to achieve convergence
         double atol - absolute error convergence tolerance
         int verb    - verbose flag, 1 = TRUE, 0 = FALSE

Returns: double - the root refined to the desired tolerance or NAN
Errors:  prints a message and returns with NAN        
******************************************************************************/
double secant(func1arg f, double x0, double x1, int Nmax, double atol, int verb)
{
    /* Initial print if verbose option was given */
  if(1 == verb) {
    //fprintf(stdout,"Secant's Algorithm:\n");
   // fprintf(stdout,"iter\tx0\tx1\terr\n");
   // fprintf(stdout,"-------------------------------------------------------\n");
  } /* if */

  /* Variables for processing */
  double tmp; /* variable for switch */
  double f0, f1; /* f(x_n-1) and f(x_n) */
	int counter = 0;

  /* change values for f(x_n-1) and f(x_n) */
  f0 = f(x0);
  f1 = f(x1);

	/* Loop will only last Nmax times at most */
	while(counter < Nmax) {

		/* Give a lot of information if the verbose option was given */
		if(1 == verb) {
			printf("iter:%d | x0:%f | x1:%f | err:%f \n", counter, x0, x1, fabs(x1 - x0));
		} /* if */

    /* Assign next x1 using Secant's formula */
    tmp = x1 - f1 * ((x1 - x0) / (f1 - f0));

    x0 = x1;
    x1 = tmp;

    /* change values for f(x_n-1) and f(x_n) */
    f0 = f(x0);
    f1 = f(x1);

		/* Check if solution was found */
		if(fabs(x1 - x0) /* / fabs(x1) */ < atol) {
			/* show result if verbose flag was set */
			if(1 == verb) {
				fprintf(stdout, "Solution found at iteration %d: %f\n\n", counter, x1);
			} /* if */

			return x1;
		} /* if */

		/* next step */
		++counter;
	} /* while */

  /* return NAN if result wasn't found */
	return NAN;
}
