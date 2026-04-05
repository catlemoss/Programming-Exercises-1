#include <stdio.h>

/* Um programa para descobrir o maior de 2 
horários informados (com informação de horas, minutos e segundos) e imprimir o 
algarismo das dezenas do valor da soma das horas, minutos e segundos do maior 
horário.    
*/

int main(){

    int hora1, min1, seg1, hora2, min2, seg2;
    int soma = 0;

    scanf("%d %d %d %d %d %d", &hora1, &min1, &seg1, &hora2, &min2, &seg2);

    if (hora1 > hora2){
        soma = hora1 + min1 + seg1;

    } else if (hora1 < hora2){
        soma = hora2 + min2 + seg2;

    } else if (hora1 == hora2){
        if (min1 > min2){
            soma = hora1 + min1 + seg1;

        } else if (min1 < min2){
            soma = hora2 + min2 + seg2;

        } else if (min1 == min2){
            if (seg1 > seg2){
                soma = hora1 + min1 + seg1;

            } else if (seg1 < seg2){
                soma = hora2 + min2 + seg2;

            } else if (seg1 == seg2){
                printf("IGUAIS\n");
                return 0;
            }
        }
    }

    int resposta;

    if (soma < 10){
        resposta = 0;

    } else {
    
        resposta = soma / 10;
        resposta = resposta % 10;
        
    }

    printf("RESP:%d\n", resposta);
    return 0;
}