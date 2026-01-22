#include<stdio.h>
#include<string.h>

int main(){
    int valor;
	char encrip[200];
	char alfabeto[28]=" abcdefghijklmnopqrstuvwxyz";
    int f=0;
	int r=0;
    
    printf("Introduzca un encriptado: ");
    scanf("%s",encrip);
    
    for(int i=0;i<strlen(encrip);i++){
    
        valor=encrip[i];
        if(valor==46){
            if(f==0){
                printf("%c", alfabeto[r]-32);
                f=1;
            }else{    
                printf("%c", alfabeto[r]);
            }
            r=0;
        }else{
            r=r*10+valor-48;
        }
    }
    printf("%c", alfabeto[r]);
}
