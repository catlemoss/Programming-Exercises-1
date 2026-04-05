#include <stdio.h>
 
/* Um programa para eliminar os caracteres espaço ‘ ‘ de 
uma frase. O programa deverá ler caracteres da entrada padrão (um por vez) até 
encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.      */

int main(){

    char frase;

    printf("RESP:");

    while (scanf("%c", &frase) == 1 && (frase != '.' && frase != '!' && frase != '?')){

        if (frase != ' ') printf("%c", frase); 
    }

    printf("%c", frase);
    return 0;
}