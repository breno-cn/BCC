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

int remove_todos(lista *l, int n){
	if(lista_vazia(*l)) return 0;
	lista aux;
	aux=(*l);
	lista aux2;
	while(aux->prox!=NULL){
		if(aux->info==n) remove_elem(l,n);
		aux=aux->prox;
	}
	remove_elem(l,n);
	return 1; 
}

int inserir_final(lista *l, int n){
	lista aux=*l;
	while(aux->prox!=NULL)
		aux = aux->prox;
	lista aux2=(lista)malloc(sizeof(struct no));
	aux2->info=n;
	aux->prox=aux2;
	aux2->prox=NULL;
	return 1;
}

int remove_impares(lista *l){
	if(lista_vazia(*l)) return 0;
	lista aux=(*l);
	while(aux!=NULL){
		if(aux->info%2!=0) remove_elem(l,aux->info);
		aux=aux->prox;
	}
	return 1;
}

int maior(lista l){
	if(lista_vazia(l)) return 0;
	int maior=l->info;
	lista aux;
	aux=(lista)malloc(sizeof(struct no));
	aux=l;
	while(aux->prox!=NULL){
		if(maior < aux->info) maior=aux->info;
		aux=aux->prox;
	}
	return maior;
}

int tamanho(lista l){
	if(lista_vazia(l)) return 0;
	int i=0;
	lista aux=l;
	while(aux!=NULL){
		aux=aux->prox;
		i++;
	}
	return i;
}

lista concatenar(lista *l1, lista *l2){
	lista aux1=(*l1);
	lista aux2=(*l2);
	lista l3=criar_lista();
	while(aux1!=NULL){
		insere_elem(&l3,aux1->info);
		aux1=aux1->prox;
	}
	while(aux2){
		insere_elem(&l3,aux2->info);
		aux2=aux2->prox;
	}
	return l3;
}