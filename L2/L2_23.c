#include <stdio.h>

/* Dado várias linhas com texto, o 
programa só imprima o texto que estiver dentro de parênteses mais externos. O 
programa será finalizado assim que achar um ponto final fora dos parênteses. 
*/

int main(){

    int c;
    int numero_parenteses = 0;
    int imprimindo = 0;   // estamos dentro de um parenteses?
    int acha_ponto = 0;

    printf("RESP:");

    while ((c = getchar()) != EOF && !acha_ponto){

        if (c == '.' && numero_parenteses == 0) {
            acha_ponto = 1; // para-te (maozinha)

        } else if (c == '('){
            numero_parenteses++;

            if (numero_parenteses == 1){ // primeiro parenteses
                imprimindo = 1;
                continue;
            }

            if (imprimindo){ // se ja achou, imprime o resto
                putchar(c);
            }

        } else if (c == ')'){
            if (numero_parenteses == 1){ // achou o par
                
                imprimindo = 0;
                numero_parenteses--;
                continue;
            }

            if (imprimindo){ // se ja achou, imprime o resto
                putchar(c);
            }

            numero_parenteses--;

        } else {
            
            if (imprimindo){ // imprime frase
                putchar(c);
            }
        }
    }

    return 0;
}