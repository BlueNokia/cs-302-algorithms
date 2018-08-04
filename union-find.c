#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge
{
	int start, end;
}edge;


int findRoot(int *, int);
int formsCycle(edge *, int *, int, int );

int main()
{
	int V, E;
	edge *graph;
	int *treeArr;
	
	printf("\n\tEnter the no. of vertices and edges resp. ::\n");
	scanf("%d%d", &V, &E);
	
	graph = (edge *)malloc( E * sizeof(edge));
	
	treeArr = (int *)malloc( V * sizeof(int));
	memset(treeArr, -1, V * sizeof(int));
	
	for(int i=0 ; i<E ; i++)
	{
		printf("\tEnter START vertice of edge [ %d ] :\n", i+1);
		scanf("%d", &graph[i].start);
		
		printf("\tEnter END vertice of edge [ %d ] :\n", i+1);
		scanf("%d", &graph[i].end);
		
		printf("\n");
	}
	
	printf("\n\t~~RESULT~~\n");
	
	if(formsCycle(graph, treeArr, V, E))
		printf("\tHurrah, it forms a cycle !\n");
	else
		printf("\tSorry, no cycle.\n");
	
	
	return 0;
}

int formsCycle(edge *edgeArr, int *rootArr, int V, int E)
{
	for(int i=0 ; i<E ; i++)
	{
		int X = findRoot(rootArr, edgeArr[i].start);
		int Y = findRoot(rootArr, edgeArr[i].end);
		
		if( X==Y )
			return 1;
			
		rootArr[X] = Y;
	}
	
	return 0;
}

int findRoot(int *rootArr, int i)
{
	if(rootArr[i] == -1)
		return i;
		
	return findRoot(rootArr, rootArr[i]);
}
