#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
	int i;
	pilha p=cria_pilha();
	for(i=1;i<=MAX;i++)
		push(p,i);
	print(p);
	pop(p,&i);
	printf("Numero removido: %d\nPilha:\n", i);
	print(p);
	ler_topo(p,&i);
	printf("Elemento no topo: %d\n", i);
	return 0;
}