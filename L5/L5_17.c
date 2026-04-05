#include <stdio.h>

#define MAX_PALAVRAS 500
#define MAX_LETRAS 501

/* um programa que leia palavras de um texto e 
imprima o texto de trás para frente com as palavras separadas por espaço e sem 
pontuação ou qualquer outro caractere que não seja letra. Percebe que a palavra em 
si deve permanecer com sua ordem natural de letras. */

int ehLetra(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(){
    char texto[MAX_PALAVRAS][MAX_LETRAS];
    int palavras = 0;

    int i = 0;
    char c;
    while ((c = getchar()) != EOF){

        if (ehLetra(c)){
            texto[palavras][i] = c;
            i++;

        } else {
            if (i > 0){
                texto[palavras][i] = '\0'; // sTop! wait a minute
                palavras++;
                i = 0;
            }
        }
    }

    // caso termine com letra
    if (i > 0) {
        texto[palavras][i] = '\0';
        palavras++;
    }

    // imprime da ultima -> first
    for (int j = palavras - 1; j >= 0; j--){
        printf("%s", texto[j]);

        if (j > 0) printf(" ");
    }

    printf("\n");
    return 0;
}