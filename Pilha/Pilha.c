#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

struct no{
    float valor;
    No *proximo;

};
struct pilha{
    No *topo;
    int tam;
};

void criarPilha(Pilha *p){
    p->topo = NULL;
    p->tam = 0;
}
void empilha(float num, Pilha *p){
    No *no = (No*) malloc(sizeof(No));
    if(no != NULL){
        no->valor = num;
        no->proximo = p->topo;
        p->topo = no;
        p->tam++;
    }
}
float desempilha(Pilha *p){
    No *no  = p->topo;
    float num;
    if(no == NULL){
        printf("\n\tpilha vazia\n");
    }else{
        p->topo = no->proximo;
        no->proximo = NULL;
        num = no->valor;
        free(no);
        return num;
    }
}
void operador(Pilha *c, char op){
    float num1, num2, resultado;

    if(c->tam >= 2){
        num2 = desempilha(c);
        num1 = desempilha(c);
        switch (op)
        {
        case '+':
            resultado = num1 + num2;
            empilha(resultado, c);
        break;
        case '-':
            resultado = num1 - num2;
            empilha(resultado, c);
           
        break;
        case '*':
            resultado = num1 * num2;
            empilha(resultado, c);
        break;
        case '/':
            if(num2 != 0){
                resultado = num1 / num2;
                empilha(resultado, c);
                break;
            }else{
                printf("\n\tImpossivel dividir por 0\n"); // XXX/
                empilha(resultado, c);
                empilha(resultado, c);
            }
        break;
        default:
            printf("\n\tOperacao invalida\n"); // XXX/
            empilha(resultado, c);
            empilha(resultado, c);

        break;
        }
    } else {
        printf("\n\tOperacao invalida pela quantidade de numeros\n"); // XXX/

    }
}
void imprimePilha(Pilha *p){
    No *no = p->topo;
    if(no != NULL){
        printf("\t\tR= ");
        while(no != NULL){
            printf("%.2f ", no->valor);
            no = no->proximo;
        }
    }else{
        printf("\n\tpilha Vazia!\n");
        return;
    }
}

void lerEntrada(char *ch, Pilha *p){
    char *pt;
    pt = strtok(ch," ");
    while(pt != NULL ){
    
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
            operador(p, pt[0]);
        }else{
            float num = strtol(pt, NULL, 10);
            empilha(num, p);
        }
        pt = strtok(NULL, " ");
    }
}


