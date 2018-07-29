#include <stdio.h>
#include <stdlib.h>


void MatrixMultiply(int n, int** A, int Ar1, int Ac1, int** B, int Br1, int Bc1, int **C, int Cr1, int Cc1)
{
	if(n == 1)
	{
		C[Cr1][Cc1] += A[Ar1][Ac1] * B[Br1][Bc1]	;
	}
	else
	{
		MatrixMultiply(n/2, A, Ar1, Ac1,B, Br1, Bc1, C, Cr1, Cc1);
		MatrixMultiply(n/2, A, Ar1, Ac1+n/2, B, Br1+n/2, Bc1, C, Cr1, Cc1);

		MatrixMultiply(n/2, A, Ar1, Ac1, B, Br1, Bc1+n/2, C, Cr1, Cc1+n/2);	
		MatrixMultiply(n/2, A, Ar1, Ac1+n/2, B, Br1+n/2, Bc1+n/2, C, Cr1, Cc1+n/2);

		MatrixMultiply(n/2, A, Ar1+n/2, Ac1, B, Br1, Bc1, C, Cr1+n/2, Cc1);	
		MatrixMultiply(n/2, A, Ar1+n/2, Ac1+n/2, B, Br1+n/2, Bc1, C, Cr1+n/2, Cc1);

		MatrixMultiply(n/2, A, Ar1+n/2, Ac1, B, Br1, Bc1+n/2, C, Cr1+n/2, Cc1+n/2);	
		MatrixMultiply(n/2, A, Ar1+n/2, Ac1+n/2, B, Br1+n/2, Bc1+n/2, C, Cr1+n/2, Cc1+n/2);
	}

}

int main()
{
	int n;
	printf("\tEnter the dimension of matrices (Should be a power of 2):\n");
	scanf("%d", &n);
	
	//int A[n][n], B[n][n];
	
	
	int **A = (int **)malloc(n * sizeof(int *));
    	for (int i=0; i<n; i++)
       	  A[i] = (int *)malloc(n * sizeof(int));
	

	int **B = (int **)malloc(n * sizeof(int *));
    	for (int i=0; i<n; i++)
      	   B[i] = (int *)malloc(n * sizeof(int));

	printf("\n\t\t~~STARTING ENTRY OF MATRIX 1~~\n\n");

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			{
				
				printf("\tMatrix 1 -->  Row [ %d ]   X   Column [ %d ]  :\n", i, j);
				scanf("%d", &A[i][j]);
			}	

	printf("\n\t\t~~STARTING ENTRY OF MATRIX 2~~\n\n");

	for(int i=0; i<n ; i++)
		for(int j=0; j<n ; j++)
			{
				
				printf("\tMatrix 2 -->  Row [ %d ]   X   Column [ %d ]  :\n", i, j);
				scanf("%d", &B[i][j]);
			}

	int **C = (int **)malloc(n * sizeof(int *));
    	for (int i=0; i<n; i++)
	   C[i] = (int *)malloc(n * sizeof(int));
	   
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			C[i][j] = 0;

	MatrixMultiply(n , A, 0, 0, B, 0, 0, C, 0, 0);

	printf("\n\t\t~~ RESULT ~~\n\n");

	printf("\nMatrix A:\n");
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
			printf("%d   ", A[i][j]);

		printf("\n");
	}
	printf("\nMatrix B:\n");
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
			printf("%d   ", B[i][j]);

		printf("\n");
	}
	printf("\nMatrix C:\n");
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
			printf("%d   ", C[i][j]);

		printf("\n");
	}
	
	return 0;
}
