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

void  imp_lista(lista l){
	lista aux;
	aux=l;
	printf("( ");
	while(aux!=NULL){
		printf("%d ", aux->info);
		aux=aux->prox;
	}
	printf(")\n");
}

int lista_vazia(lista l){
	if(l==NULL) return true;
	else return false;
}

int insere_elem(lista *l, int n){
	lista aux;
	aux=(lista)malloc(sizeof(struct no));
	if(aux==NULL) return 0;
	aux->info=n;
	aux->prox=*l;
	*l=aux;
	return 1;
}

int remove_elem(lista *l, int n){
	if(lista_vazia(*l)) return 0;
	lista aux;
	aux=*l;
	if((*l)->info==n){
		(*l)=(*l)->prox;
		free(aux);
		return 1;
	}
	while(aux!=NULL && aux->prox->info!=n)
		aux=aux->prox;
	if(aux==NULL) return 0;
	lista aux2;
	aux2=aux->prox;
	aux->prox=aux2->prox;
	free(aux2);
	return 1;
}

//PROTOTIPO, desempenho baixo, fazer depois sem usar função!
int remove_todos(lista *l, int n){
	int i=0;
	lista aux;
	aux=(lista)malloc(sizeof(struct no));
	aux=*l;
	while(aux!=NULL){
		if(aux->info==n){
			remove_elem(l,n);
			i++;
		}
		aux=aux->prox;
	}
	return i;
}