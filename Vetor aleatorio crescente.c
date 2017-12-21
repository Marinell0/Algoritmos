#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=0, j, vetor[100], crescente, tam=10, aux;
	time_t t;
	
	srand((unsigned) time(&t));
	while(i<10){
		vetor[i] = rand() %100;
		i++;
	}
	
	i=0;
	while(i<10){
		printf("Numero: %d\n", vetor[i]);
		i++;
	}
	
	i=0;
	while(tam>0){
		while(i<(tam-1)){
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
				vetor[i]=vetor[i+1];
				vetor[i+1]=aux;
			}
			i++;
		}
		tam--;
		i=0;
	}
	
	i=0;
	while(i<10){
		printf("Numero vetor crescente: %d\n", vetor[i]);
		i++;
	}
}
