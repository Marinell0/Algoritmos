int main(){
	int i=0, j=0, tam, aux, A[MAX];
	
	i=1;
	while(i<MAX){
		aux=A[i];
		j=i;
		while(aux<A[j-1] && j>0){
			j--;
			A[j+1]=A[j];
		}
		A[j]=aux;
		i++;
	}
	
	i=0;
	while(i<MAX){
		printf("%d\n", A[i]);
		i++;
	}
	return(0);
}
