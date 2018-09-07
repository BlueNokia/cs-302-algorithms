#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char a, b, check = 'Y';
	int temp ;
	
	while(1)
	{
		scanf("%c", &a) ;
		scanf("%c", &b) ;
		scanf("%d", &temp) ;
		//adMat[(int)v1-65][(int)v2-65] = temp ;
		printf("\nStill wanna enter more? ( Y / N )\n");
		scanf("%c", &check);
		if(check == 'N' || check == 'n')	
			break;
	}
	printf("\n%c \t %c\t %d\n", a, b, temp);
	return 0 ;
	
}
