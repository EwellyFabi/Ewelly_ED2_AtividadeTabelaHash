#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#define TAM 23

typedef struct  nome_table{
    char nome[20];
}Nome_table;


typedef struct hash_table{
    Nome_table * tab;
    int tam;
}Hash;

void inserir(Hash * tab_hash, char * name);
void imprimir_hash(Hash * tab_hash);
void remover(Hash * tab_hash, char * name);
void liberar_Tab(Hash * tab_hash);

#endif // FUNCOES_H_INCLUDED
