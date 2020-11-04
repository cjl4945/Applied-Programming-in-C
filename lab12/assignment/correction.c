/******************************************************************
 * Program to correct the data for the sensor
 * Note: Each student gets unique data, so this exact equation will
 * differ for each students solution
 * Be sure to use Honer's factorization  
 * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Runs the data through the fitting line */



#define ROUND(x) (x>=0?(int)(x+0.5):(int)(x-0.5))
int main(int argc, char *argv[])
{
    int res, real, ideal;
    
    double a = 0.0000644619;
    double b = 1.32088; 
    double c = 34.5329;


    int x = 0;
 
    while(scanf("%d %d", &ideal, &real) != EOF)
    {
     /* Insert your polynomial here, be sure to round properly */
        res = ( -(a * x*x) + (b * x) - c );
        real = real - (int) round(res);

        printf("%d %d\n", ideal, real);
        x ++;
				 
	
    }
    return 0;
}
