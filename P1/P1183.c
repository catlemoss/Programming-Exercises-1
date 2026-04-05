#include <stdio.h>

/* Faça um programa que compare dois códigos de 3 
caracteres cada, fazendo uma análise para cada par de caracteres correspondentes. 
A análise deve comparar cada caractere de um código com seu respectivo caractere 
no outro código e dizer se é igual, diferente ou se difere apenas por ser maiúsculo ou 
minúsculo (e.g., comparar o primeiro caractere do primeiro código com o primeiro 
do segundo código, e fazer mesmo para o segundo e terceiro caracteres). Caso algum 
dos códigos seja inválido, o programa deve informar apenas que o código é inválido. 
Um código é considerado válido se seu primeiro caractere é um dígito numérico, se 
o segundo caractere é uma letra minúscula e se o terceiro caractere é uma letra.
*/

int EhLetra (char c){
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') return 1;
    else return 0;
}

int EhLetraMaiuscula(char c){
    if (EhLetra(c) && c >= 'A' && c <= 'Z') return 1;
    return 0;
}

int EhLetraMinuscula(char c){
    if (EhLetra(c) && c >= 'a' && c <= 'z') return 1;
    return 0;
}

int EhNumero(char n){
    if (n >= '0' && n <= '9') return 1;
    return 0;
}

int main(){

    char a1, a2, a3, b1, b2, b3;
    scanf(" %c%c%c %c%c%c", &a1, &a2, &a3, &b1, &b2, &b3);

        int validoA = EhNumero(a1) && EhLetraMinuscula(a2) && EhLetra(a3);
        int validoB = EhNumero(b1) && EhLetraMinuscula(b2) && EhLetra(b3);

        if (!validoA || !validoB){
            printf("Codigo invalido!\n");
            return 0;
        }

        char c1, c2;

        //primeiro
        if (a1 == b1) printf("I");
        else printf("D");

        //segundo
        if (a2 == b2) printf("I");
        else printf("D");

        //terceiro
        if (a3 == b3){
            printf("I");

        } else {
            c1 = (EhLetraMaiuscula(a3)) ? (a3 + 32) : a3;
            c2 = (EhLetraMaiuscula(b3)) ? (b3 + 32) : b3;

            if (c1 == c2) printf("C");
            else printf("D");
        }

    printf("\n");
    return 0;
}