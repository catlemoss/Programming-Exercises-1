#include <stdio.h>

/* um programa que leia uma sequência de números 
para um vetor A e troque os elementos de posição impar com os de posição par 
imediatamente seguintes. */

void TrocaParEImpar(int vet[], int qtd){
    int aux, i;
    for (i = 0; i < qtd; i++){
        if (i % 2 != 0){
            aux = vet[i];
            vet[i] = vet[i-1];
            vet[i-1] = aux;
        }
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd){
    int i;

    printf("{");
    if (qtd == 0) printf("}");

    for (i = 0; i < qtd; i++){
        if (i == qtd-1){
            printf("%d}", vet[i]);
            break;
        }

        printf("%d, ", vet[i]);
    }

    printf("\n");
}

int main(){

    int n, i;
    scanf("%d", &n);

    int seq[n];
    for (i = 0; i < n; i++){
        scanf("%d", &seq[i]); 
    }

    TrocaParEImpar(seq, n);
    ImprimeDadosDoVetor(seq, n);

    return 0;
}