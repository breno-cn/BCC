#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
	int info;
	struct no *prox;
};

lista cria_lista(){
	return NULL;
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
	if(lista_vazia(*l)){
		aux->prox=aux;
		*l=aux;
		return 1;
	}
	else{
		aux->prox=(*l)->prox;
		(*l)->prox=aux;
		(*l)=aux;
		return 1;
	}
}

int remove_elem(lista *l, int *n){
	if(lista_vazia(*l)) return 0;
	lista aux;
	aux=(*l)->prox;
	*n=aux->info;
	if((*l)==(*l)->prox){
		(*l)=NULL;
		return 1;
	}
	else (*l)->prox=aux->prox;
	free(aux);
	return 1;
}

int imprime_lista(lista l){
	if(lista_vazia(l)) return 0;
	if(l==l->prox) printf("( %d )\n", l->info);
	lista aux;
	aux=l->prox;
	printf("( ");
	while(aux!=l){
		printf("%d ", aux->info);
		aux=aux->prox;
	}
	printf("%d )\n",aux->info);
	return 1;
}

int tamanho(lista l){
	if(lista_vazia(l)) return 0;
	if(l==l->prox) return 1;
	int i=1;
	lista aux=l->prox;
	while(aux!=l){
		i++;
		aux=aux->prox;
	}
	return i;
}

int maior(lista l){
	if(lista_vazia(l)) return 0;
	if(l==l->prox) return l->info;
	int maior=l->info;
	lista aux=l->prox;
	while(aux!=l){
		if(maior < aux->info) maior=aux->info;
		aux=aux->prox;
	}
	return maior;
}

int remove_posicao(lista *l, int pos){
	lista aux1=*l;
	lista aux2=*l;
	lista aux3=*l;
	int i=0;
	if(pos>tamanho(*l)) return 0;
	while(i<pos+1){
		aux1=aux1->prox;
		i++;
	}
	i=0;
	while(i<pos){
		aux3=aux3->prox;
		i++;
	}
	i=0;
	while(i<pos-1){
		aux2=aux2->prox;
		i++;
	}
	aux2->prox=aux1;
	if(aux3==*l)
		*l=aux2;
	return 1;
}

int insere_inicio(lista *l, int n){
	lista aux;
	aux=(lista)malloc(sizeof(struct no));
	aux->info=n;
	if(lista_vazia(*l)){
		aux->prox=aux;
		*l=aux;
		return 1;
	}
	aux->prox=(*l)->prox;
	(*l)->prox=aux;
	return 1;
}

int insere_pos(lista *l, int n, int pos){
	int i;
	lista aux1 = *lst;
	lista aux2 = *lst;
	Lista aux=(lista)malloc(sizeof(struct no));
	if (aux==NULL) return 0;
	aux->info=n;
	if(pos>tamanho(l)) return 0;
	for(i=0;i<pos;i++){
		aux->prox=aux->prox;
		aux=aux->prox;
	}
	for(i=0;i<pos-1;i++)
		aux2 = aux2->prox;
aux2->prox=aux;
return 1;
}