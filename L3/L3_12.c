#include <stdio.h>

/*  Dado um inteiro não-negativo, repetidamente
 some seus dígitos, até que o resultado tenha somente um dígito. A cada
 soma, o valor deverá ser impresso e após ele, deverá ser impresso se o
 número é ímpar ou par, e se ele é primo.
*/

int somaDigitos(int n){

    int soma = 0;
    
    while (n > 0){
        soma += n % 10;  // pega o último dígito e soma+
        n = n / 10;      // remove- o último dígito
    }

    return soma;
}

void parImpar(int n){
    if (n % 2 == 0) printf("Par ");
    else printf("Impar ");
}

void valorPrimo(int n){
    if (n < 2) {
        printf("Nao e primo\n");
        return;
    }
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            printf("Nao e primo\n");
            return;
        }
    }
    printf("Primo\n");
}

int main(){

    int inteiro, novo_num;
    scanf("%d", &inteiro);

    if (inteiro < 0) return 0;

     while (1){

        if (inteiro >= 10){
            novo_num = somaDigitos(inteiro);

        } else {
            novo_num = inteiro;
        }

        printf("%d ", novo_num);
        parImpar(novo_num);
        valorPrimo(novo_num);

        if (novo_num < 10) break;
        inteiro = novo_num;
    }

    return 0;
}

/*
    while (inteiro >= 10){
        novo_num = somaDigitos(inteiro);
        parImpar(novo_num);
        valorPrimo(novo_num);

        inteiro = novo_num;
    }
        
*/