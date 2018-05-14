#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
	int info;
	struct no *prox;
	struct no *ant;
};

lista cria_lista(){
	return NULL;
}

int lista_vazia(lista l){
	if(l==NULL) return true;
	else return false;
}

int insere_elem(lista *l, int n){
	lista aux=(lista)malloc(sizeof(struct no));
	if(aux==NULL) return 0;
	aux->info=n;
	aux->ant=NULL;
	aux->prox=(*l);
	if(!lista_vazia(*l)) (*l)->ant=aux;
	(*l)=aux;
	return 1;
}

int remove_elem(lista *l, int n){
	if(lista_vazia(*l)) return 0;
	lista aux=(*l);
	while(aux->prox!=NULL && aux->info!=n)
		aux=aux->prox;
	if(aux->info!=n) return 0;
	if(aux->prox!=NULL) aux->prox->ant=aux->ant;
	if(aux->ant!=NULL) aux->ant->prox=aux->prox;
	if(aux==(*l)) (*l)=aux->prox;
	free(aux);
	return 1;
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

int print_lista(lista l){
	if(lista_vazia(l)) return 0;
	lista aux=l;
	printf("( ");
	while(aux!=NULL){
		printf("%d ", aux->info);
		aux=aux->prox;
	}
	printf(")\n");
	return 1;
}

int remover_todos(lista *l, int n){
	if(lista_vazia(*l)) return 0;
	lista aux=(*l);
	while(aux->prox!=NULL){
		if(aux->info==n) remove_elem(l,n);
		aux=aux->prox;
	}
	return 1;
}

int remove_maior(lista *l){
	int maior=(*l)->info;
	lista aux=(*l);
	while(aux->prox!=NULL){
		if(aux->info > maior) maior=aux->info;
		aux=aux->prox;
	}
	remove_elem(l,maior);
	return 1;
}

int remove_multiplos(lista *l){
	if(lista_vazia(*l)) return 9;
	lista aux=(*l);
	while(aux->prox!=NULL){
		if(aux->info%3==0) remove_elem(l,aux->info);
		aux=aux->prox;
	}
	return 1;
}