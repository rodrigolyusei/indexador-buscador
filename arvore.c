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
    // Nao achou a palavra buscada
    if (raiz == NULL || plvr == NULL) {
        return NULL;
    }

    int comp = strcasecmp(plvr, raiz->palavra);
    if (comp == 0) {
        // Achou a palavra buscada
        return raiz;
    } else if (comp < 0) {
        // Busca na subarvore esquerda
        return buscaA(raiz->esquerda,plvr);
    } else {
        // Busca na subarvore direita
        return buscaA(raiz->direita,plvr);
    }
}

NoA* insereA(NoA* raiz, char* plvr, int lin) {
    // Aloca uma nova linha
    LinhaA* novalin = (LinhaA*) malloc(sizeof(LinhaA));
    novalin->pos = lin;
    novalin->proximo = NULL;

    // Se a raiz nao existe aloca novo no
    if (raiz == NULL){
        NoA* novono = (NoA*) malloc(sizeof(NoA));
        novono->palavra = (char*) malloc(strlen(plvr) + 1);
        strcpy(novono->palavra, plvr);
        novono->linha = novalin;
        novono->esquerda = NULL;
        novono->direita = NULL;
        novono->qntd = 1;

        return novono;
    }

    // Se a raiz existe compara com a palavra inserida
    int comp = strcasecmp(plvr, raiz->palavra);
    if ( comp < 0) {
        // Se a palavra inserida vem antes da raiz insere a esquerda 
        raiz->esquerda = insereA(raiz->esquerda, plvr, lin);
    } else if (comp > 0){
        // Se a palavra inserida vem depois da raiz insere a direita
        raiz->direita = insereA(raiz->direita, plvr, lin);
    } else {
        // Se a palavra inserida for igual da raiz, apenas incrementa
        LinhaA* aux2 = raiz->linha;
        raiz->qntd++;
        
        while (aux2->proximo != NULL){
            if (aux2->proximo->pos == lin){
                free(novalin);
                return raiz;
            }
            aux2 = aux2->proximo;
        }

        if (aux2->pos == lin){
            free(novalin);
            return raiz;
        }

        aux2->proximo = novalin;
        
    }
    return raiz;
}

void imprime_arvore_rec(NoA* no) {
    if(no){
        imprime_arvore_rec(no->esquerda);

        printf("Palavra: %s\n", no->palavra);
        printf("Quantidade de Ocorrencias: %d\n", no->qntd);

        LinhaA* arvore_atual = no->linha;
        while (arvore_atual != NULL) {
            printf("Posicao: %d\n", arvore_atual->pos);
            arvore_atual = arvore_atual->proximo;
        }
        printf("\n");

        imprime_arvore_rec(no->direita);
    }
}

void imprime_arvore(Arvore* arvore) {
    if(arvore == NULL || arvore->raiz == NULL) {
        printf("Arvore vazia\n");
        return;
    }

    imprime_arvore_rec(arvore->raiz);
}

void imprime_linhasA(LinhaA* primeira, char** linhas){
	LinhaA* aux = primeira;
	while(aux){
		printf("%05d: %s\n", aux->pos, linhas[aux->pos-1]);
		aux = aux->proximo;
	}
}