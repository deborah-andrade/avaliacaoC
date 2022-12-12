#include <stdio.h>
#include <stdlib.h>
#include "CalculadoraPosFixa.h"

struct pilha{
    float valor[MAX];
    int topo;
};

Calc *criarCalc(){
    Calc *c = (Calc*) malloc(sizeof(Calc));
    c->topo = 0;
    return c;
}

void operando(Calc *c, float valor){
    if(c->topo == MAX){
        printf("Limite atingido");
    }
    c->valor[c->topo] = valor;
    c->topo++;

}

float pop(Calc *c){
    if(c->topo == 0){
        printf("pilha vazia");
        return -1;
    }
    return c->valor[--c->topo];
}

void operador(Calc *c, char op){
    float num1, num2, resultado;

    if(c->topo >= 2){
        num2 = pop(c);
        num1 = pop(c);
        switch (op)
        {
        case '+':
            resultado = num1 + num2;
            operando(c, resultado);
        break;
        case '-':
            resultado = num1 - num2;
            operando(c, resultado);
        break;
        case '*':
            resultado = num1 * num2;
            operando(c, resultado);
        break;
        case '/':
            if(num2 != 0){
                resultado = num1 / num2;
                operando(c, resultado);
                break;
            }else{
                printf("Impossivel dividir por 0"); // XXX/
                operando(c, num1);
                operando(c, num2);
            }
        break;
        default:
            printf("Operacao invalida"); // XXX/
            operando(c, num1);
            operando(c, num2);

        break;
        }
    } else {
        printf("Operacao invalida pela quantidade de numeros"); // XXX/

    }
}

void liberaCalc(Calc *c){
    free(c);
    c->topo = 0;
}

void imprimir(Calc *c){
    printf("[ %.2f ]", c->valor[0]); // XXX/
}
