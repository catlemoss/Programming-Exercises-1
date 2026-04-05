#include <stdio.h>

/* Um programa que conte a quantidade de 
números palíndromos de uma sequência.
*/

int EhIgual(int a, int b){
    if (a == b) return 1;
    else return 0;
}

int InverteNumero(int num){
    int invertido = 0;
    while (num > 0) {
        invertido = invertido * 10 + (num % 10); // pula o dig para a esquerda e soma o resto
        num /= 10;
    }
    return invertido;
}

int main(){

    int nums, contador = 0;
    int palindromo;

    while (scanf("%d", &nums) == 1){
        palindromo = InverteNumero(nums);

        if (EhIgual(nums, palindromo)) contador++;
    }

    printf("COUNT:%d\n", contador);
    return 0;
}