/* Write the function strend(s,t), which returns 1 if the string t occurs at the end 
*  string s, and zero otherwise								*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT 512

int strend(char *s, char* t);

int main()
{
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
	printf("Time to check if [%s] appears at the end of [%s].\n", string2, string1);

	if(strend(string1, string2) == 1)
	{
		printf("Yes, [%s] appears at the end of [%s]\n", string2, string1);
	}
	else
	{
		printf("No, [%s] does not appear at the end of [%s]\n", string2, string1);
	}
}

/* strend(s,t) returns 1 if the string t occurs at the end of s, and 0 otherwise */
int strend(char* s, char* t)
{
	s += strlen(s) - strlen(t);

	/* check if t length is greater than s, if so then this isn't a valid comparision */
	if(strlen(s) >= strlen(t))
	{
		if(0 == strcmp(s,t))
			return 1;
	}
	else
	{
		return 0;
	}
}
