#include <stdio.h>

int main(){

    int escolha_da_pessoa;
    printf("Escolha uma opção:\n");
    printf("1. Opção 1\n");
    printf("2. Opção 2\n");

    scanf("%d", &escolha_da_pessoa);

    // Exemplo de uso do if-else

    if (escolha_da_pessoa == 1){
        printf("Você escolheu a Opção 1\n");

    } else if (escolha_da_pessoa == 2){
        printf("Você escolheu a Opção 2\n");
        
    } else {
        printf("Opção inválida. Por favor, escolha 1 ou 2.\n");
    }
    
    return 0;
    // This code demonstrates a simple if-else statement in C that checks a condition and prints
}