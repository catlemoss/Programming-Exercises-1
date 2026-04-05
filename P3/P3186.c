/*  Você deve fazer um sistema para contar a 
quantidade de erros ocorridos em uma fábrica. Os erros serão identificados por 
imagens. As imagens serão compostas por zeros e uns.  */

#include <stdio.h>

#define MAX 100

int main(){

    int L1, C1, // img origibal
        L2, C2; // template
    char img[MAX][MAX];
    char temp[MAX][MAX];
    int i, j, x, y;
    int cont = 0;
    int igual;

    scanf("%d %d", &L1, &C1);

    //le img
    for (i = 0; i < L1; i++){
        scanf("%s", img[i]);
    }

    // le temp
    scanf("%d %d", &L2, &C2);

    for (i = 0; i < L2; i++){
        scanf("%s", temp[i]);
    }

    // varre imag orig
    for (i = 0; i <= L1 - L2; i++){
        for (j = 0; j <= C1 - C2; j++){

            igual = 1;

            // compara
            for (x = 0; x < L2 && igual; x++){
                for (y = 0; y < C2; y++){

                    if (img[i + x][j + y] != temp[x][y]){
                        igual = 0;
                        break;
                    }
                }
            }
            if (igual){
                cont++;
            }
        }
    }

    printf("RESP:%d\n", cont);
    return 0;
}