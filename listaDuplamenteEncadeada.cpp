#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct lista
{
	char palavra[50];
	struct lista *prox;	
	struct lista *ant;
};

typedef struct lista LISTA;

LISTA * insere(LISTA *inicio, char palavra[50])
{
	LISTA * nodo = NULL;
	
	nodo = (LISTA*)malloc(sizeof(LISTA));
	
	strcpy(nodo->palavra, palavra);
	nodo->ant = NULL;
	nodo->prox = NULL;
	
	if(inicio == NULL)
	{
		inicio = nodo;
	}
	else if(strcasecmp(palavra, inicio->palavra) < 0)
	{
		nodo->prox = inicio;
		inicio->ant = nodo;
		inicio = nodo;
	}
	
	else 
	{
		LISTA *aux = inicio;
		while(aux->prox != NULL && strcasecmp(aux->palavra, palavra) < 0)
		{
			aux = aux->prox;	
		}
		
		if(strcasecmp(palavra, aux->palavra)>0)
		{
			nodo->ant = aux;
			aux->prox = nodo;
		}
		
		else
		{
			aux->ant->prox = nodo;
			nodo->ant = aux->ant;
			nodo->prox= aux;
			aux->ant = nodo;
		}
	}
	
return inicio;
}

void escreve(LISTA *inicio)
{
	LISTA *aux = inicio;
	
	while(aux != NULL)
	{
		printf("%s\n",aux->palavra);
		aux = aux->prox;
	}
}

int main()
{
	LISTA *inicio = NULL;
	
	inicio = insere(inicio, "zebra");
	inicio = insere(inicio, "cavalo");
	inicio = insere(inicio, "pinhao");
	inicio = insere(inicio, "feijao");
	inicio = insere(inicio, "banana");
	inicio = insere(inicio, "baleia");
	
	escreve(inicio);
		
return 0;
}
