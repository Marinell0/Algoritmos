#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j, k, linA, colA, linB, colB;
	
	
	FILE *matrizes, *result;
	matrizes = fopen("matrizes.txt", "r");
	result = fopen("result.txt", "w");
	
	//---------------------Scan da linha e coluna da matriz A----------------------------------
	fscanf(matrizes, "%d %d", &linA, &colA);
	printf("A matriz A tem %d linhas e %d colunas\n\n", linA, colA);
	
	int A[linA][colA];
	
	for(i=0; i<linA; i++){
		for(j=0; j<colA; j++){
			fscanf(matrizes, "%d", &A[i][j]);
		}
	}
	
	//---------------------Print da matriz A----------------------------------
	for(i=0; i<linA; i++){
		for(j=0; j<colA; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	//---------------------Scan da linha e coluna da matriz B----------------------------------
	fscanf(matrizes, "%d %d", &linB, &colB);
	printf("\n\nA matriz B tem %d linhas e %d colunas\n\n", linB, colB);
	
	int B[linB][colB];
	
	for(i=0; i<linB; i++){
		for(j=0; j<colB; j++){
			fscanf(matrizes, "%d", &B[i][j]);
		}
	}
	
	//---------------------Print da matriz B----------------------------------
	for(i=0; i<linB; i++){
		for(j=0; j<colB; j++){
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	
	//-------------------------------------Zeramento da matriz C-------------------------
	printf("\n\nMultiplicacao dessas matrizes:\n\n");
	int C[linA][colB];
	
	for(i=0; i<linA; i++){
		for(j=0; j<colB; j++){
			C[i][j]=0;
		}
	}
	
	//------------------------------Cálculo da matriz C-------------------------------
	for(i=0; i<linA; i++){
		for(k=0; k<colB; k++){
			for(j=0; j<linB; j++){
				C[i][k]=C[i][k]+(A[i][j]*B[j][k]);
			}
		}
	}
	
	//---------------------Print da matriz C----------------------------------
	for(i=0; i<linA; i++){
		for(j=0; j<colB; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<linA; i++){
		for(j=0; j<colB; j++){
			fprintf(result, "%d ", C[i][j]);
		}
		fprintf(result, "\n");
	}
	
	
	
	
	fclose(matrizes);
	fclose(result);	
	return(0);
}
