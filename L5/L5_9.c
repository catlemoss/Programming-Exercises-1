#include <stdio.h>

/* um programa que leia uma sequência de números 
para um vetor A e inverta a sequência de números, isto é, o último elemento deverá 
ser o primeiro, o penúltimo deverá ser o segundo e assim por diante. */

void InverteVetor(int vet[], int qtd){
    int i = 0,      //inicio
        j = qtd-1;  //fim
    int aux;

    while (i < j){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;

        i++;
        j--;
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

    InverteVetor(seq, n);
    ImprimeDadosDoVetor(seq, n);

    return 0;
}