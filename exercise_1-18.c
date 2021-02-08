#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define END_FLAG 'X' /* end flag */

int get_line(char line[], int maxline);
int remove_trailing(char s[]);


/* print longest line */
main() {
	int len;
	char line[MAXLINE];

	while((len = get_line(line, MAXLINE))>0)
		if(remove_trailing(line) > 0)
			printf("\n%s\n", line);

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
int remove_trailing(char s[])
{
	int i;
	for (i = 0; s[i] != '\n'; ++i)
		;
		--i;

	for ( i > 0; ((s[i] == ' ') || (s[i] == '\t')); --i)
		;

	if ( i >= 0)
	{
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	return i;
}
