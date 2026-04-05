#include <stdio.h>

/* Um programa que calcule a soma dos maiores 
dígitos primos de cada número de uma sequência. Ou seja, que extraia o maior dígito 
primo de cada número de uma sequência, e ao final apresente a soma desses dígitos. 
Caso o número não apresente dígito primo, não some nada para aquele número.  
*/

int EhPrimo(int num){
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++){
        if (num % i == 0) return 0;
    }
    return 1;
}

int MaiorDigitoPrimo(int num){
    int maior = 0;
    int digito;

    while (num > 0){                                // enquanto for maior que 0
        digito = num % 10;                          // pega o ultimo digito
        if (EhPrimo(digito)){                       // ve se é primo
            if (digito > maior) maior = digito;     // se for, ver se é o maior

        }
        num /= 10;                             // retira ultimo digito
    }
    return maior;
}

int main(){

    int nums;
    int soma = 0;

    while (scanf("%d", &nums) == 1){
        soma += MaiorDigitoPrimo(nums);
    }

    printf("SOMA:%d\n", soma);
    return 0;
}