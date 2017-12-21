#include <stdio.h>
#include <stdlib.h>

int main(){
	int A[4][5], i, j, somaA, somaL;
	time_t t;
	
	srand((unsigned) time(&t));
	
	for(i=0; i<4; i++){
		for(j=0; j<5; j++){
			A[i][j]=rand() %10;
		}
	}

	printf("\n\n----------------------------MATRIZ A----------------------------\n\n");
	for(i=0; i<4; i++){
		for(j=0; j<5; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<4; i++){
		for(j=0; j<5; j++){
			somaA=somaA+A[i][j];
		}
	}
	printf("\n\n");
	
	for(i=0; i<4; i++){
		somaL=0;
		for(j=0; j<5; j++){
			somaL=somaL+A[i][j];
		}
		printf("Soma da linha %d: %d\n", i, somaL);
	}
	
	
	printf("\n\nSoma da matriz: %d\n\n", somaA);
		
	return(0);
}
