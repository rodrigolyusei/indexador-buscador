#ifndef ARVORE_H
#define ARVORE_H

typedef struct Nod {
    char* palavra;
    struct Nod* esquerda;
    struct Nod* direita;
    int linha;
} Node;

void addNo(struct Node** raiz, struct Node* no);
struct Node* Busca(struct Node* raiz, const char* plvr);

#endif