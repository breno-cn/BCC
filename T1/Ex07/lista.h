#define false 0
#define true 1

typedef struct no *lista;

lista cria_lista();
int lista_vazia(lista l);
int insere_elem(lista *l, int n);
int remove_elem(lista *l, int n);
int tamanho(lista l);
int print_lista(lista l);
int remover_todos(lista *l, int n);
int remove_maior(lista *l);
int remove_multiplos(lista *l);