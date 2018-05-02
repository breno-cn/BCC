#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
	int info;
	struct no *prox;
};

lista criar_lista(){
	return NULL;
}

int lista_vazia(lista l){
	if(l==NULL) return true;
	else return false;
}

void imp_lista(lista l){
	printf("( ");
	lista aux;
	aux=l;
	while(aux!=NULL){
		printf("%d ", aux->info);
		aux=aux->prox;
	}
	printf(")\n");
}

int insere_ord(lista *l, int n){
	lista aux;
	aux=(lista)malloc(sizeof(struct no));
	if(aux==NULL) return 0;
	aux->info=n;
	if(lista_vazia(*l) || n<=(*l)->info){
		aux->prox=*l;
		*l=aux;
		return 1;
	}
	lista aux2;
	aux2=*l;
	while(aux2->prox!=NULL && aux2->prox->info<n)
		aux2=aux2->prox;
	aux->prox=aux2->prox;
	aux2->prox=aux;
	return 1;
}

int remove_ord(lista *l, int n){
	if(lista_vazia(*l)) return 0;
	lista aux;
	aux=(lista)malloc(sizeof(struct no));
	aux=*l;
	while(aux->prox!=NULL && aux->prox->info!=n)
		aux=aux->prox;
	if(aux->prox==NULL || aux->prox->info!=n) return 0;
	lista aux2;
	aux2=(lista)malloc(sizeof(struct no));
	aux2=aux->prox;
	aux->prox=aux2->prox;
	free(aux2);
	return 1;
}

lista intercala(lista l1, lista l2){
	lista aux1;
	aux1=l1;
	lista aux2;
	aux2=l2;
	lista l3;
	l3=criar_lista();
	while(aux1!=NULL){
		insere_ord(&l3,aux1->info);
		aux1=aux1->prox;
	}
	while(aux2!=NULL){
		insere_ord(&l3,aux2->info);
		aux2=aux2->prox;
	}
	return l3;
}