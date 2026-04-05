#include <stdio.h>

/* Um programa que diga qual mês é correspondente a 
um número. */

int main(){

    int mes;
    scanf("%d", &mes);

    if (mes == 1){
        printf("Jan.");

    } else if (mes == 2){
        printf("Fev.");

    } else if (mes == 3){
        printf("Mar.");

    } else if (mes == 4){
        printf("Abr.");

    } else if (mes == 5){
        printf("Mai.");

    } else if (mes == 6){
        printf("Jun.");

    } else if (mes == 7){
        printf("Jul.");

    } else if (mes == 8){
        printf("Ago.");

    } else if (mes == 9){
        printf("Set.");

    } else if (mes == 10){
        printf("Out.");

    } else if (mes == 11){
        printf("Nov.");

    } else if (mes == 12){
        printf("Dez.");
        
    } else {
        printf("Invalido.");
    }

    return 0;

}
