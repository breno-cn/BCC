#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no{
	int info;
	struct no *prox;
};

struct Fila{
	struct no *ini, *fim;
};

fila cria_fila(){
	fila f=(fila)malloc(sizeof(struct Fila));
	if(f!=NULL) f->ini=f->fim=NULL;
	return f;
}

int fila_vazia(fila f){
	return !(f->ini);
}

int insere_fim(fila f, int x){
	struct no *aux=(struct no *)malloc(sizeof(struct no));
	if(aux==NULL) return 0;
	aux->info=x;
	aux->prox=NULL;
	if(fila_vazia(f)) f->ini=aux;
	else f->fim->prox=aux;
	f->fim=aux;
	return 1;
}

int remove_ini(fila f, int *x){
	if(fila_vazia(f)) return 0;
	struct no *aux=f->ini;
	*x=aux->info;
	if(f->ini==f->fim) f->fim=NULL;
	f->ini=aux->prox;
	free(aux);
	return 1;
}

int imp_fila(fila f){
	if(fila_vazia(f)) return 0;
	struct no *aux=f->ini;
	printf("( ");
	while(aux!=NULL){
		printf("%d ", aux->info);
		aux=aux->prox;
	}
	printf(")\n");
return 1;
}