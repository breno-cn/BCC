#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

struct no{
    int info;
    struct no *prox, *ant;
};

struct Deque{
    struct no *ini, *fim;
};

deque cria_deque(){
    deque d=(deque)malloc(sizeof(struct Deque));
    if(d!=NULL) d->ini=d->fim=NULL;
    return d;
}

int deque_vazia(deque d){
    return !(d->ini);
}

int insere_ini(deque d, int x){
    struct no *aux=(struct no *)malloc(sizeof(struct no));
    if(aux==NULL) return 0;
    aux->info=x;
    aux->ant=NULL;
    if(deque_vazia(d)){
        aux->prox=NULL;
        d->ini=d->fim=aux;
        return 1;
    }
    aux->prox=d->ini;
    d->ini=aux;
    return 1;
}

int insere_fim(deque d, int x){
    struct no *aux=(struct no *)malloc(sizeof(struct no));
    if(aux==NULL) return 0;
    aux->prox=NULL;
    aux->info=x;
    if(deque_vazia(d)){
        aux->ant=NULL;
        d->ini=d->fim=aux;
        return 1;
    }
    d->fim->prox=aux;
    aux->ant=d->fim;
    d->fim=aux;
    return 1;
}

int remove_ini(deque d, int *x){
    if(deque_vazia(d)) return 0;
    struct no *aux=d->ini;
    *x=aux->info;
    if(d->ini==d->fim){
        d->ini=d->fim=NULL;
        free(aux);
        return 1;
    }
    d->ini=aux->prox;
    d->ini->ant=NULL;
    free(aux);
    return 1;
}

int remove_fim(deque d, int *x){
    if(deque_vazia(d)) return 0;
    struct no *aux=d->fim;
    *x=aux->info;
    if(d->ini==d->fim){
        d->ini=d->fim=NULL;
        free(aux);
        return 1;
    }
    d->fim=aux->ant;
    d->fim->prox=NULL;
    free(aux);
    return 1;
}

int imp_deque(deque d){
    if(deque_vazia(d)) return 0;
    printf("( ");
    for(struct no *aux=d->ini;aux!=NULL;aux=aux->prox)
        printf("%d ", aux->info);
    printf(")\n");
    return 1;
}