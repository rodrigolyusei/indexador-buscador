#ifndef LISTA_H
#define LISTA_H

typedef struct _linha_ {
	
	int pos;
	struct _linha_* proximo;

} Linha;

typedef struct _no_ {

	char* palavra;
    Linha* linha;
    int qntd;
	struct _no_* proximo;

} No;

typedef struct {
	
	No* primeiro;

} Lista;

Lista* cria_lista();
No* busca(Lista* lista, char* plvr);
int insere(Lista* lista, char* plvr, int lin);
void imprime_lista(Lista* lista);
void imprime_linhas(Linha* primeira, char** linhas);
#endif