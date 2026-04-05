/* Imagine um cenário em que você tenha que 
controlar os carros de uma concessionária de aluguel de carros. */

#include <stdio.h>
#include <string.h>

#define MAX_CARROS 100
#define MAX_TIPO 101

typedef struct {
    int id;
    int passageiros;
    char tipo[MAX_TIPO];
    int km;
} tCarro;

typedef struct {
    tCarro carros[MAX_CARROS];
    int qnt;
} tConcessionaria;

tCarro LeCarro(){
    tCarro carro;
    scanf("%d %d %s %d", &carro.id, &carro.passageiros, carro.tipo, &carro.km);
    return carro;
}

void ImprimeCarro(tCarro carro){
    printf("CARRO (%d): %s de %d passageiros e com %d km\n",
           carro.id, carro.tipo, carro.passageiros, carro.km);
}

int ObtemNumPassageirosCarro(tCarro carro){
    return carro.passageiros;
}

int ObtemKmCarro(tCarro carro){
    return carro.km;
}

tConcessionaria LeCarrosConcessionaria(){

    tConcessionaria concessionaria;
    scanf("%d", &concessionaria.qnt);

    int i;
    for (i = 0; i < concessionaria.qnt; i++){
        concessionaria.carros[i] = LeCarro();
    }
    return concessionaria;
}


void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km){

    int i;
    for (i = 0; i < concessionaria.qnt; i++){

        tCarro carro = concessionaria.carros[i];

        int atendePass = 0;
        int atendeKm = 0;

        // passageiros
        if (pass == -1) atendePass = 1;
        else if (ObtemNumPassageirosCarro(carro) == pass) atendePass = 1;

        // km
        if (km == -1) atendeKm = 1;
        else if (ObtemKmCarro(carro) <= km) atendeKm = 1;

        // se atender os dois critérios
        if (atendePass && atendeKm) ImprimeCarro(carro);
    }
}

int main(){ 

    tConcessionaria concessionaria; 
    concessionaria = LeCarrosConcessionaria(); 

    int qntPassageiros, km, i = 0; 

    while(scanf("%d,%d", &qntPassageiros, &km) == 2){ 
        printf("Caso %d:\n", ++i); 
        ListaCarrosConcessionaria(concessionaria, qntPassageiros, km); 
    } 

    return 0;
}