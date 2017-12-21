#include <stdio.h>
#include <stdlib.h>

int main(){
	int A[3][4], B[3][4], i, j, k, l, aux, aux2, var1, var2;
	
	//---------------------------------ENTRADA DA MATRIZ---------------------------------
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			printf("Linha %d, coluna %d: ", i, j);
			scanf("%d", &A[i][j]);
		}
	}
	
	//---------------------------------CALCULO DA SIMPLIFICAÇÃO--------------------------
	aux=1;
	aux2=0;
	
	while(aux != aux2){
		for(i=1; i<20; i++){
			for(j=1; j<20; j++){
				if(A[0][0] > 0 && A[1][0] > 0 || A[0][0] < 0 && A[1][0] < 0){
					aux=i*A[0][0];
					aux2=j*A[1][0];
				}else{
					aux=i*A[0][0];
					aux2=-j*A[1][0];
				}
			}
		}
		var1=i;
		var2=j;
	}
	if(aux2<0){
		var2=-var2;
	}
	for(l=0; l<4; l++){
		B[0][l]=A[0][l];
		B[1][l]=((var1*A[0][l])+(var2*A[1][l]));
	}
	
	//----------------------------------...FIZ MERDA-------------------------------------
	/*
	for(i=1; i<20; i++){
		for(j=1; j<20; j++){
			if((A[0][0] < 0 && A[1][0] > 0) && (A[0][0] == (-A[1][0]))){ //Se o x da primeira linha for negativo e o da segunda positivo
				for(l=0; l<4; l++){
					B[0][l]=(i*A[0][l]);
				}
				for(l=0; l<4; l++){
					B[1][l]=(j*A[1][l]);
				}
			}else{
				if((A[0][0] > 0 && A[1][0] > 0) && (A[0][0] == A[1][0])){ // X1 positivo X2 positivo
					for(l=0; l<4; l++){
						B[0][l]=(i*A[0][l]);
					}
					for(l=0; l<4; l++){
						B[1][l]=((-j)*A[1][l]);
					}
				}else{
					if((A[0][0] < 0 && A[1][0] < 0) && (A[0][0] == A[1][0])){ //Os 2 X negativos
						for(l=0; l<4; l++){
							B[0][l]=(i*A[0][l]);
						}
						for(l=0; l<4; l++){
							B[1][l]=((-j)*A[1][l]);
						}
					}else{
						if((A[0][0] > 0 && A[1][0] < 0) && (A[0][0] == (-A[1][0]))){ //Primeiro X positivo e segundo negativo
							for(l=0; l<4; l++){
								B[0][l]=(i*A[0][l]);
							}
							for(l=0; l<4; l++){
								B[1][l]=j*A[1][l];
							}
						}
					}
				}
			}
		}
	}
	for(l=0; l<4; l++){
		B[1][l]=(B[1][l]+B[0][l]);
	}
	*/
	
	//---------------------------------PRINT DAS MATRIZES---------------------------------
	
	printf("\n\n------------------------------------MATRIZ A------------------------------------\n\n");
	
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n------------------------------------MATRIZ B------------------------------------\n\n");
	
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	
	return(0);
}
