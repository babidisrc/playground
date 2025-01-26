#include <stdio.h>
#include <stdarg.h>

int sum_all(int count, ...) {
    va_list ap;
    va_start(ap, count);

    int sum = 0;

    for (int i = 0; i < count; i++) {
        int x = va_arg(ap, int);
        sum += x;
    }

    return sum;
}

int main() {
    printf("%d\n", sum_all(2, 1, 5));

    return 0;
}