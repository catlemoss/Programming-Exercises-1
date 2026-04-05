/* Exercicio */

// Structs
# include <stdio.h>

typedef struct {
    int maior;
    int menor1;
    int menor2;
} tMMs;

tMMs maiorMenores(int x, int y, int z){
    tMMs w; // cria uma caixa

    if (x > y){
        w.maior = x;
        w.menor1 = y;

    } else {
        w.maior = y;
        w.menor1 = x;
    }

    if (w.maior > z){
        w.menor2 = z;

    } else {
        w.menor2 = w.maior;
        w.maior = z;
    }
    return w;
}

int main(){

    int i1, i2, i3;
    tMMs resultado;

    printf("Insira tres numeros:\n");
    scanf("%d %d %d", &i1, &i2, &i3);

    resultado = maiorMenores(i1, i2, i3);

    printf("Maior: %d\nMenor1: %d\nMenor2: %d\n", 
        resultado.maior, resultado.menor1, resultado.menor2);
    return 0;
}