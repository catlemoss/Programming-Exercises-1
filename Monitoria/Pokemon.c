#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int A, D, N;
} tPokemon;

tPokemon lerPokemon(){

    tPokemon p;

    scanf("%d %d %d", &p.A, &p.D, &p.N);
    return p;
}

int ehPrimo(int n){

    if (n <= 1) return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

float calculaPoder(tPokemon p, int bonus){

    float poderBase = (p.A + p.D) / 2.0;

    if (ehPrimo(p.N)){
        return poderBase + bonus;

    }
    return poderBase;
}

void imprimeResultado(float poder1, float poder2){

    if (poder1 > poder2){
        printf("Primeiro\n");

    } else if (poder2 > poder1){
        printf("Segundo\n");

    } else {
        printf("Empate\n");
    }
}

int main(){

    int bat, bonus;
    scanf("%d %d", &bat, &bonus);

    for (int i = 0; i < bat; i++){
        tPokemon p1 = lerPokemon();
        tPokemon p2 = lerPokemon();

        float poder1 = calculaPoder(p1, bonus);
        float poder2 = calculaPoder(p2, bonus);

        imprimeResultado(poder1, poder2);
    }

    return 0;
}
