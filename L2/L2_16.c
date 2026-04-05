#include <stdio.h>
 
/* Um programa que imprima o menor número da primeira sequência seguido da
 posições primeira e última que ele aparece na segunda sequência. Caso o
 menor número da primeira sequência não apareça na segunda nenhuma
 vez, o programa deverá considerar o tamanho da segunda sequência
 como primeira e última posições.   */

int main(){

    int sequencia, menor = 32001, primeira_posicao = 0, ultima_posicao = -2, posicao_atual = 0;

    while (scanf("%d", &sequencia) == 1){
        if (sequencia < menor){
            menor = sequencia;
        }
    }

    getchar();
    printf("%d ", menor);

    while (scanf("%d", &sequencia) == 1){
        if (!primeira_posicao && sequencia == menor) {
            printf("%d ", posicao_atual);
            primeira_posicao = 1;
            ultima_posicao = posicao_atual;
        }

        if (sequencia == menor) ultima_posicao = posicao_atual;
        posicao_atual++;
    }

    if (ultima_posicao == -2) {
        ultima_posicao = posicao_atual;
        printf("%d %d", ultima_posicao, ultima_posicao);
        return 0;
    }

    printf("%d", ultima_posicao);
    return 0;
}