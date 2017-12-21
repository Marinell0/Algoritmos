#include <stdio.h>
#include <stdlib.h>

void Bubble(int tam, int *A){
	int i=0, j=0, aux;
	
	while(j<tam){
		i=0;
		while(i<(tam-1)){
			if(A[i]>A[i+1]){
				aux=A[i];
				A[i]=A[i+1];
				A[i+1]=aux;
			}
			i++;
		}
		j++;
		tam--;
	}
}

int main(){
	int A[10], i, tam;
	
	for(i=0; i<10; i++){
		printf("Numero para o vetor: ");
		scanf("%d", &A[i]);
	}
	tam=10;
	
	Bubble(10, A);
	
	printf("\n\n");
	for(i=0; i<10; i++){
		printf("%d ", A[i]);
	}
}
