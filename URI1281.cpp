#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct produto
{
	char nome[51];
	float preco;
};

typedef struct produto PRODUTO;

int main()
{
	int Nconjuntos, quantItens, nItensCompra, quant;
	char teste[51];
	int i,j,k;
	float custo;
	PRODUTO* v;
	
	scanf("%d",&Nconjuntos);
	
	for(i=0; i< Nconjuntos; i++)
	{
		scanf("%d",&quantItens);
		
		v=(PRODUTO*)malloc(quantItens*sizeof(PRODUTO));
		
		for(j=0; j<quantItens; j++)
		{
			scanf("%s %f",v[j].nome,&v[j].preco);
		}
		
		scanf("%d",&nItensCompra);
		custo=0;
		
		for(j=0; j<nItensCompra; j++)
		{
			scanf("%s%d",teste,&quant);
			
			for(k=0; k<quantItens; k++)
			{
				if(strcmp(teste,v[k].nome)==0)
				{					
					custo=custo + (quant*v[k].preco);
				}
			}		
		}
		printf("R$ %.2f\n",custo);
		free(v);			
	}
	
return 0;
}
