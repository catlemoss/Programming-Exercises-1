#include <stdio.h>
#include <math.h>

/* Faça um programa em C para montar uma tabela do seno, cosseno e tangente dos seguintes
graus: 0, 15, 30, 45, 60, 75, 90, 105, ... até 360 graus. */

#define pi 3.14159265359

int main(){

    float rad, sen, cosy, tg;

    printf("Sin\t\tCos\t\tTan\n");

    for (int i = 0; i <= 360; i += 15){

        rad = (i * pi) / 180;

        sen = sin(rad);
        cosy = cos(rad);
        tg = tan(rad);

        if (fabs(sen) < 0.00001) sen = 0.0;
        if (fabs(cosy) < 0.00001) cosy = 0.0;
        
        if (cosy == 0){
            printf("%.5f\t\t%.5f\t\t---\n", sen, cosy);
        }

        printf("%.5f\t\t%.5f\t\t%.5f\n", sen, cosy, tg);
    }

    return 0;
}