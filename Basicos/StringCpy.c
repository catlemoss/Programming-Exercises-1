#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N 20 // Tamanho máximo da string

int main(){

    setlocale(LC_ALL, "Portuguese");

    char origem[N] = {"Olá Mundo!"};
    char destino[N];

    printf("Antes do strcpy: \n");
    puts(origem);
    puts(destino);

    strcpy(destino, origem); // Copia a string de origem para destino

    printf("Depois do strcpy: \n");
    puts(origem);
    puts(destino);

    return 0;
}