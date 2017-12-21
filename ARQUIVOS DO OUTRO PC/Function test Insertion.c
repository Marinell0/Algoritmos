#include <stdio.h>
#include <stdlib.h>

void Insertion(int tam, int *A){
	int i=0, j=0, aux;
	
	i=1;
	for(i=1; i<tam; i++){
		aux=A[i];
		j=i;
		while(aux<A[j-1] && j>0){
			j--;
			A[j+1]=A[j];
		}
		A[j]=aux;
	}
	
	for(i=0; i<tam; i++){
		printf("%d\n", A[i]);
	}
}

int main(){
	int i, j, A[10];
	
	for(i=0; i<10; i++){
		printf("Numero: ");
		scanf("%d", &A[i]);
	}
	
	Insertion(10, A);
	
	printf("\n\n");
	for(i=0; i<10; i++){
		printf("%d ", A[i]);
	}
	return(0);
}
	
