#include <stdio.h>
#include <stdlib.h>

/*----------------------------------*/
struct lista{
    int num;
    struct lista *prox;
};
typedef struct lista LISTA;

/*----------------------------------*/
LISTA * insere(LISTA *l, int num){

    LISTA *nodo = (LISTA *)malloc(sizeof(LISTA));
    nodo->num = num;
    nodo->prox = NULL;

    if ( l == NULL){
        l = nodo;
    }
    else{
        LISTA *aux = l;
        while ( aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = nodo;
    }
    return l;
}

/*----------------------------------*/
void escreve(LISTA *l){
    LISTA *aux = l;
    while ( aux != NULL ){
        printf("Valor: %d\n", aux->num);
        aux = aux->prox;
    }
}
/*----------------------------------*/
LISTA * remover(LISTA *l){
    LISTA *inicio = l;

    if ( inicio != NULL){
        LISTA *ant = l;
        LISTA *atual= l->prox;
        while ( atual->prox!=NULL){
            ant = ant->prox;
            atual = atual->prox;
        }
        ant->prox = NULL;
        free(atual);
    }
    return inicio;


}
/*----------------------------------*/
void main(){
    LISTA *l = NULL;

    l = insere(l, 3);
    l = insere(l, 17);
    l = insere(l, 5);
    l = insere(l, 12);
    l = insere(l, 1);

    printf("--------------------\n");
    escreve(l);

    l = remover(l);

    printf("--------------------\n");
    escreve(l);

    l = remover(l);

    printf("--------------------\n");
    escreve(l);
}

