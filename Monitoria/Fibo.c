#include <stdio.h>

/* Faça um programa em C padrão para apresentar os n primeiros termos da série de Fibonacci: */

int main(){

    int num, fibo, aux1 = 0, aux2 = 1;

    printf("Quantos termos da serie de Fibonacci voce quer?\n");
    scanf("%d", &num);

    for (int i = 0; i < num; i++){

        fibo = aux1 + aux2;

        printf("%d ", fibo);

        aux2 = aux1;
        aux1 = fibo;
    }

    return 0;
}