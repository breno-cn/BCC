#define MAX 10057

typedef struct no Grafo;

struct string
{
    char palavra[30];
};

typedef struct string String;

Grafo* cria_grafo(int nro_vertices, int grau_max);
void libera_grafo(Grafo* gr);
int insere_aresta(Grafo* gr, char* origem, char* destino);
void buscaLargura_grafo(Grafo* gr, FILE* saida, char* ini, int* visitado);
