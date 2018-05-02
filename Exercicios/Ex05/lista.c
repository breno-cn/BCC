#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct no{
	char string[MAX];
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
	printf("(\n");
	lista aux;
	aux=l;
	while(aux!=NULL){
		printf("\t%s\n", aux->string);
		aux=aux->prox;
	}
	printf(")\n");
}

int insere_ord(lista *l, char *s){
	lista aux;
	aux=(lista)malloc(sizeof(struct no));
	if(aux==NULL) return 0;
	strcpy(aux->string,s);
	if(lista_vazia(*l) || s[0]<=(*l)->string[0]){
		aux->prox=*l;
		*l=aux;
		return 1;
	}
	lista aux2;
	aux2=*l;
	while(aux2->prox!=NULL && aux2->prox->string[0]<s[0])
		aux2=aux2->prox;
	aux->prox=aux2->prox;
	aux2->prox=aux;
	return 1;
}

int remove_ord(lista *l, char *s){
	if(lista_vazia(*l)) return 0;
	lista aux;
	aux=(lista)malloc(sizeof(struct no));
	aux=*l;
	if(!strcmp(aux->string,s)){
		(*l)=(*l)->prox;
		free(aux);
		return 1;
	}
	while(aux->prox!=NULL && strcmp(aux->prox->string,s)!=0)
		aux=aux->prox;
	if(aux->prox==NULL || strcmp(aux->prox->string,s)!=0) return 0;
	lista aux2;
	aux2=(lista)malloc(sizeof(struct no));
	aux2=aux->prox;
	aux->prox=aux2->prox;
	free(aux2);
	return 1;
}