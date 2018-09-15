/*EXEMPLO DE ALOCAÇÃO DINAMICA*/

#include<stdio.h>
#include<stdlib.h>

#define N 1000000000

int main()
{
	int i;
	int *vet;
	
	vet= (int *)malloc(N*sizeof(int)); 
	
	vet= (int *)calloc(N, sizeof(int)); //limpa antes de armazenar
	
	for(i=0; i<N; i++)
	{
		vet[i]=0;
	}
	
	free(vet);
	
return 0;
}
