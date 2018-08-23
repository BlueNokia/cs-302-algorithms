#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "pqHeap.c"

int main()
{
	int adMat[][], V, temp, discovered[], s, v1, v2;
	char check = 'Y';
	printf("\nEnter the no. of vertices:\n") ;
	scanf("%d", &V) ;
	printf("\nEnter the pair of edges and weight respectively:\n");
	while(1)
	{
		scanf("%d%d%d", &v1, &v2, &temp);
		adMat[v1-65][v2-65] = temp ;
		printf("\nStill wanna enter more? ( Y / N )\n");
		scanf("%c", &check);
		if(check == 'N' || check == 'n')	break;
	}
	printf("Which one will be the source ?\n");
	scanf("%d\n", &s);
	s -= 65 ;
	
	heap *H;
	H = (heap *)malloc(sizeof(heap)) ;
	init_heap(H) ;
	for(int i=0 ; i<V ;i++)
	
	
	
	return 0;
}
