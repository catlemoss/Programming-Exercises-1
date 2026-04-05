#include <stdio.h>

/* Um programa que recebe um número real (com no máximo 2 casas decimais) e
imprime a parte inteira e a parte real da seguinte forma: INTEIRO:#, REAL:0.##*/

int main(){

    float numero;
    scanf("%f", &numero);

    int inteiro = (int)numero;
		
	float decimal = numero - inteiro;

    printf("INTEIRO:%d,REAL:%.2f", inteiro, decimal);

    return 0;
}