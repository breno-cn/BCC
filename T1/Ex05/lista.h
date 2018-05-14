#define false 0
#define true 1

typedef struct no *lista;

lista criar_lista() ;
int lista_vazia(lista l);
void imprime_lista(lista l);
int insere_ord(lista *l, int n);
int remove_ord(lista *l, int n);
lista intercala(lista *l1, lista *l2);
int remove_impar(lista *l);
int menor(lista l);
int tamanho(lista l);
int iguais(lista l1, lista l2);