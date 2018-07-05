#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilha.h"
#include "fila.h"

struct Pilha{
	int info;
	struct Pilha *prox;
};

pilha cria_pilha(){
	return NULL;
}

int pilha_vazia(pilha p){
	return !p;
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
	*p=(*p)->prox;
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
	for(pilha aux=p;aux!=NULL;aux=aux->prox)
		printf("%d\n", aux->info);
	return 1;
}