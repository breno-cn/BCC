#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "grafo.h"
#include "Arquivo.h"

int main(int argc, char const *argv[])
{
    FILE* entrada = fopen("texto_base.txt", "r");
    assert(entrada != NULL);
    Grafo* gr = ler_arquivo(entrada);
    
    int visitados[10057];
    while(!grafo_vazio(gr))
    {
        buscaLargura_Grafo(gr, "pouco", visitados);
    }

    libera_grafo(gr);
    fclose(entrada);
    return 0;
}
