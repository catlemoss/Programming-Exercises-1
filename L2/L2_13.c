#include <stdio.h>
 
/* Um programa para substituir letras minúsculas de uma frase 
por letras maiúsculas. O programa deverá ler caracteres da entrada padrão (um por 
vez) até encontrar um ponto simples ‘.’, interrogação ‘?’ ou exclamação ‘!’.   */

int main(){

    char frase;

    while (scanf("%c", &frase) == 1 && (frase != '.' && frase != '!' && frase != '?')){

        if ('a' <= frase && frase <= 'z' ) frase = frase - 32;

        printf("%c", frase);
    }

    printf("%c", frase);

    return 0;
}