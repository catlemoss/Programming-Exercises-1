#include <stdio.h>
#include <stdlib.h>

/* Um programa que le uma sequência de pares de números da entrada padrão e 
imprimir a soma de cada par. */

int main(int argc, char const *argv[]){

    int quant;
	scanf("%d", &quant);

    for (int i = 0; i < quant; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}