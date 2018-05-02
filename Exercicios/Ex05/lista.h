#define false 0
#define true 1
#define MAX 30

typedef struct no *lista;

lista criar_lista() ;
int lista_vazia(lista l);
void imp_lista(lista l);
int insere_ord(lista *l, char *s);
int remove_ord(lista *l, char *s);