typedef struct grafo Grafo;
Grafo* cria_grafo(int TAM);
void inicializa_grafo(Grafo* gr);
void libera_grafo(Grafo* gr);
int insere_grafo(Grafo* gr, char* origem, char* destino);
int remove_grafo(Grafo* gr, char* origem, char* destino);
int printa_porco(Grafo* gr);