#include <stdio.h>
#include <stdlib.h>

int main(){
	int A[2][3], B[2][3], C[2][3], i, j;
	
	//-------------------------------------LEITURA DAS MATRIZES-------------------------------------
	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			printf("Numero da linha %d, coluna %d da matriz A: ", i, j);
			scanf("%d", &A[i][j]);
		}
	}
	
	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			printf("Numero da linha %d, coluna %d da matriz B: ", i, j);
			scanf("%d", &B[i][j]);	
		}
	}
	
	//-------------------------------------CÁLCULO DA MATRIZ C-------------------------------------
	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			C[i][j]=A[i][j]+B[i][j];
		}
	}
	
	//-------------------------------------PRINTANDO NA TELA AS MATRIZES-------------------------------------
	printf("\n\n-------------------------------------MATRIZ A-------------------------------------\n\n");
	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n-------------------------------------MATRIZ B-------------------------------------\n\n");
	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n-------------------------------------MATRIZ C-------------------------------------\n\n");
	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	
	return(0);
}
