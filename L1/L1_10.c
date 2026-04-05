#include <stdio.h>
 
/* Um programa que mostre se um número é par ou 
ímpar. */

int main(){
	
	int num;
	scanf("%d", &num);
	
	if (num % 2 == 0){ // % é o operador "resto da divisão"
		printf("Par");
		
	} else {
		printf("Impar");
		
	}
	
	return 0;
}
