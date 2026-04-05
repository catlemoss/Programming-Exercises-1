#include <stdio.h>

/* Faça um programa que imprima os números primos
contidos em um intervalo n e m fornecidos pelo usuário.

a) A identificação do número primo deverá ser feita por uma função (a ser
implementada) que receberá um número num e retornará verdadeiro se o número
for primo e falso caso contrário. A função deverá ter o seguinte cabeçalho:
int EhPrimo(int num); */

int EhPrimo(int num){

    if (num < 2) return 0;

    for (int i = 2; i * i <= num; i++){
        if (num % i == 0) return 0;
    }

    return 1;
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = n + 1; i < m; i++){
        if (EhPrimo(i)) printf("%d ", i);
    }

    return 0;
}