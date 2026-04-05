#include <stdio.h>
#include <stdlib.h>

/* Dado o programa abaixo que lê candidatos de um 
concurso e imprime em ordem de classificação do concurso (do primeiro a ser 
chamado ao último), implemente a função que ordena os candidatos considerando a 
prioridade de chamada dada por maior nota, menor idade, e menor código.   

maior nota, menor idade, e menor código.

*/
 
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

int ComparaCandidato(tCandidato a, tCandidato b){

    if (a.nota != b.nota) return a.nota < b.nota;
    if (a.idade != b.idade) return a.idade > b.idade;
    
    return a.codigo > b.codigo;
}

void OrdenaCrescente(tCandidato vet[], int qtd){
    int troca = 1;
    int i;
    tCandidato aux;
    while (troca){
        troca = 0;
        for (i = 0; i < qtd-1; i++){
            if (ComparaCandidato(vet[i], vet[i+1])){ 
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                troca = 1;
            }
        }
    }
}

void ImprimeCandidato(tCandidato c){
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", c.codigo, c.nome, c.sobrenome,
            c.nota, c.idade);
}

int main(){

    int qtdCand, i = 0, j; 
    scanf("%d", &qtdCand);

    tCandidato candidatos[qtdCand]; 
    
    for (i = 0; i < qtdCand; i++){ 
        candidatos[i] = LeCandidato(); 
    }

    OrdenaCrescente(candidatos, qtdCand);

    for (i = 0; i < qtdCand; i++){ 
        ImprimeCandidato(candidatos[i]); 
    }
    return 0;     
}