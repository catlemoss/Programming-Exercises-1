#include <stdio.h>

/*  Durante as Olimpíadas Rio/2016 um painel que mostrava o resultado das competições
    quebrou e você deverá escrever um programa para contabilizar e exibir os resultados.
    Cada Delegação de Atletas e cada Atleta serão identificados por um número inteiro.
    Cada Atleta realizará três provas e receberá uma nota de 0 a 10 para cada uma delas.
    Seu programa deverá dizer qual é o melhor e o pior Atleta de cada Delegação tanto
    para o Masculino quanto para o Feminino e por fim dizer qual é a Delegação Campeã
    para o Masculino e para o Feminino.
*/

int main() {
    int num_delegacoes;
    scanf("%d", &num_delegacoes);

    int delegacao_campea_masculino = 1, delegacao_campea_feminino = 1;
    int melhor_soma_masculino = -1, melhor_soma_feminino = -1;

    for (int i = 1; i <= num_delegacoes; i++) {

        int atleta, nota1, nota2, nota3;
        char sexo;

        int melhor_atleta_masc = -1, pior_atleta_masc = -1;
        int melhor_maior_masc = -1, melhor_medio_masc = -1, melhor_menor_masc = -1;
        int pior_maior_masc = 11, pior_medio_masc = 11, pior_menor_masc = 11;
        int soma_masculino = 0;

        int melhor_atleta_fem = -1, pior_atleta_fem = -1;
        int melhor_maior_fem = -1, melhor_medio_fem = -1, melhor_menor_fem = -1;
        int pior_maior_fem = 11, pior_medio_fem = 11, pior_menor_fem = 11;
        int soma_feminino = 0;

        while (1) {
            scanf("%d", &atleta);
            if (atleta == -1) break;

            scanf(" %c %d %d %d", &sexo, &nota1, &nota2, &nota3);

            // ordenar notas
            int maior = nota1, medio = nota2, menor = nota3;
            int aux;

            if (maior < medio){
                aux = maior; 
                maior = medio; 
                medio = aux;
            }
            if (medio < menor){
                aux = medio; 
                medio = menor; 
                menor = aux;
            }
            if (maior < medio){
                aux = maior; 
                maior = medio; 
                medio = aux;
            }

            if (sexo == 'M') { // masculino

                // melhor atleta
                if (maior > melhor_maior_masc ||
                    (maior == melhor_maior_masc && medio > melhor_medio_masc) ||
                    (maior == melhor_maior_masc && medio == melhor_medio_masc && menor > melhor_menor_masc) ||
                    (maior == melhor_maior_masc && medio == melhor_medio_masc && menor == melhor_menor_masc 
                        && atleta < melhor_atleta_masc)) {

                    melhor_atleta_masc = atleta;
                    melhor_maior_masc = maior;
                    melhor_medio_masc = medio;
                    melhor_menor_masc = menor;
                }

                // pior atleta
                if (maior < pior_maior_masc ||
                    (maior == pior_maior_masc && medio < pior_medio_masc) ||
                    (maior == pior_maior_masc && medio == pior_medio_masc && menor < pior_menor_masc) ||
                    (maior == pior_maior_masc && medio == pior_medio_masc && menor == pior_menor_masc 
                        && atleta > pior_atleta_masc)) {

                    pior_atleta_masc = atleta;
                    pior_maior_masc = maior;
                    pior_medio_masc = medio;
                    pior_menor_masc = menor;
                }

                soma_masculino += maior;

            } else if (sexo == 'F'){ // feminino

                // melhor atleta
                if (maior > melhor_maior_fem ||
                    (maior == melhor_maior_fem && medio > melhor_medio_fem) ||
                    (maior == melhor_maior_fem && medio == melhor_medio_fem && menor > melhor_menor_fem) ||
                    (maior == melhor_maior_fem && medio == melhor_medio_fem && menor == melhor_menor_fem 
                        && atleta < melhor_atleta_fem)) {

                    melhor_atleta_fem = atleta;
                    melhor_maior_fem = maior;
                    melhor_medio_fem = medio;
                    melhor_menor_fem = menor;
                }

                // pior atleta
                if (maior < pior_maior_fem ||
                    (maior == pior_maior_fem && medio < pior_medio_fem) ||
                    (maior == pior_maior_fem && medio == pior_medio_fem && menor < pior_menor_fem) ||
                    (maior == pior_maior_fem && medio == pior_medio_fem && menor == pior_menor_fem 
                        && atleta > pior_atleta_fem)) {

                    pior_atleta_fem = atleta;
                    pior_maior_fem = maior;
                    pior_medio_fem = medio;
                    pior_menor_fem = menor;
                }

                soma_feminino += maior;
            }
        }

        printf("MELHORES ATLETAS DA DELEGACAO %d\n", i);
        printf("MASCULINO: %d FEMININO: %d\n", melhor_atleta_masc, melhor_atleta_fem);
        printf("PIORES ATLETAS DA DELEGACAO %d\n", i);
        printf("MASCULINO: %d FEMININO: %d\n\n", pior_atleta_masc, pior_atleta_fem);

        if (soma_masculino > melhor_soma_masculino || (soma_masculino == melhor_soma_masculino 
            && i < delegacao_campea_masculino)){
            melhor_soma_masculino = soma_masculino, delegacao_campea_masculino = i;
        }

        if (soma_feminino > melhor_soma_feminino || (soma_feminino == melhor_soma_feminino 
            && i < delegacao_campea_feminino)){
            melhor_soma_feminino = soma_feminino, delegacao_campea_feminino = i;
        }
    }

    printf("DELEGACAO CAMPEA:\n");
    printf("MASCULINO: %d FEMININO: %d\n", delegacao_campea_masculino, delegacao_campea_feminino);

    return 0;
}

/* Considera-se campeã em um dos 
gêneros a Delegação que apresentar um maior valor para o somatório da maior nota 
de cada atleta daquele gênero. Em caso de empate, ganha aquela com a menor 
identificação. */