#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

int imp_reverso(pilha p){
    if(pilha_vazia(p) || p==NULL) return 0;
    for(int i=0;i<=p->topo;i++)
        printf("%d\n", p->info[i]);
    return 1;
}

int palindrommo(const char *s){
    if(s==NULL) return 0;
    int i,x;
    pilha p=cria_pilha();
    for(i=0;s[i]!='\0';i++)
        if(s[i]!=' ') push(p,tolower(s[i]));
    for(i=0;!pilha_vazia(p);i++){
        if(s[i]!=' '){
            pop(p,&x);
            if(x!=tolower(s[i])) return false;
        }
    }
    return true;
}