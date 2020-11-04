#include "Timers.h"

#ifdef EN_TIME
	#define REPEAT 100000000L
#else
	#define REPEAT 1
#endif

int main()
{
	#ifdef EN_TIME
		DECLARE_TIMER(myTimer);
		START_TIMER(myTimer);
	#endif
	
	long long int c=REPEAT;	
	double r = 2500, area;
	while (c--)
	{			
		area = 3.14 * r * r;		
	}
	
	#ifdef EN_TIME
		STOP_TIMER(myTimer);
		PRINT_TIMER(myTimer);		
	#endif
	printf("Calculated area (%lf) %lld times\n", area, (long long int)REPEAT);
}