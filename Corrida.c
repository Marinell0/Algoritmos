/*3)Durante uma corrida de automóveis com N voltas de duração foram anotados para um piloto, na ordem, os tempos registrados em cada volta. Fazer um programa em C para ler os tempos das N voltas, calcular e imprimir:
• melhor tempo;
• a volta em que o melhor tempo ocorreu;
• tempo médio das N voltas;*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	float tempo[100], media=0, melhor=100000000;
	int n, voltas, melhor2, i=0;
	
	printf("Quantas voltas foram: ");
	scanf("%d", &voltas);
	
	while(i<voltas){
		printf("\nTempo da volta %d: ", i);
		scanf("%f", &tempo[i]);
		i++;
	}
	
	i=0;
	while(i<voltas){
		media=(media + tempo[i]);
		i++;

	}

	i=0;
	while(i<voltas){
		if(tempo[i]<melhor){
			melhor=tempo[i];
			melhor2=i;
		}
		i++;
	}
	
	media = (media/voltas);
	printf("\n");
	printf("\nMedia e igual a %f", media);
	printf("\nA melhor volta foi a de tempo %f, que foi a volta de numero %d", melhor, melhor2);
	
	return(0);
}
