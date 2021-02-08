/* Write an alternate version of squeeze(s1, s2) that deletes each char in s1 that matches
*  any char in string s2 */

/* Here's a reference for squeeze(s1, s2):
*  squeeze: delete all c from s
*
*  void squeeze(char s[], int c)
*  {
*	int i, j;
*
*	for(i = j = 0; s[i] != '\0'; i++)
*		if(s[i] != c)
*			s[j++] = s[i];
*	s[j] = '\0';
*  }
*******************************************/

#include <stdio.h>
#include <string.h>
#define MAX_INPUT 100

void squeeze(char string1[], char string2[]);

int main()
{
	int c, i = 0, j = 0;
	char s1[MAX_INPUT + 2], s2[MAX_INPUT + 2];
	printf("\nPlease enter string1\n");
	while((c = getchar()) != '\n')
	{
		s1[i] = c;
		i++;
	}
	s1[i] = '\0';
	/* test to see if above worked */
	printf("\ns1 = %s\n", s1);

        printf("\nPlease enter string2\n");
        while((c = getchar()) != '\n')
        {
                s2[j] = c;
                j++;
        }
	s2[j] = '\0';
        /* test to see if above worked */
        printf("\ns2 = %s\n", s2);

	printf("\nWe will now apply the squeeze function to remove any chars");
	printf(" found in string2 from string1\n");
	squeeze(s1, s2);
	printf("Squeeze(s1, s2) = %s\n", s1);
}

/*void squeeze(char s1[], char s2[])
{
	int i = 0, j = 0; 	// for counters 
	char temp;		// for char comparison 
	temp = s2[0];

	while(s2[i] != '\0')
	{
		if(s1[i] == temp)
		{
			//printf("\ns1[i] = s1[i+1] =: %s = %s\n", s1[i], s1[i+1]);
			s1[i] = s1[i+1];
			j++;
		}
		else
		{
			j++;
		}
		temp = s2[j];
		i++;
	}
	printf("\ni = %d", i);
	printf("\nj = %d\n", j);
	s1[i+1] = '\0';

}
*/

void squeeze(char s1[], char s2[])
{
	int i = 0, j = 0;

	do
	{
		int k = 0;
		while(s2[k] != '\0' && s2[k] != s1[i])
			++k;

		if (s2[k] == '\0')
		{
			if (j != i)
				s1[j] = s1[i];
		++j;
		}
	} while (s1[i++] != '\0');

}
