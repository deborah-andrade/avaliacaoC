#include <stdio.h>
#include <stdlib.h>
#include "Converso.h"

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