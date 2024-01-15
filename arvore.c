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

int maximo(int a, int b) {
    return (a > b) ? a : b;
}



void imprime_linhasA(LinhaA* primeira, char** linhas){
	LinhaA* aux = primeira;
	while(aux){
		printf("%05d: %s\n", aux->pos, linhas[aux->pos-1]);
		aux = aux->proximo;
	}
}

int altura_no(NoA* no) {
    if (no == NULL) return 0;
    return no->altura;
}

int fator_balanceamento(NoA* no) {
    if (no == NULL) return 0;
    return altura_no(no->esquerda) - altura_no(no->direita);
}

NoA* rotacao_direita(NoA* y) {
    NoA* x = y->esquerda;
    NoA* T2 = x->direita;

    // Realiza a rotação
    x->direita = y;
    y->esquerda = T2;

    // Atualiza as alturas
    y->altura = 1 + maximo(altura_no(y->esquerda), altura_no(y->direita));
    x->altura = 1 + maximo(altura_no(x->esquerda), altura_no(x->direita));

    return x;
}

NoA* rotacao_esquerda(NoA* x) {
    NoA* y = x->direita;
    NoA* T2 = y->esquerda;

    // Realiza a rotação
    y->esquerda = x;
    x->direita = T2;

    // Atualiza alturas
    x->altura = maximo(altura_no(x->esquerda), altura_no(x->direita)) + 1;
    y->altura = maximo(altura_no(y->esquerda), altura_no(y->direita)) + 1;

    return y;
}

NoA* insere_avl(NoA* raiz, char* plvr, int lin) {
        if (raiz == NULL) {
        NoA* novo_no = (NoA*)malloc(sizeof(NoA));
        novo_no->palavra = (char*)malloc(strlen(plvr) + 1);
        strcpy(novo_no->palavra, plvr);
        novo_no->linha = (LinhaA*)malloc(sizeof(LinhaA));
        novo_no->linha->pos = lin;
        novo_no->linha->proximo = NULL;
        novo_no->esquerda = NULL;
        novo_no->direita = NULL;
        novo_no->altura = 1;
        novo_no->qntd = 1;
        return novo_no;
    }

        int comp = strcasecmp(plvr, raiz->palavra);

        
    if (comp < 0) {
        raiz->esquerda = insere_avl(raiz->esquerda, plvr, lin);
    } else if (comp > 0) {
        raiz->direita = insere_avl(raiz->direita, plvr, lin);
    } else {
        // Palavra já existe, adicionar linha
        LinhaA* nova_linha = (LinhaA*)malloc(sizeof(LinhaA));
        nova_linha->pos = lin;
        nova_linha->proximo = raiz->linha;
        raiz->linha = nova_linha;
        raiz->qntd++;
        return raiz;
    }
    raiz->altura = 1 + maximo(altura_no(raiz->esquerda), altura_no(raiz->direita));

    // Calcula o fator de balanceamento do nó
    int balance = fator_balanceamento(raiz);

    // Casos de rotação
    // Esquerda-Esquerda
    if (balance > 1 && strcasecmp(plvr, raiz->esquerda->palavra) < 0)
        return rotacao_direita(raiz);

    // Direita-Direita
    if (balance < -1 && strcasecmp(plvr, raiz->direita->palavra) > 0)
        return rotacao_esquerda(raiz);

    // Esquerda-Direita
    if (balance > 1 && strcasecmp(plvr, raiz->esquerda->palavra) > 0) {
        raiz->esquerda = rotacao_esquerda(raiz->esquerda);
        return rotacao_direita(raiz);
    }

    // Direita-Esquerda
    if (balance < -1 && strcasecmp(plvr, raiz->direita->palavra) < 0) {
        raiz->direita = rotacao_direita(raiz->direita);
        return rotacao_esquerda(raiz);
    }

    return raiz;
}

void insereArvoreAVL(NoA* raiz, char* plvr, int lin) {
    raiz = insere_avl(raiz, plvr, lin);
}