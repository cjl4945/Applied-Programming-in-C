#include <stdio.h>
#include "myFunctions.h"

/* main program*/
int main() {
	int i;  
	myPrint(); // call myPrint() from the header file
  
	//Print fibonacci numbers for [0-10]
	for (i=0;i<=10;i++)	
		printf("MyFib(%d):%d\n", i, myFib(i));
  
	return(0);
}