#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct Lista{
	int v[MAX],fim;
};

lista criar_lista(){
	lista l;
	l=(lista)malloc(sizeof(struct Lista));
	if(l!=NULL) l->fim=0;
	return l;
}

int lista_vazia(lista l){
	if(l->fim==0) return true;
	else return false;
}

int lista_cheia(lista l){
	if(l->fim==MAX) return true;
	else return false;
}

int insere_elem(lista l, int n){
	if(lista_cheia(l)) return 0;
	l->v[l->fim]=n;
	l->fim++;
	return 1;
}

int remove_elem(lista l, int n){
	int i,aux,flag=0;
	for(i=0;i<l->fim;i++){
		if(n==l->v[i]){
			flag=1;
			aux=i;
			break;
		}
	}
	if(flag==0) return 0;
	if(aux==0){
		for(i=0;i<l->fim-1;i++){
			l->v[i]=l->v[i+1];
		}
		l->fim--;
		return 1;
	}
	else if(aux==l->fim-1){
		l->fim--;
		return 1;
	}
	else{
		for(i=aux;i<l->fim;i++){
			l->v[i]=l->v[i+1];
		}
		l->fim--;
		return 1;
	}
}

void imprime_lista(lista l){
	if(lista_vazia(l)){
		printf("Nao foi possivel imprimir a lista!\n");
		return;
	}
	int i;
	printf("(");
	for(i=0;i<l->fim;i++){
		printf(" %d ", l->v[i]);
	}
	printf(")\n");
}

int remover_impares(lista l){
	for(int i=0;i<l->fim;i++){
		if(l->v[i]%2!=0){
			remove_elem(l,l->v[i]);
			i--;
		}
	}
	return 1;
}

int menor_elem(lista l){
	int i,menor=l->v[0];
	for(i=0;i<l->fim;i++){
		if(menor>l->v[i]) menor=l->v[i];
	}
	return menor;
}

int tamanho(lista l){
	return l->fim;
}

lista concatenar(lista l1, lista l2){
	if(l1==NULL || l2==NULL || l1->fim+l2->fim>MAX) return NULL;
	int i,j;
	lista l3;
	l3=criar_lista();
	for(i=0;i<l1->fim;i++){
		l3->v[i]=l1->v[i];
		l3->fim++;
	}
	j=i;
	for(i=0;i<l2->fim;i++){
		l3->v[j]=l2->v[i];
		j++;
		l3->fim++;
	}
	return l3;
}