#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "Hash.h"
#include "Arquivo.h"

void remove_sub(char* string, char* sub)
{
    char* match;
    int len = strlen(sub);
    while(match = strstr(string, sub))
    {
        *match = '\0';
        strcat(string, match + len);
    }
}

Grafo* ler_arquivo(FILE* entrada)
{
    int x = 0;
    printf("%d\n", x++);
    Grafo* g = cria_grafo(10007);
    printf("%d\n", x++);
    char frase[500];
    char* origem;
    char* destino;
    printf("%d\n", x++);
    int y = 0;

    while(1)
    {
        printf("%d\n", x++);
        if(feof(entrada)) break;
        fgets(frase, 500, entrada);
        while(1)
        {
            /*printf("Y = %d\n", y++);

            origem = strtok(frase, " ");
            if(origem == NULL) break;
            printf("%s\n", origem);

            destino = strtok(frase, " ");
            if(destino == NULL) break;
            printf("%s\n", destino);
            */

            origem = strtok(frase, " ");
            if(origem == NULL) break;
            printf("%s\n", origem);
            remove_sub(frase, origem);

            destino = strtok(frase, " ");
            if(destino == NULL) break;
            printf("%s\n", destino);

            insere_grafo(g, origem, destino);

            printf("Y = %d\n", y++);
        }
    }
    return g;
}
