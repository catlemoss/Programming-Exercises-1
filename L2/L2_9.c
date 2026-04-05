#include <stdio.h>

/* Um programa que imprima os números primos
contidos em um intervalo n e m fornecidos pelo usuário seguidos por seus múltiplos
até o final do intervalo. */

int ehPrimo(int num){
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++){
        if (num % i == 0) return 0;
    }
    return 1;
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = n + 1; i < m; i++){

        if (ehPrimo(i)){
            printf("%d\n", i);

            int mult = 0;

            for (int j = i + 1; j < m; j++){
                if (j % i == 0){
                    printf("%d ", j);

                    mult++;
                }
            }

            if (mult == 0) printf("*");
            printf("\n");
        }
    }

    return 0;
}