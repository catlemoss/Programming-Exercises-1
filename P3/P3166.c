/*  Um programa para calcular o valor do custo de muros para bilhonarios */

#include <stdio.h>

int main(){

    int w, // largura 
        h; // altura
    scanf("%d %d", &w, &h);

    if (w > 600 || h > 600) return 0;

    int mapa[h][w]; // linhas e colunas
    int custo = 0;

    int i, j;
    for (i = 0; i < h; i++){
        for (j = 0; j < w; j++){

            char c;
            scanf(" %c", &c);

            mapa[i][j] = c - '0';
        }
    }

    for (int i = 1; i < h-1; i++){
        for (int j = 1; j < w-1; j++){ // evitamos bordas pq sao sempre agua
            if (mapa[i][j] == 0 && 
                (mapa[i-1][j-1]     == 1 || 
                mapa[i-1][j]        == 1 ||
                mapa[i-1][j+1]      == 1 || 
                mapa[i][j-1]        == 1 || 
                mapa[i][j+1]        == 1 ||
                mapa[i+1][j-1]      == 1 || 
                mapa[i+1][j]        == 1 ||
                mapa[i+1][j+1]      == 1)){

                custo++;
            }
        }
    }

    printf("%d\n", custo);
    return 0;
}