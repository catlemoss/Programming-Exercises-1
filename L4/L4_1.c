#include <stdio.h>

/* Um programa para ler produtos formados pelos
campos: código (int), preço (float), quantidade em estoque (int). O programa deverá
ao final imprimir uma lista dos produtos que estão em falta, o produto mais caro e o
mais barato. Para isso, implemente e use o tipo tProduto contendo os campos
necessários, e com as seguintes operações:
*/

typedef struct {
    int codigo;
    float preco;
    int quantidade_em_estoque;
} tProduto;

tProduto LeProduto(){
    tProduto p;
    scanf("%d;%f;%d", &p.codigo, &p.preco, &p.quantidade_em_estoque);
    return p;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2){
    if (p1.preco > p2.preco) return 1;
    else if (p1.preco == p2.preco) return 2;
    else return 0;
}

int EhProduto1MenorQ2(tProduto p1, tProduto p2){
    if (p1.preco < p2.preco) return 1;
    else return 0;
}

int TemProdutoEmEstoque(tProduto p){
    if (p.quantidade_em_estoque == 0) return 0;
    else return 1;
}

void ImprimeProduto(tProduto p){
    printf("COD %d, PRE %.2f, QTD %d\n", p.codigo, p.preco, p.quantidade_em_estoque);
}

int main(){

    int n, maior = -1, menor = 999999999;
    tProduto p, p_maior, p_menor;
    scanf("%d", &n);

    p_maior.preco = maior;
    p_menor.preco = menor;

    for (int i = 0; i < n; i++){

        p = LeProduto();

        if (EhProduto1MaiorQ2(p, p_maior) == 2) p_maior = p_menor;

        if (EhProduto1MaiorQ2(p, p_maior) == 1) p_maior = p;

        if (EhProduto1MenorQ2(p, p_menor) == 1) p_menor = p;

        if (TemProdutoEmEstoque(p) == 0){
            printf("FALTA:");
            ImprimeProduto(p);
        }
    }

    printf("MAIOR:");
    ImprimeProduto(p_maior);

    printf("MENOR:");
    ImprimeProduto(p_menor);

    return 0;
}