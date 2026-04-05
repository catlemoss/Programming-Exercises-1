#include <stdio.h>

/* Um programa para apresentar todas as datas 
contidas em um intervalo formado por duas datas d1 e d2, em que o intervalo seja 
fechado em d1 e aberto em d2 [d1, d2[ */

typedef struct {
    int dia;
    int mes;
    int ano;
} tData;
// uma struct tData representa UMA data.
// nunca uma struct deve representar duas coisas diferentes ao mesmo tempo.

tData leData(){
    tData d;
    scanf("%d %d %d", &d.dia, &d.mes, &d.ano);
    return d;
}

int diasNoMes(int mes, int ano){
    if (mes == 1 || mes == 3 || mes == 5 ||
        mes == 7 || mes == 8 || mes == 10 || mes == 12) return 31;
    else {
        if (mes != 2) return 30;
        else {
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) return 29;
            else return 28;
        }
    }
}

// uma função tData precisa devolver UMA tData inteira, não um número (12, 31, etc).
tData validaData(tData d){
    if (d.mes > 12) d.mes = 12;
    int maxDia = diasNoMes(d.mes, d.ano);
    if (d.dia > maxDia) d.dia = maxDia;

    return d;
}

tData proximaData(tData d){
    d.dia++;
    int maxDia = diasNoMes(d.mes, d.ano);

    if (d.dia > maxDia){
        d.dia = 1;
        d.mes++;
        if (d.mes > 12){
            d.mes = 1;
            d.ano++;
        }
    }
    return d;
}

int dataMenor(tData d1, tData d2){
    if (d1.ano < d2.ano) return 1;
    if (d1.ano > d2.ano) return 0;

    // anos iguais
    if (d1.mes < d2.mes) return 1;
    if (d1.mes > d2.mes) return 0;

    // meses iguais
    if (d1.dia < d2.dia) return 1;

    return 0;
}

void imprimeData(tData d){
    if (d.dia < 10) printf("'%02d/", d.dia);
    else printf("'%d/", d.dia);

    if (d.mes < 10) printf("%02d/", d.mes);
    else printf("%d/", d.mes);

    printf("%d'\n", d.ano);
}

int main(){

    tData d1;
    tData d2;

    d1 = leData();
    d1 = validaData(d1);

    d2 = leData();
    d2 = validaData(d2);

    while (dataMenor(d1, d2)){
        imprimeData(d1);
        d1 = proximaData(d1);
    }
    
    return 0;
}