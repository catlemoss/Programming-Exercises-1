#include <stdio.h>
#include <math.h>

/* um programa que lê notas (de 0 a 100) de N 
participantes de um concurso.  */

int main(){

    int n;
    scanf("%d", &n);

    int notas[n];
    int menor = 101, maior = -1;
    int soma = 0;

    for (int i = 0; i < n; i++){
        scanf("%d", &notas[i]); 
        //Para cada participante, guarda a nota dele na posição i do vetor.
        soma += notas[i];

        if (notas[i] < menor) menor = notas[i];
        if (notas[i] > maior) maior = notas[i];
    }

    float media = (float)soma/n;

    float soma_dp = 0.0;
    int acima_da_media = 0;
    int reprovados = 0;

    for (int i = 0; i < n; i++){
        soma_dp += (notas[i] - media)*(notas[i] - media);

        if (notas[i] > media) acima_da_media++;
        if (notas[i] < 70) reprovados++;
    }

    float desvio_padrao = sqrt(soma_dp/n);

    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d\n",
        menor, maior, media, desvio_padrao, acima_da_media, reprovados);

    return 0;
}

/* Vetor serve pra guardar valores que você vai precisar usar de novo depois.

Se o problema pede media e algo que depende da media,
sempre serão dois loops */