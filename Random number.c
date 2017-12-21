#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	time_t t;
	
	srand((unsigned) time(&t));
	for(i=0; i<100; i++){
		printf("%d\n", rand() %50);
	}
	return(0);
}
