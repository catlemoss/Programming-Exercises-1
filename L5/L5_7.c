#include <stdio.h>

/* um programa que verifique se os itens (inteiros) de 
uma sequência de números formam uma progressão aritmética. */

int main(){

    int n, i;
    scanf("%d", &n);

    if (n <= 1){
        printf("NAO\n");
        return 0;
    }

    int seq[n];
    for (i = 0; i < n; i++){
        scanf("%d", &seq[i]); 
    }

    int razao = seq[1] - seq[0];
    int igual = 1;
    
    for (i = 2; i < n; i++){
        if (seq[i] - seq[i-1] != razao){
            igual = 0;
            break;
        }
    }
   
    if (igual) printf("RESP:%d\n", razao);
    else printf("NAO\n");
    return 0;
}