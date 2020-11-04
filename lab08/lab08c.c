/*  Example: Simple code timing,  Uses Conditional Compilation EN_TIME */
#include <stdio.h>
#include <time.h>

#ifdef EN_TIME
	#define REPEAT 10000000L
#else
	#define REPEAT 1
#endif

int main () {
	int 		A, B, C;
	long 		Index;
	#ifdef EN_TIME
		clock_t 	StartTime, StopTime, ElapsedTime;
	#endif

	/* Initialize Variables */
	A=15; B=3;

	/* Timing starts */
	#ifdef EN_TIME
		StartTime = clock();
	#endif


	for (Index = 0; Index < REPEAT; Index++) {
		C=A*A/B;
	}
	#ifdef EN_TIME
		StopTime = clock();
		ElapsedTime=  StopTime - StartTime;
	#endif
  
	/* Timing ends */
	/* Show Results */
	#ifdef EN_TIME
		printf ("Operation %d=%d^2/%d repeated %ld times\n",C,A,B,REPEAT);
	#else
		printf ("Operation %d=%d^2/%d repeated %d times\n",C,A,B,REPEAT);
	#endif
		printf ("** CLOCKS_PER_SEC  is %ld ticks/sec\n", CLOCKS_PER_SEC);
	#ifdef EN_TIME
		printf ("** Size of clock_t is %d bytes\n", (int) sizeof(clock_t));
		printf ("   Total Time = %ld \"clocks ticks\"\n", ElapsedTime);
		printf ("   Total Time = %f [sec]\n", (double) ElapsedTime / (double) CLOCKS_PER_SEC);
		printf ("   Time per Iteration=%4.2g [sec]\n", 
                                          (double) ElapsedTime / (double) CLOCKS_PER_SEC/REPEAT);
	#endif
return 0;
}

