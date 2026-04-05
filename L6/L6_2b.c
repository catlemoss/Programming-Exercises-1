#include <stdio.h>

#define MAX 7
#define MAX_CARTELAS 100

/* Imagine a mesmo cenário da questão a, porém agora 
seu programa deverá ler um conjunto de cartelas da partida. */

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

typedef struct {
    int qnt;
    tCartela cartelas[MAX_CARTELAS];
} tPartida;

tPartida LeCartelasPartida(){
    tPartida p;
    scanf("%d", &p.qnt);
    
    int i;
    for (i = 0; i < p.qnt; i++){
        p.cartelas[i] = LeCartela();
    }
    return p;
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

void ImprimeInvCartelasPartida(tPartida p){
    int i;
    for (i = p.qnt-1; i >= 0; i--){
        ImprimeCartela(p.cartelas[i]);
    }
}

int main(){

    tPartida partida;
    partida = LeCartelasPartida();
    ImprimeInvCartelasPartida(partida);

    return 0;
}