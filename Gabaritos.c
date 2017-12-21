//O exercício pede para ver uma prova com 30 questões de um número de alunos que eu esqueci. Este programa funciona perguntando quantas questões e quantos alunos na sala para se automatizar.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int alunos, i=0, aux=0, questoes;
    char gabarito[1000], resposta[1000], acertosind[1000];
    
    printf("Quantos alunos tem na sua sala: ");
    scanf("%d", &alunos);
    printf("\n");
    printf("Quantas questoes na prova: ");
    scanf("%d", &questoes);
    printf("\n");
            
    while(i<questoes){
        printf("Resposta da questao %d: ", i);
        scanf(" %c", &gabarito[i]);
        i++;
    }
    printf("\n");
    
    i=0;
    aux=0;
    while(aux<alunos){
    	acertosind[0]=0;
        while(i<questoes){
        	printf("Resposta do aluno %d para a questao %d: ", aux, i);
        	scanf(" %c", &resposta[i]);
        		if(resposta[i]==gabarito[i]){
        			acertosind[aux]=(acertosind[aux]+1);
        		}
        	i++;
   		}
   		i=0;
   		aux++;
	}
	printf("\n");
	aux=0;
	while(aux<alunos){
		printf("O aluno %d acertou %d questoes.\n", aux, acertosind[aux]);
		aux++; 
	}
	getch();
	return(0);
}
