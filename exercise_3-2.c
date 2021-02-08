/* Exercise 3-2: Write a function escape(s,t) that convers characters like newline
** and tab into visible escape sequences like \n and \t as it copies the string to to s.
** Use a switch. Write a functipon for the other direction as well, converting escape
** sequences into the real characters.						       */

#include <stdio.h>
#define NEW_LINE  '\n'
#define TAB	  '\t'
#define MAX_INPUT 100
#define END_FLAG  'X'

escape(char user_string[], char copied_string[]);
inverse_escape(char user_string[], char copied_string[]);

int main()
{
	int c;
	char buffer[MAX_INPUT];
	char altered_buffer[MAX_INPUT];
	int counter = 0;

	printf("Type out string to run through escape(). Type X and hit Enter when finished\n");
	while((c = getchar()) != END_FLAG)
	{
		buffer[counter] = c;
		counter++;
	}
	buffer[counter] = '\0';
	printf("Your string is: %s\n", buffer);


	escape(buffer, altered_buffer);
	printf("Your altered buffer by escape() is: %s\n", altered_buffer);

}


escape(char user_string[], char copied_string[])
{
	int counter = 0;
	while(user_string[counter] != '\0')
	{
		if(user_string[counter] != TAB && user_string[counter] != NEW_LINE)
		{
			copied_string[counter] = user_string[counter];
			counter++;
		}
		else
		{
			switch(user_string[counter])
			{
				case '\t': 
					copied_string[counter] = 'T';
					counter++;
					break;
				case '\n':
					copied_string[counter] = 'N';
					counter++;
					break;
			}
		}
	}
	copied_string[counter] = '\0';

}

