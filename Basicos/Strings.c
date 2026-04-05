#include <stdio.h>

int main(){

    char s[10];

    printf("Enter a string (scanf convencional): ");
    scanf("%s", s);
    fflush(stdin);// Limpar o buffer de entrada

    // Limpar o '\n' deixado no buffer
    getchar(); // <-- isso consome o Enter

    printf("You entered: %s\n\n", s);

    printf("Enter a string (scanf aprimorado): \n");
    scanf("%9[^\n]", s); // Corrigido: sem o 's' no final
    fflush(stdin);
    getchar(); // opcional, para evitar problemas futuros

    printf("You entered: %s\n\n", s);

    return 0;
}

// Note: The use of `fflush(stdin)` is not standard and may not work as expected in all compilers.
// It is generally better to use other methods to clear the input buffer, such as reading until
// a newline character or using `fgets` for safer input handling.
// The scanf format specifier `%9[^\n]` reads up to 9 characters until a newline is encountered,
// ensuring that the string does not overflow the buffer. 
