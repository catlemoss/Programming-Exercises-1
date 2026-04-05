#include <stdio.h>

/*  Um programa para exibir o índice da turma 
com a maior e a menor quantidade de alunos aprovados.
*/

double LeNotasECalculaMediaAluno(){
    double soma = 0.0, nota, menor = 101.0;
    int cont = 0;
    int c;

    do {
        c = getchar();
    } while (c != '[');

    while (1){
        if (scanf("%lf", &nota) == 1){
            soma += nota;
            cont++;
            if (nota < menor) menor = nota;
        }

        c = getchar();
        if (c == ']') break;
    }

    while ((c = getchar()) != '\n' && c != EOF);

    if (cont == 1) return soma;
    return (soma - menor) / (cont - 1);
}

int ContaAlunosAprovadosTurma(){
    int a;
    scanf("%d", &a);

    char letra1, letra2;
    int aprovados = 0;

    for (int i = 0; i < a; i++){
        scanf(" %c%c", &letra1, &letra2);

        double media = LeNotasECalculaMediaAluno();

        if (media >= 70.0) { aprovados++; printf("%c\n", letra1); }
    }
    return aprovados;
}

int main(){
    int n;
    scanf("%d", &n);

    int maior = -1, menor = 10000000;
    int turma_maior = 1, turma_menor = 1;

    for (int i = 1; i <= n; i++){
        printf("TURMA:%d\n", i);

        int aprov = ContaAlunosAprovadosTurma();

        if (aprov > maior) { maior = aprov; turma_maior = i; }
        if (aprov < menor) { menor = aprov; turma_menor = i; }
    }

    printf("MAIOR:TURMA %d MENOR:TURMA %d\n", turma_maior, turma_menor);
    return 0;
}