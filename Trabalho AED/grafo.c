#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "Hash.h"

struct grafo
{
    int matriz[16057][16057];
    int qnt;
    Hash* h;
};

Grafo* cria_grafo(int TAM)
{
    Grafo* gr = (Grafo*) malloc(sizeof(Grafo));
    Hash* h = cria_hash(TAM);
    gr->qnt = TAM;
    /*
    gr->matriz = (int**) malloc(TAM*sizeof(int*));
    for(int i=0;i<TAM;i++)
    	gr->matriz[i] = (int*) malloc(TAM * sizeof(int));
    */
    inicializa_grafo(gr);
    gr->h = h;
    return gr;
}

void inicializa_grafo(Grafo* gr)
{
    if(gr==NULL) return;
    int i,j;
    for(i=0;i<gr->qnt;i++)
        for(j=0;j<gr->qnt;j++)
            gr->matriz[i][j]=0;
}

void libera_grafo(Grafo* gr)
{
    if(gr !=NULL)
    {
	libera_hash(gr->h);
        /*
        for(int i = 0; i < gr->qnt; i++)
            free(gr->matriz[i]);
        free(gr->matriz);
        */
	free(gr);
    }
}

int insere_grafo(Grafo* gr, char* origem, char* destino)
{
    if(gr==NULL) return 0;
    insere_palavra(gr->h, origem);
    insere_palavra(gr->h, destino);
    int i = calcula_posicao(origem, getTABLE_SIZE(gr->h));
    int j = calcula_posicao(destino, getTABLE_SIZE(gr->h));
    gr->matriz[i][j]++;
    return 1;
}

int remove_grafo(Grafo* gr, char* origem, char* destino)
{
    if(gr==NULL) return 0;
    int i = calcula_posicao(origem, getTABLE_SIZE(gr->h));
    int j = calcula_posicao(destino, getTABLE_SIZE(gr->h));
    if(gr->matriz[i][j])
    {//verifica se existe uma ligacao nesta posicao
    	remove_palavra(gr->h,origem);
	remove_palavra(gr->h,destino);
	gr->matriz[i][j]--;
    }
    return 1;
}

int printa_porco(Grafo* gr)
{
    int i, j;
    for(i = 0; i < gr->qnt; i++)
    {
	for(j = 0; j < gr->qnt; j++)
        {
            if(gr->matriz[i][j] != 0)
            {
	    printf("A  %s\n", retorna_palavra(gr->h, i));
	    printf("B  %s\n", retorna_palavra(gr->h, j));
	    }
        }   
    }
}

/*void menor_caminho(Grafo* gr, char* origem, char* destino)
{
    int P[gr->qnt][gr->qnt];
    int i, j, k;

    for(i = 0; i < gr->qnt; i++)
        for(j = 0; j < gr->qnt; j++)
            P[i][j] = gr->matriz[i][j];

    int pos1 = calcula_posicao(origem, 1007);
    int pos2 = calcula_posicao(destino, 1007);

    for(j = pos1; j < gr->qnt; j++)
    {
        for(i = pos2; i < gr->qnt; i++)
        {
            if(P[i][j] > 0)
            {
                for(k = 0; k < gr->qnt; k++)
                {
                    P[j][k] = (P[i][k] > 0 || P[i][k] > 0);
                }
            }
        }
    }

    for(i = 0; i < gr->qnt; i++)
        for(j = 0; j < gr->qnt; j++)
            if(P[i][j]) printf("%s -> %s\n", retorna_palavra(gr->h, i), retorna_palavra(gr->h, j));
}*/

void busca_grafo(Grafo* gr)
{
    int count = 0;
    int anterior[1007];
    int i;

    for(i = 0; i <gr->qnt; i++)
        anterior[i] = -1;

    for(i = 0; i < gr->qnt; i++)
        if(anterior[i] == -1) busca_profundidade(gr, i, &count, anterior);
}

void busca_profundidade(Grafo* gr, int i, int* count, int* anterior)
{
    char* palavra1;
    char* palavra2;
    anterior[i] = *(count)++;
    for(int j = 0; j < gr->qnt; j++)
    {
        if(gr->matriz[i][j] != 0 && anterior[j] == -1)
        {
//            printf("%s \t->\t\t %s\n", retorna_palavra(gr->h, i), retorna_palavra(gr->h, j));
            palavra1 = retorna_palavra(gr->h, i);
            palavra2 = retorna_palavra(gr->h, j);

            if(palavra1 != NULL && palavra2 != NULL && strcmp(palavra1, palavra2) != 0)
            {
                printf("%s %s", palavra1, palavra2);
                gr->matriz[i][j]--;
            }
            busca_profundidade(gr, j, count, anterior);
        }
    }
}

int grafo_vazio(Grafo* gr)
{
    if(gr == NULL) return 0;
    for(int i = 0; i < gr->qnt; i++)
        for(int j = 0; j < gr->qnt; j++)
            if(gr->matriz[i][j] != 0) return 0;
    return 1;
}
