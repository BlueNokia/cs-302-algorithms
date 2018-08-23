#include <stdio.h>
#include <stdlib.h>

#define parent(n) ((n-1)/2)
#define lChild(n) (2*n + 1)
#define rChild(n) (2*n + 2)

typedef struct Heap
{
	unsigned int size ;
	int *arr ;
}heap ;

void minHeapify( heap *H, int low, int high )
{
	int smallest = low , temp; 
	
	if(lChild(low) <= high && H->arr[lChild(low)] < H->arr[smallest] )	smallest = lChild(low);
	if(rChild(low) <= high && H->arr[rChild(low)] < H->arr[smallest] )	smallest = rChild(low);
	
	if(smallest != low)
	{
		temp = H->arr[smallest] ;
		H->arr[smallest] = H->arr[low] ;
		H->arr[low] = temp ;
	
		minHeapify( H, smallest, high);
	}
	
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

void changePriority ( heap *H, int index, int new_priority)
{
	int temp ;
	H->arr[index] = new_priority ;
	while( index )
	{
		if(H->arr[parent(index)] <= H->arr[index])	break;
		temp = H->arr[parent(index)];
		H->arr[parent(index)] = H->arr[index];
		H->arr[index] = temp;
		index = parent(index) ;
	}
}

int extractMin( heap *H )
{
	if( H->size == 0)
	{
		printf("The heap is EMPTY. Stop extracting already !\n");
		return 0;
	}
	H->size -= 1;
	int deleted = H->arr[0];
	H->arr[0] = H->arr[H->size] ;
	
	H->arr = (int *)realloc( H->arr, H->size * sizeof(int)) ;
	
	minHeapify( H, 0, H->size - 1);
	return deleted ;
}


void printCurrentHeap( heap *H )
{
	for(int i=0 ; i< H->size ; i++)
		printf("%d  ", H->arr[i]);
		
	printf("\n");
}

void init_heap( heap *H )
{
	H->size = 0;
	H->arr = (int *)malloc(H->size * sizeof(int)) ;
}

int main()
{
	heap *newH ;
	newH = (heap *)malloc( sizeof(heap)) ;
	init_heap( newH ) ;
	push( newH, 100);
	push( newH, 100);
	push( newH, 100);
	push( newH, 100);
	push( newH, 100);
	push( newH, 0);
	printCurrentHeap( newH );
	printf("%d \n", extractMin( newH ));
	changePriority(newH, 2, 40);
	printCurrentHeap( newH );
	printf("%d \n", extractMin( newH ));
	printf("%d \n", extractMin( newH ));
	printf("%d \n", extractMin( newH ));
	printf("%d \n", extractMin( newH ));
	printf("%d \n", extractMin( newH ));
	
	return 0 ;
}




