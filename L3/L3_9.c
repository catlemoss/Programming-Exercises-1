#include <stdio.h>
#include <math.h>

/* Você e seu amigo estão desenvolvendo um projeto de 
Iniciação Científica, no qual consiste na criação de um dispositivo de análises da 
chuva de determinada região. 
O dispositivo analisa, através de uma nova tecnologia, 
o pH das gotas de chuva de uma área. 
Para demonstrar o projeto para outros 
colegas, você precisa implementar um programa que mostra as estatísticas da chuva 
de uma região, dados a área da região em metros quadrados e a densidade de gotas 
de chuva (quantas gotas de chuva caem em 1 metro quadrado a cada 1 segundo) e o 
tempo em segundos que o dispositivo analisou o local. 
*/

int verificapH(float pH){
  	if (pH == 7.0) return 0;
	else if (pH < 7.0) return 1;
	else if (pH > 7.0) return 2;
}

int verificaGotaChuvaAcida(float pH){
	
	if (pH < 5.70) return 1;
	else return 0;
}

float porcentagem(float valor, float total){
	
	return valor / total * 100;
}

void imprimeResultadosAnalise(float porcentagem){
	
    float normal = fabsf(100.00 - porcentagem); // o resto da porcentagem

    if (porcentagem >= 75.00){
        printf("Chuva Acida %.2f%% %.2f%%\n", porcentagem, normal);
    }
    if (porcentagem < 75.00 && porcentagem >= 25.00){
        printf("Chuva com indicios de chuva acida %.2f%% %.2f%%\n", porcentagem, normal);
    }
    if (porcentagem < 25.00 && porcentagem >= 0.00){
        printf("Chuva Normal %.2f%% %.2f%%\n", porcentagem, normal);
    }
}

int main(){
	
	int A, D, T; // area (m^2), densidade (m^2 / s), tempo (s)
	scanf("%d %d %d", &A, &D, &T);
	
	float P; // pH
	
    // auxiliares
	int gota_acida = 0, gota_basica = 0, gota_neutra = 0, gotas_bem_acidas = 0, total_de_gotas;
	float mais_acido = 14.0, mais_basico = 0.0, mais_neutra = -1.0, menor_distancia = 100.0;
	
    total_de_gotas = A * D * T;

	if (total_de_gotas == 0){
		printf("Nenhuma gota foi avaliada\n");
		return 0;
	}
	
    for (int i = 0; i < total_de_gotas; i++){

        scanf("%f", &P);

        // conta num gotas
        if (verificapH(P) == 0){
            gota_neutra++;
            
        } else if (verificapH(P) == 1){
            gota_acida++;

            if (verificaGotaChuvaAcida(P) == 1){
                gotas_bem_acidas++;
            }
            
        } else if (verificapH(P) == 2){
            gota_basica++;
        }

        float distancia = fabs(P - 7.00); // calcula a distância do pH neutro para ver o mais próximo

        // conta num pH
        if (P < mais_acido){
            mais_acido = P;
        }
        if (P > mais_basico){
            mais_basico = P;
        }
        if (distancia < menor_distancia){
            menor_distancia = distancia;
            mais_neutra = P;
        }
    }

    float porcentagem_final = porcentagem(gotas_bem_acidas, total_de_gotas);

    printf("%d %d %d %.2f %.2f %.2f\n", 
        gota_acida, gota_basica, gota_neutra, mais_acido, mais_basico, mais_neutra);
    imprimeResultadosAnalise(porcentagem_final);
	return 0;
}