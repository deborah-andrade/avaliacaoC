typedef struct pilha Calc;
#define MAX 50

Calc *criarCalc(); 
void operando(Calc *c, float valor);
void operador(Calc *c, char op);
void liberaCalc(Calc *c);

float pop(Calc *c);
void imprimir(Calc *c);

