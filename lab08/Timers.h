#include <time.h>
#include <unistd.h>
#include <stdio.h>

#define DECLARE_TIMER(A)                                             \
    struct timmerDetails {                                           \
      /* Start Time - set when the timer is started */               \
      clock_t Start;                                                 \
      /* Stop Time - set when the timer is stopped */                \
      clock_t Stop;                                                  \
      /* Elapsed Time - Accumulated when the timer is stopped */     \
      clock_t Elapsed;                                               \
      /* Timer State - Set automatically: 0=stopped / 1=running */   \
      int State;                                                     \
    } A = { /* Elapsed Time and State must be initialized to zero */ \
      /* Start   = */ 0,                                             \
      /* Stop    = */ 0,                                             \
      /* Elapsed = */ 0,                                             \
      /* State   = */ 0,                                             \
    } /* Timer has been declared and defined */						 \


#define START_TIMER(A)                                               \
    {                                                                \
     /* It is an error if the timer is currently running */          \
     if (1 == A.State)  {                                            \
       fprintf(stderr, "Error, running timer "#A" started.\n");      \
       }                                                             \
     /* Set the state to running */                                  \
     A.State = 1;                                                    \
     /* Set the start time, done last to maximize accuracy */        \
     A.Start = clock();                                              \
    } /* START_TIMER() */                                            \


#define RESET_TIMER(A)                                               \
    {                                                                \
     /* Reset the elapsed time to zero */                            \
     A.Elapsed = 0;                                                  \
    } /* RESET_TIMER() */                                            \


#define STOP_TIMER(A)                                                \
    {                                                                \
     /* Set the stop time, done first to maximize accuracy */        \
     A.Stop = clock();                                               \
     /* It is an error if the timer is currently stopped */          \
     if (0 == A.State) {                                             \
       fprintf(stderr, "Error, stopped timer "#A" stopped again.\n");\
     }                                                               \
     else {/*accumulate running total only if previously running */  \
		A.Elapsed += A.Stop - A.Start;                               \
     }                                                               \
     /* Set the state to stopped */                                  \
     A.State = 0;                                                    \
    } /* STOP_TIMER() */                                             \
	
#define PRINT_TIMER(A)                                               \
    {                                                                \
     /* Stop the timer (silently) if it is currently running */      \
     if (1==A.State)  {                                            \
       STOP_TIMER(A);    /* no error possible in this case */        \
       }                                                             \
     fprintf(stderr, "Elapsed CPU Time ("#A") = %g sec.\n",          \
                     (double)A.Elapsed / (double)CLOCKS_PER_SEC);    \
    } /*PRINT_TIMER() */
