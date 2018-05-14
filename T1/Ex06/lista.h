#define false 0
#define true 1

typedef struct no *lista;

lista cria_lista();
int lista_vazia(lista l);
int insere_elem(lista *l, int n);
int remove_elem(lista *l, int *n);
int imprime_lista(lista l);
int tamanho(lista l);
int maior(lista l);
int remove_posicao(lista *l, int pos);
int insere_inicio(lista *l, int n);
int insere_pos(lista *l, int n, int pos);