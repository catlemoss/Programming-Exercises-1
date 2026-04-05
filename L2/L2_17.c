#include <stdio.h>
 
/* Ana queria codificar seus textos para que mais ninguém 
lesse, e decodificá-los para quando ela quisesse ler. 

Para isso, faça um programa que 
contenha essas duas opções.   */

int eh_letra_minuscula(char c) {
    return c >= 'a' && c <= 'z';
}

int main(){

    int num, chave;
    char texto, codigo;
    
    scanf("%d %d", &num, &chave);
    getchar(); // Limpa o buffer após ler os inteiros

    if (num != 1 && num != 2){
        printf("Operacao invalida.");
        return 0;
    }

    chave %= 26;
    if (chave < 0) chave += 26; // Ajusta chave negativa para o intervalo [0, 25]

    while (scanf("%c", &texto) == 1){

        if (texto == '.') {
            printf(".");
            break;
        }

        if (num == 1){
            
            if (eh_letra_minuscula(texto)){

                codigo = ((texto - 'a' + chave) % 26) + 'a';
                
                // essa linha faz a codificação pois pega o caractere, 
                // subtrai o 'a' para alinhar ao índice 0, soma a chave, 
                // aplica o módulo 26 para garantir que fique dentro do alfabeto, 
                // e depois adiciona 'a' de volta para obter o caractere codificado.

                printf("%c", codigo);

            } else {
                printf("%c", texto);
            }

        } else if (num == 2){

           if (eh_letra_minuscula(texto)){

                codigo = ((texto - 'a' - chave + 26) % 26) + 'a'; // +26 para evitar resto negativo
                printf("%c", codigo);

            } else {
                printf("%c", texto);
            }
        }
    }

    return 0;
}

/* A Cifra de César é um tipo de criptografia de substituição 
onde cada letra de uma mensagem é substituída por outra letra que está um número fixo de posições 
à frente no alfabeto. 
Por exemplo, com um deslocamento de três posições, 'A' se torna 'D', 'B' vira 'E', e assim por diante. 
Para decifrar, o processo é invertido, voltando as letras para a sua posição original. */