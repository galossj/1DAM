#include <stdio.h>
#include <ctype.h> // Para funciones de conversión de mayúsculas a minúsculas

int main() {
    char cadena[] = "Abcdefghijklmnopqrstuvwxyz"; // Aquí puedes poner cualquier cadena
    int letras[26] = {0}; // Registro de letras, inicializado en 0
    int i = 0;
    int indice;
    int Perfecto = 1; // Suponemos que es perfecto hasta que se demuestre lo contrario

    // Recorrer la cadena carácter por carácter
    while (cadena[i] != '\0') {
        if (isalpha(cadena[i])) { // Verificar que sea letra
            char c = tolower(cadena[i]); // Convertir a minúscula
            indice = c - 'a'; // Obtener índice 0-25

            if (letras[indice] == 1) { // Ya estaba marcada
                Perfecto = 0; // No es pangrama perfecto
                break;
            } else {
                letras[indice] = 1; // Marcar la letra
            }
        }
        i++;
    }

    // Verificar que todas las letras estén presentes
    if (Perfecto) {
        for (i = 0; i < 26; i++) {
            if (letras[i] == 0) {
                Perfecto = 0; // Faltó alguna letra
                break;
            }
        }
    }

    if (Perfecto) {
		printf("La cadena es un pangrama perfecto.\n");
    } else {
        printf("La cadena NO es un pangrama perfecto.\n");
    }

    return 0;
}

