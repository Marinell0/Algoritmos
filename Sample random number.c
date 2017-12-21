#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=0;
	time_t t;
	
	srand((unsigned) time(&t));
	while(i<10){
		printf("%d\n", rand() %100);
		i++;
	}
}
