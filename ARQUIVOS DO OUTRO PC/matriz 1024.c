#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j, k, l, A[512][512], B[8][8], media;
	time_t t;
	
	srand((unsigned) time(&t));
	for(i=0; i<512; i++){
		for(j=0; j<512; j++){
			A[i][j]=rand() %255;
		}
	}
/*	
	for(i=0; i<512; i++){
		for(j=0; j<512; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
*/	
	for(i=0; i<8; i++){
		for(k=64*i; k<64*(i+1); k++){
			for(j=0; j<8; j++){
				for(l=64*j; l<64*(j+1); l++){
					media=media+A[k][l];
				}
				media=media/4096;
				B[i][j]=media;
			}
		}
	}
	printf("\n\n\n\n");
	
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
}
