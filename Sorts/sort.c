#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){

 	FILE * fP;
	fP = fopen ("sort.txt", "a");



	int indice;

	printf("Digíte o tamanho do vetor: "); scanf("%d", &indice);
	
	int vet[indice], a, b, c=0,  aux;


	srand(time(NULL));
	
	for(a=0;a<indice;a++){
		vet[a]= rand() % 101;
		printf("|%d| ", vet[a]); 
	}
	printf("\n");

	for(a=0;a<indice;a++){
		for(b=c;b<indice;b++){
			if(vet[a]>vet[b]){
				aux = vet[b];
				vet[b] = vet[a];
				vet[a] = aux;
			}
			else{
			}
		}
	c++;	
	}
	
	fprintf(fP, "\n");

	for(a=0;a<indice;a++){
		fprintf(fP, "|%d| ", vet[a]);
		printf("|%d| ", vet[a]);
	}	
	

					


}

