#include <stdio.h>
#include <stdlib.h>

int main(){
	char A[11][11]; 
	int i, j;
	time_t t;
	
	for(i=0; i<11; i++){
		for(j=0; j<11; j++){
			A[i][j]='-';
		}
	}

	for(i=0; i<11; i++){
		A[i][5-i]='*';
	}
	
	for(i=0; i<11; i++){
		for(j=0; j<11; j++){
			printf("%c ", A[i][j]);
		}
		printf("\n");
	}
	return(0);
}
