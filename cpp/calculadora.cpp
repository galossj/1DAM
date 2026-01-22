#include <stdio.h>;

void menu();
void operacion(int opcion);
float sumar(float a, float b);
float restar(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);

int main() {
    int opcion;

    do {
        menu();
        printf("Seleccione una opcion (1-5): ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= 4) {
            operacion(opcion);
        } else if (opcion == 5) {
            printf("\nSaliendo del programa.\n");
        } else {
            printf("\nOpcion no valida.\n");
        }

    } while (opcion != 5);

    return 0;
}


void menu() {
    printf("\n--- MENU DE CALCULADORA ---\n");
    printf("1. Sumar\n");
    printf("2. Restar\n");
    printf("3. Dividir\n");
    printf("4. Multiplicar\n");
    printf("5. Salir\n");
    printf("---------------------------\n");
}

void operacion(int opcion) {
    float n1, n2, resultado;
   
    printf("Introduce el primer numero: ");
    scanf("%f", &n1);
    printf("Introduce el segundo numero: ");
    scanf("%f", &n2);

    switch (opcion) {
        case 1:
            resultado = sumar(n1, n2);
            printf("Resultado: %.2f + %.2f = %.2f\n", n1, n2, resultado);
            break;
        case 2:
            resultado = restar(n1, n2);
            printf("Resultado: %.2f - %.2f = %.2f\n", n1, n2, resultado);
            break;
        case 3:
            if (n2 != 0) {
                resultado = dividir(n1, n2);
                printf("Resultado: %.2f / %.2f = %.2f\n", n1, n2, resultado);
            } else {
                printf("No se puede dividir entre cero.\n");
            }
            break;
        case 4:
            resultado = multiplicar(n1, n2);
            printf("Resultado: %.2f * %.2f = %.2f\n", n1, n2, resultado);
            break;
    }
}

float sumar(float a, float b) { return a + b; }
float restar(float a, float b) { return a - b; }
float multiplicar(float a, float b) { return a * b; }
float dividir(float a, float b) { return a / b; }
