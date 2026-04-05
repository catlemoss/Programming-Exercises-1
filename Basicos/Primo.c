#include <stdio.h>

/* Um programa para informar se um número é primo. */

int ehPrimo(int num){

    if (num < 2){
        return 0; // Nao primo
    }

    for (int i = 2; i * i <= num; i++){
        if (num % i == 0){
            return 0; // Nao primo
        }
    }

    return 1; // Primo
}

int main(){

    int num;
    scanf("%d", &num);

    if (ehPrimo(num)){
        printf("Primo");

    } else {
        printf("Nao primo");
    }

    return 0;
}

/* Se um número n não é primo então existe uma fatoração n = a * b com a > 1 e b > 1; 
um desses dois fatores sempre é menor ou igual à raiz quadrada de n, 
portanto basta procurar divisores até √n para encontrar algum par que prove que n não é primo */