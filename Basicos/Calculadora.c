#include <stdio.h>

int main(){

    printf("Vamos calcular!\nInsira sua operacao:\t");

    int num1;
    int num2;
    char escolha_da_pessoa;

    scanf("%d %c %d", &num1, &escolha_da_pessoa, &num2);
    

    switch(escolha_da_pessoa){

        case '+':
            printf("Soma: %d\n", num1 + num2);
            break;

        case '-':
            printf("Subtração: %d\n", num1 - num2);
            break;

        case '*':
            printf("Multiplicação: %d\n", num1 * num2);
            break;

        case '/':
            if (num2 != 0) {
                printf("Divisão: %.2f\n", (float)num1 / num2);
            } else {
                printf("Erro: Divisão por zero!\n");
            }
            break;

        default:
            printf("Opção inválida!\n");
    }
    return 0;
}