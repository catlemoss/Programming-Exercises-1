#include <stdio.h>

int ehPrimo(int n){
    if (n < 0) n = -n; // se for negativo, vira positivo

    if (n == 0) return 0;
    if (n == 1) return 1;

    return ehPrimo(n - 1);
}

int main(){
    int n;
    scanf("%d", &n);

    int p = ehPrimo(n);

    if (p) printf("Primo\n");
    else printf("Nao\n");

    return 0;
}