/* Write the program expr, which evaluates a
*  a reverse Polish expression from the command
*  line, where each operator or operand is a 
*  seperate arguement. For example:
*  expr 2 3 4 + *
*  evaluates to 2 x (3+4)			*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_symbol(char symbol)
{
	if(symbol == '*')
		return 1;
	if(symbol == '/')
		return 2;
	if(symbol == '+')
		return 3;
	if(symbol == '-')
		return 4;

	return 0;
}

int main(int argc, char* argv[])
{
	char* string;
	int length;
	for(int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
		length = strlen(argv[i]);
		string = argv[i];
	}
	printf("length = %d\n", length);
	printf("string = %s\n", string);

	char* buffer = malloc((length*sizeof(char)) +1);
	int tok_count = 0, k = 0;
	for(int i = 0; i < length+1; i++)
	{
		if(string[i] == ' ' || string[i] == '\0')
		{
			tok_count++;
			buffer[k++] = string[i-1];
		}
	}
	buffer[k] = '\0';
	printf("buffer[0] = %c\n", buffer[0]);
	printf("buffer[tok_count-1] = %c\n", buffer[tok_count-1]);
	printf("tok_count = %d\n", tok_count);
	printf("check_symbol(buffer[tok_count]) = %d\n", check_symbol(buffer[tok_count-1]));

	int expr = 0, i = 0, x, y;
	tok_count -= 1;
	int passes = 0;
	while(tok_count > i)
	{
		switch(check_symbol(buffer[tok_count]))
		{
			case 1:
				if(passes == 0)
				{
					x = buffer[i] - '0';
					y = buffer[i+1] - '0';
					expr = x*y;
					printf("Now evaluating: %d %c %d = %d\n", x, buffer[tok_count], y, expr);
					tok_count--;
					i += 2;
					passes++;
					break;
				}
				x = expr;
				y = buffer[i] - '0';
				expr = x*y;
				printf("Now evaluating: %d %c %d = %d\n", x, buffer[tok_count], y, expr);
				tok_count--;
				i += 2;
				passes++;
				break;
			case 2:
                                if(passes == 0)
                                {
                                        x = buffer[i] - '0';
                                        y = buffer[i+1] - '0';
                                        expr = x/y;
                                        printf("Now evaluating: %d %c %d = %d\n", x, buffer[tok_count], y, expr);
					tok_count--;
					i += 2;
					passes++;
					break;
                                }
                                x = expr;
                                y = buffer[i] - '0';
                                expr = x/y;
                                printf("Now evaluating: %d %c %d = %d\n", x, buffer[tok_count], y, expr);
                                tok_count--;
                                i += 2;
                                passes++;
				break;
			case 3:
                                if(passes == 0)
                                {
                                        x = buffer[i] - '0';
                                        y = buffer[i+1] - '0';
                                        expr = x+y;
                                        printf("Now evaluating: %d %c %d = %d\n", x, buffer[tok_count], y, expr);
					tok_count--;
					i += 2;
					passes++;
                                        break;
                                }
                                x = expr;
                                y = buffer[i] - '0';
                                expr = x+y;
                                printf("Now evaluating: %d %c %d = %d\n", x, buffer[tok_count], y, expr);
                                tok_count--;
                                i += 2;
                                passes++;
				break;
			case 4:
                                if(passes == 0)
                                {
                                        x = buffer[i] - '0';
                                        y = buffer[i+1] - '0';
                                        expr = x-y;
                                        printf("Now evaluating: %d %c %d = %d\n", x, buffer[tok_count], y, expr);
					tok_count--;
					i += 2;
					passes++;
                                        break;
                                }
                                x = expr;
                                y = buffer[i] - '0';
                                expr = x-y;
                                printf("Now evaluating: %d %c %d = %d\n", x, buffer[tok_count], y, expr);
                                tok_count--;
                                i += 2;
                                passes++;
				break;
		}
	}
	printf("The expression evaluates to: %d\n", expr);
}
