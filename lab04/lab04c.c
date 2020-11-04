
 # include <stdlib.h>
 char * allocate_memory () ;

 int main (int argc , char * argv []) {
	char * buffer = allocate_memory () ;
	buffer [0] = 0;
	return 0;
 }

 /*
 * Returns a pointer to newly allocated memory .
 */
 char * allocate_memory () {
	char * memory = (char *) malloc (sizeof (char) * 10); 
	return memory ;
}