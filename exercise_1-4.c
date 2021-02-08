#include <stdio.h>

/* print Fahrenheit to Celsius table */
/* celsius formula = (Fahr-32) * (5.0 / 9.0) */


int main() {
	float cels = 0.0, fahr = 0.0, lower = 0.0;
	int upper = 300;
	int step = 20;

	/* Header */
	printf("  F     C\n");

	while (cels <= 300) {
		cels = (fahr - 32) * (5.0 / 9.0);
		printf("%3.0f %6.1f\n", fahr, cels);
		fahr = fahr + step;
	}


	return 0;
}
