
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int time = 0 ;
int **adMat , *color, *parent, V, *disc, *fin;

void DFS_VISIT( int u )
{
	time++ ;
	disc[u] = time ;
	color[u] = 1;
	for(int i =0 ; i<V ; i++)
	{
		if( adMat[u][i] == 1)
			if( color[i] == 0)
			{
				parent[i] = u ;
				DFS_VISIT(i) ;
			}
	}
	color[u] = 2 ;
	time++ ;
	fin[u] = time ;
}

void DFS()
{
	memset(parent, -1, sizeof(parent[0]) * V) ;
	for(int i=0 ; i<V ; i++)
		if( color[i] == 0)
			DFS_VISIT(i) ;
}

int main()
{

	printf("Enter the no. of vertices : \n");
	scanf("%d", &V);
	
	adMat = (int **)malloc( sizeof(int *) * V) ;
	for(int i=0 ; i<V ; i++)
		adMat[i] = (int *)malloc( sizeof(int) * V) ;
	
	color = (int *)malloc(sizeof(int) * V) ;
	parent = (int *)malloc(sizeof(int) * V) ;
	disc = (int *)malloc(sizeof(int) * V) ;
	fin = (int *)malloc(sizeof(int) * V) ;
	
	FILE *fp = fopen("dfsInput.txt", "r") ;
	if( fp == NULL )
	{
		printf("No such file exists !! \n");
		return 0;
	}	
	
	char temp1, temp2 ; 
	while( !feof(fp))
	{
		fscanf( fp, "%c %c", &temp1, &temp2) ;
		adMat[(int)temp1 - 65][(int)temp2 - 65] = 1;
	}
	
	DFS() ;  
	
	printf("\nThe discovered and finished time of the graph is: \n ") ;
	for(int i=0 ; i<V ; i++)
		printf("%c \t %d \t %d \n", 'A' + i, disc[i], fin[i]) ;
		
	printf("\n");
	
	return 0 ;
}
