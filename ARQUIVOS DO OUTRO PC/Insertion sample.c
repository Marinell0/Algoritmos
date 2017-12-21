void Insertion(int tam, int *A){
	int i=0, j=0, aux;
	
	i=1;
	for(i=1; i<tam; i++){
		aux=A[i];
		j=i;
		while(aux<A[j-1] && j>0){
			j--;
			A[j+1]=A[j];
		}
		A[j]=aux;
	}
}
