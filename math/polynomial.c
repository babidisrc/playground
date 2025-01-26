#include <stdio.h>
#include <time.h> 

int horner(int poly[], int n, int x)  { 
    int result = poly[0]; 
 
    for (int i = 1; i < n; i++) 
        result = result * x + poly[i]; 
 
    return result; 
} 

int main() {
    clock_t t; 
    t = clock();

    int poly[] = {2, -6, 2, -1}; 
    int x = 3; 
    int n = sizeof(poly)/sizeof(poly[0]); 

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("Valor do polinômio: %d\n", horner(poly, n, x)); 
    // perceba o quão rápido é
    printf("horner() demorou %f segundos para executar\n", time_taken); 

    return 0; 
}