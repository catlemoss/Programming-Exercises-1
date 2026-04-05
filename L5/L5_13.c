#include <stdio.h>
#include <stdlib.h>

/* Dado o programa abaixo que lê pares de palavras 
separadas por espaço e imprime “IGUAL” quando elas são iguais e “DIFERENTE” 
quando elas são diferente, implemente a função que falta para comparar duas 
strings. */
 
int ComparaString(char str1[], char str2[]){
   int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i]){
            return 0;
        }

        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0'){
        return 1;
    }

    return 0;
}

int main(){
    
    char str1[1000]; 
    char str2[1000]; 
   
    while (scanf("%s %s", str1, str2) == 2){ 

        if (ComparaString(str1, str2)) printf("IGUAL\n"); 
        else printf("DIFERENTE\n"); 
    }
  
    return 0;     
}