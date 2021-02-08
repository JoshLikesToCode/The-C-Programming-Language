#include <stdio.h>

#define IN 1
#define OUT 0


int main() {
	int c;
	char end_flag = 'X';
	int state = IN;

	while((c = getchar()) != end_flag) {
		if (c == '\t' || c == '\n' || c == ' ') {
			state = OUT;
			printf("\n");
			state = IN;
		} else if (state == IN)
			putchar(c);
	}


}
