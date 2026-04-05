#include <stdio.h>

/* Um código capaz de calcular o mmc e o mdc de dois números positivos fornecidos 
pelo usuário. */

// Função do  Euclides para MDC
int euclides(int a, int b){

    while (b != 0){
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int main(){

    int a, b, mdc;
    long long mmc; // para evitar overflow

    if (scanf("%d %d", &a, &b) != 2) return 1;
    if (a <= 0 || b <= 0) return 1; // positivos

    mdc = euclides(a, b);
    mmc = (long long)a / mdc * b;

    printf("%d %lld", mdc, mmc);
    return 0;
}