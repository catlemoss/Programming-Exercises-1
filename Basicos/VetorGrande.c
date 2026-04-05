#include <stdio.h>

int main(){

    int v[5] = {10, 20, 30, 40, 50}; // Initialize array with ten in the first element
    int i;
    float soma;

    for (i = 0; i < 5; i++){ // Deve ser menor qu eo vetor, já que o vetor tem 5 elementos e começa em 0.
        soma += v[i]; // Accumulate the sum of the elements
    }

    printf("Média: %.2f\n", soma/5.0);

    return 0;
}