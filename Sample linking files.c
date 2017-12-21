//Percorrer o arquivo e descobrir tamanho da matriz. Arquivo de entrada vai ser o mesmo de saída.

#include <stdio.h>
#include <stdlib.h>

/*
-----------------------------------SAMPLE---------------------------------
int main(){
	int A[3][3], i, j;
	
	FILE *arquivo;
	FILE *saida;
	arquivo = fopen("entrada.txt", "r");
	saida = fopen("saida.txt", "r+");
	
	if(fopen("entrada.txt", "r") == NULL){
		perror("Erro ao abrir o arquivo");
	}else{
		printf("Arquivo aberto para leitura\n");
		
		for(i=0; i<3; i++){
			for(j=0; j<3; j++){
				fscanf(arquivo, "%d ", &A[i][j]);
			}
		}
		printf("\n\n");
		for(i=0; i<3; i++){
			for(j=0; j<3; j++){
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
		
		for(i=0; i<3; i++){
			for(j=0; j<3; j++){
				fprintf(saida, "%d ", A[i][j]);
			}
			fprintf(saida, "\n");
		}
		
	}
	
	fclose(arquivo);
	fclose(saida);

	return(0);
}
*/
