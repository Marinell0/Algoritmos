#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=0, tam=0, vetor[100000], hist[10], j=0;
	time_t t;
	
	printf("Tamanho do vetor: ");
	scanf("%d", &tam);
	
	i=0;
	while(i<tam){
		vetor[i]=0;
		i++;
	}
	
	i=0;
	srand((unsigned) time(&t));
	while(i<tam){
		vetor[i]=rand() %10;
		printf("\n%d", vetor[i]);
		i++;
	}
	i=0;
	while(j<10){
		while(i<tam){
			if(vetor[i]==j){
				hist[j]++;
			}
			i++;
		}
		j++;
	}
	
	printf("\n");
	
	i=0;
	while(i<tam){	
		printf("\n%d", hist[i]);
		i++;
	}
}
