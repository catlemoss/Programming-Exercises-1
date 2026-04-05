#include <stdio.h>
 
/* Um programa que diga se o algarismo da ordem de um 
número (unidade, dezena ou centena, dependendo do que for informado) é par ou 
ímpar. */

int main(){

    int num, ordem, algarismo;
    scanf("%d %d", &num, &ordem);

    if (ordem == 1) {
        algarismo = num % 10;  

    } else if (ordem == 2){
        algarismo = (num / 10) % 10;

    } else if (ordem == 3){
        algarismo = (num / 100) % 10;

    }

    if (algarismo % 2 == 0){
        printf("PAR");
    } else {
        printf("IMPAR");
    }

    return 0;
}