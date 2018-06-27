#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void inserir(Hash * tab_hash, char * name){
    int i, h, g, posicao;
    posicao = (int) name[0] % TAM;
    i = 0;
    while (i < TAM && (strcmp(tab_hash->tab[posicao].nome, "-1") != 0 && strcmp(tab_hash->tab[posicao].nome, "-2") != 0)) {
        h = (int) name[0] % TAM;
        g = 1 + (int) name[i+1] % (TAM - 2);
        posicao = (h+i*g) % TAM;
        i++;
    }

    if (strcmp(tab_hash->tab[posicao].nome, "-1") != 0 || strcmp(tab_hash->tab[posicao].nome, "-2") != 0){
        strcpy(tab_hash->tab[posicao].nome, name);
    } else{
        printf("Sem espaco para armazenamento\n");
    }
}

void imprimir_hash(Hash * tab_hash){
    printf("Tabela Hash\n");
    for (int i = 0; i < TAM; i++) {
        if (!(strcmp(tab_hash->tab[i].nome, "-1") == 0 || strcmp(tab_hash->tab[i].nome, "-2") == 0)) {
            printf("Posicao: %d nome : %s \n",i,tab_hash->tab[i].nome);
        } else {
             printf("Posicao: %d vazia\n",i);
        }
    }
}

void remover(Hash * tab_hash, char * name){
    int h, g;
    int i=0;
    int posicao = (int) name[0] % TAM;
    while (posicao < TAM && strcmp(tab_hash->tab[posicao].nome, name) != 0) {
        h = (int) name[0] % TAM;
        g = 1 + (int) name[i+1] % (TAM - 2);
        posicao = (h+i*g) % TAM;
        i++;
    }
    if (strcmp(tab_hash->tab[posicao].nome, name) == 0)
        strcpy(tab_hash->tab[posicao].nome, "-2");
    else
        printf("Nome não encontrado");
}

void liberar_Tab(Hash * tab_hash){
    free(tab_hash->tab);

}
