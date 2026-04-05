#include <stdio.h>

/* Faça um programa que implemente as operações de 
uma calculadora para números inteiros e informe os resultados. 
*/

int main(){

    int num1, num2;
    char escolha_da_pessoa;

    scanf("%d %c %d", &num1, &escolha_da_pessoa, &num2);

    switch(escolha_da_pessoa){

        case '+':
            printf("SOMA:%d\n", num1 + num2);
            break;

        case '-':
            printf("SUB:%d\n", num1 - num2);
            break;

        case '*':
            printf("MULT:%d\n", num1 * num2);
            break;

        case '/':
            if (num2 != 0){
                if (num1 % num2 == 0){
                    printf("DIV:%d\n", num1 / num2);

                } else {
                    printf("DIV:%d, RESTO:%d\n", num1 / num2, num1 % num2);
                }
            } else {
                break;
            }
            break;

        default:
            printf("Opção inválida!\n");
    }
    return 0;
}