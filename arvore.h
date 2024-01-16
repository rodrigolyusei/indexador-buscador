#ifndef ARVORE_H
#define ARVORE_H

typedef struct _linhaA_ {

    int pos;
    struct _linhaA_* proximo;

} LinhaA;

typedef struct _noA_ {

    char* palavra;
    LinhaA* linha;
    int qntd;
    struct _noA_* esquerda;
    struct _noA_* direita;

} NoA;

typedef struct _arvore_ {
    
    NoA* raiz;

} Arvore;

Arvore* cria_arvore();
NoA* buscaA(NoA* raiz, char* plvr);
NoA* insereA_rec(NoA* raiz, char* plvr, int lin);
int insereA(Arvore* arvore, char* plvr, int lin);
void imprime_arvore(Arvore* arvore);
void imprime_arvore_rec(NoA* no);
void imprime_linhasA(LinhaA* primeira, char** linhas);

#endif