#define false 0
#define true 1

typedef struct no *lista;

lista criar_lista() ;
int lista_vazia(lista l);
void imp_lista(lista l);
int insere_ord(lista *l, int n);
int remove_ord(lista *l, int n);