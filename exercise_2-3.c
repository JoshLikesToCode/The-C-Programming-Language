/* Write the function htoi(s), which converts a string of hexadecimal digits
*  (including the optional 0x or 0X) into its equivalent integer value.
*  The allowable digits are 0 through 9, a through f, and A through F */
#include <stdio.h>
#define END_FLAG '\n'
#define MAX_INPUT 100

int htoi_func(char s[]);
int main() {
	int c, i = 0;
	char input_string[MAX_INPUT+1];

	// initialize input_string
	//for (int j = 0; j < MAX_INPUT; j++)
	//	input_string[j] = (char)0;

	printf("Enter a 4 digit hexadecimal # to be converted into an integer value:  ");

	while((c = getchar()) != END_FLAG)
	{
		input_string[i] = c;
		++i;
	}

	printf("\nYou entered the hexadecimal value of: %s\n", input_string);
	printf("\nThe integer value of [%s] is: %d\n", input_string, htoi_func(input_string));
}

int htoi_func(char s[]) {

	int rt = 0;
	int start = 0;

	/* For the optional leading '0x' or '0X' */
	if((s[0] == '0' && s[1] == 'X') || (s[0] == '0' && s[1] == 'x'))
	{
		start = 2;
	}

	int i;
  	char c;
  	for (i = start; (c = s[i]) != '\0'; i++)
	{
    		int v;
   	 	if ('0' <= c && c <= '9')
		{
      			v = c - '0';
    		}
		else if ('a' <= c && c <= 'f')
		{
      			v = 10 + c - 'a';
    		}
		else if ('A' <= c && c <= 'F') {
      			v = 10 + c - 'A';
    		}
		else
		{
      			printf("Error: Illegal hexadecimal digits: %s\n", s);
      			return 0;
    		}
    		rt = rt * 16 + v;
  		}
 	return rt;

}
