#include <stdio.h>
#define STEPS 20
/* print Fahrenheit to Celsius table */
/* celsius formula = (Fahr-32) * (5.0 / 9.0) */


int main() {
	float cels = 300.0, fahr = 600.0;

	/* Header */
	printf("  F     C\n");
	for (int step = 20; fahr >= 0; --step) {
		cels = (fahr - 32) * (5.0 / 9.0);
		printf("%3.0f %6.1f\n", fahr, cels);
		fahr = fahr - STEPS;
        }

	/*while (cels <= 300) {
		cels = (fahr - 32) * (5.0 / 9.0);
		printf("%3.0f %6.1f\n", fahr, cels);
		fahr = fahr + step;
	}*/


	return 0;
}
