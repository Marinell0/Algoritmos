#include <stdio.h>
#include <stdlib.h>

int main(){
	int n[6], i, faces[1000], jogadas;
	time_t t;
	
	while(i<6){
		n[i]=0;
		i++;
	}
	
	printf("Quantas jogadas de dado: ");
	scanf("%d", &jogadas);
	
	srand((unsigned) time(&t));
	for(i=0; i<jogadas; i++){
		faces[i] =(rand() %6);
		n[faces[i]]++;
	}
	printf("\n");
	for(i=0; i<6; i++){
		printf("\n Cairam %d jogadas com a face %d", n[i], i+1);
	}
	return(0);
}
