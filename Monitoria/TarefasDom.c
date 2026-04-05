#include <stdio.h>

#define ESCOVADO 1
#define ARRUMADA 1
#define PREPARADO 1
#define PENDENTE 0

int dentes = PENDENTE;
int cama = PENDENTE;
int cafe = PENDENTE;
int tempo = 15;


void EscovarDentes() {
    printf("Escovando os dentes!\n");
    dentes = ESCOVADO;
    tempo -= 2;
}

void ArrumarCama() {
    printf("Arrumando a cama!\n");
    cama = ARRUMADA;
    tempo -= 3;
}

void PrepararCafe() {
    printf("Preparando o cafe!\n");
    cafe = PREPARADO;
    tempo -= 5;
}

int main() {
    int opcao;

    while (1) {
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (dentes == ESCOVADO) {
                    printf("Isso ja foi feito!\n");
                } else {
                    EscovarDentes();
                }
                break;
            case 2:
                if (cama == ARRUMADA) {
                    printf("Isso ja foi feito!\n");
                } else {
                    ArrumarCama();
                }
                break;
            case 3:
                if (cafe == PREPARADO) {
                    printf("Isso ja foi feito!\n");
                } else {
                    PrepararCafe();
                }
                break;
            case 0:
                if (tempo <= 0) {
                    printf("### Perdeu o onibus! ###\n");
                    return 0;
                } else if (dentes == ESCOVADO && cama == ARRUMADA && cafe == PREPARADO) {
                    printf("Saindo de casa!\n");
                    return 0;
                } else {
                    printf("### Ainda ha tarefas pendentes! ###\n");
                }
                break;
            default:
                printf("nao\n");
        }

        if (tempo <= 0) {
            printf("### Perdeu o onibus! ###\n");
            return 0;
        } else {
            printf("Tempo restante: %d minutos\n", tempo);
        }
    }

    return 0;
}
