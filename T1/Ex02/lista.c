#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct Lista{
	int v[MAX];
    int fim;
};

lista criar_lista(){
	lista l;
	l=(lista)malloc(sizeof(struct Lista));
	if(l!=NULL) l->fim=0;
	return l;
}

void imprime_lista(lista l){
	int i;
	printf("(");
	for(i=0;i<l->fim;i++){
		printf(" %d ", l->v[i]);
	}
	printf(")\n");
}

int lista_vazia(lista l){
	if(l->fim==0) return true;
	else return false;
}

int lista_cheia(lista l){
	if(l->fim==MAX) return true;
	else return false;
}

int insere_ord(lista l, int n){
	if(lista_vazia(l)){
		l->v[0]=n;
		l->fim++;
		return 1;
	}
	if(lista_cheia(l)) return 0;
	if(l->v[l->fim-1]<=n){
		l->v[l->fim]=n;
		l->fim++;
		return 1;
	}
	int i,j,aux;
	for(i=0;i<l->fim;i++){
		if(l->v[i]>n){
			aux=i;
			break;
		}
	}
	for(j=l->fim;j>=aux;j--)
		l->v[j]=l->v[j-1];
	l->v[aux]=n;
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
	if(!flag) return 0;
	if(aux==0){
		for(i=0;i<l->fim-1;i++)
			l->v[i]=l->v[i+1];
		l->fim--;
		return 1;
	}
	else if(aux==l->fim-1){
		l->fim--;
		return 1;
	}
	else{
		for(i=aux;i<l->fim;i++)
			l->v[i]=l->v[i+1];
		l->fim--;
		return 1;
	}
}

lista intercala(lista l1, lista l2){
	if(l1==NULL || l2==NULL || l1->fim+l2->fim>10) return NULL;
	if(lista_vazia(l1) || lista_vazia(l2)) return NULL;
	int i;
	lista l3;
	l3=criar_lista();
	for(i=0;i<l1->fim;i++){
		insere_ord(l3,l1->v[i]);
	}
	for(i=0;i<l2->fim;i++){
		insere_ord(l3,l2->v[i]);
	}
	return l3;
}

int remover_pares(lista l){
	if(lista_vazia(l) || l==NULL) return 0;
	int i;
	for(i=0;i<l->fim;i++){
		if(l->v[i]%2==0){
			remove_elem(l,l->v[i]);
		}
	}
	return 0;
}

int maior(lista l){
	return l->v[l->fim-1];
}

int tamanho(lista l){
	return l->fim;
}

int listas_iguais(lista l1, lista l2){
	if(l1==NULL || l2==NULL || l1->fim!=l2->fim) return false;
	for(int i=0;i<l1->fim;i++)
		if(l1->v[i]!=l2->v[i]) return false;
	return true;
}