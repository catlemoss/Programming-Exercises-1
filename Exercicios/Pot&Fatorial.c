/* Exercicio */

#include <stdio.h>

float potencia(float x, int i){
    float pot = 1;
    int cont;

    for (cont = 0; cont < i; cont++){
        pot = pot * x;
    }
    return pot;
} //função de potencia

int fatorial(int i){
    int fat = 1;
    int mult = 1;

    for (mult = 2; mult <= i; mult++){
        fat = fat * mult;
    }
    return fat;
} // função de fatorial

int main(){

    float x;
    int i;
    scanf("%f %d", &x, &i);

    float pot = potencia(x, i);
    int fat = fatorial(i);

    printf("%.2f %d\n", pot, fat);
    return 0;
}

// x = base
// i = expoente e fatorial

