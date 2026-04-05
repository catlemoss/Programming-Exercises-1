#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N 50 // Tamanho máximo da string

int main(){

    setlocale(LC_ALL, "Portuguese");

    char s[N];
    int i;

    printf("Digite um texto: \n");

    fgets(s, N, stdin); // Lê uma string do usuário, incluindo espaços

    i = strlen(s); // Calcula o comprimento da string
    
    printf("\nTamanho do texto: %d\n", i);

    printf("Impressão de posição a posição: \n");
   
    for (int i = 0; i < strlen(s); i++){
        printf("%c", s[i]); // Imprime cada caractere da string em uma nova linha
    }

    return 0;
}