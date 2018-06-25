#define false 0
#define true 1
#define MAX 20

typedef struct Fila *fila;

fila cria_fila();
int fila_vazia(fila f);
int fila_cheia(fila f);
int insere_fim(fila f, int x);
int remove_ini(fila f, int *x);
int print_fila(fila f);
int imp_fila(fila f);