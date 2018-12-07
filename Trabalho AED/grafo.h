#define MAX 10057

typedef struct no Grafo;

struct string
{
    char palavra[30];
    int n_letras;
};

typedef struct string String;

Grafo* cria_grafo(int nro_vertices, int grau_max);
void libera_grafo(Grafo* gr);
int insere_aresta(Grafo* gr, char* origem, char* destino);
void buscaProfundidade(Grafo* gr, char* ini, int* visitado, int cont);
void buscaProfundidade_Grafo(Grafo* gr, char* ini, int* visitado);
void buscaLargura_Grafo(Grafo* gr, char* ini, int* visitado);
int grafo_vazio(Grafo* gr);
