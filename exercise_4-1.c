/* Write the function strrindex(s,t), which returns the position of the rightmost occurrence
** of t in s, or -1 if there is none. */
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
#define NEW_LINE '\n'
#define END_FLAG 'X'
#define TEST_CHAR 'z'

char pattern[] = "ell";

int strrindex(char s[], char t);
int strrindex_string(char s[], char t[]); // for string comparision

int main()
{
	int c, counter = 0;
	char buffer[MAX_LENGTH];

	while((c = getchar()) != END_FLAG)
	{
		buffer[counter] = c;
		counter++;
	}
	buffer[counter] = '\0';
	printf("\nbuffer[counter] = %s", buffer);
	printf("\nstrrindex(buffer, TEST_CHAR) = %d", strrindex(buffer, TEST_CHAR));
	printf("\nstrrindex_string(buffer, pattern) = %d\n", strrindex_string(buffer, pattern));
}

int strrindex(char s[], char t)
{
	int size_of_s = 0, right_counter = 0; /* used to get size of s[] */
	while(s[size_of_s] != '\0')
	{
		size_of_s++;
	}
	printf("\nSize of s[] = %d", size_of_s);

	right_counter = size_of_s;
	while(right_counter >= 0)
	{
		if(s[right_counter] == t)
		{
			return right_counter;
		}
		right_counter--;
	}
	return -1;
}

int strrindex_string(char s[], char t[])
{
        int size_of_s = 0, right_counter = 0, size_of_t = 0, t_counter = 0; /* used to get sizes */
        while(s[size_of_s] != '\0')
        {
                size_of_s++;
        }
        printf("\nSize of s[] = %d", size_of_s);

	size_of_t = strlen(t);
	printf("\nSize of t[] = %d", size_of_t);

        right_counter = size_of_s;
	t_counter = size_of_t - 1; // minus one for '\0'
        while(right_counter > 0)
        {
                if(s[right_counter] == t[t_counter])
                {
			int place_holder = right_counter;
			while(s[right_counter] == t[t_counter])
			{
				if(t_counter == 0)
				{
					return place_holder;
				}
				right_counter--;
				t_counter--;
			}
                }
                right_counter--;
        }
	return -1;
}
