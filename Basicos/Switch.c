#include <stdio.h>

int main(){

    int escolha_da_pessoa;

    printf("Escolha uma opção:\n");
    printf("1. Opção 1\n");
    printf("2. Opção 2\n");
    printf("3. Opção 3\n");

    scanf("%d", &escolha_da_pessoa);

    // Exemplo de uso do switch
    switch (escolha_da_pessoa){
        case 1:
            printf("Você escolheu a Opção 1\n");
            break;

        case 2:
            printf("Você escolheu a Opção 2\n");
            break;

        case 3:
            printf("Você escolheu a Opção 3\n");
            break;

        default:
            printf("Opção inválida. Por favor, escolha 1, 2 ou 3.\n");
    }
return 0;
}
// This code demonstrates a simple switch statement in C.
// It allows the user to choose an option and prints a message based on the choice.
// The switch statement evaluates the variable 'escolha_da_pessoa' and executes the corresponding case.