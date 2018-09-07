#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define parent(n) ((n-1)/2)
#define lChild(n) (2*n + 1)
#define rChild(n) (2*n + 2)

typedef struct Heap
{
	unsigned int size ;						// size of the Priority Queue
	int *face, *arr, *idLock;					// arr :: the heap-array
}heap ;									// face :: the face value of every vertex, e.g. - A, B, F, D
									
									
void swap (heap *H, int i1, int i2)					// Swapping two nodes of the Heap
{
	int temp ;
	temp = H->arr[i1];
	H->arr[i1] = H->arr[i2] ;
	H->arr[i2] = temp ;
	
	temp = H->face[i1];
	H->face[i1] = H->face[i2] ;
	H->face[i2] = temp ;
	
	H->idLock[H->face[i1]] = i1 ;
	H->idLock[H->face[i2]] = i2 ;
	
}
void minHeapify( heap *H, int low, int high )
{
	int smallest = low , temp; 
	
	if(lChild(low) <= high && H->arr[lChild(low)] < H->arr[smallest] )	smallest = lChild(low);
	if(rChild(low) <= high && H->arr[rChild(low)] < H->arr[smallest] )	smallest = rChild(low);
	
	if(smallest != low)
	{
		swap (H, smallest, low) ;
		minHeapify( H, smallest, high);
	}
	
}

void push( heap *H, int new)
{
	H->size += 1;
	H->arr = (int *)realloc(H->arr, H->size * sizeof(int));
	H->face = (int *)realloc(H->face, H->size * sizeof(int));
	
	int index = H->size - 1, temp;
	H->arr[index] = new;
	H->face[index] = H->size - 1;
	H->idLock[index] = H->size - 1; 
	
	while( index )
	{
		if(H->arr[parent(index)] <= H->arr[index])	break;
		swap (H, index, parent(index)) ;
		index = parent(index) ;
	}	
	
}

void changePriority ( heap *H, int index, int new_priority)
{
	H->arr[index] = new_priority ;
	while( index )
	{
		if(H->arr[parent(index)] <= H->arr[index])	break;
		swap (H, index, parent(index)) ;
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
	int deleted = H->face[0];
	H->arr[0] = H->arr[H->size] ;
	H->face[0] = H->face[H->size] ;
	
	H->arr = (int *)realloc( H->arr, H->size * sizeof(int)) ;
	H->face = (int *)realloc( H->face, H->size * sizeof(int)) ;
	
	minHeapify( H, 0, H->size - 1);
	return deleted ;
}

int getId (heap *H, int i)
{
	return H->idLock[i] ;
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
	H->face = (int *)malloc(H->size * sizeof(int)) ;
	H->idLock = (int *)malloc(H->size * sizeof(int)) ;
}

int main()
{
	int V, temp, s;
	char check = 'Y', v1, v2, S;
	
	printf("\nEnter the no. of vertices:\n") ;
	scanf("%d", &V) ;
	int dist[V], origin[V], adMat[V][V];
	memset(adMat, 0, sizeof(adMat[0][0]) * V * V) ;
	printf("\nEnter the pair of edges and weight respectively:\n");
	while(check == 'Y' || check == 'y')
	{
		scanf("%c%c%d", &v1, &v2, &temp);
		
		adMat[((int)v1)-65][((int)v2)-65] = temp ;
		printf("\nStill wanna enter more? ( Y / N )\n");
		scanf("%c", &check);
	}
	printf("Which one will be the source ?\n");
	scanf("%c\n", &S);
	s = (int)S - 65 ;
	
	heap *H;
	H = (heap *)malloc(sizeof(heap)) ;
	init_heap(H) ;
	
	for(int i=0 ; i<V ;i++)
	{
		dist[i] = INT_MAX ;
		origin[i] = -1;
		push(H, INT_MAX);
	}
	
	dist[s] = 0;
	changePriority(H, getId(H, s), 0) ;
	
	int u, v, alt;
	while( H->size != 0)
	{
		u = extractMin(H) ;
		for(v=0 ; v < V ; v++)
		{
			if( adMat[u][v] == 0)	continue ;
			
			alt = dist[u] + adMat[u][v] ;
			if( alt < dist[v] )
			{
				origin[v] = u ;
				dist[v] = alt ;
				changePriority(H, getId(H, v), alt) ;
			}
		}
	}
	
	printf("\n\tThe minimum distance of other vertices from the source is:\n");
	
	for(int i=0 ; i<V ; i++)
		printf("\t%c  \t -->  %d\n", i+65, dist[i]);
		
	printf("\tEOF\n") ;
	
	return 0;
}
