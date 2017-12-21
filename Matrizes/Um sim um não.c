#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j;
	char A[21][21];
	
	for(i=0; i<21; i=i+2){
		for(j=0; j<21; j=j+2){
			A[i][j]='*';
			A[i][j+1]='-';
		}
	}
	for(i=1; i<21; i=i+2){
		for(j=0; j<21; j=j+2){
			A[i][j]='-';
			A[i][j+1]='*';
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
