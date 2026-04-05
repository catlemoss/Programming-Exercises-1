#include <stdio.h>

/*  Um programa para exibir a placa com maior 
débito (considerando valores não prescritos) das multas referentes a placas de 
algumas cidades e por fim apresentar a soma dos maiores débitos das cidades 
consideradas.  
*/

int QtdDebitoPlaca(int presc){
    int valor, anos;
    int soma = 0;
    char c;

    while (1){
        c = getchar();

        if (c == '\n' || c == EOF) break;  // acabou linha placa

        if (c == '('){
            scanf("%d:%d)", &valor, &anos);
            if (anos <= presc) soma += valor;
        }
    }
    return soma;
}

int MaiorDebitoCidade(){
    int p;
    scanf("%d", &p);

    char a, b, c;
    int maior = 0;
    int soma;
    char ma, mb, mc; //maior debito

    while (1){
        scanf(" %c", &a);
        scanf("%c", &b); 
        scanf("%c", &c);

        if (a == 'F' && b == 'I' && c == 'M') break;

        soma = QtdDebitoPlaca(p);

        if (soma > maior){
            maior = soma;
            ma = a;
            mb = b;
            mc = c;
        }
    }

    if (maior == 0){
        printf("SEM DEBITO!\n");
        return 0;
    }

    printf("PLACA:%c%c%c DEBITO:%d\n", ma, mb, mc, maior);
    return maior;
}

int main(){
    int n; // num cidades
    scanf("%d", &n);

    int soma_total = 0;

    for (int i = 0; i < n; i++){
        soma_total += MaiorDebitoCidade();
    }

    printf("SOMA:%d\n", soma_total);
    return 0;
}