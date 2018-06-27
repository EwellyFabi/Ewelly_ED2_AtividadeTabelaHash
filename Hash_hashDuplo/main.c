#include <stdio.h>
#include <stdlib.h>
#include "funcoes.c"

int main() {
    int n, i;
    char name[20];

    Hash* tab_hash = (Hash*) malloc(sizeof(Hash));
    tab_hash->tab = (Nome_table*)malloc(TAM* sizeof(Nome_table));
    tab_hash->tam = TAM;

    for(i=0; i<TAM; i++){
        strcpy(tab_hash->tab[i].nome,"-1");
    }

    printf("Digite a quantidade de numeros que voce deseja inserir: ");
    scanf("%d", &n);


    for (i = 0; i < n; i++){
        scanf("%s", &name);

        inserir(tab_hash, &name);
    }
    imprimir_hash(tab_hash);
    printf("Digite um nome que deseja remover: ");
    scanf("%s", &name);
    remover(tab_hash, &name);
    imprimir_hash(tab_hash);
}
