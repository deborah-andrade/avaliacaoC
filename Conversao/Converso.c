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
    printf("z\n\t----------- FILA ----------\n\t\t");
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

int main(){
   Fila *fila;
   No *r;
   int op, valor;
   criarFila(fila);

   do{
        printf("\n--------- MENU ----------\n");
        printf("\n\t1 - Converte\n\t2 - Remover(1)\n\t3 - Remover Tudo\n\t4 - imprimir\n\t0 - Sair\n =>");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n\tDigite um Valor: ");
            scanf("%d", &valor);
            binario(fila, valor);
            printf("\n\tValor salvo na Fila\n");
            imprimir(fila);
        break;
        case 2:
            r = removerDaFila(fila);
            if(r != NULL){
                printf("Removido: %d\n", r->valor);
                free(r);
            }
        break;
        case 3:
            removerTudo(fila);
            criarFila(fila);
        break;
        case 4:
            imprimir(fila);
        break;
        
        default:
            printf("\nOpcao invalida\n");
        break;
        }
   }while(op != 0);

}