#include <stdio.h>

int main(){

    char forma;

    scanf(" %c", &forma);
    
    if (forma == 'R'){
        char elemento;
        int base, altura;
        scanf(" %c", &elemento);
        scanf("%d %d", &base, &altura);

        for (int i = 0; i < base; i++){
            for (int j = 0; j < altura; j++){
                printf(" %c", elemento);
            }
            printf("\n");
        }

    } else if (forma == 'T'){
        char elemento, modo;
        int lado;
        scanf(" %c", &elemento);
        scanf("%d", &lado);
        scanf(" %c", &modo);

            if (modo == 'C') {
                for (int i = 1; i <= lado; i++) {
                    for (int j = 0; j < i; j++) {
                    printf("%c ", elemento);
                    }
                printf("\n");
                }
            } else if (modo == 'D') {
                for (int i = lado; i > 0; i--) {
                    for (int j = 0; j < i; j++) {
                    printf("%c ", elemento);
                    }
                printf("\n");
                }
            }
    } else if (forma == 'Q'){
        char elemento1, elemento2, elemento3;
        int lado;
        scanf(" %c", &elemento1);
        scanf(" %c", &elemento2);
        scanf(" %c", &elemento3);
        scanf("%d", &lado);
        
        for (int i = 0; i < lado; i++){
            for (int j = 0; j < lado; j++){
                if (i == j){
                    printf(" %c", elemento2);
                } else if (i < j){
                    printf(" %c", elemento3);
                } else {
                    printf(" %c", elemento1);
                }
            }
            printf("\n");
        }

    } else {
        printf("NAO EH FORMA VALIDAAAAAA!!!!!!!\n");
    }
    return 0;
}