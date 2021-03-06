#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
	int info;
	struct no *prox;
};

lista criar_lista(){
	lista cabecalho;
	cabecalho=(lista)malloc(sizeof(struct no));
	if(cabecalho!=NULL){
		cabecalho->info=0;
		cabecalho->prox=NULL;
	}
	return cabecalho;
}

int lista_vazia(lista l){
	if(l->prox==NULL) return true;
	else return false;
}

int insere_ord(lista *l, int n){
	lista aux;
	aux=(lista)malloc(sizeof(struct no));
	if(aux==NULL) return 0;
	if(lista_vazia(*l)){
		aux->info=n;
		(*l)->prox=aux;
		(*l)->info++;
		return 1;
	}
	if(n<=(*l)->prox->info){
		aux->info=n;
		aux->prox=(*l)->prox;
		(*l)->prox=aux;
		(*l)->info++;
		return 1;
	}
	aux->info=n;
	lista aux2;
	aux2=*l;
	while(aux2->prox!=NULL && aux2->prox->info<n)
		aux2=aux2->prox;
	aux->prox=aux2->prox;
	aux2->prox=aux;
	(*l)->info++;
	return 1;
}

int remove_elem(lista *l, int n){
	if(lista_vazia(*l)) return 0;
	lista aux;
	aux=(lista)malloc(sizeof(struct no));
	aux=(*l);
	while(aux->prox!=NULL && aux->prox->info!=n)
		aux=aux->prox;
	if(aux->prox==NULL || aux->prox->info!=n) return 0;
	lista aux2;
	aux2=(lista)malloc(sizeof(struct no));
	aux2=aux->prox;
	aux->prox=aux2->prox;
	free(aux2);
	(*l)->info--;
	return 1;
}

void imprime_lista(lista l){
	int i;
	lista aux=l->prox;
	printf("( ");
	while(aux!=NULL){
		printf("%d ", aux->info);
		aux=aux->prox;
	}
	printf(")\n");
}

int tamanho(lista l){
	return l->info;
}