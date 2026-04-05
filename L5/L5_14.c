#include <stdio.h>
#include <stdlib.h>

/* Dado o programa abaixo que lê candidatos de um 
concurso, complete o programa para imprimir os candidatos com sobrenome 
repetidos e na ordem de entrada.  */
 
typedef struct { 
    int codigo; 
    char sobrenome[21]; 
    char nome[21]; 
    int nota; 
    int idade; 
} tCandidato; 
 
tCandidato LeCandidato(){
    tCandidato c;

    scanf(" {%d, %[^,], %[^,], %d, %d}", &c.codigo, c.sobrenome,
          c.nome, &c.nota, &c.idade);

    return c;
}

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

void ImprimeCandidato(tCandidato c){
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", c.codigo, c.nome, c.sobrenome,
            c.nota, c.idade);
}

int main(){

    int qtdCand, i, j; 
    scanf("%d", &qtdCand);

    tCandidato candidatos[qtdCand]; 
    
    for (i = 0; i < qtdCand; i++){
        candidatos[i] = LeCandidato();
    }
    
    for (i = 0; i < qtdCand; i++){
        int achou = 0;
        int jaImprimiu = 0;

        // sobrenome ja apareceu antes?
        for (j = 0; j < i; j++){
            if (ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome)){
                jaImprimiu = 1;
                break;
            }
        }

        if (jaImprimiu) continue;

        for (j = i+1; j < qtdCand; j++){
            if (ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome)){

                if (!achou){
                    ImprimeCandidato(candidatos[i]);
                    achou = 1;
                }

                ImprimeCandidato(candidatos[j]);
            }
        }
    }
    return 0;
}