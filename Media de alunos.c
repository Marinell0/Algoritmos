//Pegar a média de 10 alunos de uma determinada disciplina e determinar o número de alunos que tiveram nota superior a média.

#include <stdio.h>
#include <stdlib.h>

int main(){
	float vetor [100], media=0;
	int i=0, maior;
	
	while(i<10){
		printf("Nota do aluno %d: ", i);
		scanf("%f", &vetor[i]);
		media=media+vetor[i];
		i++;
	}
	i=0;
	media=media/10;
	printf("\nA media e %f\n\n", media);
	while(i<10){
		if(vetor[i]>media){
			maior++;
		}
		i++;
	}
	if(maior==1){
		printf("%d aluno foram maior que a media na sala.", maior);
	}else{
		printf("%d alunos foram maior que a media na sala.", maior);
	}
	return(0);
}
