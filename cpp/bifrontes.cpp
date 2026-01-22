#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para la función tolower

#define ALPHABET_SIZE 26 // Para contar las 26 letras de 'a' a 'z'


int sonBifrontes(const char *C, const char *D) {
    if (strlen(C) != strlen(D)) {
        return 0;
    }
    int frecuencia[ALPHABET_SIZE] = {0};

    for (int i = 0; C[i] != '\0'; i++) {
        char charC = tolower(C[i]);
        char charD = tolower(D[i]);
        
        // Solo contamos letras del alfabeto (a-z)
        if (charC >= 'a' && charC <= 'z') {
            frecuencia[charC - 'a']++; 
        }

        if (charD >= 'a' && charD <= 'z') {
            frecuencia[charD - 'a']--; 
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (frecuencia[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char cadena1[] = "amor";
    char cadena2[] = "roma";
    char cadena3[] = "arroz";
    char cadena4[] = "zorra";

    if (sonBifrontes(cadena1, cadena2)) {
        printf("Las cadenas \"%s\" y \"%s\" SON bifrontes (anagramas).\n", cadena1, cadena2);
    } else {
        printf("Las cadenas \"%s\" y \"%s\" NO son bifrontes (anagramas).\n", cadena1, cadena2);
    }

    if (sonBifrontes(cadena3, cadena4)) {
        printf("Las cadenas \"%s\" y \"%s\" SON bifrontes (anagramas).\n", cadena3, cadena4);
    } else {
        printf("Las cadenas \"%s\" y \"%s\" NO son bifrontes (anagramas).\n", cadena3, cadena4);
    }

    return 0;
}
