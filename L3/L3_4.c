#include <stdio.h>

/* Faça um programa que imprima os números primos
contidos em um intervalo n e m fornecidos pelo usuário seguidos por seus múltiplos
até o final do intervalo.

a) A identificação do número primo deverá ser feita por uma função (a ser
implementada) que receberá um número num e retornará verdadeiro se o número
for primo e falso caso contrário. A função deverá ter o seguinte cabeçalho:
int EhPrimo(int num);

b) A impressão dos múltiplos de um número deverá ser feita por uma função (a ser
implementada) que receberá um número num e um número máximo max e
imprimirá todos os múltiplos de num menores do que max. A função deverá ter o
seguinte cabeçalho: void ImprimeMultiplos(int num, int max) */

int EhPrimo(int num){
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++){
        if (num % i == 0) return 0;
    }
    return 1;
}

void ImprimeMultiplos(int num, int max){

    int mult = 0;

    for (int j = num + 1; j < max; j++){
        if (j % num == 0){
            printf("%d ", j);
            mult++;
        }
    }

    if (mult == 0) printf("*");
    printf("\n");
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = n + 1; i < m; i++){

        if (EhPrimo(i)){
            printf("%d\n", i);

            ImprimeMultiplos(i, m);
        }
    }

    return 0;
}
