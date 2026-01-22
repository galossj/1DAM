#include <stdio.h>

void imprimirDivisores(int N) {
    printf("Los divisores de %d son: ", N);

    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            printf("%d", i);
            
            if (i < N) {
                printf(", ");
            }
        }
    }
    printf("\n");
}

int main() {
    int numero;
    printf("Introduce un numero entero N: ");
    
    if (scanf("%d", &numero) != 1 || numero <= 0) {
        printf("Entrada invalida. Por favor, introduce un numero entero positivo.\n");
    }

    imprimirDivisores(numero);

    return 0;
}
