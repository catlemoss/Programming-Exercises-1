#include <stdio.h>

/*  Um programa para verificar a validade de 
um código de 4 caracteres, em que o primeiro caractere deve ser maiúsculo, o 
segundo deve ser um dígito, o terceiro deve ser uma vogal, e o quarto deve ser uma 
consoante minúscula.   
*/

int ehLetra(char c){
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') return 1;
    else return 0;
}

int ehLetraMaiuscula(char c){
    if (ehLetra(c) && (c >= 'A' && c <= 'Z')) return 1;
    else return 0;
}

int ehLetraMinuscula(char c){
    if (ehLetra(c) && (c >= 'a' && c <= 'z')) return 1;
    else return 0;
}

int ehNumero(char c){
    if (c >= '0' && c <= '9') return 1;
    else return 0;
}

int ehVogal(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
    else return 0;
}

int main(){

    char maiusculo, digito, vogal, consoante_minuscula;
    scanf(" %c%c%c%c", &maiusculo, &digito, &vogal, &consoante_minuscula);

    if (ehLetraMaiuscula(maiusculo) && ehNumero(digito) && ehVogal(vogal) && 
        (!ehVogal(consoante_minuscula) && ehLetraMinuscula(consoante_minuscula))){

            if (ehLetraMinuscula(vogal)) vogal -=32;
            consoante_minuscula -= 32;
            
            printf("%c%c%c%c\n", maiusculo, digito, vogal, consoante_minuscula);

    } else {
            printf("Invalido\n");
    }

    return 0;
}