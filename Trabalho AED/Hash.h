typedef struct hash Hash;

Hash* cria_hash(int TABLE_SIZE);
void libera_hash(Hash* h);
int calcula_posicao(char* palavra, int TABLE_SIZE);
int insere_palavra(Hash* h, char* palavra);
int remove_palavra(Hash* h, char* palavra);
char* retorna_palavra(Hash* h, int pos);
int printar(Hash* h);
int getTABLE_SIZE(Hash* h);
