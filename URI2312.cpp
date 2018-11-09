#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct pais
{
	char nome[51];
	int Mouro;
	int Mprata;
	int Mbronze;
};

typedef struct pais PAIS;

int main()
{
	int Npaises;
	int i,j;
	PAIS* v;
	PAIS aux;
	
	scanf("%d",&Npaises);
	
	v= (PAIS*)malloc(Npaises*sizeof(PAIS));
		
	for(i=0; i<Npaises; i++)
	{
		scanf("%s%d%d%d",v[i].nome, &v[i].Mouro, &v[i].Mprata, &v[i].Mbronze);
	}
	
	
	for(j=0; j<Npaises-1; j++)
	{
		for(i=0; i<Npaises-1; i++)
		{
			if(v[i].Mouro*pow(10,8)+v[i].Mprata*pow(10,4)+v[i].Mbronze < v[i+1].Mouro*pow(10,8)+v[i+1].Mprata*pow(10,4)+v[i+1].Mbronze)
			{
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
			}
			
			else if(v[i].Mouro*pow(10,8)+v[i].Mprata*pow(10,4)+v[i].Mbronze == v[i+1].Mouro*pow(10,8)+v[i+1].Mprata*pow(10,4)+v[i+1].Mbronze)
			{
				if(strcmp(v[i].nome,v[i+1].nome) > 0)
				{
					aux=v[i];
					v[i]=v[i+1];
					v[i+1]=aux;		
				}
			}
		}
	}
	
	for(i=0; i<Npaises; i++)
	{
		printf("%s %d %d %d\n",v[i].nome, v[i].Mouro, v[i].Mprata, v[i].Mbronze);
	}
	
	free(v);	
}

