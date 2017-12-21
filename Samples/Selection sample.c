void Selection(int tam, int *A){
	int i=0, j=0, aux, min;
	
	for(i=0; i<tam; i++){
		aux=A[i];
		for(j=i; j<tam; j++){
			if(A[j]<aux){
				min=j;
				aux=A[j];
			}
		}
		A[min]=A[i];
		A[i]=aux;
	}
}
