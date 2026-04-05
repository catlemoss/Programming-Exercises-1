#include <stdio.h>

/* Um programa que imprima na tela um 
desenho em forma de um diamante do tamanho especificado pelo tamanho do seu topo e 
pelo tamanho do seu meio. 
*/

void imprime_linha(int quantidade, int m){
    int underline = (m - quantidade) / 2;

    for (int i = 0; i < underline; i++)
        printf("_");
    for (int i = 0; i < quantidade; i++)
        printf("$");
    for (int i = 0; i < underline; i++)
        printf("_");
    
    printf("\n");
}

int main(){
    int t, m;
    scanf("%d %d", &t, &m);
    if (t % 2 == 0 || m % 2 == 0) return 0;
    int quantidade = t;
    while (quantidade < m){
        imprime_linha(quantidade, m);
        quantidade += 2;
    }
    imprime_linha(m, m);
    quantidade = m - 2;
    while (quantidade >= 1){
        imprime_linha(quantidade, m);
        quantidade -= 2;
    }
    return 0;
}