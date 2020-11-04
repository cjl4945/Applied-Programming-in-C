/****************************************************************************
 09/09/2019 R. Repka    Minor formatting changes
****************************************************************************/
#include <stdio.h> 
int main() 
{ 	
   short int si = 1;
   unsigned short int usi = 2;
   unsigned int ui = 3;
   int i = 4;
   long int li = 5;
   unsigned long int uli = 6;
   long long int lli = 7;
   unsigned long long int ulli = 8;
   signed char sc = (char)56;
   unsigned char uc = (char)57;
   float f = 11;
   double d = 12;
   long double ld = 13;  
    
   printf("Value: %hd, Size: %ld bytes\n", si,sizeof(short int)); 
   printf("Value: %hu, Size: %ld bytes\n", usi,sizeof(unsigned short int)); 
   printf("Value: %u, Size: %ld bytes\n", ui,sizeof(unsigned int)); 
   printf("Value: %d, Size: %ld bytes\n", i,sizeof(int)); 
   printf("Value: %ld, Size: %ld bytes\n", li,sizeof(long int)); 
   printf("Value: %lu, Size: %ld bytes\n", uli,sizeof(unsigned long int)); 
   printf("Value: %lld, Size: %ld bytes\n", lli,sizeof(long long int)); 
   printf("Value: %llu, Size: %ld bytes\n", ulli,sizeof(unsigned long long int)); 
   printf("Value: %c, Size: %ld bytes\n", sc,sizeof(signed char)); 
   printf("Value: %c, Size: %ld bytes\n", uc,sizeof(unsigned char)); 
   printf("Value: %f, Size: %ld bytes\n", f,sizeof(float)); 
   printf("Value: %lf, Size: %ld bytes\n", d,sizeof(double)); 
   
   /* Long double requires L not l */
   printf("Value: %Lf, Size: %ld bytes\n", ld,sizeof(long double)); 	
  
    return 0; 
} 