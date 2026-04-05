/*  Faça um programa que faça o deslocamento dos 
números de uma sequência de acordo com os números de uma segunda sequência.  */

#include <stdio.h>

#define MAX 1000

int main(){
    
    int s;
    
    while (scanf("%d", &s) == 1){
        int seq[MAX];
        int temp[MAX];
        
        // le primeira sequencia
        for (int i = 0; i < s; i++){
            scanf("%d", &seq[i]);
        }

        int desloc;
        scanf("%d", &desloc);

        while (desloc != -1){
            // faz o deslocamento
            for (int i = 0; i < s; i++){
                int nova_pos = (i + desloc) % s;
                temp[nova_pos] = seq[i];
            }

            // copia de volta e imprime
            for (int i = 0; i < s; i++){
                seq[i] = temp[i];
                printf("%d", seq[i]);
                if (i < s - 1) printf(" ");
            }
            printf("\n");

            scanf("%d", &desloc);
        }
    }
    return 0;
}