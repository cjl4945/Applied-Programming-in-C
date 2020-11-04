/**************************************************************************
  quadTest.c - for the instructor
  This program demonstrates C99's complex support.
 
 12/22/2018 - R. Repka  Initial version
 03/27/2019 - R. Repka  b**2 typo
**************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <math.h>
#include </usr/include/complex.h>
#include "ClassErrors.h"
#include "rootfinding.h"


/************************************************************************
   Simple code to test complex support  
************************************************************************/
int main(int argc, char* argv[]){ 

  double a,b,c = 0;
  int rc;
   /* getopt_long stores the option index here. */
   int option_index = 0;
  
   /* This contains the short command line parameters list */
   char *getoptOptions = "v";    /* add lots of stuff here */
  
   /* This contains the long command line parameter list, it should mostly 
 *      match the short list                                                  */
   struct option long_options[] = {
      /* These options don’t set a flag.
 *          We distinguish them by their indices. */
      {"a",   required_argument,       0, 'a'},
      {"b",      required_argument,       0, 'b'},
      {"c",   required_argument,       0, 'c'},

   };
   opterr = 1;           /* Enable automatic error reporting */
   while ((rc = getopt_long_only(argc, argv, getoptOptions, long_options, &option_index)) != -1) {

      switch (rc)
    {

      case 'a':
        a = atof(optarg);
        break;
        
      case 'b':
        b = atof(optarg);
        break;

      case 'c':
        c = atof(optarg);
        break;  


        case '?':  /* Handled by the default error handler */
          break;

       default:
          printf ("Internal error: undefined option %0xX\n", rc);
          exit(PGM_INTERNAL_ERROR);
        }
  

                                                    }
  int nterm = 3;
  polynomial poly;
  initPoly(&poly,nterm);
  poly.polyCoef[2] = a;
  poly.polyCoef[1] = b;
  poly.polyCoef[0] = c;
  double complex *roots = malloc(2 * sizeof(double complex));
  MALLOC_DEBUG(roots);
  roots = quadraticRoots(&poly,roots);
  printf("The roots of; %fx**2 + %fx + %f", poly.polyCoef[2], poly.polyCoef[1],poly.polyCoef[0]);
  printf("Root1: %f/nRoot2: %f",roots[0], roots[1]);
  free(roots);
  freePoly(&poly);

} /* End main */


 /*---------------------------------------------------------------------------
  Returns the two roots from a quadratic polynomial
  
    =  -b +-sqrt(b**2-4ac)
       ----------------------
                 2a
  
  Where: polynomial *p      - Pointer to a 2nd order polynomial
  Returns: double complex* - A pointer to a complex root pair.
  Errors:  prints an error and exits
---------------------------------------------------------------------------*/
double complex* quadraticRoots(polynomial *p, double complex *rootList){

        double complex sqrt_term;
	double complex a = p->polyCoef[2];
	double complex b = p->polyCoef[1];
	double complex c = p->polyCoef[0];
	
	if(rootList == NULL) {
		fprintf(stderr, "Failed to allocate memory.\n");
		exit(MALLOC_ERROR);
	}

	if(p->nterms != 3) {
		fprintf(stderr, "Error: quadraticRoots() called using %d order polynomial\n"
				, p->nterms-1);
		exit(PGM_INTERNAL_ERROR);
	}

	sqrt_term = csqrt(cpow(b,2)- 4 * a * c);

	rootList[0] = ((-1 * b) + sqrt_term) / (2*a);
	rootList[1] = ((-1 * b) - sqrt_term) / (2*a);

	return rootList;



}


/*---------------------------------------------------------------------------
  Initializes a polynomial data structure with nterms to NAN.  
  This allocates storage   for the actual polynomial.
  
  Where: polynomial *p       - Pointer to polynomial data structure to create
         unsigned int nterms - The number of elements to create
  Returns: nothing
  Errors:  prints an error and exits
---------------------------------------------------------------------------*/
void initPoly(polynomial *p, unsigned int nterms){

        p->nterms = nterms;
	p->polyCoef = malloc(nterms*sizeof(double complex));
	MALLOC_DEBUG(p->polyCoef);
	if(p->polyCoef == NULL) {
		fprintf(stderr, "Failed to allocate memory for polynomial. File: %s Line: %d",
				__FILE__, __LINE__);
		exit(MALLOC_ERROR);
	}


}


/*---------------------------------------------------------------------------
  Destroys/frees a polynomial
  
  Where: polynomial *p - Pointer to polynomial data structure to destroy
  Returns: nothing
  Errors:  none
---------------------------------------------------------------------------*/
void freePoly(polynomial *p){

	p->nterms = 0;
	FREE_DEBUG(p->polyCoef);
	free(p->polyCoef);

}


