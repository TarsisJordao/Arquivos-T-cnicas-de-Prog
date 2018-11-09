#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int val;	
	struct lista *prox;	
};

typedef struct lista LISTA;

LISTA *insere (LISTA *inicio, int n)    //funcao retorna um ponteiro de um struct tipo lista 
{
	LISTA *nodo = NULL;  //Declaração de um ponteiro tipo LISTA
	
	nodo = (LISTA *)malloc(sizeof(LISTA));	
	
	(*nodo).val = n;    // o ponteiro nodo aponta para o compo val da struct e recebe n
	nodo->prox = NULL;  // '->' Eh outra maneira de dizer que o ponteiro nodo aponta para o compo prox da struct
	
	(*nodo).prox = inicio;
	inicio = nodo; 

return inicio;
}

LISTA *insereFinal(LISTA *inicio, int n)
{
	LISTA *nodo = NULL;
	LISTA *aux = NULL;
	
	nodo = (LISTA *)malloc(sizeof(LISTA));
	
	(*nodo).val = n;
	(*nodo).prox = NULL;
	
	if(inicio == NULL)	// caso a lista esteja vazia ele cai nessa condição
	{
		inicio = nodo;
	}
	
	else
	{
		aux = inicio;	
		
		while((*aux).prox != NULL) // testa se o ponteiro da struct eh nulo
		{
			aux = (*aux).prox;    // "incrementa a lista"
		}
		
		(*aux).prox = nodo;		
	}
	
	return inicio;
}

void escreve(LISTA *inicio)
{
	LISTA *aux = inicio;  // variavel auxiliar para nao perder o endereço inicial da lista
	
	while(aux!=NULL)      // condição pois como o ponteiro da struct aponta para NULL significa que eh o fim da lista
	{
		printf("%d\n", (*aux).val);   // escreve o val da lista apontado por 'aux'
		aux = (*aux).prox;            //o ponteiro aux recebe o campo prox do aux "anterior" para "incrementar a lista" e entrar na condição do laço
	}
}

int main()
{
	LISTA *lista1 = NULL;
	
	lista1 = insere(lista1, 5);
	lista1 = insere(lista1, 4);
	lista1 = insere(lista1, 3);
	lista1 = insere(lista1, 2);

	lista1 = insereFinal(lista1, 1);
	
	escreve(lista1);
	
	
return 0;
}
