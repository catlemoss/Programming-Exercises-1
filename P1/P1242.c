#include <stdio.h>

int main(){

    int n, m;

    scanf("%d %d", &n, &m);

    long long anterior = 0;
    long long atual = 1;
    long long proximo;

    if (m == 0) {
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                printf("0 ");
            } else if (i == 1) {
                printf("1 ");
            } else {
                proximo = 2 * atual + anterior;
                printf("%lld ", proximo);
                anterior = atual;
                atual = proximo;
            }
        }
        printf("\n");

    } else if (m == 1) {
        
        long long soma_pares = 0;

        for (int i = 0; i <= n; i++) {
            long long termo;
            if (i == 0) {
                termo = 0;
            } else if (i == 1) {
                termo = 1;
            } else {
                termo = 2 * atual + anterior;
                anterior = atual;
                atual = termo;
            }

            if (termo % 2 != 0) {
                printf("%lld ", termo);
            } else {
                soma_pares += termo;
            }
        }
        printf("\n%lld\n", soma_pares);
    }

    return 0;
}

