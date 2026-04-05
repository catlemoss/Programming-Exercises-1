#include <stdio.h>

int main(){

    int v[5];
    float m;

    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    v[3] = 40;
    v[4] = 50;

    m = (v[0] + v[1] + v[2] + v[3] + v[4]) / 5.0;

    printf("Média: %.2f\n", m);

    return 0;
}