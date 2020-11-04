/* leak.c */
#include <stdio.h>
#include <stdlib.h>
int main() {
   char *p;
   p = (char *) malloc(19); /* Allocation #1 of 19 bytes, line 6*/
   free(p);
   p = (char *) malloc(12); /* Allocation #2 of 12 bytes, line 7*/
   free(p);		     /* No null, using p again */
   p = (char *) malloc(16); /* Allocation #3 of 16 bytes, line 9*/
   free(p);
   return 0;
}

