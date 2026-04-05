#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N 50 // Tamanho máximo da string

int main(){

    setlocale(LC_ALL, "Portuguese");

    char s1[N] = {"Cata"};
    char s2[N] = {"rina!"};

    printf("Antes do strcat: \n");
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    strcat(s1, s2); // Concatena s2 ao final de s1

    printf("Depois do strcat: \n");
    puts(s1);

    return 0;
}