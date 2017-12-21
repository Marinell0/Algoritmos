void Bubble(int tam, int *A){
	int i=0, j=0, aux;
	
	while(j<100){
		i=0;
		while(i<(tam-1)){
			if(A[i]>A[i+1]){
				aux=A[i];
				A[i]=A[i+1];
				A[i+1]=aux;
			}
			i++;
		}
		j++;
		tam--;
	}
}
