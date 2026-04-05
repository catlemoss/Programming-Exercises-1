/* Prova 2 do Flávio Varejão */
/* A Google te contratou para participar do projeto de reengenharia do software 
Agenda (Calendar) da suite Google.*/

#include <stdio.h>

#define MAX_EVENTOS 100
typedef struct {
    int dia_sa_semana; // 0 a 6
    int hora_de_inicio; // 0 a 23
    int duracao_evento; // 0 a 23
} tInfoEvento; // um evento

typedef struct {
    int qnt_eventos;
    tInfoEvento eventos[MAX_EVENTOS];
} tListaEventos; // conjunto de eventos

typedef struct {
    int calendario[24][7]; // linha = horas, coluna = dia
} tMatrizEventos;


int comparaEventos (tInfoEvento e1, tInfoEvento e2){
    if (e1.dia_sa_semana < e2.dia_sa_semana) return -1; // antes
    else if (e1.dia_sa_semana > e2.dia_sa_semana) return 1; // depois
    else {
        if (e1.hora_de_inicio < e2.hora_de_inicio) return -1;
        else if (e1.hora_de_inicio > e2.hora_de_inicio) return 1;
        else return 0; // iguais
    }
}

tListaEventos incluiEvento (tListaEventos agenda, tInfoEvento e){
    int i = agenda.qnt_eventos - 1;

    while (i >= 0 && comparaEventos(e, agenda.eventos[i]) < 0){
        agenda.eventos[i + 1] = agenda.eventos[i];
        i--;
    }

    agenda.eventos[i + 1] = e;
    agenda.qnt_eventos++;

    return agenda;
}

tMatrizEventos iniciaVazia(){
    tMatrizEventos m;

    int i, j;
    for (i = 0; i < 24; i++){
        for (j = 0; j < 7; j++){

            m.mat[i][j] = 0; // atribuição, e não comparação "=="
        }
    }
    return m;
}

tMatrizEventos controlaAgenda(tListaEventos agenda){
    tMatrizEventos m = iniciaVazia();

    int i, h;
    for (i = 0; i < ag.qtd; i++){

        int dia = agenda.eventos[i].dia_sa_semana;
        int inicio = agenda.eventos[i].hora_de_inicio;
        int dur = agenda.eventos[i].duracao_evento;

        for (h = inicio; h < inicio + dur; h++){

            m.calendario[h][dia] = 1;
        }
    }
    return m;
}
