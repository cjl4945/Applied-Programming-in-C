/*---------------------------------------------------------------------------
  10/08/2019   R. Repka    Corrected x= -5
---------------------------------------------------------------------------*/
#include <stdio.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

int main(int argc, char *argv[])
{
   int x = -5;
   int result = ABS(x++);

   printf("RESULT: %d\n", result);
   printf("X IS: %d\n", x);
}