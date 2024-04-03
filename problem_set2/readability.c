#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Função para contar o número de letras em uma string
int countLetters(string text) {
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++) {
        if (isalpha(text[i])) {
            count++;
        }
    }
    return count;
}

// Função para contar o número de palavras em uma string
int countWords(string text) {
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++) {
        if (isspace(text[i])) {
            count++;
        }
    }
    return count + 1;
}

// Função para contar o número de frases em uma string
int countSentences(string text) {
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }
    return count;
}

// Função para calcular o nível de leitura usando a fórmula Coleman-Liau index
int calculateGradeLevel(int letters, int words, int sentences) {
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return round(index);
}

int main() {
    // Solicitação da entrada de texto
    string text = get_string("Text: ");

    // Contagem de letras, palavras e frases
    int numLetters = countLetters(text);
    int numWords = countWords(text);
    int numSentences = countSentences(text);

    // Cálculo do nível de leitura usando Coleman-Liau index
    int gradeLevel = calculateGradeLevel(numLetters, numWords, numSentences);

    // Saída do resultado
    if (gradeLevel < 1) {
        printf("Before Grade 1\n");
    } else if (gradeLevel >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", gradeLevel);
    }

    return 0;
}
