#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "windows.h"

Lista* cria_lista(){
	Lista* lista =  (Lista*) malloc (sizeof(Lista));
	lista->primeiro = NULL;
	
	return lista;
}

No* busca(Lista* lista, char* plvr){
	int i = 0;
	No* p = lista->primeiro;

	while(p && strcasecmp(plvr, p->palavra) <= 0 ){
		p = p->proximo;
        if( strcasecmp(plvr, p->palavra) == 0 ) return p;
	}

	return NULL;
}

int insere(Lista* lista, char* plvr, int lin){
	//Se a palavra ja existe, apenas incrementa qntd
	No* p = busca(lista, plvr);

	Linha* result = (Linha*) malloc(sizeof(Linha));
	result->pos = lin;

	if(p) {
		p->qntd++;

		Linha* aux = p->linha;

		// 1 2 --> 6
		while (aux->proximo){
			if (aux->proximo->pos == lin){
				free(result);
				return 0;
			}
			aux = aux->proximo;
		}
		aux->proximo = result;
		return 0;
	}

	//Aloca o novo no
	No* anterior;
	No* novo = (No*) malloc(sizeof(No));
	novo->palavra = plvr;
	novo->linha = result;
	anterior = NULL;
	p = lista->primeiro;

	//Percorre a lista ate chegar na posicao certa
	//de acordo com a ordem alfabetica (ASCII)
	while(p){
		if( strcasecmp(plvr, p->palavra) > 0 ) break;
 		
		anterior = p;
		p = p->proximo;
	}
	
	//Insere o novo no na lista
	novo->proximo = p;
	if(anterior) anterior->proximo = novo;
	else lista->primeiro = novo;
	novo->qntd++;

    return 0;
}