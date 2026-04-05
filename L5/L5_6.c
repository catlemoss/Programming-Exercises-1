#include <stdio.h>

/* um programa para ler duas sequências de números
e armazena-las em dois vetores A e B. No final, o programa deverá dizer se todos os
itens de A estão em B, se somente parte deles está, ou se nenhum deles está. */

int main(){

    int i, j;
    int n1; // primeira sequencia
    scanf("%d", &n1);

    int A[n1];
    for (i = 0; i < n1; i++){
        scanf("%d", &A[i]); 
    }

    int n2; // second seq
    scanf("%d", &n2);

    int B[n2];
    for (j = 0; j < n2; j++){
        scanf("%d", &B[j]);
    }

    int busca = 0;

    for (i = 0; i < n1; i++){
    int achou = 0;

        for (j = 0; j < n2; j++){
            if (A[i] == B[j]){
                achou = 1;
                break;
            }
        }
        if (achou) busca++;
    } // esse for conta apenas se o numero apareceu alguma unica vez

    if (busca == n1) printf("TODOS\n");
    else if (busca == 0) printf("NENHUM\n");
    else if (0 < busca && busca < n1) printf("PARCIAL\n");

    return 0;
}