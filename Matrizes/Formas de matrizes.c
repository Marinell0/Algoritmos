#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j, a=1;
	char A[21][21], B[21][21], C[21][21], D[21][21], E[21][21];
	
	printf("------------------------------- MATRIZ %d --------------------------------\n\n", a);
	
	/*
	
	* * * * *
	* * * * -
	* * * - -
	* * - - -
	* - - - -
	
	Use matriz A
	*/
	
	for(i=0; i<21; i++){
		for(j=0; j<(21-i); j++){
			A[i][j]='*';
		}
	}
	
	for(i=21; i>0; i--){
		for(j=(21-i); j<21; j++){
			A[i][j]='-';
		}
	}
	
	for(i=0; i<21; i++){
		for(j=0; j<21; j++){
			printf("%c ", A[i][j]);
		}
		printf("\n");
	}
	
	a=2;
	printf("\n\n-------------------------------- MATRIZ %d --------------------------------\n\n", a);
	
	/*
	
	* * * * *
	- * * * *
	- - * * *
	- - - * *
	- - - - *
	
	Use matriz B
	*/
	
	for(i=20; i>=0; i--){
		for(j=20; j>=i; j--){
			B[i][j]='*';
		}
	}
	
	for(i=1; i<21; i++){
		for(j=0; j<i; j++){
			B[i][j]='-';
		}
	}
	
	for(i=0; i<21; i++){
		for(j=0; j<21; j++){
			printf("%c ", B[i][j]);
		}
		printf("\n");
	}
	
	a++;
	printf("\n\n-------------------------------- MATRIZ %d --------------------------------\n\n", a);
	
	/*
	
	* * * - -
	* * - - -
	* - - - *
	- - - * *
	- - * * *
	
	Use matriz C
	*/
	
	
	for(i=0; i<21; i++){
		C[20-i][i-1]='-';
		C[20-i][i]='-';
		C[20-i][i+1]='-';
	}
	
	for(i=0; i<19; i++){
		for(j=0; j<19-i; j++){
			C[i][j]='*';
			C[20-i][20-j]='*';
		}
	}
	

	
	for(i=0; i<21; i++){
		for(j=0; j<21; j++){
			printf("%c ", C[i][j]);
		}
		printf("\n");
	}
	
	
	a++;
	printf("\n\n-------------------------------- MATRIZ %d --------------------------------\n\n", a);
	
	/*
	
	- - * - -
	- * * * -
	* * * * *
	- - - - -
	- - - - -
	
	Use matriz D
	*/
	
	/*
	for(i=0; i<21; i++){
		for(j=0; j<21; j++){
			printf("%c ", D[i][j]);
		}
		printf("\n");
	}
	*/
	
	a++;
	printf("\n\n-------------------------------- MATRIZ %d --------------------------------\n\n", a);
	
	/*
	
	* * * * *
	- * * * -
	- - * - -
	- * * * -
	* * * * *
	
	Use matriz E
	*/
	
	for(i=0; i<21; i++){
		for(j=i; j<21-i; j++){
			E[i][j]='*';
			E[20-i][j]='*';
		}
	}
	
	
	for(i=0; i<21; i++){
		for(j=0; j<21; j++){
			printf("%c ", E[i][j]);
		}
		printf("\n");
	}
	
	return(0);
}
