#include<stdio.h>
#include <stdlib.h>	/* for calloc and malloc */

typedef double MatElement;
void free_matrix_space(MatElement **A, int m);
/* Dynamically Allocated Arrays */  
int main() {    
	typedef double MatElement;
	int i,j; /* row index counter    */
	int nr=3,nc=5; /* # rows and # columns */ 		 

	MatElement **A = NULL; /* declare 2D matrix A */ 		

	/* Allocate space for array of pointers */
	A = malloc( nr * sizeof(MatElement *));
   
	/* Allocate space for matrix elements and set to zero */   
	for (i=0; i<nr; i++){ 
		A[i] = calloc(nc, sizeof(MatElement) );		
	}
	
	for (i=0; i<3; i++){ /* Initialize to random */
		for (j=0; j<5; j++)
			A[i][j] = rand() % 100; //0-99
	}
	
	for (i=0; i<nr; i++){ /* print */
		for (j=0; j<nc; j++){
			printf("%f\t", A[i][j]);
		}
		printf("\n");
	}
	free_matrix_space(A,nr);
	return 0;
}
	

void free_matrix_space(MatElement **A, int m) {
	int i;
	for (i=0; i<m; i++){
		free(A[i]);
		A[i] = NULL;
	}
	free(A);
	A = NULL;
}


