#include <stdio.h>

int main(){

    int i = 0;

    do {
        printf("%d ", i);
        i++;

    } while (i <= 10); // O loop continuará enquanto i for menor que 10

    return 0;
}

// Exemplo de uso do do-while para imprimir números de 0 a 10
// Ele obrigatoriamente executa o bloco de código pelo menos uma vez, 
// mesmo que a condição seja falsa inicialmente.