typedef struct Fila *fila;

fila cria_fila();
int fila_vazia(fila f);
int insere_elem(fila f, int x);
int remove_ini(fila f, int *x);
int imp_fila(fila f);