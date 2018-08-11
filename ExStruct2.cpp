#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define P 3
#define T 2

struct piloto
{
	char nome[50];
	char equipe[50];
	int tempos[T];
	float media;
};

typedef struct piloto PILOTO; //renomeia o nome da struct para facilitar a escrita do codigo

void lePilotos(PILOTO pilotos[P]);

void escrevePilotos(PILOTO pilotos[P]);

PILOTO escolheAMelhorMedia(PILOTO pilotos[P]);

int main()
{
	PILOTO pilotos[P], m;
	
	lePilotos(pilotos);
	
	escrevePilotos(pilotos);
	
	m = escolheAMelhorMedia(pilotos);
	
	printf("\nA melhor media eh a do piloto %s\n",m.nome);

return 0;	
}

void lePilotos(PILOTO pilotos[P])
{
	int i, j, posicao, somatorio;
	
	for(i=0;i<P;i++)
	{
		printf("Escreva o nome do piloto:\n");
		fgets(pilotos[i].nome,50,stdin);
		
		posicao = strlen(pilotos[i].nome)-1;   
		pilotos[i].nome[posicao]='\0';          // Realiza o preenchimento da penultima posição da string com um '\0' para evitar uma quebra extra de linha
		
		printf("Escreva o nome da equipe do piloto:\n");
		fgets(pilotos[i].equipe,50,stdin);
		
		posicao = strlen(pilotos[i].equipe)-1; 
		pilotos[i].equipe[posicao]='\0';         // Realiza o preenchimento da penultima posição da string com um '\0' para evitar uma quebra extra de linha
		
		somatorio=0;
		for(j=0;j<T;j++)
		{
			printf("Digite o tempo %d do piloto %d\n",j+1,i+1);
			scanf("%d", &pilotos[i].tempos[j]);
			somatorio+=pilotos[i].tempos[j];	
		}
		
		pilotos[i].media=(float)somatorio/T;    //Realiza o Casting para float do valor do somatorio que eh inteiro
		
		fflush(stdin);			
	}
	printf("\n");
}

void escrevePilotos(PILOTO pilotos[P])
{
	int i,j;
	
	for(i=0;i<P;i++)
	{
		printf("Piloto %d\n\n",i+1);
		printf("Nome: %s\n",pilotos[i].nome);
		printf("Equipe: %s\n",pilotos[i].equipe);
		
		for(j=0; j<T; j++)
		{
			printf("O tempo %d do piloto %s eh:%d\n",j+1,pilotos[i].nome,pilotos[i].tempos[j]);
		}
		
		printf("Media %.2f\n",pilotos[i].media);
	}
}

PILOTO escolheAMelhorMedia(PILOTO pilotos[P])
{
	int i;
	PILOTO m;
	m=pilotos[0];
	
	for(i=1;i<P;i++)
	{
		if(pilotos[i].media < m.media)
			m=pilotos[i];
	}
	
return m;	
}
