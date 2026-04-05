#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N 50 // Tamanho máximo da string

int main(){

    setlocale(LC_ALL, "Portuguese");

    char hardText[N] = {"Cat"}; // Senha hardcoded para comparação
    // A senha hardcoded é "Cat"
    char senha_user[N]; // Variável para armazenar a senha do usuário
    // A senha do usuário será lida do teclado
    // e comparada com a senha hardcoded
    int ok; // Variável para armazenar o resultado da comparação

    printf("Digite a senha: \n");
    fgets(senha_user, N, stdin); // Lê a senha do usuário, incluindo espaços
    senha_user[strcspn(senha_user, "\n")] = '\0';
    // Remove o caractere de nova linha da string lida

    ok = strcmp(senha_user, hardText); // Compara a senha do usuário com a senha hardcoded

    if (ok == 0){ 
        printf("Senha correta!\n");

    } else {
        printf("Senha incorreta!\n");
    }

    return 0;
}
// This program compares a hardcoded password with user input using strcmp.
// If the passwords match, it prints "Senha correta!", otherwise it prints "Senha incorreta!".

// Lembre-se de que a senha pode acabar por ler o \n, fazendo-se necessário removê-lo
// com a função strcspn para evitar problemas na comparação.


// Não é recomendado usar senhas hardcoded em programas reais,
// pois isso pode comprometer a segurança do sistema.