#ifndef ARVORE_H
#define ARVORE_H

typedef struct Nod {

    char* palavra;
    struct Nod* esquerda;
    struct Nod* direita;
    int linha;

} Node;

typedef struct _arvore_ {

    Node* raiz;

} Arvore;

Arvore* cria_arvore();
void addNo(Node** raiz, Node* no);
Node* Busca(Node* raiz, const char* plvr);

#endif