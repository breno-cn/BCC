#include <stdlib.h>

int main(){
    system("gcc -c user.c");
    system("gcc -c -lm pilha.c");
    system("gcc -c fila.c");
    system("gcc -c expressao.c");
    system("gcc -o prog user.o pilha.o fila.o expressao.o -lm");
    return 0;
}