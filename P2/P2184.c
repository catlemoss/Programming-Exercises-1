#include <stdio.h>

/* Um programador resolveu codificar a sua senha 
de 6 dígitos como números de um texto. Os valores relevantes para a montagem da 
senha são armazenados em números que estão entre parênteses no texto. Cada 
número entre parênteses representa um dígito secreto. Um dígito secreto é dado 
pela soma dos algarismos do número entre parênteses, sucessivamente até que só 
reste um dígito (por exemplo, 29 = 2 + 9 = 11; 11 = 1 + 1 = 2, portanto, 29 codifica o 
dígito secreto 2). A senha é montada inserindo os dígitos secretos pela direita de 
acordo com a ordem de ocorrência (por exemplo, se apareceram no texto os dígitos 
secretos 3, depois o 2 e depois o 6, isso formaria a senha 326). Faça um programa 
que converta os números entre parênteses para o dígito secreto, e ao final imprima a 
senha codificada.  
*/

int ReduzInteiro(int n){
    int soma;
    if (n < 10) return n;
    while (n >= 10){ // repete ate que num so tenha um digito
        soma = 0;
        while (n > 0){
            soma += n % 10;
            n /= 10;
        }
        n = soma;
    }
    return soma;
}

int MontaSenha(int senha, int dig){ //senha até o momento e dígito a ser incluído
    return senha * 10 + dig;
}

int ReduzCodigo(){
    int soma = 0;
    int tem_digito = 0;
    char c;
    while ((c = getchar()) != EOF && c != ')'){
        if (c >= '0' && c <= '9'){
            tem_digito = 1;
            soma += (c - '0');
        }
    }
    if (!tem_digito) return -1;
    return ReduzInteiro(soma);
}

int main(){

    char c;
    int digito;
    int senha = 0;

    while ((c = getchar()) != EOF){
        if (c == '('){
            digito = ReduzCodigo();

            if (digito == -1){
                printf("[ERRO]");
                
            } else {
                printf("[%d]", digito);
                senha = MontaSenha(senha, digito);
            }
        } else {
            putchar(c);
            if (c == '.') break;
        }
    }

    printf(" SENHA:%d\n", senha);
    return 0;
}