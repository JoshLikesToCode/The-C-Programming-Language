#include <stdio.h>

#define NONBLAN 'm'

int main() {
	int c, lastc;
	char end_flag = 'X';
	char replace = '~';

	while ((c = getchar()) != end_flag) {
		if (c != '\t' | '\b' | '\\')
			putchar(c);
		if (c == '\t')
			putchar(replace);
		if (c == '\b')
			putchar(replace);
		if (c == '\\')
			putchar(replace);
		lastc = c;
	}
	return 0;

}
