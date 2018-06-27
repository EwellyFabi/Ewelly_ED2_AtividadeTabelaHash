#include <stdio.h>
#include <stdlib.h>
#include "funcoes.c"
#define TAM 3

int main() {
    int n, valor, i, j;
    int posicao;

    Table *tabela = criar_Hash(TAM);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &valor);
        posicao = valor%TAM;
        inserir_hash(tabela, posicao, valor);
    }
    imprime_hash(tabela);
}

