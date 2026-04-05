#include <stdio.h>
#include <stdlib.h> //para usar modulo

/* um programa que lê as alturas (de 0 a 100) de uma 
sequência de N postes de uma cidade para um vetor.   */

int main(){

    int n, i; // postes
    scanf("%d", &n);

    if (n < 2) printf("IMPOSSIVEL\n");

    int alturas[n];
    for (i = 0; i < n; i++){ scanf("%d", &alturas[i]); } //guardando os valores

    int diferenca, maior = -1;

    for (i = 0; i < n - 1; i++){ //for da diferenca (-1 para nao ir alem do vetor)
        diferenca = abs(alturas[i] - alturas[i+1]);

        if (diferenca > maior) maior = diferenca; // aqui guarda a diferenca
    }

    for (i = 0; i < n - 1; i++){ //for da impressao
        diferenca = abs(alturas[i] - alturas[i+1]);

        if (diferenca == maior) printf("(%d %d) ", i, i+1);
    }
    printf("\n");
    return 0;
}