#include <stdio.h>

#define f1()	\
      {	int var1 = 10;\
	printf("var1 in f1: %d\n", var1);\
      }

void f2()
{
	int var1 = 5;
	printf("var1 in f2: %d\n", var1);
	f1();
}

int main()
{
	f2();
}
