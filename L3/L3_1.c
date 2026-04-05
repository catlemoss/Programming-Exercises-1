#include <stdio.h>

/* Dado o programa abaixo que lê pares de números
separados por espaço e imprime o resultado da soma, da subtração, da divisão e da
multiplicação deles, implemente as funções Soma, Subtração, Divisão e Multiplicação
(cabeçalhos definidos abaixo) que fazem respectivamente cada uma das operações
com os dois números lidos. A única alteração permitida no programa é a
implementação das funções que recebem dois floats e retornam um float. */

float Soma(float num1, float num2){
    return num1 + num2;
}

float Subtracao(float num1, float num2){
    return num1 - num2;
}

float Divisao(float num1, float num2){
    if (num2 == 0) return 0;
    else return num1 / num2;
}
float Multiplicacao(float num1, float num2){
    return num1 * num2;
}

int main(){

    float num1, num2;

    while (scanf("%f %f", &num1, &num2) == 2){

        float result;
        result = Soma(num1, num2);
        printf("%.2f", result);

        result = Subtracao(num1, num2);
        printf(" %.2f", result);

        result = Divisao(num1, num2);
        printf(" %.2f", result);

        result = Multiplicacao(num1, num2);
        printf(" %.2f\n", result);
    }

return 0;
}