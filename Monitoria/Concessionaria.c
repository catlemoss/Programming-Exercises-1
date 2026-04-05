/* Thiago, dono de uma concessionária em crescimento no Brasil, procurou ajuda 
de estudantes da UFES para implementar um código que auxilie o funcionamento de 
seu estabelecimento. Cabe a você, programador, colocar as ideias em prática a fim de 
modularizar as atividades realizadas na loja. */

#include <stdio.h>

#define MAX_NOME 21
#define MAX_CAR 50

typedef struct {
    char modelo[MAX_NOME];
    char marca[MAX_NOME];
    int ano;
    int quilometragem;
    char placa[MAX_NOME];
    char cor[MAX_NOME];
    float preco;
} tCarro;

typedef struct {
    char nome[MAX_NOME];
    int qnt_car_atual;
    tCarro carros[MAX_CAR];
} tConcessionaria;

tConcessionaria LeConcessionaria(){

    tConcessionaria con;
    scanf(" %[^\n]", con.nome); // le ate o \n para imprimir auto vitoria
    con.qnt_car_atual = 0;
    return con;
}

tCarro LeCarro(){
    tCarro c;
    scanf("%20s", c.modelo);
    scanf("%20s", c.marca);
    scanf("%d", &c.ano);
    scanf("%d", &c.quilometragem);
    scanf("%20s", c.placa);
    scanf("%20s", c.cor);
    scanf("%f", &c.preco);
    return c;
}

tConcessionaria CadastraCarro(tConcessionaria con){
    if (con.qnt_car_atual < MAX_CAR){
        con.carros[con.qnt_car_atual] = LeCarro();
        con.qnt_car_atual++; // se leu, tem mais um carro
        printf("Carro cadastrado com sucesso!\n");
    }
    return con;
}

void ImprimeCarro(tCarro c){
    printf("%s %s (%d) - %s - %s - R$ %.2f\n", c.marca, c.modelo, c.ano, c.placa,
           c.cor, c.preco);
}

void ImprimeConcessionaria(tConcessionaria con){
    printf("\nConcessionaria: %s\n", con.nome);
    int i;
    for (i = 0; i < con.qnt_car_atual; i++){
        ImprimeCarro(con.carros[i]);
    }
}

void ImprimeMenu(){
    printf("--- Concessionaria ---\n");
    printf("C - Cadastrar carro\n");
    printf("I - Listar carros\n");
    printf("O - Ordenar por preco\n");
    printf("M - Imprimir preco medio\n");
    printf("F - Finalizar\n\n");
} 

tConcessionaria OrdenaPorPreco(tConcessionaria con){
    tCarro aux;
    int i, j;
    for (i = 0; i < con.qnt_car_atual - 1; i++){ // nao acessar fora do vet
        for (j = 0; j < con.qnt_car_atual - 1; j++){

            if (con.carros[j].preco > con.carros[j + 1].preco){
                aux = con.carros[j];
                con.carros[j] = con.carros[j + 1];
                con.carros[j + 1] = aux;
            }
        }
    }
    return con;
}

float CalculaMediaPreco(tConcessionaria con){
    float soma = 0;
    int i;
    for (i = 0; i < con.qnt_car_atual; i++){
        soma += con.carros[i].preco;
    }
    if (con.qnt_car_atual == 0) return 0;
    return soma / con.qnt_car_atual;
}

int main(){
    tConcessionaria con = LeConcessionaria();
    ImprimeMenu();
    char opcao;
    
    while (1){
        scanf(" %c", &opcao);

        if (opcao == 'C'){
            con = CadastraCarro(con);

        } else if (opcao == 'I'){
            ImprimeConcessionaria(con);

        } else if (opcao == 'O'){
            con = OrdenaPorPreco(con);

        } else if (opcao == 'M'){
            float media = CalculaMediaPreco(con);
            printf("\nPreco medio: R$ %.2f\n", media);

        } else if (opcao == 'F'){
            printf("\nPrograma Encerrado!\n");
            break;
        }
    }
    return 0;
}