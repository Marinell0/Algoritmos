#include <stdio.h>
#include <stdlib.h>

int main(){
	char A[21][21]; 
	int i, j;

	for(i=0; i<21; i++){
		for(j=0; j<21; j++){
			A[i][j]='-';
		}
	}

	
	for(i=0; i<11; i++){
		for(j=10; j<11+i; j++){
			A[i][j]='*';
			A[20-i][j]='*';
			A[j][i]='*';
			A[20-j][i]='*';
		}
	}
	
	for(i=0; i<21; i++){
		for(j=0; j<21; j++){
			printf("%c ", A[i][j]);
		}
		printf("\n");
	}
	return(0);
}
