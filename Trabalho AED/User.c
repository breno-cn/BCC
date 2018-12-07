#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "grafo.h"
#include "Arquivo.h"

int main(int argc, char const *argv[])
{
    FILE* entrada = fopen("texto_base.txt", "r");
    FILE* saida = fopen("saida.txt", "w");

    assert(entrada != NULL);
    assert(saida != NULL);

    char maiusculas[1000][50];
    int nMaiusculas = 0;

    Grafo* gr = ler_arquivo(entrada, maiusculas, &nMaiusculas);
    int visitados[10057];
    int n;
    printf("Quantas frases deseja formar? ");
    scanf("%d", &n);

    srand(time(NULL));
    for(int i = 0; i < n; i++)
        buscaLargura_grafo(gr, saida, maiusculas[rand() % nMaiusculas], visitados);

    libera_grafo(gr);

    fclose(entrada);
    fclose(saida);
    return 0;
}
