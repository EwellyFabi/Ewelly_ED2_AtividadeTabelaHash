#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

enum Color {BLACK = 1, RED = 0};

typedef struct no
{
    int info;
    int color;
    struct no* esq;
    struct no* dir;
    struct no* p;
}Nodo;

typedef struct arv{
    Nodo * raiz;
}Arv;

typedef struct Table {
    Arv **Tab;
    int size;
}Table;

Table* criar_Hash(int n);
Arv* cria_arb();
Nodo* criar_no(int info);

void inserir_hash(Table* tabela, int posicao, int info);
void inserir_rb(Arv* arv, int info);

void rb_insert(Arv *t, Nodo *z);
void rb_fix_up_insert(Arv *t, Nodo *z);
void leftRotate(Arv *t, Nodo *x);
void rightRotate(Arv *t,Nodo *x);

void imprime_rb(Arv* arv);
void imprime_rb_no(Nodo* raiz);
void imprime_hash(Table* tabela);

Nodo* busca_hash(Arv* arv, int info);
Nodo* busca_rb(Nodo* r, int info);

void libera_hash(Table* tabela);
void libera_arv(Arv* arv);
void libera_no(Nodo*r);


#endif // FUNCOES_H_INCLUDED
