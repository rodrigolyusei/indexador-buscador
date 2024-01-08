#ifndef ARVORE_H
#define ARVORE_H

struct Node {
    char* palavra;
    struct Node* esquerda;
    struct Node* direita;
    int linha;
} No;

void addNo(struct Node* raiz, struct Node* no);



#endif
