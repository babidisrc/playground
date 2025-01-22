#include <stdio.h>

// macros para simplificação, não é obrigatório mas deixa a construção do código mais fácil
#define TAG_INT(x) ((struct dynamic){ .tag = _TAG_INT, .value.i = (x) })
#define TAG_FLOAT(x) ((struct dynamic){ .tag = _TAG_FLOAT, .value.f = (x) })
#define TAG_CHAR(x) ((struct dynamic){ .tag = _TAG_CHAR, .value.c = (x) })

enum enumTag {
    _TAG_INT,
    _TAG_FLOAT,
    _TAG_CHAR,
};

struct dynamic {
    enum enumTag tag;

    // para os que nunca viram ou não se lembram, `union` é uma forma de agrupar várias variáveis em um só lugar
    // ela é parecida com um struct, mas o "twist" dela é que só é reservado UM espaço de memória pras variáveis
    // o que isso significa? significa que você só pode usar uma variável de cada vez
    // a vantagem disso é que um union economiza mais memória que um struct convencional (nesse exemplo, economiza 2x mais)
    // a desvantagem é, claro, você estar limitado a usar só uma variável
    union {
        int i;
        float f;
        char c;
    } value;
};

int main() {
    struct dynamic d;

    // tente comentar as expressões abaixo para ver o resultado que é printado!
    d = TAG_INT(49);
    d = TAG_FLOAT(65.5);
    d = TAG_CHAR('A');

    printf("Sizeof d: %zu\n", sizeof d);

    // printa de acordo com a tag
    switch (d.tag) {
        case _TAG_INT: printf("Value: %d\n", d.value.i); break;
        case _TAG_FLOAT: printf("Value: %f\n", d.value.f); break;
        case _TAG_CHAR: printf("Value: %c\n", d.value.c); break;

        default: printf("UNKNOWN\n"); break;
    }
    
    return 0;
}