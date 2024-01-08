## TO-DO

- Completar arvore.c:
    - struct Node;
        - possui campos: string palavra, Node* esquerda, Node* direita, e int linha;
    - void addNo(Node* no);
    - int buscaArvore(string palavra);

- Completar lista.c:
    - struct Item;
        - possui campos: string palavra, char* proximo, char* primeiro;
    - void addItem(Item* item);
    - int buscaLista(string palavra);