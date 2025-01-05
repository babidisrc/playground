## O que é memória?

Bytes -> 8 bits, 0 a 255
Memória -> Longa sequência de bytes

A função sizeof determina o número de bytes para um determinado tipo de dados.

Note-se que o número de bytes reservados pode variar de acordo com o compilador utilizado.  

Exemplo:

```c
x = sizeof(int); // retorna 4 no gcc
```
```c
#include <stdlib.h>

int main() {
  void *ptr = malloc(sizeof(int));
  free(ptr);
  return 0;
}
```

`malloc(sizeof(int))`: aloca o tamanho de int, nesse caso sendo 4 bytes
`free(ptr)`: diz ao alocador que a memória não será mais utilizada, ela então retorna ao pool de memória disponível.

`malloc` retorna um ponteiro, um endereço de memória. Esse endereço é normalmente escrito em hexadecimal, usando "0x" como um prefiro para diferenciar de números decimais.

