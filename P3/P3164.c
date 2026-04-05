/* Faça um programa que diga quantos números de 
uma lista de números são maiores do que cada elemento dessa lista. Isto é, para cada 
elemento da lista, diga quantos dos elementos são maiores do que ele. */

#include <stdio.h>

int main(){

    int casos, n;
    scanf("%d", &casos);

    while (casos--){

        scanf("%d", &n);

        int seq[n];
        int resultado[n];

        int i;
        for (i = 0; i < n; i++){ // coloca nums no vetor
            scanf("%d", &seq[i]);
        }

        int j, k;
        for (j = 0; j < n; j++){ // num para analisar
            int cont = 0;

            for (k = 0; k < n; k++){ // ve outros nums e compara
                if (seq[k] > seq[j]) cont++;
            }
            resultado[j] = cont;
        }

        for (i = 0; i < n; i++){

            if (i > 0) printf(" ");
            printf("%d", resultado[i]);
        }
        printf("\n");
    }
    return 0;
}