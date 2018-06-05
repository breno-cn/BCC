#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct Pilha{
	int info[MAX],topo;
};

pilha cria_pilha(){
	pilha p=(pilha)malloc(sizeof(struct Pilha));
	if(p!=NULL) p->topo=-1;
	return p;
}

int pilha_vazia(pilha p){
	if(p->topo==-1) return true;
	else return false;
}

int pilha_cheia(pilha p){
	if(p->topo==MAX-1) return true;
	else return false;
}

int push(pilha p, int n){
	if(p==NULL || pilha_cheia(p)) return 0;
	p->info[++p->topo]=n;
	return 1;
}

int pop(pilha p, int *n){
	if(p==NULL || pilha_vazia(p)) return 0;
	*n=p->info[p->topo--];
	return 1;
}

int ler_topo(pilha p, int *n){
	if(p==NULL || pilha_vazia(p)) return 0;
	*n=p->info[p->topo];
	return 1;
}

int print(pilha p){
	if(p==NULL || pilha_vazia(p)) return 0;
	int i;
	for(i=p->topo;i>=0;i--)
		printf("%d\n", p->info[i]);
	return 1;
}