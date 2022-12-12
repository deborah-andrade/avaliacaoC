typedef struct contato Contato;

void salvandoContato(Contato *ctt, FILE *arq);
void inserirContato(Contato *ctt);
void cadastraContato();
void exibirContatos(int i);
void listaDaAgenda();
int procurandocombinacao(char *a, char *b, int i, int limit);
void procuraContato();
void menuPrincipal();