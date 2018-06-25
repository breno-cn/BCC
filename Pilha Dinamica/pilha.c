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
		x=x>>1;
	}
	char s[100];
	for(int i=0;!pilha_vazia(p);i++){
		pop(&p,&x);
		s[i]=x+'0';
	}
	strcpy(string,s);
	return 1;
}

int escopo_valido(const char *s){
	if(s==NULL) return 0;
	pilha p=cria_pilha();
	int x;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
			push(&p,s[i]);
		}
		if(s[i]==')'){
			if(!pop(&p,&x)) return false;
			if(x!='(') return false;
		}
		if(s[i]==']'){
			if(!pop(&p,&x)) return false;
			if(x!='[') return false;
		}
		if(s[i]=='}'){
			if(!pop(&p,&x)) return false;
			if(x!='{') return false;
		}
	}
	if(pilha_vazia(p)) return true;
	else return false;
}

int infixa_posfixa(const char *inf, char *pos){
	if(inf==NULL || pos==NULL) return 0;
	int x,j=0;
	pilha p=cria_pilha();
	for(int i=0;inf[i]!='\0';i++){
        if(inf[i]==')'){
			if(!pop(&p,&x)) return 0;
			pos[j++]=x;
			pos[j++]=')';
		}
		else if(inf[i]==']'){
			if(!pop(&p,&x)) return 0;
			pos[j++]=x;
			pos[j++]=']';
		}
		else if(inf[i]=='}'){
			if(!pop(&p,&x)) return 0;
			pos[j++]=x;
			pos[j++]='}';
		}
		else if(inf[i]=='+' || inf[i]=='-' || inf[i]=='*' || inf[i]=='/'){
			push(&p,inf[i]);		
		}
		else{
			pos[j++]=inf[i];
		}
	}
	pos[j]='\0';
	return 1;
}
