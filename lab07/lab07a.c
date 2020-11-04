#include<stdio.h>
#define MACRO1(N)                               \
    { int i ## N, sum = 0;                      \
      for(i ## N=0; i ## N < N; i ## N++) {   \
        sum += (i ## N * i ## N * i ## N);      \
      printf("%d\n",sum);                                 \
    } /* End for */ } /* End macro */

int main() {
   /* The looping variable will be _t_20  */
   MACRO1(3);
}
