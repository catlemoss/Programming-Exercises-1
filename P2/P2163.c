#include <stdio.h>

/*  Uma padaria resolveu identificar seu cliente mais guloso e pediu para que 
você fizesse um programa para ajuda-los. Nessa padaria, o cliente será considerado 
o mais guloso quando ele for o que comprar a maior quantidade de um mesmo 
produto. Portanto, o programa deve receber uma lista de clientes com os produtos 
comprados por eles, e imprimir o código do primeiro cliente da lista que comprou a 
maior quantidade de um mesmo produto seguido da quantidade comprada daquele 
produto.
*/

int EhProduto(char prd){
    return (prd >= 'A' && prd <= 'Z');
}

int AcabaramOsProdutos(char prd){
    return prd == '0';
}

int QtdDoProdutoMaisComprado(){
    int max = 0, atual = 0;
    char ultimo = 0, c;

    while (1){
        scanf(" %c", &c);  // ignora espacos e quebras de linha

        if (AcabaramOsProdutos(c)) break;

        if (EhProduto(c)){
            if (c == ultimo){
                atual++;

            } else {
                atual = 1;
                ultimo = c;
            }

            if (atual > max) max = atual;
        }
    }
    return max;
}

int main(){

    int codigo;

    while (1){

        scanf(" %d", &codigo);  // ignora espaco antes do número

        if (codigo == -1) break;

        int mais_guloso = codigo;
        int maior_quant = 0;

        while (codigo != -1){

            int qtd = QtdDoProdutoMaisComprado();

            if (qtd > maior_quant){
                maior_quant = qtd;
                mais_guloso = codigo;
            }

            scanf(" %d", &codigo);  //le o proximo codigo
        }

        printf("CLIENT:%d QTD:%d\n", mais_guloso, maior_quant);
    }

    return 0;
}