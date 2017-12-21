#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, fatorial;
	
	printf("Numero para ser fatoriado: ");
	scanf("%d", &fatorial);
	i=fatorial-1;
	while(i>1){
		fatorial=fatorial*i;
		i=i-1;
	}
	printf("\nfatorial: %d", fatorial);
	getch();
	return 0;
}
