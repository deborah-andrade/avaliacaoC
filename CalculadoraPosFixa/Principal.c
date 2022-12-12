#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CalculadoraPosFixa.h"

int main(){
    char ch[100];
    char *pt;
    Calc *c = criarCalc();

    printf("\nCalculadora Pos-Fixa\n"); // XXX/
    printf("Digite a conta separado por espaco: "); // XXX/
    gets(ch);
    /* 51 13 12 * + R = 207
    5 3 2 + * 4 / 6 - R = 0,25
    5 3 + 2 4 * + 6 7 * 1 * - R = - 26 */

    pt = strtok(ch," ");
    while(pt != NULL ){
    
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
            operador(c, pt[0]); //5 25 -> 25 4 / 
        }else{
            float num = strtol(pt, NULL, 10);
            operando(c, num);
        }
        pt = strtok(NULL, " ");
    }
    imprimir(c);
    return 0;
}
