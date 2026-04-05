#include <stdio.h>

/*  Considere uma caixa registradora com quantidade 
infinita de notas de 5 e notas de 1 e que não possui outras notas além dessas. 
Considere também que o troco a ser dado por essa caixa deve, sempre que possível, 
priorizar a saída das notas com maior valor. Faça um programa que diga qual de 
dois valores a serem dados como troco (i.e., troco 1 ou troco 2) possui a maior 
quantidade de notas. Por exemplo, o troco de 7 deve ser dado com 1 nota de 5 e 2 de 
1, totalizando 3 notas, já o troco de 10 deve ser dado com 2 notas de 5, totalizando 2 
notas, portanto o troco de 7 tem mais notas do que o de 10) 
*/

int main(){

    int a, b;

    while (scanf("%d %d", &a, &b) == 2){
        int notas1 = a / 5 + a % 5;
        int notas2 = b / 5 + b % 5;

        if (notas1 > notas2){
            printf("QTD troco 1 eh maior!\n");

        } else if (notas2 > notas1){
            printf("QTD troco 2 eh maior!\n");

        } else {
            printf("Iguais!\n");
        }
    }

    return 0;
}