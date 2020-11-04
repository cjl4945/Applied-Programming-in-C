/* Example: Simple code timing1.c */
#include <stdio.h>
#include <time.h>
#define REPEAT 10000000L
int main () {
  int 	A, B, C;
  long 	Index;
  clock_t 	StartTime, StopTime, ElapsedTime;
  A=15; B=3;       			/* Initialize Variables */
  StartTime = clock();	/* Timing starts */
     for (Index = 0; Index < REPEAT; Index++) { C=A*A/B; }
       StopTime = clock();
  ElapsedTime=  StopTime - StartTime; 	/* Timing ends */




/* Show Results */
  printf ("Operation %d=%d^2/%d repeated %ld times\n",C,A,B,REPEAT);
  printf ("** CLOCKS_PER_SEC  is %d ticks/sec\n", CLOCKS_PER_SEC);
  printf ("** Size of clock_t is %d bytes\n", (int) sizeof(clock_t));
  printf ("   Total Time = %ld \"clocks ticks\"\n", ElapsedTime);
  printf ("   Total Time = %f [sec]\n", (double) ElapsedTime / (double) CLOCKS_PER_SEC);
  printf ("   Time per Iteration=%4.2g [sec]\n", (double)ElapsedTime/(double)CLOCKS_PER_SEC/REPEAT);
return 0; }
