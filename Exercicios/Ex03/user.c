#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
	int n,i;
	lista l;
	l=criar_lista();
	imp_lista(l);
	for(int i=0;i<11;i++){
		printf("Digite um elemento: ");
		scanf("%d", &n);
		setbuf(stdin,NULL);
		insere_elem(&l,n);
	}
	imp_lista(l);
	printf("Digite um elemento a ser removido: ");
	scanf("%d", &n);
	setbuf(stdin,NULL);
	i=remove_todos(&l,n);
	printf("Elementos removidos: %d\n", i);
	imp_lista(l);
	return 0;
}