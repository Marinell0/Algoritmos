#include <stdio.h>
#include <stdlib.h>
#define MAX 100 //MAX é como uma variavel, mas que pode colocar dentro do vetor. O valor é "100" do lado, nesse caso, podendo trocar por qualquer número.

int main(){
	int i=0, j=0, aux=0, min, A[MAX];
	time_t t;
	
	srand((unsigned) time(&t));
	for(i=0; i<MAX; i++){
		A[i]=rand() %100;
		printf("%d\n", A[i]);
	}
	
	i=0;
	while(i<MAX){
		j=i;
		aux=A[i];
		while(j<MAX){
			if(A[j]<aux){
				min=j;
				aux=A[j];
			}
			j++;
		}
		A[min]=A[i];
		A[i]=aux;
		i++;
	}
	
	printf("\n\n--------------------------------\n\n");
	
	i=0;
	while(i<MAX){
		printf("%d\n", A[i]);
		i++;
	}	
	
	return(0);
}
