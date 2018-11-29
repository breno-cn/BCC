#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string
{
    char palavra[30];
};

struct hash
{
    int qtd;
    int TABLE_SIZE;
    struct string** itens;
};

Hash* cria_hash(int TABLE_SIZE)
{
    Hash* h = (Hash*) malloc(sizeof(Hash));
    if(h != NULL)
    {
        h->qtd = 0;
        h->TABLE_SIZE = TABLE_SIZE;
        h->itens = (struct string**) malloc(TABLE_SIZE * sizeof(struct string*));
        if(h->itens == NULL)
        {
            free(h);
            return 0;
        }
        for(int i = 0; i < TABLE_SIZE; i++)
            h->itens[i] = NULL;
    }
    return h;
}

void libera_hash(Hash* h)
{
    if(h != NULL)
    {
        for(int i = 0; i < h->TABLE_SIZE; i++)
            if(h->itens[i] != NULL) free(h->itens[i]);
        free(h->itens);
        free(h);
    }
}

int calcula_posicao(char* palavra, int TABLE_SIZE)
{
    int valor = 7;
    for(int i = 0; palavra[i] != '\0'; i++)
        valor = (i + (31 * valor * (int) palavra[i])) % TABLE_SIZE;

    return valor;
}

int insere_palavra(Hash* h, char* palavra)
{
    if(h == NULL || h->qtd == h->TABLE_SIZE) return 0;

    int pos = calcula_posicao(palavra, h->TABLE_SIZE);// % h->TABLE_SIZE;
    //printf("%d\n", pos);
    struct string* novo = (struct string*) malloc(sizeof(struct string));
    if(novo == NULL) return 0;

    strcpy(novo->palavra, palavra);
    h->itens[pos] = novo;
    h->qtd++;
    return 1;
}

int remove_palavra(Hash* h, char* palavra)
{
    if(h == NULL || palavra == NULL) return 0;

    int pos = calcula_posicao(palavra, h->TABLE_SIZE);
    free(h->itens[pos]);
    h->itens[pos] = NULL;
    return 1;
}

char* retorna_palavra(Hash* h, int pos)
{
    if(h == NULL || pos < 0) return NULL;
    return h->itens[pos]->palavra;
}

int printar(Hash* h)
{
    if(h == NULL) return 0;
    for(int i = 0; i < h->TABLE_SIZE; i++)
        if(h->itens[i] != NULL) printf("%s\n", h->itens[i]->palavra);
    return 1;
}

int getTABLE_SIZE(Hash* h)
{
    return h->TABLE_SIZE;
}
