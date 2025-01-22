#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// EXEMPLO 1
// inicializa facilmente elementos específicos, além de não se importar com a ordem - Sintaxe de C99
static const char *lookup[256] = {
    ['+'] = "mais",
    ['-'] = "menos",
};

int main() {
    char *string = NULL;
    size_t size = 0;
    size_t chars_read;

    puts("Escreva sua operação matemática:");

    chars_read = getline(&string, &size, stdin);

    // checagem de erros
    if (chars_read < 0) {
        puts("couldn't read the input");
        free(string);
        return 1;
    }

    int len = strlen(string);

    // remove o caractere de nova linha, se presente
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
        len--;
    }

    // printa em extenso as operações (+, -)
    for (int i = 0; i < len; i++) {
        if (string[i] == '+' || string[i] == '-') {
            printf("%s", lookup[(int)string[i]]);
        } else {
            printf("%c", string[i]);
        }
    }
    printf("\n");
    
    // libere a memória pós uso
    free(string);

    // EXEMPLO 2
    // ... -> fica entre dois valores, representa um intervalo
    int widths[] = { [0 ... 9] = 1, [10 ... 99] = 2, [100] = 3 };

    // perceba os intervalos de cada inicializador
    printf("%d\n", widths[4]);
    printf("%d\n", widths[7]);
    printf("%d\n", widths[10]);
    printf("%d\n", widths[98]);
    printf("%d\n", widths[100]);

    return 0;
}