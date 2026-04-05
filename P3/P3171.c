/*  Ler cartelas de bingo e imprimir ao contrario  */

#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    int tam;
    int nums[MAX][MAX];
} tCartela; // uma cartela 

void LeCartela(tCartela *c){

    scanf("%d %d", &c->id, &c->tam);

    int i, j;
    for (i = 0; i < c->tam; i++){
        for (j = 0; j < c->tam; j++){
            scanf("%d", &c->nums[i][j]);
        }
    }
}

void ImprimeCartela(tCartela *c){
    int i, j;
    for (i = 0; i < c->tam; i++){
        for (j = 0; j < c->tam; j++){

            if (j > 0) printf("|");
            printf("%03d", c->nums[j][i]);
        }
        printf("\n");
    }
}

typedef struct {
    int qnt;
    tCartela cart[MAX];
} tPartida; // grupo de cartelas

void LeCartelasPartida(tPartida *p){
    int i;
    for (i = 0; i < p->qnt; i++){
        LeCartela(&p->cart[i]);
    }
}

void ImprimeInvCartelasPartida(tPartida *p){
    int i;
    for (i = p->qnt - 1; i >= 0; i--){
        printf("ID:%d\n", p->cart[i].id);
        ImprimeCartela(&p->cart[i]);
        printf("\n");
    }
}

int main(){

    tPartida p;

    if (scanf("%d", &p.qnt) != 1 || p.qnt <= 0) return 0;
    
    LeCartelasPartida(&p);
    ImprimeInvCartelasPartida(&p);

    return 0;
}