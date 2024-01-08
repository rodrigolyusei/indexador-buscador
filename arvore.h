#ifndef ARVORE_H
#define ARVORE_H

struct Node {
    char* palavra;
    struct Node* esquerda;
    struct Node* direita;
    int linha;
} Nod;

void addNo(struct Node** raiz, struct Node* no);
struct Node* Busca(struct Node* raiz, const char* plvr);


#endif
