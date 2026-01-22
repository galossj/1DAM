#include <stdio.h>

int calcularLongitud(char cadena[]) {
    int contador = 0;

    while (cadena[contador] != '\0') {
        contador++;
    }

    return contador;
}

int main() {
    char miCadena[] = "tu putisima madre"; 
    int longitud;

    longitud = calcularLongitud(miCadena);

    printf("La cadena es: \"%s\"\n", miCadena);
    printf("La longitud calculada es: %d\n", longitud);
    
    return 0;
}
