#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>

int calcula_posicao(char* palavra, int TABLE_SIZE)
{
    int valor = 7;

    for(int i = 0; palavra[i] != '\0'; i++)
        valor = (i + (31 * valor * (int) palavra[i])) % TABLE_SIZE;

    return valor;
}
