/*  Faça um programa para contar o número de 
ocorrências de um padrão vertical ou horizontal em uma matriz.   */

#include <stdio.h>

int main(){

    int e,      // num do padrao
        l,      // linhas
        c;      // colunas
    char t;     //horiz ou vert
    
    scanf("%d%c", &e, &t);
    
    scanf("%d %d", &l, &c);
    char mat[l][c];
    
    for (int i = 0; i < l; i++){
        scanf("%s", mat[i]);
    } // le mat

    int cont = 0;

    // HORIZONTAL
    if (t == 'H'){

        for (int i = 0; i < l; i++){
            int seq = 0;

            for (int j = 0; j < c; j++){

                if (mat[i][j] == 'X') seq++;
                else {

                    if (seq >= e) cont += seq - e + 1;
                    seq = 0;
                }
            }
            // fim da linha
            if (seq >= e) cont += seq - e + 1;
        }
    }

    // VERTICAL
    else if (t == 'V'){

        for (int j = 0; j < c; j++){
            int seq = 0;

            for (int i = 0; i < l; i++){

                if (mat[i][j] == 'X') seq++;
                else {
                    if (seq >= e) cont += seq - e + 1;
                    seq = 0;
                }
            }
            // fim col
            if (seq >= e) cont += seq - e + 1;
        }
    }

    printf("CONT: %c %d\n", t, cont);
    return 0;
}