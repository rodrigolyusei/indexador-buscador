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

NoA* insereA(NoA* raiz, char* plvr, int lin) {

    LinhaA* linha = (LinhaA*) malloc(sizeof(LinhaA));
    linha->pos = lin;
    linha->proximo = NULL;


    if (raiz == NULL){
        NoA* aux = (NoA*) malloc(sizeof(NoA));
        aux->linha = linha;
        //aux->palavra = plvr;
        aux->palavra = (char*) malloc(strlen(plvr) + 1);
        strcpy(aux->palavra, plvr);
        aux->esquerda = NULL;
        aux->direita = NULL;

        aux->qntd = 1;
        return aux;
    }

    int comp = strcmp(plvr, raiz->palavra);

    if ( comp < 0) {
            raiz->esquerda = insereA(raiz->esquerda, plvr, lin);
    } else if (comp > 0){
        raiz->direita = insereA(raiz->direita, plvr, lin);
        //Refaz a função porém comparando com o elemento a esquerda 
    } else { 

        LinhaA* aux2 = raiz->linha;
        raiz->qntd++;
        
        while (aux2->proximo != NULL){
            if (aux2->proximo->pos == lin){
                free(linha);
                return raiz;
            }
            aux2 = aux2->proximo;
        }

        if (aux2->pos == lin){
            free(linha);
            return raiz;
        }

        aux2->proximo = linha;
        
    }
    return raiz;
}
