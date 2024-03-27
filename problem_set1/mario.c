#include <stdio.h>
#include <stdlib.h> // Para a função atoi

int main() {
    int altura;
    char input[100]; // Buffer para armazenar a entrada do usuário

    do {
        printf("Digite a altura da escada (um número positivo maior que zero): ");
        fgets(input, sizeof(input), stdin); // Ler a entrada do usuário como string

        // Converter a entrada para um número inteiro
        altura = atoi(input);

        // Verificar se a entrada é válida
        if (altura <= 0) {
            printf("Por favor, insira um número positivo maior que zero.\n");
        }
        else {
            break; // Saia do loop se a entrada for válida
        }
    } while (1); // Loop infinito

    // Agora a variável 'altura' contém um valor válido

    // Imprimir a escada
    for (int i = 1; i <= altura; i++) {
        // Loop para imprimir os espaços à esquerda da escada
        for (int j = 0; j < altura - i; j++) {
            printf(" ");
        }

        // Loop para imprimir os blocos de subida da escada
        for (int k = 0; k < i; k++) {
            printf("#");
        }

        // Ir para a próxima linha para a próxima etapa da escada
        printf("\n");
    }

    return 0;
}
