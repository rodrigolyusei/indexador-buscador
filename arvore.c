#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addNo(struct Node* raiz, struct Node* no) {
    if (raiz== NULL) {
        raiz = no;
    } else {
        int i = strcmp(no->palavra, raiz->palavra);
        if ( i <= 0) {
            if (raiz->esquerda == NULL) {
                raiz->esquerda = no;
            } else {
                addNo(raiz->esquerda, no);
//Refaz a função porém comparando com o elemento a esquerda 
            }}
       if ( i > 0) {
            if (raiz->direita == NULL) {
                raiz->direita = no;
            } else {
                addNo(raiz->direita, no);
            }
        }        
    }
}
