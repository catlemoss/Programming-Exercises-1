#include <stdio.h>

#define MAX 7

/* Imagine um cenário, em que você tenha cartelas de 
um jogo de bingo e que você queira simular várias partidas de um bingo. */

typedef struct {
    int id;
    int tam_cart;
    int nums[MAX][MAX];
} tCartela;

tCartela LeCartela(){
    tCartela c;
    int i, j;

    scanf("%d %d", &c.id, &c.tam_cart);

    for (i = 0; i < c.tam_cart; i++){
        for (j = 0; j < c.tam_cart; j++){
            scanf("%d", &c.nums[i][j]);
        }
    }
    return c;
}

void ImprimeCartela(tCartela c){
    int i, j;

    printf("ID:%d\n", c.id);

    for (i = 0; i < c.tam_cart; i++){
        for (j = 0; j < c.tam_cart; j++){

            if (j > 0) printf(" | ");
            printf("%03d", c.nums[j][i]);
        }
        printf("\n");
    }
}

int main(){

    tCartela cartela; 
    cartela = LeCartela(); 
    ImprimeCartela(cartela);

    return 0; 
} 