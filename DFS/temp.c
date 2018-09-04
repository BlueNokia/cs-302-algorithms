#include <stdio.h>
#include <stdlib.h>

int **adMat , V;



int main()
{
	int v;
	printf("Enter the no. of vertices : \n");
	scanf("%d", &v);
	V= v ;
	
	printf("1 \n");
	
	adMat = (int **)malloc( sizeof(int *) * V) ;
	for(int i=0 ; i<V ; i++)
		adMat[i] = (int *)malloc( sizeof(int) * V) ;
	
	for(int i=0 ; i<V ; i++)
	{
		for(int j=0 ; j<V ; j++)
			printf("\t %d", adMat[i][j]) ;
		printf("\n");
		
	}
	
	printf("\n") ;
	
	printf("2 \n");
		
	FILE *fp ;
	fp = fopen("dfsInput.txt", "r") ;
	if( fp == NULL )
	{
		printf("No such file exists !! \n");
		return 0;
	}	
	
	printf("3 \n");
	
	char temp1, temp2 ; 
	for(int i=0 ; i<7 ; i++)
	{
		printf("^^^ \n");
		fscanf( fp, "%c %c", &temp1, &temp2) ;
		printf("*** \n");
		int k1 = ((int)temp1) - 65;
		int k2 = ((int)temp2) - 65;
		adMat[k1][k2] = 1;
	}
	
	printf("4 \n");
	
	for(int i=0 ; i<V ; i++)
	{
		for(int j=0 ; j<V ; j++)
			printf("\t %d", adMat[i][j]) ;
		printf("\n");
		
	}
	
	printf("5 \n");
	
	fclose(fp) ;
	return 0 ;
}
