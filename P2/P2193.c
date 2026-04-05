#include <stdio.h>

int EhDigito(char c){
    return (c >= '0' && c <= '9');
}

char LeProxChar(char terminador){
    int cha = getchar();
    if (cha == terminador) return 0;
    return cha;
}

void ImprimePorExtenso(char digito){
    switch (digito){
        case '0': printf("zero"); break;
        case '1': printf("um"); break;
        case '2': printf("dois"); break;
        case '3': printf("tres"); break;
        case '4': printf("quatro"); break;
        case '5': printf("cinco"); break;
        case '6': printf("seis"); break;
        case '7': printf("sete"); break;
        case '8': printf("oito"); break;
        case '9': printf("nove"); break;
    }
}

int main(){
    char d, frase;
    scanf("%c ", &d);

    while ((frase = LeProxChar(d))){
        if (EhDigito(frase)){
            char num[100];
            int tamanho = 0;
            num[tamanho++] = frase;

            char resto;
            while ((resto = LeProxChar(d)) && EhDigito(resto)){
                num[tamanho++] = resto;
            }

            if (tamanho == 1){
                ImprimePorExtenso(num[0]);
            } else {
                for (int i = 0; i < tamanho; i++){
                    putchar(num[i]);
                }
            }

            if (resto){
                putchar(resto);
            }

            if (!resto){
                break;
            }

        } else {
            putchar(frase);
        }
    }
    return 0;
}