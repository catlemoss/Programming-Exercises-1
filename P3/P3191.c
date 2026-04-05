/* Faça um programa para parear duas listas de 
números, ou seja, cada número da primeira lista deverá ser pareado com o número 
da posição correspondente da segunda lista. */

#include <stdio.h>

int main(){

    int n; // n nums seq 1
    scanf("%d", &n);

    int a[n];
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    } // le seq 1

    int m; // m nums seq 2
    scanf("%d", &m);

    int b[m];
    int j;
    for (j = 0; j < m; j++){
        scanf("%d", &b[j]);
    } // le seq 2

    printf("PARES:\n");
    
    j = 0; // ind vet b
    for (int i = 0; i < n; i++){

        printf("%d - %d\n", a[i], b[j]);

        j++;
        if (j == m) j = 0;
    }
    return 0;
}