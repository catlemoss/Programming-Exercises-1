#include <stdio.h>

/* Usando o tipo tReta acima, faça um programa para 
informar se uma reta está totalmente contida em um quadrante.  */

typedef struct {
    int x;
    int y;
} tPonto;

tPonto lePonto(){
    tPonto p;
    scanf("%d %d", &p.x, &p.y);
    return p;
}

typedef struct {
    tPonto inicio, fim;
} tReta;

tReta leReta(){
    tReta r;
    r.inicio = lePonto();
    r.fim = lePonto();
    return r;
}

tPonto obtPi(tReta r){ return r.inicio; } 
tPonto obtPf(tReta r){ return r.fim; }

int identificaQuad(tPonto p){
    if (p.x > 0 && p.y > 0) return 1;
    else if (p.x < 0 && p.y > 0) return 2;
    else if (p.x < 0 && p.y < 0) return 3;
    else if (p.x > 0 && p.y < 0) return 4;
    else return 0;
}

int main(){

    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        tReta r;
        r = leReta();
        
        int quadI = identificaQuad(r.inicio);
        int quadF = identificaQuad(r.fim);

        if (quadI != 0 && quadI == quadF) printf("MESMO\n");
        else printf("DIFERENTE\n");
    }
    return 0;
}