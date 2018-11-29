#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "Hash.h"
#include "Arquivo.h"

/*Grafo* ler_arquivo(FILE* entrada)
{
    int i = 0;
    char palavra[50];
    char frase[5000];
    Grafo* g = cria_grafo(1007);
    int control;
    char palavras[5000][50];
    while(1)
    {
        if(feof(entrada)) break;
        fgets(frase, 5000, entrada);
        //palavras[i] = strtok(frase, " ");
        strcpy(palavra, strtok(frase, " "));
        strcpy(palavras[i],palavra);
        control = 0;
        while(1)
        {
            if(control)
            {
                //palavra = strtok(NULL, " ");
                strcpy(palavra, strtok(NULL, " "));
                if(palavra == NULL) break;
                strcpy(palavras[i],palavra);

                //palavra= strtok(NULL, " ");
                strcpy(palavra, strtok(NULL, " "));
                if(palavra == NULL) break;
                strcpy(palavras[i],palavra);
            }
            else
            {
                //palavra = strtok(NULL, " ");
                strcpy(palavra, strtok(NULL, " "));
                if(palavra==NULL) break;
                strcpy(palavras[i],palavra);
            }
            control++;
            i++;
        }
    }
    return g;
}*/

Grafo* ler_arquivo(FILE* entrada)
{
    if(entrada == NULL) return NULL;

    char frase[500];
    char origem[50];
    char destino[50];
    char* aux;
    Grafo* g = cria_grafo(16057);

    while(1)
    {
        if(feof(entrada)) break;

        fgets(frase, 500, entrada);
        strcpy(origem, strtok(frase, " "));

        while(1)
        {
            aux = strtok(NULL, " ");
            if(aux == NULL) break;
            strcpy(destino, aux);
            insere_grafo(g, origem, destino);
        }
    }
    return g;
}
