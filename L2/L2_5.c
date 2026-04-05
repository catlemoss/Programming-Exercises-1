#include <stdio.h>
#include <math.h>

/* Um programa para calcular o valor de π de acordo 
com a seguinte fórmula:  π= √∑6/k^2 -> n; k=1 */

int main(){

    int n, k = 1;
    double soma = 0.0;

    scanf("%d", &n);

    while (k <= n){
        soma += 6.0 / (k * k);
        k++;
    }

    double pi = sqrt(soma);

    printf("%.6lf", pi);
    return 0;
}