typedef struct Deque *deque;

deque cria_deque();
int deque_vazia(deque d);
int insere_ini(deque d, int x);
int insere_fim(deque d, int x);
int remove_ini(deque d, int *x);
int remove_fim(deque d, int *x);
int imp_deque(deque d);