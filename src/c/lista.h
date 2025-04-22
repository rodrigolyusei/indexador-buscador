#ifndef LISTA_H
#define LISTA_H

typedef struct _linhaL_ {
	
	int pos;
	struct _linhaL_* proximo;

} LinhaL;

typedef struct _noL_ {

	char* palavra;
    LinhaL* linha;
    int qntd;
	struct _noL_* proximo;

} NoL;

typedef struct _lista_ {
	
	NoL* primeiro;

} Lista;

Lista* cria_lista();
NoL* buscaL(Lista* lista, char* plvr);
int insereL(Lista* lista, char* plvr, int lin);
void imprime_lista(Lista* lista);
void imprime_linhasL(LinhaL* primeira, char** linhas);

#endif