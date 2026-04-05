/*   soma de numeros enormes  */

#include <stdio.h>

#define MAX 53

int main(){

    int n; // paresp de nums
    scanf("%d", &n);

    int kitty;
    for (kitty = 0; kitty < n; kitty++){

        int seq1[MAX], seq2[MAX];
        int tam1 = 0, tam2 = 0;

        // le num 1
        while (1){

            scanf("%d", &seq1[tam1]);
            if (seq1[tam1] == -1) break;
            tam1++;
        }

        // le num 2
        while (1) {
            scanf("%d", &seq2[tam2]);
            if (seq2[tam2] == -1) break;
            tam2++;
        }

        int resp[MAX];
        int tamResp = 0;
        int vai_um = 0;

        int i = tam1 - 1;
        int j = tam2 - 1;

        // soma
        while (i >= 0 || j >= 0 || vai_um){

            int soma = vai_um;

            if (i >= 0) soma += seq1[i--];
            if (j >= 0) soma += seq2[j--];

            resp[tamResp++] = soma % 10;
            vai_um = soma / 10;
        }

        // resp
        for (int k = tamResp - 1; k >= 0; k--){
            printf("%d", resp[k]);
        }
        printf("\n");
    }
    return 0;
}