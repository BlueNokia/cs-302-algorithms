#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *arr = (int *)malloc( 4 * sizeof(int));
	arr[0] = 1, arr[1] = 2, arr[2] = 3, arr[3] = 4;
	arr = (int *)realloc(arr,  5 * sizeof(int)) ;
	arr[4] = 5;
	for(int i=0 ; i<5 ; i++)
		printf("%d  ", arr[i]);
	printf("\n");
	return 0;
}
