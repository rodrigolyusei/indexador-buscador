#ifndef ARVORE_H
#define ARVORE_H

typedef struct _linha1_ {
   int pos;
   struct _linha1_* proximo;
}linha1;
typedef struct Nod {

    char* palavra;
    struct Nod* esquerda;
    struct Nod* direita;
    Linha1* linha1;
    int qntd;

} Node;

typedef struct _arvore_ {

    Node* raiz;

} Arvore;

Arvore* cria_arvore();
void addNo(Node** raiz, Node* no);
Node* Busca(Node* raiz, const char* plvr);

#endif
