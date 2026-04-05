#include <stdio.h>

/* um jogo de sudoku */

void sudoku(int num[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            scanf("%d", &num[i][j]);
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }
}

int verificaNum(int linha, int coluna, int n, int num[9][9]) {
    //linha
    for (int j = 0; j < 9; j++){
        if (num[linha][j] == n) return 0;
    }

    //coluna
    for (int i = 0; i < 9; i++){
        if (num[i][coluna] == n) return 0;
    }

    // quadrado 3x3
    int L = (linha / 3) * 3;
    int C = (coluna / 3) * 3; //canto sup esq
    for (int i = L; i <= L + 2; i++){
        for (int j = C; j <= C + 2; j++){ //mais duas casas
            if (num[i][j] == n) return 0;
        }
    }
    //todo quadrado 3×3 começa em multiplos de 3
    //divisao inteira separa em tres grupinhos
    return 1;
}

int main(){

    int num[9][9];
    sudoku(num);

    int linha, coluna, n; //numero
    scanf("%d %d %d", &linha, &coluna, &n);

    if (verificaNum(linha, coluna, n, num)) printf("Jogada valida!\n");
    else printf("Jogada invalida!\n");

    return 0;
}