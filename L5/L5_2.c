#include <stdio.h>

/* um programa que lê notas (de 0 a 100) de N 
participantes de um concurso para um vetor. No final, o programa deverá dizer se o 
vetor está ordenado em ordem crescente, decrescente, ou se está desordenado.  */

int main(){

    int n;
    scanf("%d", &n);

    int notas[n];

    for (int i = 0; i < n; i++){ scanf("%d", &notas[i]); }

    int crescente = 1;
    int decrescente = 1;

    for (int i = 0; i < n - 1; i++){
        if (notas[i] > notas[i + 1]) crescente = 0;

        if (notas[i] < notas[i + 1]) decrescente = 0;
    }

    if (crescente && decrescente) printf("CRESCENTE&DECRESCENTE\n");
    else if (crescente) printf("CRESCENTE\n");
    else if (decrescente) printf("DECRESCENTE\n");
    else printf("DESORDENADO\n");

    return 0;
}

/* Pergunta mental automática:

“Vou precisar comparar esse valor com algo que ainda não existe?”

Se a resposta for sim → vetor.
Se for não → dá pra resolver direto.

--------------------------------------------------------------------------

Regra final (decora essa)

Pergunta mental definitiva:

“Quando eu estiver lendo esse número, eu já sei com o que comparar?”

✅ sim → não precisa de vetor

❌ não → precisa de vetor
*/