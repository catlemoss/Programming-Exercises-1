#include <stdio.h>

/* Um satélite tira fotos regulares da terra, e as imagens 
são armazenadas em matrizes. Após um certo processamento na imagem, é possível 
diferenciar água de terra (valores 0 representam terra e valores 1 representam 
água).  */

int main(){

    int horas;
    scanf("%d", &horas);

    int w, h;
    scanf("%d %d", &w, &h);

    int mapa[h][w];

    int terra = 0;

    // le mapa
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){ // os numeros estao grudados, entao le como char

            char c;
            scanf(" %c", &c);

            mapa[i][j] = c - '0'; // mapa agora e int
            /*  '1' - '0' = 1
                '0' - '0' = 0
            */
            if (mapa[i][j] == 0) terra++;
        }
    }

    // simula agua
    for (int t = 0; t < horas; t++){

        int novo[h][w];

        // copia o mapa
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){ 
                novo[i][j] = mapa[i][j]; // atualiza mapa
            }
        }

        // avanco agua
        for (int i = 1; i < h-1; i++){
            for (int j = 1; j < w-1; j++){ // evitamos bordas pq sao sempre agua
                if (mapa[i][j] == 0 &&
                    (mapa[i-1][j] == 1 || 
                    mapa[i+1][j] == 1 ||
                    mapa[i][j-1] == 1 || 
                    mapa[i][j+1] == 1)){

                    // se a posicao e terra e tem agua tocando nela,
                    // entao terra vira agua

                    novo[i][j] = 1;
                }
            }
        }

        // atualiza mapa
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                mapa[i][j] = novo[i][j];
    }

    // conta terra final
    int terra_final = 0;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){

            if (mapa[i][j] == 0) terra_final++;
        }
    }

    printf("%d %d\n", terra, terra_final);
    return 0;
}