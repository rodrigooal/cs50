#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    int cents;
    int coins_count = 0;
    int denominations[] = {25, 10, 5, 1};
    int valid_input = 0;

    do {
        printf("Change owed: ");
        fgets(input, sizeof(input), stdin);

        // Remover o caractere de nova linha do final da entrada
        input[strcspn(input, "\n")] = '\0';

        // Verificar se a entrada está vazia ou não numérica
        int i = 0;
        valid_input = 1; // Supõe que a entrada é válida
        while (input[i] != '\0') {
            if (!isdigit(input[i])) {
                valid_input = 0; // A entrada não é válida
                break;
            }
            i++;
        }

        // Se a entrada for vazia ou não numérica, ou se for negativa, rejeite
        if (strlen(input) == 0 || !valid_input) {
            printf("Por favor, insira um valor numérico válido.\n");
            valid_input = 0; // Redefine a flag para rejeitar a entrada
            continue;
        }

        // Converter a entrada para centavos
        cents = atoi(input);

        // Verificar se o valor é negativo
        if (cents < 0) {
            printf("Por favor, insira um valor positivo.\n");
            valid_input = 0; // Redefine a flag para rejeitar a entrada
        }

    } while (!valid_input); // Solicitar novamente se a entrada for inválida

    // Calculando o número mínimo de moedas necessárias
    for (int j = 0; j < sizeof(denominations) / sizeof(denominations[0]); j++) {
        coins_count += cents / denominations[j];
        cents %= denominations[j];
    }

    printf("%d\n", coins_count);

    return 0;
}
