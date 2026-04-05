#include <stdio.h>

/* Um programa que conte a quantidade de 
pares de números de uma sequência de pares de números, cujo os maiores dígitos 
de cada número do par são iguais.
*/

int EhIgual(int a, int b){
    if (a == b) return 1;
    else return 0;
}

int MaiorDigito(int num){
    int maior = 0;
    int digito;

    while (num > 0){
        digito = num % 10;
        if (digito > maior) maior = digito;
        num /= 10;
    }
    return maior;
}

int main(){

    int num1, num2;
    int maior1, maior2;
    int contador = 0;

    while(scanf("(%d,%d)", &num1, &num2) == 2){
        maior1 = MaiorDigito(num1);
        maior2 = MaiorDigito(num2);

        if (EhIgual(maior1, maior2)) contador++;
    }

    printf("COUNT:%d\n", contador);
    return 0;
}