#include <stdio.h>
 
/* Um programa para imprimir a quantidade de 
números negativos, a quantidade de números positivos, a soma dos negativos e a 
soma dos positivos de uma sequência de números. O programa deverá ler números 
da entrada padrão (um por vez) enquanto ainda tiverem números para serem lidos. 
Considere que os números estão entre -100 e 100.  */

#define MAX 100
#define MIN -100

int main(){

    int sequencia, contNeg = 0, contPos = 0, somaNeg = 0, somaPos = 0;
    char c;

    while (scanf("%d", &sequencia) == 1){

        if (sequencia > MAX && sequencia < MIN) break;

        if (sequencia > 0){
			somaPos += sequencia;
			contPos++;
		}
		
		if (sequencia < 0){
			somaNeg += sequencia;
			contNeg++;
		}

        c = getchar(); // lê o próximo caractere
        if (c == '\n' || c == EOF) break; // fim da entrada
        else if (c == ' ' || c == '\t') continue; // ignora espaços em branco
    }

    printf("%d %d %d %d", contNeg, contPos, somaNeg, somaPos);
    return 0;
}