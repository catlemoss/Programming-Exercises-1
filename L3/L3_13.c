#include <stdio.h>

/* Você deve ler uma série de palavras, onde cada palavra é
   composta somente por letras no intervalo a-z e A-Z. Cada letra possui um valor
   específico, a letra 'a' vale 1, a letra 'b' vale 2 e assim por diante, até a letra 'z', que
   vale 26. Do mesmo modo, a letra 'A' vale 27, a letra 'B' vale 28 e a letra 'Z' vale 52. 
   O valor da palavra é soma dos valores das letras. 
   Você deve escrever um programa 
   para determinar se uma palavra é uma palavra prima ou não. Caso ela não seja
   prima, você deverá indicar o próximo número àquela palavra que é primo.
*/

int letra_para_numero(char c){
    if (c >= 'a' && c <= 'z'){
        return c - 'a' + 1;
    } else if (c >= 'A' && c <= 'Z'){
        return c - 'A' + 27;
    } else {
        return 0;
    }
}

int CalculaValorPalavra(){
    int soma = 0;
    char c;

    while (1){

        c = getchar();

        if (c == EOF) return -1;
        if (c == '\n') break; // fim da palavra

        soma += letra_para_numero(c);
    }

    return soma;
}

int EhPrimo(int n){
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return 0;
        }
    }

    return 1;
}

int ProximoPrimo(int n){
    n++;
    while (!EhPrimo(n)){
        n++;
    }
    return n;
}

int main(){

    int valor;

    while (1){
        valor = CalculaValorPalavra();

        if (valor == -1) break; // sai por EOF

        if (EhPrimo(valor)) printf("E primo\n");
        else printf("Nao e primo %d\n", ProximoPrimo(valor));
    }

    return 0;
}