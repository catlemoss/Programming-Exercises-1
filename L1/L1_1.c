#include <stdio.h>
#include <math.h>

/* Um programa para ler 2 números inteiros e calcular 
a soma de suas raízes quadradas. */

int main(){

    int num1, num2;
    scanf("%d %d", &num1, &num2);

    float raiz1 = sqrt(num1);
    float raiz2 = sqrt(num2);

    float soma = raiz1 + raiz2;

    printf("%.2f", soma);
    return 0;
}