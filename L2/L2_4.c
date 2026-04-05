#include <stdio.h>

/* Um programa que leia números inteiros e retorne o 
maior dos números digitados até o momento e a média atual. */

int main(){

    int num, soma = 0, maior, contador;
    float media;

    scanf("%d", &num); 

    if (num == 0) return 0;

    if (num != 0){

        contador = 1;

        maior = num; 
        soma += num;
        media = (float)soma / contador;

        printf("%d %.6f\n", maior, media);
    }

    while(1){

        scanf("%d", &num);

        if (num == 0) break;

        if (num != 0){
            contador++;

            if (num > maior) maior = num; 

            soma += num;
            media = (float)soma / contador;

            printf("%d %.6f\n", maior, media);
        }
    }

    return 0;
}