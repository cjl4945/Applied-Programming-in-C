#include <stdio.h>

//my simple macro
#define MULTIPLY(n) ((n) * 5)

int main(int argc, char *argv[])
{
	int n = 5;
	int m = MULTIPLY(n + 5);
	printf("MULTIPLY: %d\n", m);
}
