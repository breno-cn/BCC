#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "Hash.h"

//#define MAX 10057

struct no
{
    int nro_vertices;
    int grau_max;
    struct string** arestas;
    int** peso;
    int* grau;
    int* n_palavras;
    int num_palavras;
};

Grafo* cria_grafo(int nro_vertices, int grau_max)
{
    Grafo* gr = (Grafo*) malloc(sizeof(struct no));
    if(gr != NULL)
    {
        int i;
        gr->num_palavras = 0;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->grau = (int*) calloc(nro_vertices, sizeof(int));
        gr->arestas = (struct string**) malloc(grau_max * sizeof(struct string*));
        for(i = 0; i < nro_vertices; i++)
            gr->arestas[i] = (struct string*) malloc(grau_max * sizeof(struct string));

        gr->peso = (int**) malloc(nro_vertices * sizeof(int*));

        for(i = 0; i < nro_vertices; i++)
            gr->peso[i] = (int*) malloc(grau_max * sizeof(int));

        gr->n_palavras = (int*) malloc(nro_vertices * sizeof(int));
        for(i = 0; i < nro_vertices; i++)
            gr->n_palavras[i] = 0;
    }

    return gr;
}

void libera_grafo(Grafo* gr)
{
    if(gr != NULL)
    {
        int i;
        
        for(i = 0; i < gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        for(i = 0; i < gr->nro_vertices; i++)
            free(gr->peso[i]);
        free(gr->peso);
    }
    free(gr->grau);
    free(gr->n_palavras);
    free(gr);
}

int insere_aresta(Grafo* gr, char* origem, char* destino)
{
    if(gr == NULL) return 0;

    if(origem == NULL || destino == NULL) return 0;
    
    int pos1 = calcula_posicao(origem, MAX);
    int pos2 = calcula_posicao(destino, MAX);

    struct string* orig = (struct string*) malloc(sizeof(struct string));
    strcpy(orig->palavra, origem);

    struct string* dest = (struct string*) malloc(sizeof(struct string));
    strcpy(dest->palavra, destino);

    gr->arestas[pos1][gr->grau[pos1]] = *dest;

    gr->peso[pos1][gr->grau[pos1]]++;

    gr->grau[pos1]++;

    gr->n_palavras[pos1]++;
    gr->n_palavras[pos2]++;

    gr->num_palavras += 2;

    return 1;
}

void buscaProfundidade(Grafo* gr, char* ini, int* visitado, int cont)
{
    printf("%s\n", ini);
    int i;
    int x = 0;
    int aux = calcula_posicao(ini, MAX);

    visitado[aux] = cont;

    for(i = 0; i < gr->grau[aux]; i++)
    {
        printf("%s\n", gr->arestas[aux][i].palavra);
        aux = calcula_posicao(gr->arestas[aux][i].palavra, MAX);
        if(visitado[aux] == 0)
        {
            buscaProfundidade(gr, gr->arestas[aux][i+1].palavra, visitado, cont + 1);
        }
    }
    printf("AAA\n");
}

void buscaProfundidade_Grafo(Grafo* gr, char* ini, int* visitado)
{
    int i;
    int cont = 1;

    for(i = 0; i < gr->nro_vertices; i++)
        visitado[i] = 0;

    buscaProfundidade(gr, ini, visitado, cont);
}

void buscaLargura_Grafo(Grafo* gr, char* ini, int* visitado)
{
    int i, vert, NV, cont = 1, *fila, IF = 0, FF = 0;
    int pos = calcula_posicao(ini, MAX);

    for(i = 0; i < gr->nro_vertices; i++)
        visitado[i] = 0;

    NV = gr->nro_vertices;
    fila = (int*) malloc(NV * sizeof(int));
    FF++;
    fila[FF] = pos;
    visitado[pos] = cont;
    while(IF != FF)
    {
        IF = (IF + 1) % NV;
        vert = fila[IF];
        cont++;
        for(i = 0; i < gr->grau[vert]; i++)
        {
            if(!visitado[calcula_posicao(gr->arestas[vert][i].palavra, MAX)])
            {
                FF = (FF + 1) % NV;
                //fila[FF] = gr->arestas[vert][i];
                printf("%s ", gr->arestas[vert][i].palavra);
                fila[FF] = calcula_posicao(gr->arestas[vert][i].palavra, MAX);
                visitado[calcula_posicao(gr->arestas[vert][i].palavra, MAX)] = cont;
                gr->num_palavras -= 2;
                if(gr->num_palavras == 0) return;
            }
        }
    }
    free(fila);
}

int grafo_vazio(Grafo* gr)
{
    return (gr->num_palavras == 0);
}
