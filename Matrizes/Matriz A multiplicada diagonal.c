#include <stdio.h>
#include <stdlib.h>

int main(){
	int A[4][4], i, j, k;
	time_t t;
	
	srand((unsigned) time(&t));
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			A[i][j]=rand() %10;
		}
	}
	
	printf("\n\n----------------------------MATRIZ A----------------------------\n\n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	printf("\nConstante k: ");
	scanf("%d", &k);
	
	for(i=0; i<4; i++){
		A[i][i]=k*A[i][i];
	}
	
	printf("\n\n----------------------------MATRIZ MULTIPLICADA----------------------------\n\n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	return(0);
}
