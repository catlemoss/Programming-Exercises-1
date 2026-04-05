#include <stdio.h>

/* Um programa que dados os coeficientes de uma 
equação de 3° grau, correspondentes ao a, b, c e d respectivamente 
(ax³ + bx² + cx + d = y) 
e dados os limites e e f do intervalo fechado [e,f], avalie esse 
intervalo procurando o pico e o vale e então os imprima na tela.
*/

double funcao(double a, double b, double c, double d, int x){
    return a*x*x*x + b*x*x + c*x + d;
}

int main(){
    double a, b, c, d;
    int e, f;

    while (scanf("%lf %lf %lf %lf %d %d", &a, &b, &c, &d, &e, &f) == 6){
        int acha_pico = 0, acha_vale = 0;

        for (int x = e; x <= f; ++x){
            if (x - 1 < e || x + 1 > f) continue;

            double y_antes = funcao(a,b,c,d, x-1);
            double y_atual  = funcao(a,b,c,d, x);
            double y_prox = funcao(a,b,c,d, x+1);

            if (y_atual > y_antes && y_atual > y_prox){
                printf("Pico em x=%d\n", x);
                acha_pico = 1;

            } else if (y_atual < y_antes && y_atual < y_prox){
                printf("Vale em x=%d\n", x);
                acha_vale = 1;
            }
        }

        if (!acha_pico) printf("Nao ha pico\n");
        if (!acha_vale) printf("Nao ha vale\n");
    }
    return 0;
}