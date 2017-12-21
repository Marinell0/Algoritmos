//O exercicio fala para ler e colocar o vetor na ordem crescente.

#include <stdio.h>
#include <stdlib.h>

int main(){
	int vetor[100], i=0, c=0, n=0, tam=0;
	
	while(tam<10){
		printf("Numero para o vetor: ");
		scanf("%d", &n);
		
		i=tam-1;
		if(tam==0){
			vetor[0]=n;
		}else{
			if(tam==1 && n>vetor[0]){
				vetor[1]=n;
			}else{
				while(n<vetor[i] && i>0){
					vetor[i+1]=vetor[i];
					i--;
				}
				vetor[i]=n;
			}
		}
		tam++;
	}
	
	printf("\n");
	
	c=0;
	for(c=0; c<10; c++){	
		printf("%d\n", vetor[c]);
	}
	return(0);
}
