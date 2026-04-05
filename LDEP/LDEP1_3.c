#include <stdio.h>

/* Um programa capaz de imprimir os múltiplos de 2 e 3 de um intervalo*/

int main(int argc, char const *argv[]){

    int quant;
    scanf("%d", &quant);

    for (int i = 1; i < quant; i++){

        if (i % 2 == 0 || i % 3 == 0){
            printf("%d ", i);
        }
    }
    
    printf("\n");
    return 0;
}