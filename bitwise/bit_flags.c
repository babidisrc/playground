#include <stdio.h>

// typedef unsigned int t_flag
// #define LEITURA (1 << 0)
// #define ESCRITA (1 << 1)
// #define EXECUTA (1 << 2)

// a forma de cima também está correta

typedef enum {
    LEITURA = (1 << 0), // 1 --> 0001
    ESCRITA = (1 << 1), // 2 --> 0010
    EXECUTA = (1 << 2) // 4 --> 0100
} t_flags;

// o operador bit a bit "<<", o left shift, é conhecido por multiplicar por potências de 2
// 1 << 0 = 1 * 2⁰ = 1
// 1 << 1 = 1 * 2¹ = 2
// 1 << 2 = 1 * 2² = 4

// já o operador ">>", right shift, equivale à divisão por potências de 2
// 4 >> 0 = 4 / 2⁰ = 4
// 4 >> 1 = 4 / 2¹ = 2
// 4 >> 2 = 4 / 2² = 1

int main(void) {
    char arquivo = LEITURA | ESCRITA;

    if (arquivo & LEITURA) {
        printf("É possível ler o arquivo\n"); // VERDADEIRO
    }

    if (arquivo & ESCRITA) {
        printf("É possível escrever no arquivo\n"); // VERDADEIRO
    }

    if (arquivo & EXECUTA) {
        printf("É possível executar o arquivo\n"); // FALSO, não vai ser printado
    }

    printf("%d\n", arquivo); // 3 --> 0011, percebe-se que o terceiro bit (equivalente a 4) é falso
                            // portanto o arquivo não executa

    arquivo |= EXECUTA; // o operador OR (|) junta os bits de arquivo (0011) e de EXECUTA (0100)

    if (arquivo & EXECUTA) {
        printf("É possível executar o arquivo\n"); // agora sim é VERDADEIRO
    }

    printf("%d\n", arquivo); // 7 --> 0111

    arquivo ^= ESCRITA; // o operador XOR (^) remove o bit de ESCRITA se estiver presente

    // o operador " ~ " seria a mesma coisa que um "not" ou "!", o inverso
    // na condição abaixo, queremos saber se arquivo NÃO possui ESCRITA
    if (arquivo & ~ESCRITA) {
        printf("NÃO é possível escrever no arquivo\n"); // VERDADEIRO
    }

    printf("%d\n", arquivo); // 5 --> 0101

    return 0;
}
