/* Write a pointer version of the function strcat that we showed in Chapter 2:
				strcat(s,t) copies the string t to the end of s */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT 512

void my_strcat(char *s, char* t);

int main()
{
	/* char* string1 = "Hello";
	char* string2 = " World!";
	while(*string1)
		printf("%c", *(string1++));
	while(*string2)
		printf("%c", *(string2++));
	printf("\n"); */

	int c, i = 0;
	char string1[MAX_INPUT];
	char string2[MAX_INPUT];

	while((c = getchar()) != '\n')
	{
		string1[i] = c;
		i++;
	}
	string1[i] = '\0';
	i = 0;
	while((c = getchar()) != '\n')
	{
		string2[i] = c;
		i++;
	}
	string2[i] = '\0';
	printf("%s\n", string1);
	printf("%s\n", string2);

	my_strcat(string1, string2);
	printf("combined string is: [%s]\n", string1);
}

/* copies the string t to the end of s */
void my_strcat(char* s, char* t)
{
	/* while *s is not equal to null terminator, then increment s */
	while('\0' != *s)
		++s;
	/* starting where we left off in s, make *s = *t while they're not equal to null
	   the null terminator								*/
	while('\0' != (*s = *t))
	{
		++s;
		++t;
	}
}
