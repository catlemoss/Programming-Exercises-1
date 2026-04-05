#include <stdio.h>

/* Faça um programa em C padrão para apresentar a soma dos n primeiros termos da série: */

float potencia(float x, int i){
    float pot = 1;
    int cont = 0;
    for (cont = 0; cont < i; cont++){
        pot = pot * x;
    }
    return pot;
}

int fatorial(int i){
    int fat = 1, mult = 1;
    for (mult = 2; mult <= i; mult++){
        fat = fat * mult;
    }
    return fat;
}

int main(){

    float x, soma = 0;
    int n;

    printf("Qual seu x?\n");
    scanf("%f", &x);

    printf("Quantos termos?\n");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n tem q ser maior que 0!!\n");
        return 1;
    }

    for (int i = 1; i <= n; i++){

        float termo = potencia(x, i) / (float)fatorial(i);

        if (i % 2 == 0){
            termo = -termo;
        }
        soma += termo;
    }

    printf("%.6f\n", soma);
    return 0;
}