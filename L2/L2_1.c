#include <stdio.h>

/* Um programa para exibir todos os números 
pares contidos em um determinado intervalo. */

int main(){

    int n, m;

    scanf("%d %d", &n, &m);

    printf("RESP:");

    for (int i = n + 1; i < m; i++){

        if (i % 2 == 0){

            printf("%d ", i);
        }
    }

    return 0;
}