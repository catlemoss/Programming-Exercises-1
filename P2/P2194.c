#include <stdio.h>

/* Um programa para analisar as senhas de grupos 
de usuários e ao final apresentar o grupo com maior quantidades de senhas fortes, o 
com maior de senhas fracas e o com maior de senhas inválidas. Uma senha é dita forte 
quando ela é válida e contém pelo menos uma letra maiúscula, uma letra minúscula, 
um número e um caractere não alfanumérico. Uma senha é dita fraca quando ela é 
válida, mas não é forte. Uma senha é inválida quando ele possui menos de 6 caracteres. 
*/

int EhLetraMaiuscula(char c){
    return (c >= 'A' && c <= 'Z');
}

int EhLetraMinuscula(char c){
    return (c >= 'a' && c <= 'z');
}

int EhNumero(char c){
    return (c >= '0' && c <= '9');
}

int AnalisaSenha(){
    int c;
    int maiusculas = 0, minusculas = 0, digitos = 0, nao_alfanum = 0;
    int cont = 0;

    do {
        c = getchar();
        if (c == EOF) return 0;
    } while (c != '(');

    while (1){
        c = getchar();
        if (c == EOF || c == ')') break;
        cont++;
        if (EhLetraMaiuscula((char)c)) maiusculas++;
        else if (EhLetraMinuscula((char)c)) minusculas++;
        else if (EhNumero((char)c)) digitos++;
        else nao_alfanum++;
    }

    if (cont < 6) return 0;
    if (maiusculas >= 1 && minusculas >= 1 && digitos >= 1 && nao_alfanum >= 1) return 2;
    return 1;
}

int main(){
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int ch = getchar();
    (void)ch;

    int max_fortes = 0, grupo_forte = 1;
    int max_fracas = 0, grupo_fraco = 1;
    int max_invalidas = 0, grupo_invalido = 1;

    for (int i = 1; i <= n; i++){
        int codigo;
        int fortes = 0, fracas = 0, invalidas = 0;

        printf("GRUPO %d\n", i);

        while (1){
            if (scanf("%d", &codigo) != 1) return 0;

            if (codigo == -1) break;

            int tipo = AnalisaSenha();

            if (tipo == 2){
                printf("FORTE\n");
                fortes++;
            } else if (tipo == 1){
                printf("FRACA\n");
                fracas++;
            } else {
                printf("INVALIDA\n");
                invalidas++;
            }
        }

        if (fortes > max_fortes){
            max_fortes = fortes;
            grupo_forte = i;
        }
        if (fracas > max_fracas){
            max_fracas = fracas;
            grupo_fraco = i;
        }
        if (invalidas > max_invalidas){
            max_invalidas = invalidas;
            grupo_invalido = i;
        }
        printf("\n");
    }

    printf("FORTES: GRUPO(%d) QTD(%d)\n", grupo_forte, max_fortes);
    printf("FRACAS: GRUPO(%d) QTD(%d)\n", grupo_fraco, max_fracas);
    printf("INVALIDAS: GRUPO(%d) QTD(%d)\n", grupo_invalido, max_invalidas);

    return 0;
}