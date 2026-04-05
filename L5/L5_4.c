#include <stdio.h>

/* um programa que lê números de uma sequência de
N números para um vetor. No final, ler um intervalo fechado (a e b, onde a < b) e
dizer quantos números estão dentro do intervalo e quantos números estão fora do
intervalo. */

int main(){

    int n, i; // n numeros
    scanf("%d", &n);

    int num[n];
    for (i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    int a, b; // intervalo fechado
    scanf("%d %d", &a, &b);

    if (a >= b) return 0;

    int dentro = 0,
        fora = 0;

    for (i = 0; i < n; i++){
        if (a <= num[i] && num[i] <= b) dentro++;
        else fora++;
    }

    printf("%d %d\n", dentro, fora);
    return 0;
}