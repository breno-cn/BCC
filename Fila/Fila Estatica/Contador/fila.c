#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct Fila{
	int info[MAX],cont,ini;
};

fila cria_fila(){
	fila f=(fila)malloc(sizeof(struct Fila));
	if(f!=NULL) f->ini=f->cont=0;
	// printf("Inicio: %d\nCont: %d\n", f->ini, f->cont);
	return f;
}
  
int fila_vazia(fila f){
	if(f->cont==0) return true;
	return false;
}

int fila_cheia(fila f){
	if(f->cont==MAX-1) return true;
	return false;
}

int insere_fim(fila f, int x){
	if(f==NULL || fila_cheia(f)) return 0;
	f->info[(f->ini+f->cont++)%MAX]=x;
	return 1;
}

int remove_ini(fila f, int *x){
	if(fila_vazia(f) || f==NULL) return 0;
	*x=f->info[f->ini];
	f->ini=(f->ini+1)%MAX;
	f->cont--;
	return 1;
}

int imp_fila(fila f){
	if(fila_vazia(f) || f==NULL) return 0;
	printf("( ");
	for(int aux=f->ini;aux!=(f->ini+f->cont)%MAX;aux=(aux+1)%MAX)
		printf("%d ", f->info[aux]);
	printf(")\n");
	return 1;
}