/*  Faça um programa que diga se uma palavra alvo 
pode ser escrita com as letras de uma palavra fonte ao retirar algumas letras da 
palavra fonte. Isso sem alterar a ordem das letras e considerando letras maiúsculas 
e minúsculas iguais. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 401

int main(){

    int casos;
    scanf("%d", &casos);

    int i;
    for (i = 0; i < casos; i++){

        char alvo[MAX];
        char fonte[MAX];
        int cont = 0;

        scanf(" %s %s", alvo, fonte);

        int f = strlen(fonte);
        int a = strlen(alvo);

        int j;
        for (j = 0; j < f; j++){

            if (cont >= a) break;
            if (tolower(fonte[j]) == tolower(alvo[cont])) cont++;
        }
        

        if (cont == a) printf("PODE!\n");
        else printf("NAO PODE!\n");
    }

    return 0;
}