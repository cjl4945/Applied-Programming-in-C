/****************************************************************************
 09/09/2019 R. Repka    Minor formatting changes
****************************************************************************/

#include<string.h>
#include<stdio.h>

/* string example to illustrate string functions */  
int main() {    
  char str[256];
  int count = 0;
  printf("Enter 'q' or 'quit' to exit\n");
  do {
    printf("Enter a string:\t");
    scanf("%s",str);    
    
   //strcmp
   if (strcmp(str,"quit") == 0)
      break;   
   //strchr 
   if (strchr (str,'q') != NULL)
      break;
   
   if (strstr (str,"exit"))
      break;
   
   ++count;
  } while (1);
  
  printf("You entered:\t%d strings!\n", count);
}