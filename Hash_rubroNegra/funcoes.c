#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"
//CRIA TABELA HASH
Table* criar_Hash(int n){
    Table* hash = (Table*)malloc(sizeof(Table)); //ALOCA ESPAÇO PARA A HASH
    hash->Tab = (Arv**)malloc(n* sizeof(Arv*)); // CRIA UMA HASH DE ÁRVORES RUBRO-NEGRAS
    hash->size = n; // O TAMANHO DA HASH É PREENCHIDO COM N
    for (int i = 0; i <n; i++) //CRIA AS ÁRVORES
        hash->Tab[i] = cria_arb();
    return hash;
}
//CRIA A ÁRVORE RUBRO NEGRA
Arv* cria_arb(){
    Arv* arv = (Arv*) malloc(sizeof(Arv));
    arv->raiz = NULL;
    return arv;
}
//CRIA NO
Nodo* criar_no(int info){
    Nodo * nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->dir = NULL;
    nodo->esq = NULL;
    nodo->p = NULL;
    nodo->info = info;
    nodo->color = RED;

    return nodo;
}

//INSERE VALORES NA TABELA HASH COM RUBRO NEGRA
void inserir_hash(Table* tabela, int posicao, int info){
    inserir_rb(tabela->Tab[posicao], info);
}
//INSERE VALORES NA ÁRVORE RUBRO NEGRA
void inserir_rb(Arv* arv, int info){
    Nodo* novo = criar_no(info);
    rb_insert(arv, novo);
}

void rb_insert(Arv *t, Nodo *z){
    Nodo*y = NULL;
    Nodo*x = t->raiz;

    while( x != NULL){
        y = x;
        if(z->info < x->info)
            x = x->esq;
        else
            x = x->dir;
    }
    z->p = y;

    if(y == NULL)
        t->raiz = z;
    else if(z->info < y->info)
        y->esq = z;
    else y->dir = z;

    z->esq = z->dir = NULL;
    z->color = RED;
    rb_fix_up_insert(t, z);
}

void rb_fix_up_insert(Arv *t, Nodo *z){
    while(z != t->raiz &&(z->color != BLACK && z->p->color == RED)){
        if(z->p == z->p->p->esq){
            Nodo*y = z->p->p->dir;
            if(z->p->p->dir != NULL && y->color == RED){
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else{
                if(z == z->p->dir){
                    z = z->p;
                    leftRotate(t,z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                rightRotate(t, z->p->p);
            }
        }
        else{
            Nodo*y = z->p->p->esq;
            if(z->p->p->esq != NULL && y->color == RED){
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else{
                if(z == z->p->esq){
                    z = z->p;
                    rightRotate(t,z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                leftRotate(t, z->p->p);
            }
        }
    }
    t->raiz->color = BLACK;
}

void leftRotate(Arv *t, Nodo *x){
    Nodo*y = x->dir;
    x->dir = y->esq;

    if(y->esq != NULL)
        y->esq->p = x;
    y->p = x->p;
    if(x->p == NULL)
        t->raiz = y;
    else if(x == x->p->esq)
        x->p->esq = y;
    else
        x->p->dir = y;
    y->esq = x;
    x->p = y;
}

void rightRotate(Arv *t,Nodo *x){
    Nodo*y = x->esq;
    x->esq = y->dir;

    if(y->dir != NULL)
        y->dir->p = x;
    y->p = x->p;
    if(x->p == NULL)
        t->raiz = y;
    else if(x->p->dir == x)
        x->p->dir = y;
    else
        x->p->esq = y;
    y->dir = x;
    x->p = y;
}

void imprime_rb(Arv* arv){
    imprime_rb_no(arv->raiz);
}

void imprime_rb_no(Nodo* raiz){
    if(raiz != NULL){
        imprime_rb_no(raiz->esq);
        printf("%d\t", raiz->info);
        imprime_rb_no(raiz->dir);
    }
}

void imprime_hash(Table* tabela){
    printf("Tabela Hash\n");
    for(int i = 0; i < tabela->size; i++){
        printf("Arvore RB %d:\n", i);
        imprime_rb(tabela->Tab[i]);
        printf("\n");
    }
}

Nodo* busca_hash(Arv* arv, int info){
    busca_rb(arv->raiz, info);
}

Nodo* busca_rb(Nodo* r, int info){
    if(r == NULL || r->info == info)
        return r;
    if(info < r->info)
        return busca_rb(r->esq,info);
    else
        return busca_rb(r->dir,info);
}

void libera_hash(Table* tabela){
    int i;
    for(i=0; i < tabela->size; i++){
       libera_arv(tabela->Tab[i]);
    }
    free(tabela);
}

void libera_arv(Arv* arv){
    libera_no(arv->raiz);
    free(arv);
}

void libera_no(Nodo*r){
    if(r != NULL){
        libera_no(r->esq);
        libera_no(r->dir);
        free(r);
    }
}


