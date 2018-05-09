#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
	int i,n;
	lista l;
	l=criar_lista();
	printf("Lista vazia!\n");
	imprime_lista(l);
	printf("Tamanho da lista: %d\n", tamanho(l));
	for(i=0;i<5;i++){
		printf("Insira um elemento: ");
		scanf("%d", &n);
		setbuf(stdin,NULL);
		insere_elem(&l,n);
	}
	imprime_lista(l);
	printf("Tamanho da lista: %d\n", tamanho(l));
	printf("Digite um elemento a ser removido: ");
	scanf("%d", &n);
	setbuf(stdin,NULL);
	remove_elem(&l,n);
	imprime_lista(l);
	printf("Tamanho da lista: %d\n", tamanho(l));
	return 0;
}