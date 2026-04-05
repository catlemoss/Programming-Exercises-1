#include <stdio.h>

/*  Um programa para descobrir qual de 3 
números possui o menor algarismo na casa das centenas.    
*/

int main(){

    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int centena_1 = (n1 >= 100) ? (n1 / 100) % 10 : -1;
    int centena_2 = (n2 >= 100) ? (n2 / 100) % 10 : -1;
    int centena_3 = (n3 >= 100) ? (n3 / 100) % 10 : -1;

    if (centena_1 == -1 && centena_2 == -1 && centena_3 == -1) {
        printf("Nenhum\n");
        return 0;
    }

    int menor = 10;

    if (centena_1 != -1 && centena_1 < menor) menor = centena_1;
    if (centena_2 != -1 && centena_2 < menor) menor = centena_2;
    if (centena_3 != -1 && centena_3 < menor) menor = centena_3;

    if (centena_1 == menor) printf("N1\n");
    else if (centena_2 == menor) printf("N2\n");
    else printf("N3\n");

    return 0;
}