#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addNo(Node** raiz, Node* nod) {
    if (*raiz== NULL) {
        *raiz = nod;
    } else {
        int i = strcmp(nod->palavra, (*raiz)->palavra);
        if ( i <= 0) {
            if ((*raiz)->esquerda == NULL) {
                (*raiz)->esquerda = nod;
            } else {
                addNo(&((*raiz)->esquerda), nod);
//Refaz a função porém comparando com o elemento a esquerda 
            }}
       if ( i > 0) {
            if ((*raiz)->direita == NULL) {
                (*raiz)->direita = nod;
            } else {
                addNo(&((*raiz)->direita), nod);
            }
        }        
    }
}

Node* Busca(Node* raiz,const char* plvr) {
    if (raiz == NULL || plvr == NULL) {
        return NULL;
    }
    int comp = strcmp(plvr, raiz->palavra);
    if (comp == 0) {
        return raiz; // O no é a raíz 
    } else if (comp < 0) {
        return Busca(raiz->esquerda,plvr); // Busca na subárvore esquerda
    } else {
        return Busca(raiz->direita,plvr);
    }
}
