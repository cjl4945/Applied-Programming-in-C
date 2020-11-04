#include <stdio.h>
#include "myFunctions.h"

/* Implementations of my functions*/

//my simple print 
void myPrint(void) {
	printf("CMPE380 Makefile Example!\n");
	return;
}

//my simple recursive fibonacci 
int myFib(int n) 
{ 
    if (n <= 1) 
        return n; 
    return myFib(n-1) + myFib(n-2); 
} 