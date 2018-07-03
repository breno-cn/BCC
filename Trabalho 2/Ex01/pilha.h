#define false 0
#define true 1
#define MAX 100

typedef struct Pilha *pilha;

pilha cria_pilha();
int pilha_vazia(pilha p);
int pilha_cheia(pilha p);
int push(pilha p, int n);
int pop(pilha p, int *n);
int ler_topo(pilha p, int *n);
int print(pilha p);
int imp_reverso(pilha p);
int palindrommo(const char *s);