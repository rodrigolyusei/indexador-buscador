#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista * cria_lista(){
	Lista * lista =  (Lista *) malloc (sizeof(Lista));
	lista->primeiro = NULL;
	
	return lista;
}

int insere(Lista * lista, char * plvr){
	No * p;
	No * anterior;
	No * novo = (No *) malloc(sizeof(No));

	novo->palavra = plvr;
	anterior = NULL;
	p = lista->primeiro;

	while(p){
		if( strcasecmp(plvr, p->palavra) > 0 ) break;
 		
		anterior = p;
		p = p->proximo;
	}
	
	novo->proximo = p;
	if(anterior) anterior->proximo = novo;
	else lista->primeiro = novo;

    return 0;
}

No * busca(Lista * lista, char * plvr){
	int i = 0;
	No * p = lista->primeiro;

	while(p && strcasecmp(plvr, p->palavra)){
		p = p->proximo;
        if( strcasecmp(plvr, p->palavra) = 0 ) return p;
	}
}