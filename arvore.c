#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "windows.h"

Arvore* cria_arvore(){
	Arvore* arvore =  (Arvore*) malloc (sizeof(Arvore));
	arvore->raiz = NULL;
	
	return arvore;
}

NoA* buscaA(NoA* raiz, char* plvr) {
    if (raiz == NULL || plvr == NULL) {
        return NULL;
    }

    int comp = strcmp(plvr, raiz->palavra);
    // O no é a raíz 
    if (comp == 0) {
        return raiz;
    } else if (comp < 0) {
        return buscaA(raiz->esquerda,plvr); // Busca na subárvore esquerda
    } else {
        return buscaA(raiz->direita,plvr);
    }
}

int insereA(NoA* raiz, char* plvr) {
    NoA* aux = (NoA*) malloc(sizeof(NoA));

    if (raiz == NULL) {
        raiz = aux;
    } else {
        int i = strcmp(aux->palavra, (raiz)->palavra);
        if ( i < 0) {
            if ((raiz)->esquerda == NULL) {
                (raiz)->esquerda = aux;
            } else {
                insereA((raiz)->esquerda, plvr);
                //Refaz a função porém comparando com o elemento a esquerda 
            }
        }
        if ( i > 0) {
            if ((raiz)->direita == NULL) {
                (raiz)->direita = aux;
            } else {
                insereA((raiz)->direita, plvr);
            }
        }else{ // quando as strings são iguais
	        LinhaA* novaLinha = (LinhaA*)malloc(sizeof(LinhaA));
            novaLinha->pos = aux->linha->pos;
            novaLinha->proximo = (raiz)->linha;
            (raiz)->linha = novaLinha;
            (raiz)->qntd++;
       }
    }
}