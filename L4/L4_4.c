#include <stdio.h>
#include <math.h>

/* Implemente um tipo de dados tPonto para representar um 
ponto cartesiano com coordenadas inteiras.
    Faça um programa que leia n pontos e informe seu quadrante, 
seu simétrico e o quadrante do seu simétrico. */

typedef struct {
    int x;
    int y;
} tPonto; // variavel tipo ponto

// (a) inicialização do ponto a partir de um x e um y dados;
tPonto inicializaPonto(int x, int y){
    tPonto p;
    p.x = x;
    p.y = y;
    return p;
}

// (b) inicialização de ponto com coordenadas lidas da entrada padrão;
tPonto lePonto(){
    tPonto p;
    scanf("%d %d", &p.x, &p.y);
    return p;
}

// (c) apresentação das coordenadas do ponto na saída padrão com o formato “(x,y)”;
void apresentaCord(tPonto p){
    printf("(%d,%d) ", p.x, p.y);
}

// (d) alteração da abscissa x do ponto;
tPonto alteraAbs(tPonto p, int novoX){
    p.x = novoX;
    return p;
}

// (e) alteração da ordenada y do ponto;
tPonto alteraOrd(tPonto p, int novoY){
    p.y = novoY;
    return p;
}

// (f) obtenção da abscissa x do ponto;
int obtX(tPonto p){
    return p.x;
}

// (g) obtenção da ordenada y do ponto;
int obtY(tPonto p){
    return p.y;
}

// (h) movimentação do ponto por um delta x e um delta y;
tPonto movePonto(tPonto p, int dx, int dy){
    p.x += dx;
    p.y += dy;
    return p;
}

// (i) cálculo da distância entre dois pontos;
float distancia(tPonto p1, tPonto p2){
    float d;
    d = sqrt( pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    return d;
}

// (j) identificação do quadrante do ponto
//(1, 2, 3 ou 4 para os quadrantes normais e 0 para pontos em cima dos eixos);
void identificaQuad(tPonto p){
    if (p.x > 0 && p.y > 0) printf("1 ");
    else if (p.x < 0 && p.y > 0) printf("2 ");
    else if (p.x < 0 && p.y < 0) printf("3 ");
    else if (p.x > 0 && p.y < 0) printf("4 ");
    else printf("0 ");
}

// (k) obtenção do ponto simétrico a um ponto.
tPonto simetrico(tPonto p){
    tPonto s;
    s.x = -p.x;
    s.y = -p.y;
    return s;
}

int main(){

    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        tPonto p, s;
        p = lePonto();
        apresentaCord(p);
        identificaQuad(p);

        s = simetrico(p);
        apresentaCord(s);
        identificaQuad(s);
        printf("\n");
    }
    return 0;
}