#include <stdio.h>

int main(){

    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("Imprimindo primeira linha da matriz:\n");
        for (int i = 0; i < 3; i++) { // menor que 3 pois a matriz tem 3 colunas
            printf("%d ", matriz[0][i]); // 0 pois queremos a primeira linha
        }
    printf("\n");

    printf("Imprimindo a matriz:\n");
        for (int i = 0; i < 3; i++) { // menor que 3 pois a matriz tem 3 linhas
            for (int j = 0; j < 3; j++) { // menor que 3 pois a matriz tem 3 colunas
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
    return 0;
}