#include <stdio.h>

/* Dado um conjunto de 1 a 9 números inteiros e um
 texto entre aspas com indicadores %i, crie um programa que imprima esse
 texto substituindo cada %i pelo i-ésimo número do conjunto.
*/

int main(){

    int n;
    int a1, a2, a3, a4, a5, a6, a7, a8, a9;
    char frase[500];

    scanf("%d", &n);

    // le ate 9 números
    if (n >= 1) scanf("%d", &a1);
    if (n >= 2) scanf("%d", &a2);
    if (n >= 3) scanf("%d", &a3);
    if (n >= 4) scanf("%d", &a4);
    if (n >= 5) scanf("%d", &a5);
    if (n >= 6) scanf("%d", &a6);
    if (n >= 7) scanf("%d", &a7);
    if (n >= 8) scanf("%d", &a8);
    if (n >= 9) scanf("%d", &a9);

    scanf(" \"%[^\"]\"", frase); // le a frase "entre aspas"

    for (int i = 0; frase[i] != '\0'; i++){

        if (frase[i] == '%'){
            int num = frase[i+1] - '0';

            // Verifica validade
            if (num < 1 || num > n){
                printf("ERRO");

            } else {
                switch (num){
                    case 1: printf("%d", a1); break;
                    case 2: printf("%d", a2); break;
                    case 3: printf("%d", a3); break;
                    case 4: printf("%d", a4); break;
                    case 5: printf("%d", a5); break;
                    case 6: printf("%d", a6); break;
                    case 7: printf("%d", a7); break;
                    case 8: printf("%d", a8); break;
                    case 9: printf("%d", a9); break;
                }
            }

            i++; // pular o dígito do placeholder

        } else {
            printf("%c", frase[i]);
        }
    }

    return 0;
}