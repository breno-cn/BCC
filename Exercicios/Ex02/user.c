#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
	int n,i;
	lista l;
	l=criar_lista();
	for(i=0;i<11;i++){
		setbuf(stdin,NULL);
		printf("Digite um elemento: ");
		scanf("%d", &n);
		insere_ord(&l,n);
	}
	imp_lista(l);
	printf("Digite um elemento para ser removido: ");
	scanf("%d", &n);
	setbuf(stdin,NULL);
	remove_ord(&l,n);
	imp_lista(l);
	return 0;
}