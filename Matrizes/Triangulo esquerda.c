#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j;
	char A[21][21];
	
	for(i=0; i<21; i++){
		for(j=0; j<21-i; j++){
			A[i][j]='*';
		}
	}
	for(i=1; i<21; i++){
		for(j=21; j>21-i; j--){
			A[i][j]='-';
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
