#include <stdio.h>
#include <stdlib.h>

/* Dado o programa abaixo que lê candidatos de um 
concurso e imprime em ordem crescente, implemente a função que ordena os 
candidatos em ordem crescente considerando o nome completo do candidato.  */
 
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
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}
/* < 0 a vem antes de b
   > 0 a vem depois de b
   0 iguais
*/

int ComparaCandidato(tCandidato a, tCandidato b){
    int c;
    c = ComparaString(a.nome, b.nome);
    if (c != 0) return c;

    return ComparaString(a.sobrenome, b.sobrenome);
}

void CopiaString(char orig[], char dest[]){
    int i = 0;
    while (orig[i] != '\0'){
        dest[i] = orig[i];
        i++;
    }
    dest[i] = '\0';
}

void OrdenaCrescente(tCandidato vet[], int qtd){
    int troca = 1;
    int i;
    tCandidato aux;

    while (troca){
        troca = 0;

        for (i = 0; i < qtd-1; i++){
            if (ComparaCandidato(vet[i], vet[i+1]) > 0){
                
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
    
    for(i = 0; i < qtdCand; i++){ 
        candidatos[i] = LeCandidato(); 
    } 
    
    OrdenaCrescente(candidatos, qtdCand); 
    
    for(i = 0; i < qtdCand; i++){ 
        ImprimeCandidato(candidatos[i]); 
    }
  
    return 0;     
}