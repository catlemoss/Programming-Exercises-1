#include <stdio.h>

/* um programa para multiplicar duas matrizes de 
inteiros. Uma sequência de pares de matrizes será dada, e o programa deverá 
multiplicar a primeira pela segunda quando for possível.  */

int main(){

    int n;
    scanf("%d", &n);

    int zhopa;
    for (zhopa = 0; zhopa < n; zhopa++){

        int l1, c1, l2, c2;
        int i, j, k;

        scanf("%d %d", &c1, &l1);
        int mat1[l1][c1];

        for (i = 0; i < l1; i++){
            for (j = 0; j < c1; j++){
                scanf("%d", &mat1[i][j]);
            }
        }

        scanf("%d %d", &c2, &l2);
        int mat2[l2][c2];

        for (i = 0; i < l2; i++){
            for (j = 0; j < c2; j++){
                scanf("%d", &mat2[i][j]);
            }
        }

        if (c1 != l2){
            printf("IMPOSSIVEL\n");

        } else {
            int res[l1][c2];

            for (i = 0; i < l1; i++){
                for (j = 0; j < c2; j++){

                    res[i][j] = 0;

                    for (k = 0; k < c1; k++){
                        res[i][j] += mat1[i][k] * mat2[k][j];
                    }
                }
            }

            for (i = 0; i < l1; i++){
                for (j = 0; j < c2; j++){

                    if (j > 0) printf(" ");
                    printf("%d", res[i][j]);
                }
                printf("\n");
            }
        }

        if (zhopa < n-1) printf("\n");
    }
    return 0;
}

/*
- cada linha da primeira matriz, multiplica todas as colunas da segunda matriz.
- número de colunas da primeira matriz seja igual ao número de linhas da segunda matriz.

A matriz C, resultado da multiplicação A . B, tem as dimensões m x p, 
ou seja, o número de linhas da primeira matriz e o número de colunas da segunda.
*/