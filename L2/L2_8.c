#include <stdio.h>

/* Um programa que imprima os números primos
contidos em um intervalo n e m fornecidos pelo usuário. */

int ehPrimo(int num){

    if (num < 2) return 0;

    for (int i = 2; i * i <= num; i++){
        if (num % i == 0) return 0;
    }

    return 1;
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    printf("RESP:");

    for (int i = n + 1; i < m; i++){

        if (ehPrimo(i)) printf("%d ", i);
    }

    return 0;
}