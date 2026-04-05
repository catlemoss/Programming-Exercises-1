/* um robô de solda move-se em duas
direções (horizontal e vertical) em cima de uma placa representada por uma matriz.
Dada uma nova posição x e y (representando as coordenadas horizontal e vertical
respectivamente), o robô sai de sua posição atual para soldar na posição dada. */

#include <stdio.h>
#include <stdlib.h>

int main(){

    int C, // colnas/ largura
        L; // linhas/ altura

    scanf("%d %d", &C, &L);

    int mat[L][C];

    int i, j;
    for (i = 0; i < L; i++){
        for (j = 0; j < C; j++){

            mat[i][j] = 0;
        }
    }

    int X = 0, // cord x
        Y = 0; // cord y

    mat[Y][X] = 1; // marca pos ini

    int new_x, new_y;

    while (1){

        scanf("%d %d", &new_x, &new_y);

        int dist_x = abs(new_x - X);
        int dist_y = abs(new_y - Y);

        if (dist_x > dist_y){

            while (Y != new_y){

                if (Y < new_y) Y++;
                else Y--;

                mat[Y][X] = 1;
            }

            while (X != new_x){

                if (X < new_x) X++;
                else X--;

                mat[Y][X] = 1;
            }

        } else {

            while (X != new_x){

                if (X < new_x) X++;
                else X--;

                mat[Y][X] = 1;
            }

            while (Y != new_y){

                if (Y < new_y) Y++;
                else Y--;

                mat[Y][X] = 1;
            }
        }

        if (new_x == 0 && new_y == 0) break;
    }

    for (i = 0; i < L; i++){
        for (j = 0; j < C; j++){

            if (j > 0) printf(" ");
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;

}