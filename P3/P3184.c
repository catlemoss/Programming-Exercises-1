/*   Faça um programa que leia uma lista com um 
número par de palavras e analise cada par de palavras consecutivas (ex. palavra 0 
com a 1, a 2 com a 3, a 4 com a 5, etc.).   */

#include <stdio.h>
#include <string.h>

#define MAX_PAL 100
#define TAM 101

int main(){

    char p1[TAM], p2[TAM];
    char result[MAX_PAL][TAM];
    int qtd = 0;

    // le par
    while (scanf("%s", p1) != EOF){
        scanf("%s", p2);

        int t1 = strlen(p1);
        int t2 = strlen(p2);

        if (t1 > t2){
            strcpy(result[qtd], p1);
            qtd++;

        } else if (t2 > t1){
            strcpy(result[qtd], p2);
            qtd++;
        }
        // se forem iguais, no guarda
    }

    // nao ha palavra
    if (qtd == 0){
        printf("MAX:--\n");
        return 0;
    }

    // lista
    int i;
    for (i = 0; i < qtd; i++){
        printf("%s\n", result[i]);
    }

    // descobre maior word
    int maior_word = strlen(result[0]);
    int id_maior_word = 0;

    for (i = 1; i < qtd; i++){
        int t = strlen(result[i]);

        if (t > maior_word){
            maior_word = t;
            id_maior_word = i;
        }
    }

    printf("MAX:%s\n", result[id_maior_word]);

    return 0;
}