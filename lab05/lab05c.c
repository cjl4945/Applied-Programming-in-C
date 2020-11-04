/****************************************************************************
 09/09/2019 R. Repka    Minor formatting changes
****************************************************************************/

#include <stdio.h> 
#include <stdint.h> 
   
int main() 
{  
   union
   {
      float  real;
      unsigned int integer;
   } aNumber;
   aNumber.real = 3.1416F;
   aNumber.integer = 10U;
   printf("SizeOf(aNumber):%ld, aNumber.integer:%d\n", sizeof(aNumber), aNumber.integer);
   
   union 
   {
      uint16_t   number;   
      struct 
      {
         uint8_t high; 
         uint8_t low;
      } bytes; 
   } aUnion;
   aUnion.bytes.high= 1;
   aUnion.bytes.low = 2;
   printf("SizeOf(aUnion):%ld, aUnion.number:%d\n", sizeof(aUnion), aUnion.number);

  
    return 0; 
} 