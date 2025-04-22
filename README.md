# Indexador e Buscador em C
É um programa em C produzido com o objetivo de estudar estrutura de dados e seus desempenhos, usado para comparar com a implementação em outras linguagens também. Tem como funcionamento receber um arquivo de texto e armazenar em uma lista ligada ou uma árvore binária. Depois recebe uma palavra do usuário a ser buscada na estrutura e apresenta o resultado de ocorrências junto com o tempo de execução da busca.

## Compilar pelo compilador

### Compilação no Linux

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

## Compilar pelo Makefile

Caso tenha o Makefile, a compilação é mais simples, basta indicar se está no Linux ou Windows.\
É possível instalar o Makefile no Windows pelo gerenciador de pacotes ou coleção de ferramentas.\
E para a execução, basta seguir pelos mesmos comandos acima.

```
make lin
```
```
make win
```

## Execução

Adicione os arquivos de texto a ser usado em `/data` e substitua o `teste`.\
Indique a estrutura de dados usada no final, sendo `lista` ou `arvore`.\
Depois use o comando `busca` seguido de uma palavra para ser procurada no texto.\
Para finalizar o programa digite `fim`.\
Caso não indique a estrutura, o programa irá apenas imprimir as palavras do texto.

```
./indexador.exe data/teste.txt
```
```
./indexador.exe data/teste.txt lista
```
```
./indexador.exe data/teste.txt arvore
```
