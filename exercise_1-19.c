#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define END_FLAG 'X' /* end flag */

int get_line(char line[], int maxline);
void reverse_input(char s[]);

/* print longest line */
main() {
	char line[MAXLINE];
	int len;

	while((len = get_line(line, MAXLINE)) > 0)
	{
		reverse_input(line);
		printf("\n%s\n", line);
	}
	return 0;
}

/* get_line: read a line into s, return length */
int get_line (char s[], int lim) {
	int c, i;

	for(i=0; i < lim-1 && (c = getchar()) != END_FLAG && c!= '\n'; ++i)
		s[i] = c;
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* remove: removes trailing tabs and blank lines */
void reverse_input(char s[])
{
	int i, j;
	char temp;

	for (i=0; s[i] != '\0'; ++i)
		;
	--i;

	if (s[i] == '\n')
		--i;

	j = 0;

	while( j < i)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}
}
