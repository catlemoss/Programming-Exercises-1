#include <stdio.h>

/* Mostrar movimentos de peças de xadrez:
Sabendo que o tabuleiro de xadrez possui 8 linhas e 8 colunas, você foi convocado(a) 
para desenvolver um programa em C que ajude Beth (e outros iniciantes) a visualizar 
os movimentos possíveis de diferentes peças, com base em uma posição inicial.
*/

int tabuleiro_do_rei(int x, int y){
    for (int linhas = 1; linhas <= 8; linhas++){
        for (int colunas = 1; colunas <= 8; colunas++){
            int dx = linhas - x;
            int dy = colunas - y;

            if ((dx >= -1 && dx <= 1) && (dy >= -1 && dy <= 1)){
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    return 0;
}

int tabuleiro_da_torre(int x, int y){
    for (int linhas = 1; linhas <= 8; linhas++){
        for (int colunas = 1; colunas <= 8; colunas++){
            if (linhas == x || colunas == y){
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    return 0;
}

int tabuleiro_do_bispo(int x, int y){
    for (int linhas = 1; linhas <= 8; linhas++){
        for (int colunas = 1; colunas <= 8; colunas++){
            int dx = linhas - x;
            int dy = colunas - y;

            if (dx < 0) dx = -dx;
            if (dy < 0) dy = -dy;

            if (dx == dy){
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    return 0;
}

int tabuleiro_do_cavalo(int x, int y){
    for (int linhas = 1; linhas <= 8; linhas++){
        for (int colunas = 1; colunas <= 8; colunas++){
            int dx = linhas - x;
            int dy = colunas - y;

            if (dx < 0) dx = -dx;
            if (dy < 0) dy = -dy;

            if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)){
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    return 0;
}

int main(){

    char opcao;

    while (1){

        printf("Menu:\n");
        printf("R - Rei\nT - Torre\nB - Bispo\nC - Cavalo\nQ - Sair\n");
        printf("Escolha uma opcao:\n");

        scanf(" %c", &opcao);

        if (opcao == 'Q'){
            return 0;
        }

        if (opcao != 'R' && opcao != 'T' && opcao != 'B' && opcao != 'C'){
            printf("Opcao invalida! Escolha novamente.\n");
            continue;
        }

        int x, y;

        printf("Indique a coordenada (X,Y):\n");
        scanf("%d %d", &x, &y);

        while (x < 1 || x > 8 || y < 1 || y > 8){
            printf("Coordenadas invalidas!\n");
            printf("Indique a coordenada (X,Y):\n");
            scanf("%d %d", &x, &y);
        }

        if (opcao == 'R'){
            tabuleiro_do_rei(x, y);
        } 
        else if (opcao == 'T'){
            tabuleiro_da_torre(x, y);
        }
        else if (opcao == 'B'){
            tabuleiro_do_bispo(x, y);
        }
        else if (opcao == 'C'){
            tabuleiro_do_cavalo(x, y);
        }
    }
    return 0;
}