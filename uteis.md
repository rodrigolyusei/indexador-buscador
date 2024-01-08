## CALCULAR TEMPO

- Iremos calcular o tempo de execução dentro do código indexador.c.
- Para calcular o tempo de execução, usar a biblioteca `#include <time.h>` e os comandos:
```
start_time = clock();

// Código que precisa ter o tempo medido

end_time = clock();

 cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

```