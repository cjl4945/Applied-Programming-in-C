/* Program compiles, no errors or warnings */
#include <stdlib.h>
#include <stdio.h>
int main(){
    int *num;  
	int arr[100]; //array for 100 integers
    
    for (int i = 0; i <= 99; i++) {	   
		/* random int between 0 and 99 */
		int r = rand() % 100;		
		num = malloc(sizeof(int)*2); //allocate mem		
		num[0] = r;
		arr[i] = num[0];
		free(num);
    }	
    printf("Last two random numbers are %d %d\n", arr[98], arr[99]);

return(0);
}
