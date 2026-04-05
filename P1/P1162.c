#include <stdio.h>

/* Faça um programa para dizer se um grupo de 
pontos está ou não em uma reta definida por: 
    a𝑥 +𝑏 =𝑦 
*/

int funcao(int a, int b, int x){
    return a*x + b;
}

int main(){

    int a, b, x1, y1, x2, y2, x3, y3;
    int soma = 0;
    scanf("%d %d %d %d %d %d %d %d", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);

    if (funcao(a, b, x1) == 0 || funcao(a, b, x1) == y1) soma++;
    if (funcao(a, b, x2) == 0 || funcao(a, b, x2) == y2) soma++;
    if (funcao(a, b, x3) == 0 || funcao(a, b, x3) == y3) soma++;

    if (soma == 0) printf("Nenhum\n");
    else if (soma == 1) printf("Um\n");
    else if (soma == 2) printf("Dois\n");
    else if (soma == 3) printf("Todos\n");

    return 0;
}