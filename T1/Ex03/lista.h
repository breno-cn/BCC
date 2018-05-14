#define false 0
#define true 1

typedef struct no *lista;

lista criar_lista();
int lista_vazia(lista l);
void  imp_lista(lista l);
int insere_elem(lista *l, int n);
int remove_elem(lista *l, int n);
int remove_todos(lista *l, int n);
int inserir_final(lista *l, int n);
int remove_impares(lista *l);
int maior(lista l);
int tamanho(lista l);
lista concatenar(lista *l1, lista *l2);