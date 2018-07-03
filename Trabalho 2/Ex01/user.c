#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    char s[MAX];
    FILE *f=fopen("string","r");
    while(fscanf(f,"%s",s)!=EOF){
        if(palindrommo(s)) printf("%s e um palindromo!\n", s);
        else printf("%s nao e um palindromo!\n", s);
    }
    char *a="Socorram me subi no onibus em marrocos";
    printf("%d\n", palindrommo(a));
    // pilha p=cria_pilha(p);
    // int x;
    // for(int i=0;i<5;i++){
    //     printf("Insira um elemento: ");
    //     scanf("%d", &x);
    //     setbuf(stdin,NULL);
    //     push(p,x);
    // }
    // imp_reverso(p);
    return 0;
}