#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
	int n,i;
	lista l1;
	l1=criar_lista();
	printf("Primeira lista!\n");
	for(i=0;i<11;i++){
		printf("Insira um elemento: ");
		scanf("%d", &n);
		setbuf(stdin,NULL);
		insere_ord(&l1,n);
	}
	imp_lista(l1);
	lista l2;
	l2=criar_lista();
	printf("Segunda lista!\n");
	for(i=0;i<7;i++){
		printf("Insira um elemento: ");
		scanf("%d", &n);
		setbuf(stdin,NULL);
		insere_ord(&l2,n);
	}
	imp_lista(l2);
	lista l3;
	l3=criar_lista();
	l3=intercala(l1,l2);
	printf("Intercala:\n");
	imp_lista(l3);
	return 0;
}