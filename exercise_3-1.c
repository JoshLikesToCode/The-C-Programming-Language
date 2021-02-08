/* The binary search given in the book makes two tests inside the loop, when one would suffice
** (at the price of more tests outside). Write a version with only one test inside the loop
** and measure the difference in run-time */

/* Example of binary_search() given in book:
** 
** binary_search: find x in v[0] <= v[1] <= ... <= v[n-1]:
**
** int binary_search(int x, int v[], int n)
** {
**	int low, high, mid;
**	low = 0;
**	high = n - 1;
**	while (low <= high) {
**		mid = (low+high) / 2;
**		if (x < v[mid])
**			high = mid - 1;
**		else if (x > v[mid])
**			low = mid + 1;
**		else // found match
**			return mid;
**	}
**	return -1;  // no match
**}
					*/

#include <stdio.h>
#define MAX_SIZE 10
#define NEW_LINE '\n'
#define END_FLAG 'X'

int binary_search(int x, int v[], int n);
int modified_binary_search(int x, int v[], int n);

int main()
{
	int int_array[MAX_SIZE];
	int c, i;

	/* populate array with 0s to avoid junk data */
	for(int i = 0; i < MAX_SIZE; i++)
		int_array[i] = 0;

	/* test above */
	for(int i = 0; i < MAX_SIZE; i++)
		printf("\nint_array[%d] = %d", i, int_array[i]);

	printf("\n\nEnter 10 ints (lowest - highest) to populate array, press enter after each #.\n");

	for(int i = 0; i < MAX_SIZE; i++)
		scanf("%d", &int_array[i]);

        /* test above */
        for(int i = 0; i < MAX_SIZE; i++)
                printf("\nint_array[%d] = %d", i, int_array[i]);
	printf("\n");

	printf("Enter a # to binary search for: ");
	int search_for;
	scanf("%d", &search_for);
	printf("If your was found its place in the array will be returned, else -1 will be returned.");
	printf("\nReturn: %d\n", binary_search(search_for, int_array, MAX_SIZE));

	printf("Now let's do the modified_binary_search()\n");
        printf("If your was found its place in the array will be returned, else -1 will be returned");
        printf("\nReturn: %d\n", modified_binary_search(search_for, int_array, MAX_SIZE));


}

int binary_search(int x, int v[], int n)
{
	int low, high, mid;
        low = 0;
        high = n - 1;
        while (low <= high) {
         	mid = (low+high) / 2;
              	if (x < v[mid])
                	high = mid - 1;
                else if (x > v[mid])
                      	low = mid + 1;
              	else // found match
                        return mid;
      }
	      return -1;  // no match
}

int modified_binary_search(int x, int v[], int n)
{
    	int low, high, mid;
    	low = 0;
    	high = n - 1;
    	mid = (low+high) / 2;
    	while ( low <= high && x != v[mid] ) {
        	if ( x < v[mid] )
            		high = mid - 1;
        	else
            		low = mid + 1;
        mid = (low+high) / 2;
    }
    	if ( x == v[mid] )
        	return mid;
    	else
        	return -1;
}

