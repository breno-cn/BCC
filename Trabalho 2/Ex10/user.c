#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main(){
    int x;
    deque d=cria_deque();
    for(int i=0;i<5;i++){
        printf("Insira um elemento: ");
        scanf("%d", &x);
        setbuf(stdin,NULL);
        insere_fim(d,x);
    }
    imp_deque(d);
    remove_ini(d,&x);
    printf("Elemento removido: %d\n", x);
    imp_deque(d);
    remove_fim(d,&x);
    printf("Elemento removido: %d\n", x);
    imp_deque(d);
    // while(!deque_vazia(d)){
    //     remove_ini(d,&x);
    //     printf("Elemento removido: %d\n", x);
    //     imp_deque(d);
    // }
    return 0;
}