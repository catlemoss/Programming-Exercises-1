#include <stdio.h>

/* Dado um inteiro não-negativo, repetidamente some seus 
dígitos, até que o resultado tenha somente um dígito.  
*/

int main(){

    int num, soma;
    scanf("%d", &num);

    while (num >= 10){ // repete ate que num so tenha um digito
        soma = 0;

        while (num > 0){
            soma += num % 10;
            num /= 10;
        }

        num = soma;
    }

    printf("RESP:%d\n", num);

    return 0;
}