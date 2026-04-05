#include <stdio.h>
 
/* Alguns números tem uma propriedade curiosa. 

Caso você inverta a ordem dos algarismos desse número ele continuará tendo o mesmo valor. 
A esses números, damos o nome de Palíndromos. 

Você deverá implementar um 
programa que identifica se um dado número é Palíndromo ou não. 

a) A identificação do número palíndromo deverá ser feita por uma função (a ser 
implementada) que receberá um número inteiro num e retornará verdadeiro se o 
número for palíndromo e falso caso contrário. A função deverá ter o seguinte 
cabeçalho: int EhPalindromo(int num); */

#include <stdio.h>

int EhPalindromo(long long num){

    if (num < 0) num = -num;

    long long original = num;
    long long reverso = 0;

    while (num > 0){
        int digito = num % 10;
        reverso = reverso * 10 + digito;
        num /= 10;
    }

    return original == reverso;
}

int main(){

    long long n;

    while (scanf("%lld", &n) == 1){

        if (EhPalindromo(n)) printf("S\n");
        else printf("N\n");
    }

    return 0;
}