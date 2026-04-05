#include <stdio.h>
#include <stdlib.h>
#define MAX_DISPOSITIVOS 100

typedef struct {
    int cdd;
    float nota;
} tDisp;

tDisp listadisp(){

    tDisp d;

    scanf("%d %f", &d.cdd, &d.nota);
    return d;
}

int quant = 0;

void cadastrar(tDisp disp[]){
    if (quant >= MAX_DISPOSITIVOS){
        printf("Limite de dispositivos atingido.\n");
        return;

    } else {
        printf("Codigo do dispositivo: ");
        scanf("%d", &disp[quant].cdd);
        printf("Nota de vulnerabilidade: ");
        scanf("%f", &disp[quant].nota);
        quant++;
    }
}

void listar(tDisp disp[]){

    if (quant == 0){
        printf("Nenhum dispositivo cadastrado.\n");
        return;

    } else {
        printf("Lista de dispositivos cadastrados: \n");

        for (int i = 0; i < quant; i++){
            printf("Codigo: %d | Vulnerabilidade: %.1f\n", disp[i].cdd, disp[i].nota);
        }
    }
}

void ordenar(tDisp disp[]){

    if (quant == 0){
        printf("Nenhum dispositivo cadastrado para ordenar.\n");
        return;

    } else {
        for (int i = 0; i < quant - 1; i++){

            for (int j = i + 1; j < quant; j++){

                if (disp[i].nota < disp[j].nota || (disp[i].nota == disp[j].nota && disp[i].cdd > disp[j].cdd)){
                    tDisp valor = disp[i];
                    disp[i] = disp[j];
                    disp[j] = valor;
                }
            }
        }
    printf("Ordenando dispositivos...\n");
    }
}

int main(){

    int n;
    tDisp disp[MAX_DISPOSITIVOS];

    do {
        
        printf("====== CYBERTEST - MENU ======\n");
        printf("1. Cadastrar novo dispositivo\n");
        printf("2. Listar dispositivos\n");
        printf("3. Ordenar por vulnerabilidade\n");
        printf("4. Sair\n");
        printf("Escolha: ");

        scanf("%d", &n);

        if (n == 1){
            cadastrar(disp);

        } else if (n == 2){
            listar(disp);

        } else if (n == 3){
            ordenar(disp);

        } else if (n == 4){
            printf("Saindo do sistema...\n");

        } else {
            break;
        }

    } while (n != 4);

    return 0;
}