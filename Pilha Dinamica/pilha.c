#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct Pilha{
    int info;
    struct Pilha *prox;
};

pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(pilha p){
    if(p==NULL) return true;
    return false;
}

int push(pilha *p, int x){
    pilha aux=(pilha)malloc(sizeof(struct Pilha));
    if(aux==NULL) return 0;
    aux->info=x;
    aux->prox=*p;
    *p=aux;
    return 1;
}

int pop(pilha *p, int *x){
    if(pilha_vazia(*p)) return 0;
    pilha aux=*p;
    *x=aux->info;
    (*p)=(*p)->prox;
    free(aux);
    return 1;
}

int ler_topo(pilha p, int *x){
    if(pilha_vazia(p)) return 0;
    *x=p->info;
    return 1;
}

int print(pilha p){
    if(p==NULL) return 0;
    pilha aux=p;
    while(aux!=NULL){
        printf("%d\n", aux->info);
        aux=aux->prox;
    }
    return 1;
}