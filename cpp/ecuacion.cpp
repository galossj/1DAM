#include <stdio.h>
#include <math.h>

int main(){
	int a, b, c, cuadrado, raiz2;
	float x1, x2, raiz;
	
	printf("Introduzca A: ");
	scanf("%d", &a);
	
	printf("Introduzca B: ");
	scanf("%d", &b);
	
	printf("Introduzca C: ");
	scanf("%d", &c);
	
	cuadrado = b * b;
	
	raiz2 = 4 * a * c;
	
	raiz = sqrt(cuadrado - raiz2);
	
	x1 = (-b + raiz) / (2 * a);
	x2 = (-b - raiz) / (2 * a);
	
	printf("Los resultados son %f %f", x1, x2);
}
