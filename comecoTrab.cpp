#include<stdio.h>
#include<stdlib.h>

struct lista
{
	char letra;
	struct lista *prox;
};

typedef struct lista LISTA;

LISTA *insere(LISTA *inicio, char c);
void escreve(LISTA *inicio);

int main()
{
	LISTA *inicio = NULL;
	
	inicio = insere(inicio, 'm');
	inicio = insere(inicio, 'y');
	inicio = insere(inicio, 'c');
	inicio = insere(inicio, 'b');
	inicio = insere(inicio, 't');
	inicio = insere(inicio, 'j');
	inicio = insere(inicio, 'z');
	escreve(inicio);	
	
return 0;
}

LISTA *insere(LISTA *inicio, char c)
{
	LISTA *nodo = NULL;
	nodo = (LISTA *)malloc(sizeof(LISTA));
		
	nodo->letra = c;          
	nodo->prox = NULL;      // le-se: "o cara apontado por nodo campo prox"
	
	if(inicio == NULL)
	{
		inicio = nodo;
	}
	
	else if(c < inicio->letra )
	{
		nodo->prox = inicio;
		inicio = nodo;
	}
	
	else
	{
		LISTA *aux1 = inicio->prox;    
		LISTA *aux2 = inicio;
		
		while(aux1 != NULL && aux1->letra < c)
		{
			aux1 = aux1->prox;
			aux2 = aux2->prox;
		}
		aux2->prox = nodo;
		nodo->prox = aux1;
		
		if(aux1 == NULL)
		{
			aux2->prox = nodo;
		}
		
		else
		{
			aux2->prox = nodo;
			nodo->prox = aux1;
		}
	}
	
return(inicio);	
}

void escreve(LISTA *inicio)
{
	LISTA *aux = inicio;
	
	while(aux != NULL)
	{
		printf("%c\n",aux->letra);
		aux = aux->prox;
	}
}
