#include <stdio.h>

/* Um programa capaz de calcular todos os 
números primos até um valor fornecido pelo usuário. */

int ehprimo(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main(){

  int i = 0, den = 0, primo = 0, qtd = 0, cont = 0;
  scanf("%d", &qtd);

    for(i = 2; i <= qtd; i++){
        if(ehprimo(i)){
            printf("%d ", i);
        }
    }
  return 0;
}