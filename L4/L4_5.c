#include <stdio.h>
#include <math.h>

/* Com o tipo tPonto definido acima, faça um programa que 
leia n pontos e informe a distância para seu predecessor em ordem de 
aparecimento. Caso não haja predecessor, imprima “-”.  */

typedef struct {
    int x;
    int y;
} tPonto;

tPonto lePonto(){
    tPonto p;
    scanf("%d %d", &p.x, &p.y);
    return p;
}

float distancia(tPonto p1, tPonto p2){
    float d;
    d = sqrt( pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    return d;
}

void imprimeDistancia(float d){
    if (d > 0) printf("%.2f\n", d);
    else printf("-");
}

int main(){

    int n, i;
    scanf("%d", &n);

    int zero = 0;
    tPonto p, p_atual;
    float aux;

    p_atual.x = zero;
    p_atual.y = zero;

    for (i = 0; i < n; i++){
        p = lePonto();
        
        if (i == 0) printf("-\n");
        else {
            aux = distancia(p, p_atual);
            imprimeDistancia(aux);
        }
        p_atual = p;
    }
    return 0;
}