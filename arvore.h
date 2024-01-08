#ifndef ARVORE_H
#define ARVORE_H

struct Node {
    char* palavra;
    struct Node* esquerda;
    struct Node* direita;
    int linha;
} No;

void addNo(struct No* raiz, struct No* no);



#endif
