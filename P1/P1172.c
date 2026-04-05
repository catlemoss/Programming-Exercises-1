#include <stdio.h>

/*  Um programa para identificar o tipo do 
conjunto de pessoas passado. As pessoas serão identificadas por números inteiros 
de 1 a 10 inclusive, em que identidades de 1 a 5 são de homens e identidades de 6 a 
10 são de mulheres. Identidades fora desses limites são inválidas. 
*/

int main(){

    int pessoa1, pessoa2;
    int soma_h = 0, soma_m = 0;
    scanf("%d %d", &pessoa1, &pessoa2);

    if (pessoa1 < 1 || pessoa1 > 10 || pessoa2 < 1 || pessoa2 > 10){
        printf("Invalido\n");
        return 0;
    }

    if (pessoa1 == pessoa2){
        if (pessoa1 >= 1 && pessoa1 <= 5) printf("Um homem\n");
        else printf("Uma mulher\n");

    } else {
        if (pessoa1 >= 1 && pessoa1 <= 5) soma_h++;
        else soma_m++;

        if (pessoa2 >= 1 && pessoa2 <= 5) soma_h++;
        else soma_m++;
    }

    if (soma_h == 1 && soma_m == 1) printf("Um casal\n");
    if (soma_h == 2 && soma_m == 0) printf("Par de homens\n");
    if (soma_h == 0 && soma_m == 2) printf("Par de mulheres\n");

    return 0;
}