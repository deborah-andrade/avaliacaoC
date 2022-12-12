typedef struct pilha Pilha;
typedef struct no No;

void criarPilha(Pilha *p);
void empilha(float num, Pilha *p);
float desempilha(Pilha *p);
void operador(Pilha *c, char op);
void imprimePilha(Pilha *p);
void lerEntrada(char *ch, Pilha *p);