#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "Hash.h"
#include "Arquivo.h"

//#define MAX 100057
#define MAXF 1000
#define CONT 500

Grafo* ler_arquivo(FILE* entrada)
{
    int cont = 0;
    char frases[MAXF][CONT];
    char palavras[5000][CONT];
    int n = 0;
    char origem[CONT];
    char destino[CONT];
    char aux[CONT];
    char* temp;
    Grafo* gr = cria_grafo(MAX, MAX);

    for(cont = 0; fgets(frases[cont], CONT, entrada) != NULL; cont++);

    for(int i = 0; i < cont; i++)
    {
        temp = strtok(frases[i], " ");
        if(temp == NULL) break;
        else strcpy(aux, temp);

        //printf("%s ", aux);
        strcpy(palavras[n], aux);
        n++;

        while(1)
        {
            temp = strtok(NULL, " ");
            if(temp == NULL) break;
            else strcpy(aux, temp);

            //printf("%s ", aux);
            strcpy(palavras[n], aux);
            n++;
        }
    }

    for(int i = 0; i < n - 1; i++)
        insere_aresta(gr, palavras[i], palavras[i + 1]);

    return gr;
}
