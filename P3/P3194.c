/*  Considere o mesmo cenário da concessionária da 
questão anterior, porém, agora, você já tem as funções para ler os carros. Sua 
segunda tarefa será ler eventos de aluguel e devoluções de carro e processá-los de 
acordo com a disponibilidade dos carros. */

#include <stdio.h>
#include <string.h>

#define MAX_CARROS 100
#define MAX_TIPO 101

typedef struct {
    int id;
    int passageiros;
    char tipo[MAX_TIPO];
    int km;
    int cliente;      // novo
    int disponivel;   // novo (1 = disponível, 0 = alugado)
} tCarro;

typedef struct {
    tCarro carros[MAX_CARROS];
    int qnt;
} tConcessionaria;

tCarro LeCarro(){
    tCarro carro;
    scanf("%d %d %s %d", &carro.id, &carro.passageiros, carro.tipo, &carro.km);

    carro.disponivel = 1;
    carro.cliente = -1;
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

int EstaDisponivelCarro(tCarro carro){
    return carro.disponivel;
}

int ObtemClienteAlugouCarro(tCarro carro){
    return carro.cliente;
}

tCarro AlugaCarro(tCarro carro, int cliente){
    carro.disponivel = 0;
    carro.cliente = cliente;
    return carro;
}

tCarro DevolveCarro(tCarro carro){
    carro.disponivel = 1;
    carro.cliente = -1;
    return carro;
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


tConcessionaria AlugaCarroConcessionaria( tConcessionaria concessionaria, int cliente,
                                            int pass, int km){
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

        if (EstaDisponivelCarro(carro) && atendePass && atendeKm){

            concessionaria.carros[i] = AlugaCarro(carro, cliente);

            printf("Alugado (cliente %d) -> ", cliente);
            ImprimeCarro(concessionaria.carros[i]);

            return concessionaria;
        }
    }
    printf("Carro Indisponivel\n");
    return concessionaria;
}


tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int cliente){

    int i;
    for (i = 0; i < concessionaria.qnt; i++){

        tCarro carro = concessionaria.carros[i];

        if (!EstaDisponivelCarro(carro) &&
            ObtemClienteAlugouCarro(carro) == cliente){

            concessionaria.carros[i] = DevolveCarro(carro);

            printf("Devolvido (cliente %d) -> ", cliente);
            ImprimeCarro(concessionaria.carros[i]);
            return concessionaria;
        }
    }
    return concessionaria;
}

int main(){

    tConcessionaria concessionaria;
    concessionaria = LeCarrosConcessionaria();

    int cliente;
    char evento;

    while (scanf("%d,%c", &cliente, &evento) == 2){

        if (evento == 'A'){

            int pass, km;
            scanf("%d,%d", &pass, &km);

            concessionaria = AlugaCarroConcessionaria(concessionaria, cliente, pass, km);

        } else if (evento == 'D'){

            concessionaria = DevolveCarroConcessionaria(concessionaria, cliente);
        }
    }
    return 0;
}