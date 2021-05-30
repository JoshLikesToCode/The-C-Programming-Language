/* Extend atof to handle scientific notation of the form:
							 	123.45e-6
	which should be displayed as: 0.00012345
	or for example 123.45e+6 = 123450000
   where a floating-point number may be followed by an e or E and an optional signed exponent*/

#include <stdio.h>
#define NEW_LINE '\n'
#define NULL_TERM '\0'
#define MAX_LENGTH 255
#define NEG_SIGN '-'
#define PLUS_SIGN '+'
#define DECIMAL '.'
#define LC_E_SIGN 'e'
#define UC_E_SIGN 'E'
#define END_FLAG 'X'

double my_atof(char s[]);

int main()
{
	int c, counter = 0;
	char buffer[MAX_LENGTH];

	while((c = getchar()) != NEW_LINE)
	{
		buffer[counter] = c;
		counter++;
	}
	buffer[counter] = NULL_TERM;

	printf("\nbuffer = %s", buffer);
	my_atof(buffer);

}

double my_atof(char s[])
{
	int counter = 0, decimal_places, hold_num_counter = 0;
	char sign, exponent;
	char hold_numbers[MAX_LENGTH];
	/* find sign & decimal place */
	while(s[counter] != NULL_TERM)
	{
		if(s[counter] == LC_E_SIGN || s[counter] == UC_E_SIGN)
		{
			sign = s[counter+1];
			exponent = s[counter+2];
		}
		if(s[counter]  == DECIMAL)
		{
			decimal_places = counter;
		}
		if(s[counter] == '1' || s[counter] == '2' || s[counter] == '3' || s[counter] == '4' || s[counter] == '5' || s[counter] == '6' || s[counter] == '7' || s[counter] == '8' || s[counter] == '9')
		{
			hold_numbers[hold_num_counter] = s[counter];
			hold_num_counter++;
		}
	counter++;
	}
	hold_numbers[hold_num_counter] == NULL_TERM;
	hold_num_counter = 0;	/* reset counter */


	char place_holder[MAX_LENGTH];
	if(sign == NEG_SIGN)
	{
		place_holder[0] = '0';
		place_holder[1] = '.';
		for(counter = 2; counter < decimal_places+2; counter++)
		{
			place_holder[counter] = '0';
		}
		while(hold_numbers[hold_num_counter] != NULL_TERM)
		{
			place_holder[counter] = hold_numbers[hold_num_counter];
			counter++;
			hold_num_counter++;
		}
		place_holder[counter-1] = '\0';
	}

	if(sign == PLUS_SIGN)
	{
		for(int i = 0; hold_numbers[i] != NULL_TERM; i++)
		{
			place_holder[i] = hold_numbers[i];
		}
	}


	/* testing purposes */
	printf("\nsign = %c\n", sign);
	printf("exponent = %c\n", exponent);
	printf("decimal_place = %d\n", decimal_places);
	printf("hold_numbers[] = %s\n", hold_numbers);
	printf("place_holder[] = %s\n", place_holder);
}
