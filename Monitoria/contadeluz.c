#include <stdio.h>

/* Faça um programa em C que leia o consumo mensal de energia elétrica (em kWh) de várias
residências e calcule o valor da respectiva conta, considerando faixas de tarifa progressivas. O
programa deve ser encerrado quando for lido um consumo negativo. */

int main(){

    float consumo = 1, kWh;

    printf("Quanto voce usou de kWh:\n");

    while (consumo > 0){

        scanf("%f", &consumo);

        if (consumo <= 100){
            kWh = consumo * 0.5;

        } else if (101 < consumo && consumo <= 200){
            kWh = consumo * 0.7;

        } else if (200 < consumo && consumo < 300){
            kWh = consumo * 0.9;

        } else if (300 <= consumo){
            kWh = (consumo * 0.9) * 1.1;
        }

        printf("Voce deve pagar: %f\n", kWh);
    }

    return 0;
}