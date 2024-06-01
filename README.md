
# Indexador-Buscador
É um programa produzido com o objetivo de estudar estrutura de dados e seus desempenhos. Tem como funcionamento receber um arquivo de texto e armazenar em uma lista ligada ou uma árvore binária. Depois recebe uma palavra do usuário a ser buscada na estrutura e apresenta o resultado de ocorrências junto com o tempo de execução da busca.

## Instruções para execução usando diretamente o compilador

### Compilação

Primeiro é necesário que esteja no diretório `/src` para compilar.\
O compilador usado é o gcc, mas caso seja diferente basta substitur.

```
gcc -Wall src/main.c src/arvore.c src/lista.c -o indexador
```

### Compilação no Windows

Há uma função como o "strsep" que não é padrão na biblioteca string.h pelo MinGW no Windows.\
Nesse caso, colocamos uma implementação no arquivo windows.c e deve ser compilado como:

```
gcc -Wall src/main.c src/arvore.c src/lista.c src/windows.c -o indexador
```

### Execução

Adicione os arquivos de texto a ser usado em `/data` e substitua o `teste`.\
Indique a estrutura de dados usada no final, sendo `lista` ou `arvore`.\
Caso não indique nada, o programa irá apenas imprimir as palavras do texto.

```
./indexador.exe data/teste.txt
./indexador.exe data/teste.txt lista
./indexador.exe data/teste.txt arvore
```

## Instruções para execução usando Makefile

Caso tenha o Makefile, basta usar o comando `make` e indicar qual compilação usar:

```
make lin
make win
```

Se estiver no Linux use a primeira opção, e no Windows a segunda.\
A diferença é apenas as funções padrões explicadas acima.\
Para a execução, basta seguir no mesmo método do terminal.