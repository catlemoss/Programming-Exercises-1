/* Prova 1 do Flávio Varejão */
/* A Federação Internacional de Automobilismo (FIA) te contratou para fazer um programa para
calcular a pontuação acumulada dos pilotos de seu campeonato de Fórmula 1. */

#include <stdio.h>

#define MAX_PILOTOS 30  

typedef struct {
    int id;
    int pontos;
} tInfoPiloto;                                  // um piloto

typedef struct {
    int qntPilotos;
    tInfoPiloto pilotos[MAX_PILOTOS];
} tListaPilotos;                                // lista de pilotos

int comparaPilotos (tInfoPiloto e1, tInfoPiloto e2){

    if (e1.pontos > e2.pontos) return 0;        // maior ponto
    else if (e1.pontos < e2.pontos) return 1;   // menor
    else {
        if (e1.id < e2.id) return 0;            // menor id
        else return 1;                          // maior id
    }
}

tListaPilotos atualizaPiloto(tListaPilotos pilotos, tInfoPiloto e){

    int i;
    for (i = 0; i < pilotos.qntPilotos; i++){ 
        // nao posso tentar inserir o piloto dentro do for

        if (pilotos.pilotos[i].id == e.id){

            pilotos.pilotos[i].pontos += e.pontos;
            return pilotos;
        }
    }

    if (pilotos.qntPilotos < MAX_PILOTOS){

        pilotos.pilotos[pilotos.qntPilotos] = e;
        pilotos.qntPilotos++;
    }
    return pilotos;
}


tListaPilotos ordenaPilotos (tListaPilotos pilotos){

    int troca = 1;
    int i;
    int n = pilotos.qntPilotos - 1;
    tInfoPiloto aux;

    while (troca){
        troca = 0;

        for (i = 0; i < n; i++){

            if (comparaPilotos(pilotos.pilotos[i], pilotos.pilotos[i + 1]) > 0){

                aux = pilotos.pilotos[i];
                pilotos.pilotos[i] = pilotos.pilotos[i + 1];
                pilotos.pilotos[i + 1] = aux;

                troca = 1;
            }
        }
        n--;
    }
    return pilotos;
}