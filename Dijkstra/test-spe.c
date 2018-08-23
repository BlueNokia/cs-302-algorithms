#include <stdio.h>
#include <stdlib.h>

#define parent(n) (n-1)/2

typedef struct Heap
{
	unsigned int size ;
	int *arr ;
}heap ;

void init_heap( heap *H )
{
	//H = (heap *)malloc( sizeof(heap)) ;
	H->size = 0;
	H->arr = (int *)malloc(H->size * sizeof(int)) ;
}

void push( heap *H, int new)
{
	H->size += 1;
	H->arr = (int *)realloc(H->arr, H->size * sizeof(int));
	int index = H->size - 1, temp;
	H->arr[index] = new;
	while( index )
	{
		if(H->arr[parent(index)] <= H->arr[index])	break;
		temp = H->arr[parent(index)];
		H->arr[parent(index)] = H->arr[index];
		H->arr[index] = temp;
		index = parent(index) ;
	}	
	
}

void printCurrentHeap( heap *H )
{
	for(int i=0 ; i< H->size ; i++)
		printf("%d  ", H->arr[i]);
		
	printf("\n");
}

int main()
{
	heap *H;
	H = (heap *)malloc( sizeof(heap)) ;
	init_heap(H);
	push(H, 4);
	printCurrentHeap(H);
	return 0;
}
