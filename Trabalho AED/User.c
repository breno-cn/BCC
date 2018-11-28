#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "grafo.h"
#include "Arquivo.h"

int main(int argc, char const *argv[])
{
    /*Grafo* grafo = cria_grafo(997);
    char* s1 = "Eu";
    char* s2 = "vou";
    char* s3 = "sair.";
    char* s4 = "nao";
    char* s5 = "sei.";
    insere_grafo(grafo,s1,s2);
    insere_grafo(grafo,s2,s3);
    insere_grafo(grafo,s1,s4);
    insere_grafo(grafo,s4,s5);
    libera_grafo(grafo);*/
    FILE* entrada = fopen("texto_base.txt", "r");
    assert(entrada != NULL);
    Grafo* g = ler_arquivo(entrada);
    printa_porco(g);
    libera_grafo(g);
    fclose(entrada);
    return 0;
}
