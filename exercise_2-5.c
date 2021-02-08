/* Write the function any(s1,s2) which returns the first location in the string s1 where any
*  char from string s2 occurs, or -1 if s1 contains no characters from s2. (The standard lib-
*  rary function strpbrk does the same job but returns a pointer to the location.) */
#include <stdio.h>
#define MAX_INPUT 100
#define NEWLINE '\n'

int any(char s1[], char s2[]);

int main()
{
	int c, i = 0;
	char buffer1[MAX_INPUT+2];
	char buffer2[MAX_INPUT+2];

	printf("\nPlease enter a string for buffer1[]\n");
	while((c = getchar()) != NEWLINE)
	{
		buffer1[i] = c;
		i++;
	}
	buffer1[i] = '\0';
	i = 0;			/* reset counter */
	printf("\nbuffer1[] = %s\n", buffer1);

        printf("\nPlease enter a string for buffer2[]\n");
        while((c = getchar()) != NEWLINE)
        {
                buffer2[i] = c;
                i++;
        }
        buffer2[i] = '\0';
        printf("\nbuffer2[] = %s\n", buffer2);

	printf("The location of the first char found in s1 from s2 is located at index: %d\n", any(buffer1, buffer2));
}

int any(char s1[], char s2[])
{
	int loc = -1;
	int i = 0, j = 0;

		do
		{
			if(s2[j] == s1[i])
				loc = i;
			if(s2[j] != s1[i])
				j++;
			if(s2[j] == '\0')
				j = 0;
			i++;
		} while(s1[i] != '\0');

	return loc;
}
