#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addNo(struct Node** raiz, struct Node* no) {
    if (*raiz== NULL) {
        *raiz = no;
    } else {
        int i = strcmp(no->palavra, (*raiz)->palavra);
        if ( i <= 0) {
            if ((*raiz)->esquerda == NULL) {
                (*raiz)->esquerda = no;
            } else {
                addNo(&((*raiz)->esquerda), no);
//Refaz a função porém comparando com o elemento a esquerda 
            }}
       if ( i > 0) {
            if ((*raiz)->direita == NULL) {
                (*raiz)->direita = no;
            } else {
                addNo(&((*raiz)->direita), no);
            }
        }        
    }
}
struct Node* Busca(struct Node* raiz,const char* plvr) {
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
