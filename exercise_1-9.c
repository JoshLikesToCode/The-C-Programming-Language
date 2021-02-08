#include <stdio.h>
#define NONBLANK 'm'

/* Write a program to copy its input to its output. Replace double spaces with a single space */

int main() {
	int c, lastc;
	char end_flag = 'X';
	char space = ' ';

	lastc = NONBLANK;
	while((c = getchar()) != end_flag) {
		if (c != ' ')
			putchar(c);
		if (c == ' ')
			if (lastc != ' ')
				putchar(c);
		lastc = c;
	}


	return 0;
}
