/*  Faça um programa que leia uma lista de palavras 
e analise cada uma delas. Ao final, o programa deverá imprimir somente as vogais, 
somente as consoantes ou a palavra inteira dependendo da quantidade de vogais e 
consoantes em cada palavra. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int ehLetra(char letra){
    if ((letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z')){
        return 1;
    }
    return 0;
}

int ehVogal(char letra){
    letra = tolower(letra);
    if (letra == 'a' || letra == 'e' || letra == 'i' || 
        letra == 'o' || letra == 'u') return 1;
        
    return 0;
}

void pacMan(char palavra[]){
    int vogais = 0;
    int consoantes = 0;
    int tam = strlen(palavra);

    int i, k, 
        j = 0;
    for (i = 0; i < tam; i++){
        if (ehLetra(palavra[i])){
            if (ehVogal(palavra[i])) vogais++;
            else consoantes++;
        }
    }

    if (vogais == consoantes) return;
    
    if (vogais > consoantes){

        for (k = 0; k < tam; k++){

            if (ehLetra(palavra[k])){

                if (ehVogal(palavra[k])){
                    palavra[j++] = palavra[k];
                }
            }
        }

    } else {

        for (k = 0; k < tam; k++){

            if (ehLetra(palavra[k])){

                if (!ehVogal(palavra[k])){
                    palavra[j++] = palavra[k];
                }
            }
        }
    }

    palavra[j] = '\0';
}

int main(){

    char palavra[MAX];
    
    while (scanf("%s", palavra) != EOF){

        pacMan(palavra);
        printf("%s\n", palavra);
    }

    return 0;
}