#include <stdio.h>

/* O irmão de Ana sendo muito experto descobriu como ela 
codificou os textos dela na L2_17, por conta disso, ela veio recorrer novamente a 
você, pra que você faça melhorias pro programa pra que dessa vez ninguém 
descubra o que há nos textos codificados.
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

char Codifica(char letra, int n){

    char codigo;

    n %= 26;
    if (n < 0) n += 26;
    
    if (EhLetraMaiuscula(letra) == 1){
        codigo = ((letra - 'A' + (n * 2)) % 26) + 'A';
        return codigo;

    } else if (EhLetraMinuscula(letra) == 1){
        codigo = ((letra - 'a' + n) % 26) + 'a';
        return codigo;

    } else {
        return letra;
    }
    return 1;
}

char Decodifica (char letra, int n){

    char decodigo;

    n %= 26;
    if (n < 0) n += 26;

    if (EhLetraMaiuscula(letra) == 1){
        decodigo = ((letra - 'A' - (n * 2) + 26) % 26) + 'A';
        return decodigo;

    } else if (EhLetraMinuscula(letra) == 1){
        decodigo = ((letra - 'a' - n + 26) % 26) + 'a';
        return decodigo;

    } else {
        return letra;
    }
    return 1;
}

int main(){

    int modo, chave;
    char texto;

    scanf("%d %d", &modo, &chave);
    getchar();

    if (modo != 1 && modo != 2){
        printf("Operacao invalida.");
        return 0;
    }

    while (scanf("%c", &texto) == 1){

         if (texto == '.'){
            printf(".");
            break;
        }

        if (modo == 1){
            Codifica(texto, chave);
            printf("%c", Codifica(texto, chave));

        } else if (modo == 2){
            Decodifica(texto, chave);
            printf("%c", Decodifica(texto, chave));
        }
    }

    return 0;
}