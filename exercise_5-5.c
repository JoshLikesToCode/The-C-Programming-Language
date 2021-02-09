/* Write versions of the library functions strncpy and strncmp,
 * which operate on at most the first n characters of their arguement strings.
 * For example, strncpy(s,t,n) copies at most the n characters of t to s. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT 512

int strend(char *s, char* t);
/* strncpy(s,t,n) copies at most n characters of t to s */
char* my_strncpy(char* s, char* t, int n);
/* strcmp(s,t,n) compares at most n characters of t to s, and returns 0 if they're identical
 * and returns value < 0 if s is less than t and returns value > 0 if t is less than s */
int my_strcmp(char* s, char* t, int n);

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
	printf("%s\n", my_strncpy(string1, string2, 3));
	int ret = my_strcmp(string1, string2, 3);

	if(ret < 0)
		printf("string1 is less than string2\n");
	else if(ret > 0)
		printf("string1 is more than string2\n");
	else
	{
		printf("The strings are equal\n");
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

/* strncpy(s,t,n) copies at most n characters of t to s */
char* my_strncpy(char* s, char* t, int n)
{
	int length = strlen(s) + n + 1;

	char* copy = malloc(length * sizeof(char*));

	/* copy s into copy */
	int i = 0;
	while(s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	/* Copy n characters of t to copy */
	for(int k = 0; k < n; k++)
	{
		copy[i] = t[k];
		i++;
	}
	copy[i] = '\0';

	return copy;
}

/* strcmp(s,t,n) compares at most n characters of t to s, and returns 0 if they're identical
 * and returns value < 0 if s is less than t and returns value > 0 if t is less than s */
int my_strcmp(char* s, char* t, int n)
{
	int s_is_more = 0, t_is_more = 0;
	for(int i = 0; i < n; i++)
	{
		s_is_more += s[i] + '0';
		t_is_more += t[i] + '0';
	}

	if(s_is_more > t_is_more)
	{
		return -1;
	}
	else if(s_is_more < t_is_more)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

