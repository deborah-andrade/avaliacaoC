#include <stdio.h>
#include <stdlib.h>
#include "Converso.h"

struct no{
    int valor;
    struct no *proximo;
    
};

struct fila{
    No *prim;
    No *fim;
    int tam;
};

void criarFila(Fila *f){
    f->prim = NULL;
    f->fim = NULL;
    f->tam = 0;
}

void inserirFila(Fila *f, int num){
    No *aux = (No*) malloc(sizeof(No));
    No *novo = (No*) malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(f->prim == NULL){
            f->prim = novo;
            f->fim = novo;
        }else{
            f->fim->proximo = novo;
            f->fim = novo;
        }
            f->tam++;
    }
}

No* removerDaFila(Fila *f){
    No *remover = NULL;

    if(f->prim != NULL){
        remover = f->prim;
        f->prim = remover->proximo;
        f->tam--;
    }else{
        printf("\tFila vazia\n");
    }
    return remover;
}

void removerTudo(Fila *f){
    No *remover = f->prim;

    while(remover != NULL){
        No *aux = remover->proximo;
        free(remover);
        remover = aux;
    }
    printf("\tFila vazia\n");
}

void imprimir(Fila *f){
    No *aux = f->prim;
    printf("\n\t----------- FILA ----------\n\t\t");
    while(aux != NULL){
        printf("%d", aux->valor);
        aux = aux->proximo;
    }
    printf("\n\t--------- FIM -------------\n");
}



void binario(Fila *f, int n){
    if(n == 0){
    }else{
        binario(f, n/2);
        inserirFila(f, n%2);
    }
}
