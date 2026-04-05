#include <stdio.h>

/* Faça um programa para dizer o dia da semana de 
acordo com o número informado, sendo Domingo para 1, Segunda para 2, ..., Sabado 
para 7 e Invalido para qualquer outra coisa. 
*/

int main(){

    int n;
    scanf("%d", &n);

    if (n < 1 || n > 7) printf("Invalido\n");

    if (n == 1) printf("Domingo\n");
    if (n == 2) printf("Segunda\n");
    if (n == 3) printf("Terca\n");
    if (n == 4) printf("Quarta\n");
    if (n == 5) printf("Quinta\n");
    if (n == 6) printf("Sexta\n");
    if (n == 7) printf("Sabado\n");

    return 0;
}