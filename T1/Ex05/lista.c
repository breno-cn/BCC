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

int remove_ord(lista *l, int n){
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

lista intercala(lista *l1, lista *l2){
	lista l3=criar_lista();
	lista aux1=(*l1)->prox;
	lista aux2=(*l2)->prox;
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

int remove_impar(lista *l){
	if(lista_vazia(*l)) return 0;
	lista aux=(*l);
	while(aux!=NULL){
		if(aux->info%2!=0) remove_ord(l,aux->info);
		aux=aux->prox;
	}
	return 1;
}

int menor(lista l){
	int menor=l->prox->info;
	lista aux=l;
	while(aux->prox!=NULL){
		if(menor > aux->info) menor=l->info;
		aux=aux->prox;
	}
	return menor;
}

int tamanho(lista l){
	return l->info;
}

int iguais(lista l1, lista l2){
	lista aux1=l1;
	lista aux2=l2;
	if(tamanho(l1)!=tamanho(l2)) return false;
	while(aux1!=NULL){
		if(aux1->info!=aux2->info) return false;
		aux1=aux1->prox;
		aux2=aux2->prox;
	}
	return true;
}