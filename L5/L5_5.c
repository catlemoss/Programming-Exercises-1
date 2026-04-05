#include <stdio.h>

/* um programa para ler uma sequência de N números
para um vetor e procurar a primeira ocorrência de um número X nesse vetor. */

int main(){

    int x, i,   // num inteiro a ser procurado
        n,      // quant nums
        pos;
    scanf("%d %d", &x, &n);

    int seq[n];
    for (i = 0; i < n; i++){
        scanf("%d", &seq[i]);
    }

    for (i = 0; i < n; i++){
        if (x != seq[i]) pos = n;
        else if (x == seq[i]){
            pos = i;
            break;
        }
    }

    printf("RESP:%d\n", pos);
    return 0;
}