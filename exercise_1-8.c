#include <stdio.h>

int main() {

	int c;
	char tab = '\t';
	char nl = '\n';
	char spaces = ' ';
	char end_flag = 'X';
	int tabcount = 0, nlcount = 0, spacescount = 0;

	while((c = getchar()) != end_flag) {
		if (c == nl) {
			nlcount++;
		} else if (c == tab) {
			tabcount++;
		} else if (c == spaces) {
			spacescount++;
		}
	}
	printf("There are %d newlines, %d tabs, and %d spaces in this stream\n", nlcount, tabcount, spacescount);

	return 0;
}
