#include <stdio.h>

/*  Imagine um cenário em que se tenha duas salas (1 
e 2) com uma parede de separação entre elas. A sala 1 contém um conjunto de 
esferas que devem ser jogadas para a sala 2 através de buracos na parede que as 
separa. Faça um programa para contar a quantidade de esferas que não poderão ser 
jogas para a sala 2 (ou seja, esferas maiores ou iguais do que o buraco) quando 
considerada uma configuração de diâmetros de esferas e de buracos na parede. 
Considere que a parede poderá não ter buracos e a sala 1 poderá não conter esferas. 
*/

int EhFinalDaLista(int buraco){
    return buraco == -1;
}

int EcontraMaiorBuraco(){ 
    //procure o maior buraco de uma lista de diâmetros de buracos

    int buraco, maior = 0;

    while (1){
        scanf("%d", &buraco);
        if (EhFinalDaLista(buraco)) break;
        if (buraco > maior) maior = buraco;
    }

    return maior;
}

int ContaEsferasGrandes(int maiorBuraco){
    //conte as esferas grandes de uma lista de esferas considerando o maior buraco da parede

    int esfera, contador = 0;

    while (1){
        scanf("%d", &esfera);
        if (EhFinalDaLista(esfera)) break;
        if (esfera >= maiorBuraco) contador++;
    }

    return contador;
}

int main(){

    int maior = EcontraMaiorBuraco();
    int qtd = ContaEsferasGrandes(maior);
    
    printf("QTD:%d\n", qtd);
    return 0;
}