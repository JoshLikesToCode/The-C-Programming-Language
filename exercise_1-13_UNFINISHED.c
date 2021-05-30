#include <stdio.h>
/* for bool */
#include "stdbool.h"
#define MAX_WORD_LENGTH 10
#define MAX_WORD_STORAGE 300

int main() {

	int c;
	char end_flag = 'X', white_space = ' ', new_line = '\n', tab = '\t';
	bool in_word = true;
	//char store_word[MAX_WORD_LENGTH];
	char stored_words[MAX_WORD_STORAGE];

	/* init store_words */
	for (int i = 0; i < MAX_WORD_STORAGE; ++i) {
		stored_words[i] = end_flag;
	}

	printf("%c %c\n", stored_words[0], stored_words[299]);

	while ((c = getchar()) != end_flag) {
		in_word = true;
		while (in_word) {
			for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
				stored_words[i] = c;
				if (c == white_space || new_line || tab) {
					in_word = false;
					stored_words[i] = '\0';
				}
			}
		}

	}

        printf("%c %c %c\n", stored_words[0], stored_words[5], stored_words[299]);

	/* print stored_words array */
	int j = 0;
	while (stored_words[j] != end_flag) {
		printf("%c", stored_words[j]);
		j++;
		if (stored_words[j] == '\0')
			printf("\n");
	}



}
