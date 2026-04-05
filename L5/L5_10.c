#include <stdio.h>

/*  um programa que leia uma sequência de números 
para um vetor A e ordene em ordem crescente a sequência de números. */

void OrdenaCrescente(int vet[], int qtd){
    int troca = 1;
    int i, aux;

    while (troca){
        troca = 0;
        for (i = 0; i < qtd-1; i++){
            if (vet[i] > vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                troca = 1;
            }
        }
    }
    qtd--;
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

    OrdenaCrescente(seq, n);
    ImprimeDadosDoVetor(seq, n);

    return 0;
}