/* Write a program detab that replaces tabs in the input with the proper number of
*  blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
*  Should n be  variable of symbolic parameter?						*/

/* Tabs are 5 spaces so: -----|-----|-----|-----|-----|-----
*  So if we write 2 chars on the first tab and hit tab it should only bring us up to | line 
*  #1.											*/

#include <stdio.h>
#define END_FLAG 'X'
#define TAB_LENGTH 5
#define TAB '\t'
#define MAX_CHARS 100

int n_Cols = 5;


int main() {
	int c, num_of_chars = 0, chars_until_tab = 0;
	char input[MAX_CHARS];

	while((c = getchar()) != END_FLAG)
	{
		num_of_chars++;
		chars_until_tab++;

		if (chars_until_tab == 5)		/* reset chars_until_tabl */
			chars_until_tab = 0;

		if (c == TAB && (chars_until_tab < 5))
		{
			int blank_spaces;
			blank_spaces = (num_of_chars % TAB_LENGTH);
			for (int i = 0; i < blank_spaces; i++)
			{
				putchar(' ');
			}
		}
	}



}
