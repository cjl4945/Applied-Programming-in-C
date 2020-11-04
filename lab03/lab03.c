#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {  
   char *someText; 

   /* allocate memory dynamically */
   someText = malloc( 30 * sizeof(char) );
	
   if( someText == NULL ) {
      fprintf(stderr, "Error - unable to allocate memory!\n");
   } else {
      strcpy( someText, "CMPE380 lab malloc().");
   }
	
   /* you want to store larger text */
   someText = realloc( someText, 100 * sizeof(char) );
	
   if( someText == NULL ) {
      fprintf(stderr, "Error - unable to allocate additional memory!\n");
   } else {
      strcat( someText, "\nRealloc() Successful");
   }
 
   printf("Result: %s\n", someText );

   /* release memory using free() function */
   free(someText);
   someText=NULL;
}