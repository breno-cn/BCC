#define false 0
#define true 1
#define MAX 10

typedef struct Lista *lista;

lista criar_lista();
void imprime_lista(lista l);
int lista_vazia(lista l);
int lista_cheia(lista l);
int insere_ord(lista l, int n);
int remove_elem(lista l, int n);
lista intercala(lista l1, lista l2);
int remover_pares(lista l);
int maior(lista l);
int tamanho(lista l);
int listas_iguais(lista l1, lista l2);