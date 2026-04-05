#include <stdio.h>
#include <string.h>

typedef struct {
    char extensao[100]; // vem primeiro pq no input ta antes
    char nome[100];
    int tamanho; // tamanho do arquivo, nao usado no codigo mas pode ser usado para validar se o arquivo cabe na pasta
} tArquivo;

tArquivo tArquivo_le() {
    tArquivo a;
    scanf("%s %s %d", a.extensao, a.nome, &a.tamanho); // sem & porque extensao e nome são arrays
    return a;
}

void tArquivo_imprime(tArquivo arquivo) {
    printf("  (%s) %s\n", arquivo.extensao, arquivo.nome); // imprime a extensao entre parenteses
} // lembrar que void nao tem return

int tArquivo_qualTamanho(tArquivo arquivo) {
    return arquivo.tamanho;
}

typedef struct {
    char nome[100];
    int quant_arq;
    tArquivo arquivos[100]; // array de arquivos, maximo 100
    int max_tamanho; // tamanho maximo da pasta
} tPasta;

tPasta tPasta_adicionaArquivo(tPasta pasta, tArquivo arquivo) {
    pasta.arquivos[pasta.quant_arq] = arquivo; // adiciona o arquivo na pasta
    pasta.quant_arq++; // incrementa a quantidade de arquivos pois adicionou um novo
    return pasta;
}

int tPasta_cabeArquivo(tPasta pasta, tArquivo arquivo) {
    int soma = 0;
    for (int i = 0; i < pasta.quant_arq; i++) {
        soma += tArquivo_qualTamanho(pasta.arquivos[i]);
    }
    return (soma + tArquivo_qualTamanho(arquivo) <= pasta.max_tamanho);
}

tPasta tPasta_le() {
    tPasta p;
    int qtd;
    scanf("%s %d %d", p.nome, &qtd, &p.max_tamanho);
    p.quant_arq = 0; // inicializa a quantidade de arquivos como 0 pois ainda nao tem nenhum

    for (int i = 0; i < qtd; i++) { // for para ler os arquivos
        tArquivo a = tArquivo_le();
        p = tPasta_adicionaArquivo(p, a);
    }
    return p;
}

void tPasta_imprime(tPasta pasta) {
    printf("%s:\n", pasta.nome);
    for (int i = 0; i < pasta.quant_arq; i++) { // percorre os arquivos da pasta
        tArquivo_imprime(pasta.arquivos[i]); // imprime o arquivo se ele passar no filtro    
    }
}

int main() {
    int nPasta;
    scanf("%d", &nPasta);

    tPasta pastas[50];
    for (int i = 0; i < nPasta; i++){
        pastas[i] = tPasta_le();
    }

    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++){
        char pastaNome[100];
        tArquivo novoArq;
        scanf("%s %s %s %d", pastaNome, novoArq.extensao, novoArq.nome, &novoArq.tamanho);

        int encontrada = 0;
        for (int j = 0; j < nPasta; j++){
            if (strcmp(pastas[j].nome, pastaNome) == 0){
                encontrada = 1;
                if (tPasta_cabeArquivo(pastas[j], novoArq)){
                    pastas[j] = tPasta_adicionaArquivo(pastas[j], novoArq);
                } else {
                    printf("ERRO: Arquivo nao cabe na pasta %s.\n", pastaNome);
                }
                break;
            }
        }
        if (!encontrada) {
            printf("ERRO: Pasta %s nao encontrada.\n", pastaNome);
        }
    }
    for (int i = 0; i < nPasta; i++) {
        tPasta_imprime(pastas[i]);
    }
    return 0;
}