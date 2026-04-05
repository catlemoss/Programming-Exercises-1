#include <stdio.h>
#include <stdlib.h>

/* Um programa capaz de informar se uma pessoa pode votar ou não.  */

int main(int argc, char const *argv[]){

    int idade;
    scanf("%d", &idade);

    if(idade < 16) printf("vc nao pode votar!\n");
    if(16 <= idade && idade < 18) printf("vc pode votar, mas nao eh obrigado!\n");
    if(18 <= idade && idade < 65) printf("vc eh obrigado a votar!\n");
    if(65 <= idade) printf("vc pode votar, mas nao eh obrigado!\n");
    
    return 0;
}