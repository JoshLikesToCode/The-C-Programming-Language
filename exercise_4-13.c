/* Write a recursive function for reverse(s) which reverses a string s in place */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 255
#define NEW_LINE '\n'
#define NULL_TERM '\0'

void swap(char *x, char* y);
void my_reverse(char* str, int index);

int main()
{
	int c, i = 0;
	char* buffer = malloc(MAX_LENGTH);

	printf("\nEnter your string to be reversed: ");

	while((c = getchar()) != NEW_LINE)
	{
		buffer[i] = c;
		i++;
	}
	buffer[i] = NULL_TERM;

	printf("\nThe string you entered was: %s", buffer);
	my_reverse(buffer, 0);
	printf("\nYour string reversed is: %s", buffer);
}

void my_reverse(char *str, int index)
{
	static i = 0;
	if(str[index] == NULL_TERM)
		return;

	my_reverse(str, index + 1);

	if(i <= index)
		swap(&str[i++], &str[index]);
}

void swap(char* x, char* y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}
