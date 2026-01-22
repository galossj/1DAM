#include<stdio.h>
#include<conio.h>

int main(){
	
	int option = 0;
	int contador = 0;
	char palabra[50];
	
	printf("Opciones:\n");
	printf("1. Convertir palabra de mayuscula a minuscula:\n");
	printf("2. Convertir palabra de minuscula a mayuscula:\n");
	printf("3. Contar vocales:\n");
	printf("4. Contar consonantes:\n");
	
	//si pulsamos 1 guarda en option "1" == 49
	
	option = getch();
	
	switch(option){
		case '1':
			
			printf("Introduce una palabra para convertirla: ");
			scanf("%s", palabra);
			
			for(int i = 0; palabra[i] != '\0'; i++){
				if(palabra[i] >= 'A' && palabra[i] <= 'Z'){
					palabra[i] += 32;
					//palabra[i] = palabra[i] + 32
				}
			}
			
			printf("La palabra en minuscula es %s", palabra);
			break;
		
		case '2':
			printf("Introduce una palabra para convertirla: ");
			scanf("%s", palabra);
			
			for(int i = 0; palabra[i] != '\0'; i++){
				if(palabra[i] >= 'a' && palabra[i] <= 'z'){
					palabra[i] -= 32;
					//palabra[i] = palabra[i] - 32
				}
			}
			
			printf("La palabra en minuscula es %s", palabra);
			break;
		
		case '3':
			printf("Introduce una palabra para convertirla: ");
			scanf("%s", palabra);
			
			contador = 0;
			
			for(int i = 0; palabra[i] != '\0'; i++){
				if(palabra[i] == 'a' || palabra[i] == 'A'
				|| palabra[i] == 'e' || palabra[i] == 'E'
				|| palabra[i] == 'i' || palabra[i] == 'I'
				|| palabra[i] == 'o' || palabra[i] == 'O'
				|| palabra[i] == 'u' || palabra[i] == 'U'){
					contador++;
				}
			}
			
			printf("Hay %d vocales en la palabra\n", contador);
			break;
		
		case '4':
			printf("Introduce una palabra para convertirla: ");
			scanf("%s", palabra);
			
			contador = 0;
			
			for(int i = 0; palabra[i] != '\0'; i++){
				if(palabra[i] != 'a' && palabra[i] != 'A'
				&& palabra[i] != 'e' && palabra[i] != 'E'
				&& palabra[i] != 'i' && palabra[i] != 'I'
				&& palabra[i] != 'o' && palabra[i] != 'O'
				&& palabra[i] != 'u' && palabra[i] != 'U'){
					contador++;
				}
			}
			
			printf("Hay %d consonantes en la palabra\n", contador);
			break;
			
	}
}
