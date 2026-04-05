#include <stdio.h>

int main(){

    int i = 1;

    while (i <= 10) {
        printf("Valor de i: %d\n", i);
        i++;

        if (i == 5) {
            printf("Chegou ao meio do loop!\n");
            continue; // Pula para a próxima iteração quando i é 5,
                      // ignorando o restante do código nesta iteração

        } else if (i == 8) {
            printf("Chegou ao final do loop!\n");
            break; // Encerra o loop quando i é 8
        }
    }

    return 0;
}

// Este código demonstra o uso de break e continue em um loop while.
// O loop continua enquanto i for menor que 10. Quando i atinge 5,
// a instrução continue faz com que o loop pule para a próxima iteração,
// ignorando o restante do código naquela iteração. Quando i atinge 8,
// a instrução break encerra o loop. Assim, o loop imprime os valores de i
// de 0 a 7, mas pula o código quando i é 5 e para quando i é 8.
// O uso de break e continue é útil para controlar o fluxo de execução
// dentro de loops, permitindo que você saia de um loop ou pule iterações
// com base em condições específicas. Isso pode tornar o código mais eficiente
// e legível, evitando a necessidade de estruturas condicionais mais complexas.