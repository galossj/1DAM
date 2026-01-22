#include<stdio.h>
#include<string.h>

int main(){
	char palabra [200];
	int longitud;
	char letra;
	
	printf("Introduzca una palabra: ");
	scanf("%s", &palabra);
	
	longitud=strlen(palabra);
	for(int i=longitud-1; palabra[i] != '\0'; i--) {
		letra= palabra[i];
		printf("%c", letra);
	}
}
