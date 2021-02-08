#include <stdio.h>
#define NUM_LETTERS_IN_ALPHA 26

/* This program will create a histogram of word frequencies found in input */

int main() {

	char alphabet[NUM_LETTERS_IN_ALPHA];
	int alphabet_freq[NUM_LETTERS_IN_ALPHA];
	char end_flag = 'X';
	char stars = '*';
	int c;

	// initialize alphabet array
	for (int i = 0; i < NUM_LETTERS_IN_ALPHA; i++)
		alphabet[i] = (char)(97+i);

	// initialize alphabet_freq array
	for (int i = 0; i < NUM_LETTERS_IN_ALPHA; i++)
		alphabet_freq[i] = 0;

	// for testing purposes
	for (int i = 0; i < NUM_LETTERS_IN_ALPHA; i++)
		printf(" %c", alphabet[i]);
	printf("\n");

	while ((c = getchar()) != end_flag) {
		for (int i = 0; i < NUM_LETTERS_IN_ALPHA; i++) {
			if (alphabet[i] == c)
				alphabet_freq[i]++;
		}
	}

	for (int i = 0; i < NUM_LETTERS_IN_ALPHA; i++)
		printf("%c	%d\n", alphabet[i], alphabet_freq[i]);
	printf("\n");


	// checks for a max frequency of 3
	for (int i = 0; i < NUM_LETTERS_IN_ALPHA; i++) {
		printf("\n%c:	", alphabet[i]);
		if (alphabet_freq[i] == 1) {
			printf("*");
		} else if (alphabet_freq[i] == 2) {
				printf("**");
		} else if (alphabet_freq[i] == 3) {
				printf("***");
		}
	}
	printf("\n");
}
