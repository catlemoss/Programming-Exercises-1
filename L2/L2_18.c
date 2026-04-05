#include <stdio.h>
 
/* Um programa que, dado o tamanho da matriz e seus valores, que nunca são iguais,
 calculasse o maior valor e imprimisse a posição dele na matriz.
 Também com dúvidas em Programação, Padi agora pede sua ajuda e
 você deve implementar o código para depois tirar as dúvidas do código
 dele.  */

int main(){

    int L, C; // linhas e colunas
    int maior = -32767, posicao_linha, posicao_coluna;
    scanf("%d %d", &L, &C);

    if (L < 1 || L > 100 || C < 1 || C > 100){
        return 0; // tamanho inválido
    }

    for (int i = 1; i <= L; i++){

        for (int j = 1; j <= C; j++){

            int V;
            scanf("%d", &V);

            if (V < -32767 || V > 32767){
                return 0; // valor inválido
            }

            if (V > maior){
                maior = V;
                posicao_linha = i;
                posicao_coluna = j;
            }
        }
    }

    printf("%d (%d, %d)\n", maior, posicao_linha, posicao_coluna);
    return 0;
}