/* Write a function expand(s1, s2) that expands shorthand notations like a-z in the string
** s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
** and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
** that a leading ore trailing - is taken literally					*/

#include <stdio.h>
#include <ctype.h> 	/* for tolower() */
#include <string.h>	/* for strlen */
#include <stdlib.h>	/* for atoi */
#define MAX_INPUT 100
#define NEW_LINE '\n'
#define ALPHABET_SIZE 27
#define INT_SIZE 11

void expand(char s1[], char s2[]);

int main()
{
	char buffer[MAX_INPUT];
	char altered_buffer[2 * MAX_INPUT];
	int c, counter = 0;

	printf("Please enter a-z or 0-9 and I will expand your shorthand notation: ");
	while((c = getchar()) != NEW_LINE)
	{
		buffer[counter] = tolower(c);
		counter++;
	}
	buffer[counter] = '\0';
	printf("You entered: \n%s\n", buffer);
	expand(buffer, altered_buffer);
	//printf("Your shorthand notation expanded is:\n%s\n", altered_buffer);
}

void expand(char s1[], char s2[])
{
	char alphabet[ALPHABET_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','y','x','z', '1'};
	int zero_through_nine[INT_SIZE] = {0,1,2,3,4,5,6,7,8,9,-1};
	int temp_int1, temp_int2; 	/* to hold #'s from s1 we want to expand on */
	char temp_letter1, temp_letter2;	/* to hold the letters from s1 we want to expand on */
	int digits_on = 0, letters_on = 0;

	for(int i = 0; i < strlen(s1) - 1; i++)
	{
		if(isdigit(s1[i]) && s1[i+1] == '-')
		{
			temp_int1 = s1[i] - '0';	/* converts char to proper int */
			temp_int2 = s1[i+2] - '0';	/* converts char to proper int */
			digits_on = 1;		/* set digits_on flag to true */
			break;
		}
		else
		{
			// enter code here to check for alphabets and get them
			temp_letter1 = s1[i];
			temp_letter2 = s1[i+2];
			letters_on = 1;
			break;
		}
	}

	if(digits_on == 1)
	{
		int i = 0;	/* to store starting place */
		/* get starting point in zero_through_nine array that matches temp_int1 */
		for(; zero_through_nine[i] != temp_int1; i++)
		;
		/* print from starting place to temp_int2 */
		for(; zero_through_nine[i] != temp_int2; i++)
			printf("%d ", zero_through_nine[i]);
		/* print trailing digit */
		printf("%d\n", temp_int2);
	}

	if(letters_on == 1)
	{
                int i = 0;      /* to store starting place */
                /* get starting point in alphabet array that matches temp_letter1 */
                for(; alphabet[i] != temp_letter1; i++)
                ;
                /* print from starting place to temp_letter2 */
                for(; alphabet[i] != temp_letter2; i++)
                        printf("%c ", alphabet[i]);
                /* print trailing digit */
                printf("%c\n", temp_letter2);
	}
}


