#include <stdio.h>

int main(){

        int a, b;

        //Le os valores de entrada
        scanf("%d %d", &a, &b);

        //Troca simples usando uma variavel temporaria
        int temp = a;
        a = b;
        b = temp;

        //Exibe os valores trocados
        printf("%d, %d", a, b);

        return 0;

}