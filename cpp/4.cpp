#include<stdio.h>
#include<string.h>

int main(){
	char palabra[100];
	int suma_letra=0;
	
	printf("Introduzca una palabra: \n");
	scanf("%s", palabra);
	
	for(int i=0; i<strlen(palabra); i++){
		suma_letra += palabra[i];
		
	}
	
	printf("La suma de las letras es: %d", suma_letra);
}
