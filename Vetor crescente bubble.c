#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=0, vetor[1000], tam=10, aux;
	
	while(i<10){
		printf("Numero para o vetor: ");
		scanf("%d", &vetor[i]);
		i++;
	}
	i=0;
	while(tam>0){
		while(i<tam-1){
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
	for(i=0; i<10; i++){	
		printf("%d\n", vetor[i]);
	}
	return(0);
}
