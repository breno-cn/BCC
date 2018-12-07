#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "Hash.h"
#include "Arquivo.h"

#define MAXF 1000
#define CONT 500

Grafo* ler_arquivo(FILE* entrada, char maiusculas[][50], int* nMaiusculas)
{
    int cont = 0;
    char frases[MAXF][CONT];
    char palavras[5000][CONT];
    int n = 0;
    int n_maiusculas = 0;
    char origem[CONT];
    char destino[CONT];
    char aux[CONT];
    char* temp;
    Grafo* gr = cria_grafo(MAX, MAX);
    char M[1000][50];

    for(cont = 0; fgets(frases[cont], CONT, entrada) != NULL; cont++);
    
    for(int i = 0; i < cont; i++)
    {
        temp = strtok(frases[i], " ");
        if(temp == NULL) break;
        else
        {
            if(temp[0] >= 'A' && temp[0] <= 'Z')
            {
                strcpy(M[n_maiusculas++], temp);
            }
            strcpy(aux, temp);
            strcpy(palavras[n], aux);
            n++;
        }

        while(1)
        {
            temp = strtok(NULL, " ");
            if(temp == NULL) break;
            if(temp[0] >= 'A' && temp[0] <= 'Z') strcpy(M[n_maiusculas++], temp);
            strcpy(aux, temp);

            strcpy(palavras[n], aux);
            n++;
        }
    }

    for(int i = 0; i < n - 1; i++)
        insere_aresta(gr, palavras[i], palavras[i + 1]);

    *nMaiusculas = n_maiusculas;
    for(int i = 0; i < *nMaiusculas; i++)
        strcpy(maiusculas[i], M[i]);

    return gr;
}
