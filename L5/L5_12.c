#include <stdio.h>
#include <stdlib.h> //malloc e free

/* Dado o programa abaixo que lê sobrenomes e nomes 
separados por espaço e imprime o nome completo da pessoa sem espaço  */
 
void ConcatenaString(char str1[], char str2[], char strOut[]){
    int i = 0, j = 0;

    while (str1[i] != '\0'){ // copia primeira word
        strOut[i] = str1[i];
        i++;
    }

    /* 
        strOut[i] = ' '; para caso queira um espaco
        i++;
    */

    while (str2[j] != '\0'){ // copia segunda word sem cagar a primeira
        strOut[i] = str2[j];
        i++;
        j++;
    }
    strOut[i] = '\0'; //break das strings
} 

int main(){
    
    char nome[1000]; 
    char sobrenome[1000]; 
    char nomeCompleto[2000]; 
   
    while (scanf("%s %s", sobrenome, nome) == 2){ // num de word esperadas
        ConcatenaString(nome, sobrenome, nomeCompleto);     
        printf("%s\n", nomeCompleto);
    }
  
    return 0;     
}

/* 

-> Vetor Estático: 
char v[10]; 
(Tamanho fixo, memória automática).

-> Vetor Dinâmico: 
char *v = malloc(10); 
(Tamanho flexível, memória manual via stdlib.h).

*/