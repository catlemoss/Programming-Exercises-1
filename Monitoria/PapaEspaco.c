#include <stdio.h>
#include <string.h>

int main(){

    char texto[50];
    int contador = 0;
    char c;

    while (!feof(stdin)){

        contador = 0;

        while (scanf("%c", &c) == 1 && c != '\n' && contador < 50){
            if (c != ' '){
            printf("%c", c);
                texto[contador] = c;
            contador++;
            }
        }
        printf("\n");
    }
    return 0;
}