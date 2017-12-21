#include <stdio.h>
#include <stdlib.h>
#define MAX 100 //MAX é como uma variavel, mas que pode colocar dentro do vetor. O valor é "100" do lado, nesse caso, podendo trocar por qualquer número.

int main(){
	int A[MAX], i=0, j=0, tam=MAX, aux;
	time_t t;
	
	srand((unsigned) time(&t));
	for(i=0; i<100; i++){
		A[i]=rand() %100;
		printf("%d\n", A[i]);
	}
	
	while(j<MAX){
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
	
	printf("\n\n----------------------------------------\n\n");
	
	i=0;
	while(i<100){
		printf("%d\n", A[i]);
		i++;
	}
	
	return(0);
}
