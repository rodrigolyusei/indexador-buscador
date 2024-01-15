## CALCULAR TEMPO

- Iremos calcular o tempo de execução dentro do código indexador.c em milésimos.
- Para calcular o tempo de execução, usar a biblioteca `#include <time.h>` e os comandos:

```
clock_t start_time, end_time;
double cpu_time_used;

start_time = clock();

// Código que precisa ter o tempo medido

end_time = clock();

cpu_time_used = ((double) (end_time - start_time))*1000.0 / CLOCKS_PER_SEC;
```

## PRINT DE VARIÁVEIS DO TIPO FILE

- Uma forma de printar uma variável do tipo file

```
FILE * ftpr;

ftpr = fopen(argv[1], "r");
c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    }
fclose(fptr);
```
