// Duff's Device -> otimização para copiar dados de um array para outro.

#include <stdio.h>

// to = target
// from = source
// count = número de bytes a serem copiados, nesse nosso exemplo são 20 bytes

void duffCopy (char *to, char *from, int count) {
    if (count <= 0) return;

    size_t n = (count + 7) / 8; // (20 + 7) / 8 --> n = 3
                                // "while" vai rodar 3 vezes

    switch (count % 8) { // o resto é 4, então pula direto pro caso 4
        case 0: 
                do { // o while pula para cá
                    *to++ = *from++;
        case 7:     *to++ = *from++;
        case 6:     *to++ = *from++;
        case 5:     *to++ = *from++;
        case 4:     *to++ = *from++; // --> o primeiro loop começa aq
        case 3:     *to++ = *from++;
        case 2:     *to++ = *from++;
        case 1:     *to++ = *from++;
                } while (--n > 0); // reduz n em 1, então pula para o "do"
                                    // se n for maior que 0
    }
}

int main() {
    static char source[20] = "Esse é o source!!";
    static char target[20];

    duffCopy(&target[0], &source[0], 20);

    printf("Source: %s \nTarget: %s \n", source, target);
    return 0;
}

