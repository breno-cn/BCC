#define false 0
#define true 1
#define MAX 100

typedef struct Pilha *pilha;

pilha cria_pilha();
int pilha_vazia(pilha p);
int push(pilha *p, int x);
int pop(pilha *p, int *x);
int ler_topo(pilha p, int *x);
int print(pilha p);