#include<stdio.h>
#include <stdlib.h>	/* for calloc and malloc */

typedef double MatElement;

/* free matrix*/
void free_all_matrix (MatElement **A) {
	free(A[0]);  /* free array of elements     */
	A[0] = NULL;
	free(A); 	   /* free array of ptrs to rows */
	A = NULL;
}

/* Dynamically Allocated Arrays */  
int main() {    
	
	int i,j; /* row index counter    */
	int nr=3,nc=5; /* # rows and # columns */ 		 

	MatElement **A = NULL; /* declare 2D matrix A */ 
	MatElement *ptr = NULL;  /* pointer to rows      */

	/* Allocate space for array of pointers */
	A = malloc( nr * sizeof(MatElement *));
   
	/* Allocate all matrix at once */
	ptr = calloc( nr * nc , sizeof(MatElement));
	/* Set array of row pointers properly */
	for (i=0;i<nr;i++)
		A[i] = ptr + nc*i; 
	
	for (i=0; i<3; i++) /* Initialize to random */
		for (j=0; j<5; j++)
			A[i][j] = rand() % 100; //0-99

	
	for (i=0; i<nr; i++){ /* print */
		for (j=0; j<nc; j++){
			printf("%f\t", A[i][j]);
		}
		printf("\n");
	}
	/*free mem*/	
	free_all_matrix(A);

  return 0;
}