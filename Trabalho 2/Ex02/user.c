#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    int x;
    pilha p=cria_pilha();
    pilha par=cria_pilha();
    pilha imp=cria_pilha();
    for(int i=0;i<6;i++){
        printf("Insira um elemento: ");
        scanf("%d", &x);
        setbuf(stdin,NULL);
        push(&p,x);
    }
    par_impar(p,&par,&imp);
    printf("Pilha par!\n");
    print(par);
    printf("Pilha impar!\n");
    print(imp);
    return 0;
}