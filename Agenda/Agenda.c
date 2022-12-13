#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Agenda.h"
#define MAX 250
#define ARQ_NAME "contatos.ccf"

struct contato{
    char nome[51];
    char telefone[16];
    char email[251];
};

Contato *agenda[MAX];
int cont = 0;

void salvandoContato(Contato *ctt, FILE *arq){
    fputs(ctt->nome, arq);
    fputs(ctt->telefone, arq);
    fputs(ctt->email, arq);
}

void inserirContato(Contato *ctt){

    FILE *arq = fopen(ARQ_NAME,"a+");

    if(arq != NULL){
        salvandoContato(ctt, arq);
        agenda[cont] = ctt;
        cont++;
        printf("\nContato Salvo!\n");
    }else {
        printf("\nOcorreu um Erro1\n");
    }
  
    fclose(arq);
}

void cadastraContato(){
    printf("\nNovo Contato\n");
    
    Contato *ctt = (Contato*) malloc(sizeof(Contato));

    printf("Nome: ");
    fgets(ctt->nome, 50, stdin);
    fflush(stdin);
    
    printf("Telefone: ");
    fgets(ctt->telefone, 15, stdin);
    fflush(stdin);

    printf("Email: ");
    fgets(ctt->email, 249, stdin);
    fflush(stdin);

    inserirContato(ctt);
}
void exibirContatos(int i){
    printf("%s", agenda[i]->nome);
    printf("%s", agenda[i]->telefone);
    printf("%s", agenda[i]->email);
}
void listaDaAgenda(){
    printf("\nLista da agenda\n\n");

    for(int i = 0; i < cont; i++){
        exibirContatos(i);
        printf("---------------------\n");
    }
}
int procurandocombinacao(char *a, char *b, int i, int limit){
    if(a[i] == b[i]){
        i++;
        if(i < limit){
            return procurandocombinacao(a, b, i, limit);
        }else {
            return 1;
        }

    }else {
        return 0;
    }
}
void procuraContato(){
    char nomeBusca[51] = {""};

    printf("\nBUSCA CONTATO\n\n"); 

    printf("Digite o nome para busca: ");
    fgets(nomeBusca, 50, stdin);

    int limite = strlen(nomeBusca);
    limite--;
    for(int i = 0; i <cont; i++){
        if(strlen(agenda[i]->nome) >= limite){
          int resp = procurandocombinacao(nomeBusca, agenda[i]->nome, 0, limite);
                if(resp == 1 ){
                    printf("\nContato(s) encontrado(s):\n");
                    exibirContatos(i);
                    printf("----------------------");
                }else{
                }
        }else {
            printf("Falha na busca\n");
        }
    }

}
void menuPrincipal(){
    int op = 0;
    while(op != 4){
        printf("\nSelecione a opcao desejada:\n");
        printf("1 - Novo Contato\n");
        printf("2 - Lista de contatos\n");
        printf("3 - Busca contatos\n");
        printf("4 - Sair\n");
        scanf("%d", &op);
        fflush(stdin);


        if(op == 1){
            cadastraContato();
        }else if(op == 2){
            listaDaAgenda();
        }else if(op == 3){
            procuraContato();
        }else{
            printf("Tchau!");

        }
    }
}
