#include <stdio.h>
#include <math.h>

/* Utilizando o tipo tPonto, implemente um tipo de dados 
tReta para representar uma reta no plano cartesiano com coordenadas inteiras.   */

typedef struct {
    int x;
    int y;
} tPonto;

tPonto lePonto(){
    tPonto p;
    scanf("%d %d", &p.x, &p.y);
    return p;
}

//(a) inicialização da reta a partir de um ponto inicial e outro final;
typedef struct {
    tPonto inicio, fim;
} tReta;

//(b) inicialização a partir da leitura de dois pontos da entrada padrão;
tReta leReta(){
    tReta r;
    r.inicio = lePonto();
    r.fim = lePonto();
    return r;
}

//(c) apresentação da reta com os pontos iniciais pi e finais pf no 
//seguinte formato “[(pi.x,pi.y):(pf.x,pf.y)]”;
void imprimeReta(tPonto pi, tPonto pf){
    printf("[(%d,%d):(%d,%d)]", pi.x, pi.y, pf.x, pf.y);
}

//(d) obtenção do ponto inicial da reta;
tPonto obtPi(tReta r){
    return r.inicio;
} 

//(e) obtenção do ponto final da reta;
tPonto obtPf(tReta r){
    return r.fim;
}

//(f) movimentação da reta;
tReta moveReta(tReta r, int dx, int dy){
    r.inicio.x += dx;
    r.inicio.y += dy;
    r.fim.x += dx;
    r.fim.y += dy;
    return r;
}

//(g) tamanho da reta.
float distancia(tPonto pi, tPonto pf){
    return sqrt( pow((pi.x - pf.x), 2) + pow((pi.y - pf.y), 2));
    //raiz de pi-pfx^2 + pi-pfy^2
}

int main(){

    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        tPonto p;
        p = lePonto();

        tReta r;
        r = leReta();
        float distInicial = distancia(p, r.inicio);
        float distFinal = distancia(p, r.fim);

        if (distInicial < distFinal) printf("INICIO\n");
        else if (distInicial > distFinal) printf("FIM\n");
        else printf("EQUIDISTANTE\n");
    }
    return 0;
}