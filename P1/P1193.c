#include <stdio.h>

/* Um programa que verifique se uma placa de 
carro é válida. Uma placa, composta por 3 letras e 4 números @@@-####, é válida 
quando @ são letras maiúsculas ou minúsculas e # são dígitos numéricos.  
*/

int ehLetra(char c){
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return 1;
    else return 0;
}

int EhNumero(char n){
    if (n >= '0' && n <= '9') return 1;
    return 0;
}

int main(){

    char a1, a2, a3, traco, h1, h2, h3, h4;
    scanf("%c%c%c%c%c%c%c%c", &a1, &a2, &a3, &traco, &h1, &h2, &h3, &h4);

    if (ehLetra(a1) && ehLetra(a2) && ehLetra(a3) && traco == '-' && 
        EhNumero(h1) && EhNumero(h2) && EhNumero(h3) && EhNumero(h4)){
            printf("Codigo valido!\n");
            return 0; // tudo certo

    } else {

        if (!ehLetra(a1) || !ehLetra(a2) || !ehLetra(a3) && traco != '-'){

            if (EhNumero(h1) && EhNumero(h2) && EhNumero(h3) && EhNumero(h4)){
                printf("Codigo invalido!Problema nas letras!\n"); //letras

            } else if (!EhNumero(h1) || !EhNumero(h2) || !EhNumero(h3) || !EhNumero(h4)){
                printf("Codigo invalido!Problema nas letras e nos numeros!\n"); // letras & nums
            }

        } else if (ehLetra(a1) && ehLetra(a2) && ehLetra(a3) && traco == '-' && 
            !EhNumero(h1) || !EhNumero(h2) || !EhNumero(h3) || !EhNumero(h4)){
                printf("Codigo invalido!Problema nos numeros!\n");
                return 0; // nums
        }
    }
    return 0;
}