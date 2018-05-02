#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
	char s[MAX];
	int i;
	lista l;
	l=criar_lista();
	for(i=0;i<3;i++){
		setbuf(stdin,NULL);
		printf("Digite um elemento: ");
		scanf("%[^\n]s", s);
		insere_ord(&l,s);
	}
	imp_lista(l);
	printf("Digite um elemento para ser removido: ");
	setbuf(stdin,NULL);
	scanf("%[^\n]s", s);
	remove_ord(&l,s);
	imp_lista(l);
	return 0;
}