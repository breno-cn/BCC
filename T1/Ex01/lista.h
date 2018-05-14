#define false 0
#define true 1
#define MAX 10

typedef struct Lista *lista;

lista criar_lista();
int lista_vazia(lista l);
int lista_cheia(lista l);
int insere_elem(lista l, int n);
int remove_elem(lista l, int n);
void imprime_lista(lista l);
int remover_impares(lista l);
int menor_elem(lista l);
int tamanho(lista l);
lista concatenar(lista l1, lista l2);