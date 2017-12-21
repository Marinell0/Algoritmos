#include <stdio.h>
#include <stdlib.h>
#define MAX 100 //MAX é como uma variavel, mas que pode colocar dentro do vetor. O valor é "100" do lado, nesse caso, podendo trocar por qualquer número.

int main(){
	int i=0, j=0, tam, aux, A[MAX];
	time_t t;
	
	srand((unsigned) time(&t));
	for(i=0; i<MAX; i++){
		A[i]=rand() %100;
		printf("%d\n", A[i]);
	}
	
	printf("\n\n---------------------------------------------\n\n");
	
	i=1;
	while(i<MAX){
		aux=A[i];
		j=i;
		while(aux<A[j-1] && j>0){
			j--;
			A[j+1]=A[j];
		}
		A[j]=aux;
		i++;
	}
	
	i=0;
	while(i<MAX){
		printf("%d\n", A[i]);
		i++;
	}
	return(0);
}
