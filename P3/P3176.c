/*   Você deve fazer um sistema para controlar um 
robô de solda. O robô recebe coordenadas x e y de uma placa de circuito, onde ele 
deve efetuar uma solda.   */

#include <stdio.h>

#define MAX 100

int main(){

    int Lp, Cp, // linhas e colulas placa
        Lt, Ct; // template

    int placa[MAX][MAX];
    int template[MAX][MAX];

    // le placa
    scanf("%d %d", &Lp, &Cp);
    for (int i = 0; i < Lp; i++){
        for (int j = 0; j < Cp; j++){

            scanf("%1d", &placa[i][j]);
        }
    }

    // Leitura do template
    scanf("%d %d", &Lt, &Ct);
    for (int i = 0; i < Lt; i++){
        for (int j = 0; j < Ct; j++){

            scanf("%1d", &template[i][j]);
        }
    }

    // varre placa
    for (int i = 0; i <= Lp - Lt; i++){
        for (int j = 0; j <= Cp - Ct; j++){

            int igual = 1;

            // compara c template
            for (int ti = 0; ti < Lt && igual; ti++){
                for (int tj = 0; tj < Ct; tj++){

                    if (placa[i + ti][j + tj] != template[ti][tj]){
                        igual = 0;
                        break;
                    }
                }
            }

            // encontrou ponto de solda
            if (igual){
                printf("%d,%d\n", j, i);
            }
        }
    }

    return 0;
}