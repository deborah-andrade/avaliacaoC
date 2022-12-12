typedef struct no No;
typedef struct fila Fila;

void criarFila(Fila *f);
void inserirFila(Fila *f, int num);
No* removerDaFila(Fila *f);
void removerTudo(Fila *f);
void imprimir(Fila *f);
void binario(Fila *f, int n);