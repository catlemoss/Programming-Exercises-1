#include <stdio.h>

/* Um programa para calsular os S de acordo com a escolha do usuario   */

int main(){

    double n, aux = 0, soma = 0;
    scanf("%lf", &n);

    if (n == 1){

        for (int i = 0.0; i < 50; i++){
            soma += ((2 * aux) + 1) / (i + 1);
            aux++;
        }

    } else if (n == 2){

        for (int i = 50; i >= 1; i--){
            soma += pow(2, aux + 1) / i;
            aux++;
        }

    } else if (n == 3){

        for (int i = 1; i <= 10; i++){
            soma += (aux + 1) / (i * i);
            aux++;
        }
    }

    printf("%.6lf", soma);
    return 0;
}