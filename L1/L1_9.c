#include <stdio.h>
 
/* Um programa que mostre a versão maiúscula de uma 
letra minúscula.  */

int main(){
	
	char letra;
	scanf("%c", &letra);
	
	if (letra <= 90 && letra >= 65){
		printf("A letra deve ser minuscula!");
		
	} else if (letra <= 122 && letra >= 97){
		char letraMaiuscula = letra - 32;
		int numLetra = (int)letra - 32; // ou (int)letraMaiuscula

        printf("%c(%d)", letraMaiuscula, numLetra);
		
	} else {
		printf("Nao e letra!");
	}
	
	return 0;
}
