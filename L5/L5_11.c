#include <stdio.h>

/* um programa para ler duas sequências de números 
e armazena-las em dois vetores A e B.  */

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

// Tecnica de "Merge"
void ImprimeDadosDoVetor(int vet1[], int vet2[], int qtd1, int qtd2) {
    int i = 0, j = 0;

    OrdenaCrescente(vet1, qtd1); // lembrar de nao ordenar em loop
    OrdenaCrescente(vet2, qtd2);

    // aqui, usar while e mais recomendado, pois o for ficou confuso.
    // com while e mais facil comparar os dois concomitantemente
    while (i < qtd1 && j < qtd2){

        if (vet1[i] <= vet2[j]){
            printf("A");
            i++;

        } else {
           printf("B");
            j++;
        }
    }

    // possiveis sobras?
    while (i < qtd1){
        printf("A");
        i++;
    }
    while (j < qtd2){
        printf("B");
        j++;
    }

    printf("\n");
}

int main(){

    int n1, i, j;
    scanf("%d", &n1);
    int A[n1];
    for (i = 0; i < n1; i++){ scanf("%d", &A[i]); }

    int n2;
    scanf("%d", &n2);
    int B[n2];
    for (i = 0; i < n2; i++){ scanf("%d", &B[i]); }
    //leituras

    ImprimeDadosDoVetor(A, B, n1, n2);

    return 0;
}