#include <stdio.h>

/* Usando as funções do exercício L3_1, faça um programa
que resolva uma operação composta contendo operações básicas (soma, subtração,
adição e multiplicação). 

Assuma que os dados serão apresentados em notação pós-
fixada (i.e. operando da esquerda, operando da direita e operador). 

Desconsidere a
precedência dos operadores, i.e. considere que para cada operação básica (indo da
esquerda para direita), existe um parênteses para garantir sua precedência da
ordem apresentada. 

Portanto, o resultado da primeira operação (da esquerda para a
direita) será sempre utilizado como operando da esquerda da próxima operação. */

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

int main (){

    float num1, num2, result;
    char sinal;

    scanf("%f %f %c", &num1, &num2, &sinal);

        // le a primeira operação
        if (sinal == '+'){
            result = Soma(num1, num2);
        }

        if (sinal == '-'){
            result = Subtracao(num1, num2);
        }

        if (sinal == '/'){
            result = Divisao(num1, num2);
        }

        if (sinal == '*'){
            result = Multiplicacao(num1, num2);
        }

        float mais_coisa;

        // continua depois da primeira operação, caso exista mais coisa
        while (scanf("%f", &mais_coisa) == 1){

            if (scanf(" %c", &sinal) != 1) break;

            if (sinal == '+'){
                result = Soma(result, mais_coisa);
            }

            if (sinal == '-'){
                result = Subtracao(result, mais_coisa);
            }

            if (sinal == '/'){
                result = Divisao(result, mais_coisa);
            }

            if (sinal == '*'){
                result = Multiplicacao(result, mais_coisa);
            }

            if (getchar() == '\n') break;
        }

    printf("%.2f\n", result);
    return 0;
}