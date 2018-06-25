#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct Fila{
	int info[MAX],fim,inicio;
};

fila cria_fila(){
	fila f=(fila)malloc(sizeof(struct Fila));
	if(f!=NULL) f->fim=f->inicio=0;		
	return f;
}

int fila_vazia(fila f){
	if(f->inicio==f->fim) return true;
	return false;
}

int fila_cheia(fila f){
	if(f->inicio==(f->fim+1)%MAX) return true;
	return false;
}

int insere_fim(fila f, int x){
	if(f==NULL || fila_cheia(f)) return 0;
	f->info[f->fim]=x;
	f->fim=(f->fim+1)%MAX;
	return 1;
}

int remove_ini(fila f, int *x){
	if(f==NULL || fila_vazia(f)) return 0;
	*x=f->info[f->inicio];
	f->inicio=(f->inicio+1)%MAX;
	return 1;
}

int imp_fila(fila f){
	if(f==NULL) return 0;
	printf("( ");
	for(int i=f->inicio;i<f->fim;i=(i+1)%MAX)
		printf("%d ", f->info[i]);
	printf(")\n");
	return 1;
}