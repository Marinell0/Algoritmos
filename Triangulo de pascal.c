#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //Tamanho do vetor

int main(){
	int A[MAX][MAX], i=0, j=0;
	
	while(i<MAX){
		j=0;
		while(j<MAX){
			if((i==j || j==0)){
				A[i][j]=1;
			}else{
				A[i][j]=0;
			}
			printf("%d ", A[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	
	printf("\n\n------------------------------------------------\n\n");
	
	i=1;
	j=1;
	while(i<MAX){
		j=1;
		while(j<MAX){
			A[i][j]=(A[i-1][j-1]+A[i-1][j]);			
			j++;
		}
		i++;
	}
	
	
	i=0; 
	j=0;	
	while(i<MAX){
		j=0;
		while(j<MAX){
			printf("%d ", A[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	return(0);
}
