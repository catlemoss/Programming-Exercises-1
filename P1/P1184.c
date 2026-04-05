#include <stdio.h>

/* Um programa que incremente um horário com 
uma quantidade de minutos e diga o equivalente em quantidade de dias, horas e 
minutos.    
*/

int main(){

    int horas_iniciais, min, incremento;
    scanf("%d:%d %d", &horas_iniciais, &min, &incremento);

        int total = horas_iniciais*60 + min + incremento;
        int dias = total / (24*60);
        int resto_dos_min = total % (24*60);
        int horas = resto_dos_min / 60;
        int minutos = resto_dos_min % 60;

        if (dias > 0){
            if (dias == 1) printf("(1 dia)");
            else printf("(%d dias)", dias);
        }

        if (horas > 0){
            if (horas == 1) printf("(1 hora)");
            else printf("(%d horas)", horas);
        }

        if (minutos > 0){
            if (minutos == 1) printf("(1 minuto)");
            else printf("(%d minutos)", minutos);
        }

    printf("\n");
    return 0;
}