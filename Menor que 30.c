//Falar a posição se o número for maior que 30.

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, vetor[100], posicao[100];
	
	while(i<10){
		printf("Preencha o vetor: ");
		scanf("%d", &vetor[i]);
		i++;
	}
	
	printf("\n");
	i=0;	
	while(i<10){
		if(vetor[i]>30){
			printf("Posicao %d\n", i);
		}
		i++;
	}
}
