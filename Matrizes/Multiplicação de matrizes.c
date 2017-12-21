#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){
	int i=0, j=0, k=0, A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], linA, colA=1, linB=0, colB;
	
	while(colA!=linB){
		printf("Linhas da matriz A: ");
		scanf("%d", &linA);
		printf("Colunas da matriz A: ");
		scanf("%d", &colA);
		
		printf("Linhas da matriz B: ");
		scanf("%d", &linB);
		printf("Colunas da matriz B: ");
		scanf("%d", &colB);
		printf("\n\n\n");
	}
	
	printf("\n");
	
		

	//------------------ Colocando os valores em A e em B ------------------
	for(i=0; i<linA; i++){
		for(j=0; j<colA; j++){
			printf("Valor linha %d, coluna %d da matriz A: ", i, j);
			scanf("%d", &A[i][j]);
		}
	}
	for(i=0; i<linB; i++){
		for(j=0; j<colB; j++){
			printf("Valor linha %d, coluna %d da matriz B: ", i, j);
			scanf("%d", &B[i][j]);
		}
	}
	
	//------------------ Printf das matrizes A e B ------------------
	printf("\n\n ------------------ Matriz A ------------------\n\n");
	
	for(i=0; i<linA; i++){
		for(j=0; j<colA; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n ------------------ Matriz B ------------------\n\n");
	
	for(i=0; i<linB; i++){
		for(j=0; j<colB; j++){
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	
	/*------------------ Cálculo da Matriz C ------------------
	Cálculo errado, ordem de linhas e colunas ou algo assim
	*/
	for(i=0; i<linA; i++){
		for(k=0; k<colB; k++){
			for(j=0; j<linB; j++){
				C[i][k]=C[i][k]+(A[i][j]*B[j][k]);
			}
		}
	}
	
	printf("\n\n ------------------ Matriz C ------------------\n\n");
	
	//------------------ Printf da matriz C ------------------
	for(i=0; i<linA; i++){
		for(j=0; j<colB; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}

	return(0);
}
