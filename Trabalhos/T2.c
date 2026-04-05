/*  A Confederação Brasileira de Futebol (CBF) necessita de um programa que 
obtenha informações sobre a classificação de seus torneios de pontos corridos.   */

#include <stdio.h>
#include <string.h>

#define MAX_TIMES 100
#define MAX_NOME 31

typedef struct {
    char nome[MAX_NOME];
    int pontos;
    int vitorias;
    int golsPro;
    int golsContra;
    int jogos;
} Time;

void padronizaNome(char nome[]) {
    int i;
    if (nome[0] >= 'a' && nome[0] <= 'z') nome[0] -= 32; // primeira letra maiúscula

    for (i = 1; nome[i] != '\0'; i++) {
        if (nome[i-1] == '-') {
            if (nome[i] >= 'A' && nome[i] <= 'Z') nome[i] += 32; // após hífen minúscula
        } else {
            if (nome[i] >= 'A' && nome[i] <= 'Z') nome[i] += 32;   // resto minúscula
        }
    }
}

int buscaTime(Time times[], int qtd, char nome[]) {
    int i;
    for (i = 0; i < qtd; i++) {
        if (strcmp(times[i].nome, nome) == 0) return i;
    }
    return -1;
}

void ordenaTimes(Time times[], int qtd) {
    int i, j;
    Time aux;
    for (i = 0; i < qtd - 1; i++) {
        for (j = 0; j < qtd - 1 - i; j++) {
            int saldo1 = times[j].golsPro - times[j].golsContra;
            int saldo2 = times[j+1].golsPro - times[j+1].golsContra;

            if (
                times[j].pontos < times[j+1].pontos ||
                (times[j].pontos == times[j+1].pontos && times[j].vitorias < times[j+1].vitorias) ||
                (times[j].pontos == times[j+1].pontos && times[j].vitorias == times[j+1].vitorias && saldo1 < saldo2) ||
                (times[j].pontos == times[j+1].pontos && times[j].vitorias == times[j+1].vitorias && saldo1 == saldo2 && times[j].golsPro < times[j+1].golsPro) ||
                (times[j].pontos == times[j+1].pontos && times[j].vitorias == times[j+1].vitorias && saldo1 == saldo2 && times[j].golsPro == times[j+1].golsPro && strcmp(times[j].nome, times[j+1].nome) > 0)
            ) {
                aux = times[j];
                times[j] = times[j+1];
                times[j+1] = aux;
            }
        }
    }
}

int main() {
    Time times[MAX_TIMES];
    int qtdTimes = 0;

    char nome1[MAX_NOME], nome2[MAX_NOME];
    int gols1, gols2;

    for (int k = 0; k < MAX_TIMES; k++) {
        times[k].pontos = 0;
        times[k].vitorias = 0;
        times[k].golsPro = 0;
        times[k].golsContra = 0;
        times[k].jogos = 0;
        times[k].nome[0] = '\0';
    }

    while (scanf("%s %d %s %d", nome1, &gols1, nome2, &gols2) == 4) {

        padronizaNome(nome1);
        padronizaNome(nome2);

        int i1 = buscaTime(times, qtdTimes, nome1);
        int i2 = buscaTime(times, qtdTimes, nome2);

        if (i1 == -1) {
            strcpy(times[qtdTimes].nome, nome1);
            times[qtdTimes].pontos = 0;
            times[qtdTimes].vitorias = 0;
            times[qtdTimes].golsPro = 0;
            times[qtdTimes].golsContra = 0;
            times[qtdTimes].jogos = 0;
            i1 = qtdTimes;
            qtdTimes++;
        }

        if (i2 == -1) {
            strcpy(times[qtdTimes].nome, nome2);
            times[qtdTimes].pontos = 0;
            times[qtdTimes].vitorias = 0;
            times[qtdTimes].golsPro = 0;
            times[qtdTimes].golsContra = 0;
            times[qtdTimes].jogos = 0;
            i2 = qtdTimes;
            qtdTimes++;
        }

        times[i1].jogos++;
        times[i2].jogos++;

        times[i1].golsPro += gols1;
        times[i1].golsContra += gols2;

        times[i2].golsPro += gols2;
        times[i2].golsContra += gols1;

        if (gols1 > gols2) {
            times[i1].pontos += 3;
            times[i1].vitorias++;
        }
        else if (gols2 > gols1) {
            times[i2].pontos += 3;
            times[i2].vitorias++;
        }
        else {
            times[i1].pontos += 1;
            times[i2].pontos += 1;
        }
    }

    ordenaTimes(times, qtdTimes);

    for (int i = 0; i < qtdTimes; i++) {
        int saldo = times[i].golsPro - times[i].golsContra;
        double eficiencia = 0.0;
        if (times[i].jogos > 0) {
            eficiencia = ((double)times[i].pontos / (times[i].jogos * 3)) * 100.0;
        }

        printf("%d: %s Pontos: %d Vitorias: %d Pro: %d Contra: %d Saldo:%d Eficiencia: %.2f%%\n",
               i+1,
               times[i].nome,
               times[i].pontos,
               times[i].vitorias,
               times[i].golsPro,
               times[i].golsContra,
               saldo,
               eficiencia);
    }

    return 0;
}