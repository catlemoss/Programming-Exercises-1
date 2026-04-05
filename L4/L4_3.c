#include <stdio.h>

/* Usando o tipo tData implementado acima, faça um 
programa que leia n datas e informe se a data é de ano bissexto. */

typedef struct {
    int dia;
    int mes;
    int ano;
} tData;

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

tData validaData(tData d){
    if (d.mes < 1) d.mes = 1;
    if (d.mes > 12) d.mes = 12;
    int maxDia = diasNoMes(d.mes, d.ano);
    if (d.dia > maxDia) d.dia = maxDia;

    return d;
}

int ehAnoBi(int ano){
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) return 1;
    else return 0;
}

void imprimeData(tData d){
    if (d.dia < 10) printf("'%02d/", d.dia);
    else printf("'%d/", d.dia);

    if (d.mes < 10) printf("%02d/", d.mes);
    else printf("%d/", d.mes);

    printf("%d'", d.ano);

    if (ehAnoBi(d.ano)) printf(":Bisexto\n");
    else printf(":Normal\n");
}

int main(){

    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        tData d;
        d = leData();
        d = validaData(d);
        imprimeData(d);
    }
    return 0;
}