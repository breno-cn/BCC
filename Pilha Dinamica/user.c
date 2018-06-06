#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define MAX 10

int main(){
    int x;
    pilha p=cria_pilha();
    for(int i=1;i<=MAX;i++)
        push(&p,i);
    print(p);
    pop(&p,&x);
    printf("Elemento removido: %d\n", x);
    print(p);
    ler_topo(p,&x);
    printf("Elemento no topo: %d\n", x);
    return 0;
}