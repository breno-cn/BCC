#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct Pilha{
	int info;
	struct Pilha *prox;
};

pilha cria_pilha(){
	return NULL;
}

int pilha_vazia(pilha p){
	if(p==NULL) return true;
	return false;
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
	pilha aux=p;
	while(aux!=NULL){
		printf("%d\n", aux->info);
		aux=aux->prox;
	}
	return 1;
}

int dec_bin(int x, char *string){
	if(x<0) return 0;
	pilha p=cria_pilha();
	while(x>=1){
		push(&p,x%2);
		x/=2;
	}
	char s[30];
	for(int i=0;!pilha_vazia(p);i++){
		pop(&p,&x);
		s[i]=x+'0';
	}
	strcpy(string,s);
	return 1;
}

int escopo_valido(char *s){
	if(s==NULL) return 0;
	pilha p=cria_pilha();
	int x;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
			push(&p,s[i]);
		}
		if(s[i]==')'){
			if(pilha_vazia(p)) return false;
			pop(&p,&x);
			if(x!='(') return false;
		}
		if(s[i]==']'){
			if(pilha_vazia(p)) return false;
			pop(&p,&x);
			if(x!='[') return false;
		}
		if(s[i]=='}'){
			if(pilha_vazia(p)) return false;
			pop(&p,&x);
			if(x!='{') return false;
		}
	}
	if(pilha_vazia(p)) return true;
	else return false;
}
