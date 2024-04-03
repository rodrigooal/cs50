#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char encryptChar(char letter, int key) {
    if (isalpha(letter)) {
        char base = isupper(letter) ? 'A' : 'a';
        return ((letter - base + key) % 26) + base;
    }
    return letter;
}

void encryptString(char *plaintext, int key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        plaintext[i] = encryptChar(plaintext[i], key);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (!isdigit(argv[1][i])) {
            printf("Key must be a non-negative integer.\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    char plaintext[100];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    encryptString(plaintext, key);

    printf("ciphertext: %s\n", plaintext);

    return 0;
}
