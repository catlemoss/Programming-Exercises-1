#include <stdio.h>

/*  O contador de letrinhas! Um escritor maluco 
precisava manter a contagem das letras que estava escrevendo para fluir melhor as 
ideias. Para isso, ele criou uma maneira de marcar o texto com símbolos em pontos 
especiais, em que a contagem deveria ser feita. Em sua contagem, ele considerava 3 
tipos de elementos: letras, vogais e consoantes. Ele utilizava símbolos para saber o 
que contar até aquele.

O símbolo *1* no texto representava uma contagem de todas as letras;
O símbolo *2* no texto representava uma contagem de todas as vogais;
O símbolo *3* no texto representava uma contagem de todas as consoantes;
*/

//*L:#1 V:#2 C:#3*

int EhLetra(char c){
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') return 1;
    else return 0;
}

int EhVogal(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
    else return 0;
}

int ReconheceSimbolo(char c){
    char conteudo[50];
    int i = 0;

    if (c != '*') return 0;

    while ((c = getchar()) != EOF && c != '*'){
        conteudo[i++] = c;
    }
    conteudo[i] = '\0';

    if (c != '*') return -1;

    if (i == 1 && conteudo[0] == '1') return 1;
    if (i == 1 && conteudo[0] == '2') return 2;
    if (i == 1 && conteudo[0] == '3') return 3;

    return -1;
}

int main(){

    char c, simbolo;
    int letras = 0, vogais = 0, consoantes = 0;

    while ((c = getchar()) != EOF){ // leitura de palavras
        if (c != '.'){
            if (c != '*'){
                if (EhLetra(c)){
                    letras++;
                    if (EhVogal(c)){
                        vogais++;
                    } else {
                        consoantes++;
                    }
                    printf("%c", c);
                    continue;
                }
            } else if (c == '*'){
                simbolo = ReconheceSimbolo(c);

                if (simbolo == 0){
                    printf("*");
                    continue;
                }
                if (simbolo == 1){
                    printf("*L:%d V:%d C:%d*", letras, vogais, consoantes);
                    letras = vogais = consoantes = 0;
                }
                if (simbolo == 2){
                    printf("*V:%d*", vogais);
                    vogais = 0;
                }
                if (simbolo == 3){
                    printf("*C:%d*", consoantes);
                    consoantes = 0;
                }
                if (simbolo == -1){
                    printf("*ERRO*");
                }
            }
        } else if (c == '.'){
            putchar('.');
            break;
        }
    }
    return 0;
}