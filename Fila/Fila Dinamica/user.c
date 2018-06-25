#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
	int x;
	fila f=cria_fila();
	imp_fila(f);
	for(int i=0;i<4;i++){
		printf("Insira um elemento: ");
		scanf("%d", &x);
		setbuf(stdin,NULL);
		insere_fim(f,x);
	}
	imp_fila(f);
	remove_ini(f,&x);
	printf("Elemento removido: %d\n", x);
	imp_fila(f);
	while(!fila_vazia(f)){
		remove_ini(f,&x);
		printf("Elemento removido: %d\n", x);
	}
	imp_fila(f);
	return 0;
}