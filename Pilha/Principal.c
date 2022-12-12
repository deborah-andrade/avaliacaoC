#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.c"

int main(){
    
    float ingnora;
    Pilha *calc = (Pilha*) malloc(sizeof(Pilha));
    criarPilha(calc);
    char ch[100];
    printf("\n\t------------- Calculadora Pos-Fixa -------------------\n\n");
    printf("\t\tDigite a conta separado por espaco:\n\t=> "); // XXX/
    gets(ch);

    lerEntrada(ch, calc);
    imprimePilha(calc);
    ingnora = desempilha(calc);

    return 0;
}