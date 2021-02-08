/* Convert an integer into a string by calling a recursive routine */
#include <stdio.h>
#include <stdlib.h>

void my_itoa(int num, char* str);

int main()
{
	int num;

	printf("\nEnter a # to convert to a string.");
	scanf("%d", &num);
	/* this gets the length of the int */
	int length = snprintf(NULL, 0, "%d", num);
	printf("\nYou entered: %d -- which has a length of %d", num, length);
	char* str = malloc(length + 1);
	my_itoa(num, str);
	printf("\nAfter conversion %d == [%s]", num, str);

}

/* my_itoa converts an int to a string using recursion */
void my_itoa(int num, char* str)
{
	if(num > 9)
	{
		my_itoa(num/10, str);
		while(*str != '\0')
			str++;
		*str++ = num % 10 + '0';
		*str = '\0';
	}
	else
	{
		*str++ = num % 10 + '0';
		*str = '\0';
	}
}
