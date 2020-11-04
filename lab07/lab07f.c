#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

/* counts # of chars in a given string*/
int charCount(char *str)
{
	if ((*str) == '\0') return 0;
	return charCount(str + 1) + (1);
}

int main()
{
	char *str1 = "Hi", *str2 = "Hello";
	int minCharCount = MIN(charCount(str1), charCount(str2));
	printf("Minimum char count of(%s, %s): %d\n", str1, str2, minCharCount);
}