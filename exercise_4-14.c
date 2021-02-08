#include <stdio.h>
#define swap(t,x,y) \
	do { \
		t = x; \
		x = y; \
		y = t; \
	}  while (0) \

int main()
{
	int temp;
	int x = 4;
	int y = 20;
	printf("\nPre Swap:");
	printf("\nx = %d", x);
	printf("\ny = %d", y);
	swap(temp, x, y);
        printf("\nPost Swap:");
        printf("\nx = %d", x);
        printf("\ny = %d", y);


	char temp1;
	char x1 = 'x';
	char y1 = 'y';
        printf("\nPre Swap:");
        printf("\nx1 = %c", x1);
        printf("\ny1 = %c", y1);
        swap(temp1, x1, y1);
        printf("\nPost Swap:");
        printf("\nx1 = %c", x1);
        printf("\ny1 = %c\n", y1);
}
